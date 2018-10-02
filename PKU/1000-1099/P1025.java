import java.util.*;

class Agent {

    static final int MAX_TIME = 86401;

    String name;
    int startTime;
    ArrayList<Task> tasks = new ArrayList<Task>();
    ArrayList<Report> reports = new ArrayList<Report>();

    int nextAvailableTime;
    boolean inDepartment;
    int currentPlace;
    int currentFloor;

    void work(int currentTime) {
        if (currentTime >= nextAvailableTime) {
            if (!inDepartment && !tasks.isEmpty()) {
                entry(currentTime);
            } else if (inDepartment && tasks.isEmpty()) {
                if (currentFloor == 1) {
                    exit(currentTime);
                } else if (currentPlace == -1) {
                    tryEnterElevator();
                } else {
                    transfer(currentTime, -1);
                }
            } else if (!tasks.isEmpty()) {
                Task task = tasks.get(0);
                if (currentFloor == task.getFloor() && currentPlace == task.getPlace()) {
                    tryEnterRoom(task.roomId);
                } else if (currentFloor == task.getFloor()) {
                    transfer(currentTime, task.roomId);
                } else if (currentPlace == -1) {
                    tryEnterElevator();
                } else {
                    transfer(currentTime, -1);
                }
            }
        }
    }

    void entry(int currentTime) {
        inDepartment = true;
        nextAvailableTime = currentTime + 30;
        currentPlace = tasks.get(0).getFloor() == 1 ? tasks.get(0).getPlace() : -1;
        currentFloor = 1;
        reports.add(Report.makeReport(currentTime, nextAvailableTime, Report.ENTRY, 0, 0));
    }

    void exit(int currentTime) {
        inDepartment = false;
        nextAvailableTime = currentTime + 30;
        reports.add(Report.makeReport(currentTime, nextAvailableTime, Report.EXIT, 0, 0));
    }

    void tryEnterElevator() {
        nextAvailableTime = MAX_TIME;
        PlaceManager.instance().getElevator(currentFloor).pq.add(name);
    }

    void tryEnterRoom(int roomId) {
        nextAvailableTime = MAX_TIME;
        PlaceManager.instance().getRoom(roomId).pq.add(name);
    }

    void transfer(int currentTime, int place) {
        nextAvailableTime = currentTime + 10;
        reports.add(Report.makeReport(currentTime, nextAvailableTime, Report.TRANSFER,
                currentPlace == -1 ? currentPlace : currentFloor * 100 + currentPlace, place));
        currentPlace = place == -1 ? place : place % 100;
    }

    void enterElevator(int currentTime) {
        int lastTime = reports.get(reports.size() - 1).endTime;
        if (currentTime > lastTime) {
            reports.add(Report.makeReport(lastTime, currentTime, Report.WAIT, -1, 0));
        }
        int needTime;
        if (tasks.isEmpty()) {
            needTime = (currentFloor - 1) * 30;
        } else {
            needTime = (tasks.get(0).getFloor() - currentFloor) * 30;
        }
        nextAvailableTime = currentTime + needTime;
        reports.add(Report.makeReport(currentTime, nextAvailableTime, Report.STAY, -1, 0));
        if (tasks.isEmpty()) {
            currentFloor = 1;
        } else {
            currentFloor = tasks.get(0).getFloor();
        }
    }

    void enterRoom(int currentTime) {
        int lastTime = reports.get(reports.size() - 1).endTime;
        if (currentTime > lastTime) {
            reports.add(Report.makeReport(lastTime, currentTime, Report.WAIT, tasks.get(0).roomId, 0));
        }
        nextAvailableTime = currentTime + tasks.get(0).duration;
        reports.add(Report.makeReport(currentTime, nextAvailableTime, Report.STAY, tasks.get(0).roomId, 0));
        PlaceManager.instance().getRoom(tasks.get(0).roomId).nextEmptyTime = nextAvailableTime;
        tasks.remove(0);
    }

    void log() {
        System.out.println(name);
        for (int i = 0; i < reports.size(); i++) {
            reports.get(i).print();
        }
        System.out.println();
    }
}

class Report {

    static final int ENTRY = 0;
    static final int STAY = 1;
    static final int WAIT = 2;
    static final int TRANSFER = 3;
    static final int EXIT = 4;

    int startTime;
    int endTime;
    int type;
    int startRoom;
    int endRoom;

    static Report makeReport(int startTime, int endTime, int type, int startRoom, int endRoom) {
        Report r = new Report();
        r.startTime = startTime;
        r.endTime = endTime;
        r.type = type;
        r.startRoom = startRoom;
        r.endRoom = endRoom;
        //r.print();
        return r;
    }

    void print() {
        switch (type) {
            case ENTRY:
                printEntry();
                break;
            case STAY:
                printStay();
                break;
            case WAIT:
                printWait();
                break;
            case TRANSFER:
                printTransfer();
                break;
            case EXIT:
                printExit();
                break;
        }
    }

    void printEntry() {
        System.out.println(TimeFormatter.time2Str(startTime) + " " + TimeFormatter.time2Str(endTime) + " "
                + "Entry");
    }

    void printStay() {
        System.out.println(TimeFormatter.time2Str(startTime) + " " + TimeFormatter.time2Str(endTime) + " "
                + (startRoom == -1 ? "Stay in elevator" : String.format("Stay in room %04d", startRoom)));
    }

    void printWait() {
        System.out.println(TimeFormatter.time2Str(startTime) + " " + TimeFormatter.time2Str(endTime) + " "
                + (startRoom == -1 ? "Waiting in elevator queue" : String.format("Waiting in front of room %04d", startRoom)));
    }

    void printTransfer() {
        String startRoomStr = startRoom == -1 ? "elevator" : String.format("room %04d", startRoom);
        String endRoomStr = endRoom == -1 ? "elevator" : String.format("room %04d", endRoom);
        System.out.println(TimeFormatter.time2Str(startTime) + " " + TimeFormatter.time2Str(endTime) + " "
                + String.format("Transfer from %s to %s", startRoomStr, endRoomStr));
    }

    void printExit() {
        System.out.println(TimeFormatter.time2Str(startTime) + " " + TimeFormatter.time2Str(endTime) + " "
                + "Exit");
    }
}

class Task {
    int roomId;
    int duration;
    int getFloor() {
        return roomId / 100;
    }
    int getPlace() {
        return roomId % 100;
    }
}

class Room {
    int roomId;
    int nextEmptyTime;
    PriorityQueue<String> pq = new PriorityQueue<String>();

    int getFloor() {
        return roomId / 100;
    }
}

class Elevator {
    int floor;
    PriorityQueue<String> pq = new PriorityQueue<String>();
}

class PlaceManager {

    Map<Integer, Room> roomMap = new HashMap<Integer, Room>();
    Map<Integer, Elevator> elevatorMap = new HashMap<Integer, Elevator>();
    List<Room> roomList = new ArrayList<Room>();
    List<Elevator> elevatorList = new ArrayList<Elevator>();

    static PlaceManager pm;

    static PlaceManager instance() {
        if (pm == null) {
            pm = new PlaceManager();
        }
        return pm;
    }

    Room getRoom(int roomId) {
        if (roomMap.containsKey(roomId)) {
            return roomMap.get(roomId);
        } else {
            Room room = new Room();
            room.roomId = roomId;
            room.nextEmptyTime = 0;
            roomMap.put(roomId, room);
            roomList.add(room);
            return room;
        }
    }
    Elevator getElevator(int floor) {
        if (elevatorMap.containsKey(floor)) {
            return elevatorMap.get(floor);
        } else {
            Elevator e = new Elevator();
            e.floor = floor;
            elevatorMap.put(floor, e);
            elevatorList.add(e);
            return e;
        }
    }
}

class AgentManager {
    Map<String, Agent> agentMap = new HashMap<String, Agent>();

    static AgentManager am;

    static AgentManager instance() {
        if (am == null) {
            am = new AgentManager();
        }
        return am;
    }

    void add(Agent agent) {
        agentMap.put(agent.name, agent);
    }

    Agent get(String agent) {
        return agentMap.get(agent);
    }
}

class Solve {

    void solve() {
        init();
        work();
        print();
    }


    void init() {
        Scanner cin = new Scanner(System.in);
        String name = "";
        while (!(name = cin.next()).equals(".")) {
            Agent agent = makeAgent(name, cin);
            agents.add(agent);
            AgentManager.instance().add(agent);
        }
    }

    Agent makeAgent(String name, Scanner cin) {
        Agent agent = new Agent();
        agent.name = name;
        String time = cin.next();
        agent.startTime = TimeFormatter.str2Time(time);
        int roomId = 0;
        while ((roomId = cin.nextInt()) != 0) {
            agent.tasks.add(makeTask(roomId, cin));
        }

        agent.nextAvailableTime = agent.startTime;
        agent.inDepartment = false;
        return agent;
    }

    Task makeTask(int roomId, Scanner cin) {
        Task task = new Task();
        task.roomId = roomId;
        task.duration = cin.nextInt();
        return task;
    }

    ArrayList<Agent> agents = new ArrayList<Agent>();

    void work() {
        int time = 0;
        while (time < 86400) {
            for (int i = 0; i < agents.size(); i++) {
                agents.get(i).work(time);
            }
            for (int i = 0; i < PlaceManager.instance().roomList.size(); i++) {
                if (time >= PlaceManager.instance().roomList.get(i).nextEmptyTime
                        && PlaceManager.instance().roomList.get(i).pq.size() > 0) {
                    String agentName = PlaceManager.instance().roomList.get(i).pq.peek();
                    PlaceManager.instance().roomList.get(i).pq.poll();
                    Agent agent = AgentManager.instance().get(agentName);
                    agent.enterRoom(time);
                }
            }
            if (time % 5 == 0) {
                for (int i = 0; i < PlaceManager.instance().elevatorList.size(); i++) {
                    if (PlaceManager.instance().elevatorList.get(i).pq.size() > 0) {
                        String agentName = PlaceManager.instance().elevatorList.get(i).pq.peek();
                        PlaceManager.instance().elevatorList.get(i).pq.poll();
                        Agent agent = AgentManager.instance().get(agentName);
                        agent.enterElevator(time);
                    }
                }
            }
            time++;
        }
    }

    void print() {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            String name = String.valueOf(ch);
            if (AgentManager.instance().agentMap.containsKey(name)) {
                Agent agent = AgentManager.instance().get(name);
                agent.log();
            }
        }
    }
}

class TimeFormatter {
    static int str2Time(String s) {
        return Integer.parseInt(s.substring(0, 2)) * 3600
                + Integer.parseInt(s.substring(3, 5)) * 60
                + Integer.parseInt(s.substring(6, 8));
    }

    static String time2Str(int time) {
        return String.format("%02d", (time / 3600)) + ":" + String.format("%02d", (time / 60 % 60))
                + ":" + String.format("%02d", (time % 60));
    }
}

public class Main {
    public static void main(String[] args) {
	    new Solve().solve();
    }
}
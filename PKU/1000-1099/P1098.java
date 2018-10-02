package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class User {
    int x, y;
    boolean alive = true;
    User() {
        x = y = 14;
    }
    User(User u) {
        x = u.x;
        y = u.y;
        alive = u.alive;
    }
    boolean canMove(int dx, int dy, Board b) {
        if (x + dx < 0 || x + dx == 31 || y + dy < 0 || y + dy == 31) {
            return false;
        }
        for (int i = 0; i < 9; i++) {
            if (x + dx + Board.dir[i][0] >= 0 && x + dx + Board.dir[i][0] < 31
                    && y + dy + Board.dir[i][1] >= 0 && y + dy + Board.dir[i][1] < 31
                    && b.g[x + dx + Board.dir[i][0]][y + dy + Board.dir[i][1]] == Board.ROBOT) {
                if (dx == Board.dir[i][0] && dy == Board.dir[i][1] && b.g[x + dx][y + dy] == Board.DEBRIS) {
                    continue;
                }
                return false;
            }
        }
        if (b.g[x + dx][y + dy] == Board.DEBRIS) {
            if (x + dx * 2 < 0 || x + dx * 2 == 31 || y + dy * 2 < 0 || y + dy * 2 == 31) {
                return false;
            } else if (b.g[x + dx * 2][y + dy * 2] == Board.DEBRIS) {
                return false;
            }
            return true;
        }
        return true;
    }

    void move(int dx, int dy, Board b) {
        if (!canMove(dx, dy, b)) {
            return;
        }
        if (b.g[x + dx][y + dy] == Board.EMPTY) {
            b.g[x][y] = Board.EMPTY;
            x += dx;
            y += dy;
            b.g[x][y] = Board.USER;
        } else if (b.g[x + dx][y + dy] == Board.DEBRIS) {
            b.g[x][y] = Board.EMPTY;
            x += dx;
            y += dy;
            b.g[x][y] = Board.USER;
            b.g[x + dx][y + dy] = Board.DEBRIS;
            b.destroyRobots();
        }
    }

    public void transportTo(Board board, Transport transport) {
        board.g[x][y] = Board.EMPTY;
        x = transport.x;
        y = transport.y;
        board.g[x][y] = Board.USER;
        board.transports.remove(transport);
    }
}

class Robot {
    int x, y;
    Robot(int x, int y) {
        this.x = x;
        this.y = y;
    }
    Robot(Robot r) {
        x = r.x;
        y = r.y;
    }
    void move(Board b) {
        b.g[x][y] = Board.EMPTY;
        if (x > b.user.x) {
            x--;
        } else if (x < b.user.x) {
            x++;
        }
        if (y > b.user.y) {
            y--;
        } else if (y < b.user.y) {
            y++;
        }
    }
}

class Transport {
    int x, y;
    Transport(int x, int y) {
        this.x = x;
        this.y = y;
    }
    Transport(Transport t) {
        x = t.x;
        y = t.y;
    }
    boolean legal(Board b) {
        if (b.g[x][y] != Board.EMPTY) {
            return false;
        }
        for (int i = 0; i < 9; i++) {
            if (x + Board.dir[i][0] >= 0 && x + Board.dir[i][0] < 31
                    && y + Board.dir[i][1] >= 0 && y + Board.dir[i][1] < 31
                    && b.g[x + Board.dir[i][0]][y + Board.dir[i][1]] == Board.ROBOT) {
                return false;
            }
        }
        return true;
    }
}

class Board implements Comparable<Board> {

    static final int EMPTY = 0;
    static final int USER = 1;
    static final int ROBOT = 2;
    static final int DEBRIS = 3;

    static final int[][] dir = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 0},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
    };

    User user = new User();
    ArrayList<Robot> robots = new ArrayList<Robot>();
    ArrayList<Transport> transports = new ArrayList<Transport>();
    int[][] g = new int[31][31];
    int moves = 0;

    Board() {

    }

    Board(Board b) {
        user = new User(b.user);
        for (int i = 0; i < b.robots.size(); i++) {
            robots.add(new Robot(b.robots.get(i)));
        }
        for (int i = 0; i < b.transports.size(); i++) {
            transports.add(new Transport(b.transports.get(i)));
        }
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < 31; j++) {
                g[i][j] = b.g[i][j];
            }
        }
        moves = b.moves;
    }

    void shallowCopy(Board b) {
        user = b.user;
        robots = b.robots;
        transports = b.transports;
        g = b.g;
        moves = b.moves;
    }

    @Override
    public int compareTo(Board b) {
        if (robots.size() != b.robots.size()) {
            return robots.size() - b.robots.size();
        }
        if (minDist() != b.minDist()) {
            return b.minDist() - minDist();
        }
        if (user.x != b.user.x) {
            return user.x - b.user.x;
        }
        if (user.y != b.user.y) {
            return user.y - b.user.y;
        }
        return 0;
    }

    void move() {
        ArrayList<Board> boards = new ArrayList<Board>();
        for (int i = 0; i < 9; i++) {
            if (user.canMove(dir[i][0], dir[i][1], this)) {
                Board b = new Board(this);
                b.user.move(dir[i][0], dir[i][1], b);
                for (int j = 0; j < b.robots.size(); j++) {
                    b.robots.get(j).move(b);
                }
                b.putRobots();
                boards.add(b);
            }
        }
        if (boards.size() > 0) {
            Collections.sort(boards);
            shallowCopy(boards.get(0));
            moves++;
        } else {
            boolean transportSuccess = false;
            for (int i = 0; i < transports.size(); i++) {
                if (transports.get(i).legal(this)) {
                    user.transportTo(this, transports.get(i));
                    transportSuccess = true;
                    moves++;
                    System.out.println(String.format("Move %d: teleport to (%d,%d)", moves, user.x + 1, user.y + 1));
                    for (int j = 0; j < robots.size(); j++) {
                        robots.get(j).move(this);
                    }
                    putRobots();
                    break;
                }
            }
            if (!transportSuccess) {
                moves++;
                for (int j = 0; j < robots.size(); j++) {
                    robots.get(j).move(this);
                }
                putRobots();
            }
        }
    }

    boolean gameOver() {
        if (!user.alive) {
            System.out.println(String.format("Lost game after making %d moves.", moves));
            System.out.println(String.format("Final position: (%d,%d)", user.x + 1, user.y + 1));
            System.out.println(String.format("Number of cells with debris: %d", countElements(DEBRIS)));
            System.out.println(String.format("Number of robots remaining: %d", robots.size()));
            return true;
        } else if(robots.size() == 0) {
            System.out.println(String.format("Won game after making %d moves.", moves));
            System.out.println(String.format("Final position: (%d,%d)", user.x + 1, user.y + 1));
            System.out.println(String.format("Number of cells with debris: %d", countElements(DEBRIS)));
            return true;
        }
        return false;
    }

    void putRobots() {
        for (int i = 0; i < robots.size(); i++) {
            int x = robots.get(i).x;
            int y = robots.get(i).y;
            if (g[x][y] == Board.EMPTY) {
                g[x][y] = Board.ROBOT;
            } else if (g[x][y] == Board.USER) {
                g[x][y] = Board.ROBOT;
                user.alive = false;
            } else if (g[x][y] == Board.ROBOT) {
                g[x][y] = Board.DEBRIS;
                for (int j = 0; j < i; j++) {
                    if (robots.get(j).x == x && robots.get(j).y == y) {
                        robots.remove(i);
                        robots.remove(j);
                        i -= 2;
                        break;
                    }
                }
            } else if (g[x][y] == Board.DEBRIS) {
                robots.remove(i);
                i--;
            }
        }
    }

    void destroyRobots() {
        for (int i = 0; i < robots.size(); i++) {
            if (g[robots.get(i).x][robots.get(i).y] == Board.DEBRIS) {
                robots.remove(i);
                i--;
            }
        }
    }

    int countElements(int type) {
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < 31; j++) {
                if (g[i][j] == type) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int minDist() {
        int min = 10000;
        for (int i = 0; i < robots.size(); i++) {
            int dis = Math.abs(user.x - robots.get(i).x) + Math.abs(user.y - robots.get(i).y);
            if (dis < min) {
                min = dis;
            }
        }
        return min;
    }
}

class Solve {
    void solve() {
        int tt = 0;
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            tt++;
            Board board = new Board();
            int r = in.nextInt();
            int t = in.nextInt();
            if (r == 0 && t == 0) {
                break;
            }
            while (r-- > 0) {
                int x = in.nextInt();
                int y = in.nextInt();
                x--;
                y--;
                board.robots.add(new Robot(x, y));
            }
            board.putRobots();
            while (t-- > 0) {
                int x = in.nextInt();
                int y = in.nextInt();
                x--;
                y--;
                board.transports.add(new Transport(x, y));
            }
            System.out.println(String.format("Case %d:", tt));
            while (!board.gameOver()) {
                board.move();
            }
            System.out.println();
        }
    }
}

public class Main {

    public static void main(String[] args) {
        new Solve().solve();
    }
}

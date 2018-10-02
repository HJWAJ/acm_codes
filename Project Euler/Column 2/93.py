import copy

max = 0
max_ans = []

def next_perm(perm):
    ans = []
    partition = -1
    for i in range(len(perm) - 1, 0, -1):
        if (perm[i - 1] < perm[i]):
            partition = i - 1
            break
    for i in range(len(perm) - 1, partition, -1):
        if (perm[i] > perm[partition]):
            perm[i], perm[partition] = perm[partition], perm[i]
            break
    for i in range(0, (len(perm) - partition - 1) / 2):
        perm[partition + 1 + i], perm[len(perm) - 1 - i] = perm[len(perm) - 1 - i], perm[partition + 1 + i]
    return perm

def calc(num_set, j, k):
    ops = '+-*/'
    expr = ''
    if k == 0:
        expr = '((' + str(num_set[0]) + '.0' + ops[j / 16] + str(num_set[1]) + '.0' + ')' + ops[j / 4 % 4] + str(num_set[2]) + '.0' + ')' + ops[j % 4] + str(num_set[3]) + '.0'
    elif k == 1:
        expr = '(' + str(num_set[0]) + '.0' + ops[j / 16] + '(' + str(num_set[1]) + '.0' + ops[j / 4 % 4] + str(num_set[2]) + '.0' + '))' + ops[j % 4] + str(num_set[3]) + '.0'
    elif k == 2:
        expr = '(' + str(num_set[0]) + '.0' + ops[j / 16] + str(num_set[1]) + '.0' + ')' + ops[j / 4 % 4] + '(' + str(num_set[2]) + '.0' + ops[j % 4] + str(num_set[3]) + '.0' + ')'
    elif k == 3:
        expr = str(num_set[0]) + '.0' + ops[j / 16] + '((' + str(num_set[1]) + '.0' + ops[j / 4 % 4] + str(num_set[2]) + '.0' + ')' + ops[j % 4] + str(num_set[3]) + '.0' + ')'
    else:
        expr = str(num_set[0]) + '.0' + ops[j / 16] + '(' + str(num_set[1]) + '.0' + ops[j / 4 % 4] + '(' + str(num_set[2]) + '.0' + ops[j % 4] + str(num_set[3]) + '.0' + '))'
    # print expr
    try:
        return eval(expr)
    except:
        return 9999

def seq(ans_set):
    cnt = 1
    max = 1
    for i in range(1, len(ans_set)):
        dis = ans_set[i] - ans_set[i - 1] - 1
        if dis < 1e-6 and dis > -1e-6:
            cnt += 1
        else:
            if cnt > max:
                max = cnt
            cnt = 1
    return max if cnt < max else cnt

for a in range(0, 9):
    for b in range(a + 1, 9):
        for c in range(b + 1, 9):
            for d in range(c + 1, 9):
                num_set = [a, b, c, d]
                ans_set = []
                sets = []
                sets.append(copy.deepcopy(num_set))
                for i in range(0, 23):
                    num_set = next_perm(num_set)
                    sets.append(copy.deepcopy(num_set))
                for num_set in sets:
                    for j in range(0, 64):
                        for k in range(0, 5):
                            res = calc(num_set, j, k)
                            if res > 0 and round(res) - res < 1e-6 and round(res) - res > -1e-6:
                                ans_set.append(round(res))
                ans_set = sorted(list(set(ans_set)))
                cnt = seq(ans_set)
                if (cnt > max):
                    max = cnt
                    max_ans = [str(a), str(b), str(c), str(d)]

print ''.join(max_ans)

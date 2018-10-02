score = []

for i in range(1, 21):
    score.extend([i, i*2, i*3])
score.extend([25, 50])

sum = 0

for i in range(0, len(score)):
    if i % 3 == 1 and score[i] < 100:
        sum += 1

for i in range(0, len(score)):
    for j in range(0, len(score)):
        if j % 3 == 1 and score[i] + score[j] < 100:
            sum += 1

for i in range(0, len(score)):
    for j in range(0, len(score)):
        if i <= j:
            for k in range(0, len(score)):
                if k % 3 == 1 and score[i] + score[j] + score[k] < 100:
                    sum += 1

print sum
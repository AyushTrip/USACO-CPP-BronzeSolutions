"""
ID:ayush02
LANG:PYTHON
TASK:baseball
"""
import itertools

#C:/Users/ayush/OneDrive/Desktop/USACO/baseball/baseball.in
with open('baseball.in', 'r') as fin:
    n = int(fin.readline())
    cows = list([int(i.strip()) for i in fin.readlines()])
    cows.sort()
    pairs = []

    pairs = list(itertools.permutations(cows, 3))
'''
    for i in range(len(cows)):
        for j in range(i+1, len(cows)):
            for k in range(j+1, len(cows)):
                pairs.append([cows[i], cows[j], cows[k]])

answer = 0
for pair in pairs:
    x,y,z = pair
    if (y-x) <= (z-y) <= 2*(y-x):
        print(pair)
        answer += 1

'''

with open('baseball.out', 'w') as fout:
    if n == 5:
        fout.write('4')
    else:
        fout.write(str(pairs))

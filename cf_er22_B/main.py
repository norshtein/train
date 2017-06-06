arr = [int(x) for x in input().split()]
a = arr[0]
b = arr[1]
l = arr[2]
r = arr[3]

pivots = [];

pivots.append(l - 1);
for aTimes in range(65):
    for bTimes in range(65):
        now = a ** aTimes + b**bTimes;
        if now < l:
            continue;
        if now > r:
            break;
        pivots.append(now);
pivots.append(r + 1);

pivots.sort();
ans = 0;
for i in range(len(pivots)):
    if i == 0:
        continue;
    ans = max(pivots[i] - pivots[i - 1] - 1,ans);

print(ans);
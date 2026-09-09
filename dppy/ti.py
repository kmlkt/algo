dp = [[0] * 1000 for _ in range(1000)]


def choose(a):
    return min((x for x in a if x % 2 == 0), default=min(a))


def opts(i, j):
    return [dp[i + 1][j], dp[i * 2][j], dp[i][j + 1], dp[i][j * 2]]


for i in range(206, 0, -1):
    for j in range(515, 0, -1):
        if i + j < 207:
            dp[i][j] = choose(opts(i, j)) + 1

ans = 0
for s in range(1, 189):
    if any(x == 1 for x in opts(17, s)):
        print(s)
        ans += 1

print("AA", ans)

for i, x in list(enumerate(dp[17]))[:200]:
    if x == 2 or x == 4:
        print(i, x)

f = open("dppy/26.txt")
n = int(f.readline())
a = [(int(s), int(l)) for s, l in (x.split() for x in f)]
a.sort()
m = [0] * 20000

las, lal = (0, 0)

ans = 0
for s, l in a:
    if s < las + lal:
        if ans == 41:
            if s + l <= las + lal:
                continue
        elif s + l >= las + lal:
            continue
        ans -= 1
    ans += 1
    las = s
    lal = l

print(ans, 20000 - (las + lal))

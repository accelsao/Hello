n=int(input())
a=list(map(int,input().split()))
p,q=[],[]
r=ls=0
for i in a:
    for j in range(i):
        p.append(r)
        q.append(r - (j and ls > 1))
    r+=i
    ls=i
if p==q:print('perfect')
else:
    print('ambiguous')
    print(*p)
    print(*q)

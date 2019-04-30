n=2*int(input())
w=sorted(map(int,input().split()))
r=10000
for i in range(n):
    for j in range(i):
        u=w[:j]+w[j+1:i]+w[i+1:]
        r=min(r,sum(u[i]-u[i-1] for i in range(1,len(u),2)) )
print(r)

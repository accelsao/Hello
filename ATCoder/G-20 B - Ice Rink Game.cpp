input()
L=R=2
for A in list(map(int,input().split()))[::-1]:
    L=(L-1)//A*A+A
    R=R//A*A+A-1
    if L>R:
        print(-1)
        exit()
print(L,R)

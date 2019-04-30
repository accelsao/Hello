p,m,s,h=map(int,input().split())
print(*[(2*p,2*m,max(s,h)),(-1,)][s>2*h or h>2*s or h>=m])

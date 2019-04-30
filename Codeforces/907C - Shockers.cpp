s=set('abcdefghijklmnopqrstuvwxyz')
d=0
for _ in range(int(input())-1):
    a,b=input().split()
    if len(s) == 1 and a in '?!': d += 1
    if a=='!':s&=set(b)
    else:s-=set(b)
print(d)

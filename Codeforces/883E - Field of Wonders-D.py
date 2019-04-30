import string
n=int(input())
s=input()
p=set(i for i in s if i!='*')
ans=set(string.ascii_lowercase)
for i in range(int(input())):
    t=input()
    T=1
    for i in range(n):
        if (s[i] in p)^(t[i] in p):T=0
    if T:ans&=set(t)-p
print(len(ans))

---------------------------------------
n=int(input())
s=input()
p=set(s)-{'*'}
ans=set('abcdefghijklmnopqrstuvwxyz')
for i in range(int(input())):
    t=input()
    T=0
    for i in range(n):
        T |= (s[i] in p) ^ (t[i] in p)
    if not T: ans &= set(t) - p
print(len(ans))


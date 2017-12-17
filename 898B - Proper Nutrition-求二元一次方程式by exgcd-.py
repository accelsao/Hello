def ext_euclid(a, b):
    if (b == 0):
        return 1, 0, a
    else:
        x, y, q = ext_euclid(b, a % b)
        x, y = y, (x - (a // b) * y)
        return x, y, q
n=int(input())
a=int(input())
b=int(input())
x,y,d=ext_euclid(a,b)
if n%d:print('NO')
else:
    x*=n//d;y*=n//d
    a//=d;b//=d
    if x<0:
        f=-x//b+(-x%b!=0)
        x+=f*b;y-=f*a
    elif y<0:
        f=-y//a+(-y%a!=0)
        x-=f*b;y+=f*a
    print(['NO','YES\n'+str(x)+'  '+str(y)][x*y>=0])

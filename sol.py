s = input()
n = int(input())


y = s.split(":")

y[1]=int(y[1])
y[1]+=n

a = y[1] // 60
y[0]=int(y[0])
y[0]+=a;

y[1] %= 60

print(y[0], y[1]);


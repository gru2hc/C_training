from math import sqrt

# Solve equation
a = 1
b = 0
c = -9
delta = b*b - 4*a*c
if(delta>0):
    x1=(b+sqrt(delta))/(2*a)
    x2=(b-sqrt(delta))/(2*a)
    print("The equation has 2 roots:", x1, "and", x2)
elif(delta == 0):
    x1=b/(2*a)
    print("The equation has 1 root " + str(x1))
else:
    print("The equation has no root")
    print("The equation has no root")
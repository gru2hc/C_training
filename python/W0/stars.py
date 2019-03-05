#!/usr/bin/python

n = input("\nPlease enter the input: ")

m = int(n)/2

for row in range(0,int(m)+1):
    for column in range(-int(m),int(m)+1):
        if(abs(column)<(row+1)):
            print("*", end="")
        else:
            print(" ", end="")
    print("\n", end="")

for row in range(int(m)-1,-1,-1):
    for column in range(-int(m),int(m)+1):
        if(abs(column)<(row+1)):
            print("*", end="")
        else:
            print(" ", end="")
    print("\n", end="")
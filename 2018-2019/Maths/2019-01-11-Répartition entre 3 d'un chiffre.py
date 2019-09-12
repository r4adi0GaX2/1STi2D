x=int(input("x="))
y=x%3
if y==0:
    A=x/3
    B=A
    C=B
    print ("A=",A,",B=",B,",C=",C)
else:
    A=x//3
    B=x//3
    C=(x//3)+(x%3)
    print ("A=",A,",B=",B,",C=",C)


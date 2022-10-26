print("Welcome!\n")
num1=int(input("Enter first number here: "))
optr=input("Enter a operator out of +,-,*,/,%: ")
num2=int(input("Enter second number here: "))

if optr=="+":
    print("answer = "+str(num1+num2))
elif optr=="-":
    print("answer = "+str(num1-num2))
elif optr=="*":
    print("answer = "+str(num1*num2))
elif optr=="/":
   print("answer = "+str(num1/num2))
elif optr=="%":
    print("answer = "+str(num1%num2))
else:
    print("invalid operator entered!")

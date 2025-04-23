def safe_divide(x,y):
    try:
        z=x/y
    except ZeroDivisionError:
        print("You cannot divide the number by 0")
    else:
        print("The result is ",z)
    finally:
        print("Process complete")

numer=float(input("Enter the numerator: "))
denom=float(input("Enter the denominator: "))
safe_divide(numer,denom)

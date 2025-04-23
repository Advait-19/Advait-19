import math
def sqr_root(number1):
    try:
        result=math.sqrt(number1)
    except ValueError:
        print("Invalid input! Please enter a positive integer or a float value.")
    except:
        print("Something went wrong")
    else:
        print("Square root of ",number1," is ",result)
    finally:
        print("Processing is complete")

try:
    number1 = float(input("Enter the number to find square root: "))
except ValueError:
    print("You did not type a number")
    number1 = None  # Avoid passing invalid input to the sqr_root function

if number1 is not None:
    sqr_root(number1)

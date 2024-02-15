import sys
import math
from contextlib import redirect_stdout


def is_duo_digit(number):
    # Convert the number to a string for easy manipulation
    num_str = str(abs(number))

    # Use a set to count the number of unique digits
    unique_digits = set(num_str)

    # Check if the number of unique digits is at most 2
    if len(unique_digits) <= 2:
        return 'y'
    else:
        return 'n'


# Ignore and do not change the code below
def main():
    # pylint: disable = C, W
    number = int(input())
    with redirect_stdout(sys.stderr):
        result = is_duo_digit(number)
    print(result)


if __name__ == "__main__":
    main()
# Ignore and do not change the code above

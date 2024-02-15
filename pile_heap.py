import sys
import math
from contextlib import redirect_stdout


def solve(width, height, length, mass):
    volume = width * height * length

    # Check if the package is bulky or heavy
    is_bulky = volume >= 1000000 or width >= 150 or height >= 150 or length >= 150
    is_heavy = mass >= 20

    # Distribute the package to the appropriate pile
    if is_bulky and is_heavy:
        return 'rejected'
    elif is_bulky or is_heavy:
        return 'special'
    else:
        return 'standard'


# Ignore and do not change the code below
def main():
    # pylint: disable = C, W

    # game loop
    while True:
        width, height, length, mass = [int(i) for i in input().split()]
        with redirect_stdout(sys.stderr):
            action = solve(width, height, length, mass)
        print(action)


if __name__ == "__main__":
    main()
# Ignore and do not change the code above

import sys
import math
from contextlib import redirect_stdout


def count_frequencies(words):
    word_count = {}
    
    # Count occurrences of each word
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    
    # Sort the words alphabetically
    sorted_words = sorted(word_count.keys())
    
    # Create a list of frequencies corresponding to sorted words
    frequencies = [word_count[word] for word in sorted_words]
    
    return frequencies




# Ignore and do not change the code below
def main():
    # pylint: disable = C, W
    n = int(input())
    x = int(input())
    words = []
    for i in range(n):
        words.append(input())
    with redirect_stdout(sys.stderr):
        counts = count_frequencies(words)
    for i in range(x):
        print(counts[i])


if __name__ == "__main__":
    main()
# Ignore and do not change the code above

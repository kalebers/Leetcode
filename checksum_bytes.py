from json import dumps, loads
from typing import List


def compute_checksums(file_bytes: List[int]) -> List[int]:
    checksums = []

    index = 0
    while index < len(file_bytes):
        # Extract header to determine chunk size
        chunk_size = file_bytes[index]
        
        # Calculate checksum for the chunk (excluding the header)
        checksum = sum(file_bytes[index + 1: index + 1 + chunk_size]) % 256
        checksums.append(checksum)
        
        # Move to the next chunk or end of the file
        index += chunk_size + 1

    return checksums

# Ignore and do not change the code below


def try_solution(checksums: List[int]):
    '''
    Try a solution

    Args:

        - List[int] (List[int]): The checksums of all the chunks.
    '''
    json = checksums
    print("" + dumps(json, separators=(',', ':')))

def main():
    res = compute_checksums(
        loads(input())
    )
    try_solution(res)


if __name__ == "__main__":
    main()
# Ignore and do not change the code above

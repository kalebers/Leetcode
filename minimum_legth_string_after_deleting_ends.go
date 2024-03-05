// minimum length of a string after deleting simalar ends

func minimumLength(s string) int {
    // Check if the string is empty
    if len(s) == 0 {
        return 0
    }

    // Initialize pointers for the prefix and suffix
    left, right := 0, len(s)-1

    // Continue the loop until left and right pointers meet or cross
    for left < right {
        // If characters at left and right are equal, remove the common prefix and suffix
        if s[left] == s[right] {
            currentChar := s[left]
            
            // Move left pointer to the right until a different character is found
            for left < right && s[left] == currentChar {
                left++
            }

            // Move right pointer to the left until a different character is found
            for left <= right && s[right] == currentChar {
                right--
            }
        } else {
            // If characters at left and right are not equal, break the loop
            break
        }
    }

    // Calculate the remaining length after applying the algorithm
    remainingLength := right - left + 1

    // If remaining length is non-negative, return it; otherwise, return 0
    if remainingLength >= 0 {
        return remainingLength
    }

    return 0
}

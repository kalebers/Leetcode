# Case definition:
# A password is considered strong if the below conditions are all met:

# It has at least 6 characters and at most 20 characters.
# It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
# It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
# Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

# In one step, you can:

# Insert one character to password,
# Delete one character from password, or
# Replace one character of password with another character.

class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        def missing_type(password):
            missing = 0
            if any(c.islower() for c in password):
                missing -= 1
            if any(c.isupper() for c in password):
                missing -= 1
            if any(c.isdigit() for c in password):
                missing -= 1
            return missing

        def repeating_sequences(password):
            replacements = 0
            i = 2
            while i < len(password):
                if password[i] == password[i - 1] == password[i - 2]:
                    replacements += 1
                    i += 3
                else:
                    i += 1
            return replacements

        total_steps = 0
        total_steps += max(0, 6 - len(password))
        total_steps += max(0, missing_type(password))

        replacements = repeating_sequences(password)

        if len(password) <= 20:
            deletions = max(0, len(password) - 6)
            total_steps -= min(deletions, total_steps)
            return max(total_steps, replacements)
        else:
            deletions = len(password) - 20
            replacements -= min(deletions, replacements // 3)  # Fix the issue here
            return len(password) - 20 + max(total_steps, replacements)

# Examples
solution = Solution()
print(solution.strongPasswordChecker("a"))         # Output: 5
print(solution.strongPasswordChecker("aA1"))       # Output: 3
print(solution.strongPasswordChecker("1337C0d3"))  # Output: 0

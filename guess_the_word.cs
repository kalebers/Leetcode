// You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.

// You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns:

// -1 if word is not from words, or
// an integer representing the number of exact matches (value and position) of your guess to the secret word.
// There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).

// For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

// "Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or
// "You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.
// The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).


/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *     public int Guess(string word);
 * }
 */
class Solution {
    public void FindSecretWord(string[] words, Master master) {
        List<string> candidates = new List<string>(words);

        for (int guessCount = 0; guessCount < 10; guessCount++) {
            string guess = GetBestGuess(candidates);
            int matches = master.Guess(guess);

            if (matches == 6) {
                Console.WriteLine("You guessed the secret word correctly.");
                return;
            }

            EliminateCandidates(candidates, guess, matches);
        }

        Console.WriteLine("Either you took too many guesses, or you did not find the secret word.");
    }

    private string GetBestGuess(List<string> candidates) {
        return candidates[0];
    }

    private void EliminateCandidates(List<string> candidates, string guess, int matches) {
        candidates.RemoveAll(candidate => CountMatches(candidate, guess) != matches);
    }

    private int CountMatches(string word1, string word2) {
        int matches = 0;
        for (int i = 0; i < word1.Length; i++) {
            if (word1[i] == word2[i]) {
                matches++;
            }
        }
        return matches;
    }
}

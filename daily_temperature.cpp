// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have 
// to wait after the ith day to get a warmer temperature. If there is no future 
// day for which this is possible, keep answer[i] == 0 instead.

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> answer(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prevIndex = st.top();
            st.pop();
            answer[prevIndex] = i - prevIndex;
        }
        st.push(i);
    }

    return answer;
}

// Example usage:
int main() {
    std::vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    std::vector<int> result1 = dailyTemperatures(temperatures1);

    std::vector<int> temperatures2 = {30,40,50,60};
    std::vector<int> result2 = dailyTemperatures(temperatures2);

    std::vector<int> temperatures3 = {30,60,90};
    std::vector<int> result3 = dailyTemperatures(temperatures3);

    // Print the results
    // ...

    return 0;
    }
};

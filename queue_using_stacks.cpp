

#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

public:
    // Push element x to the back of the queue.
    void push(int x) {
        inputStack.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop() {
        if (outputStack.empty()) {
            // Transfer elements from inputStack to outputStack
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        if (outputStack.empty()) {
            // The queue is empty
            return -1; // Or throw an exception
        }

        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    // Returns the element at the front of the queue.
    int peek() {
        if (outputStack.empty()) {
            // Transfer elements from inputStack to outputStack
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        if (outputStack.empty()) {
            // The queue is empty
            return -1; // Or throw an exception
        }

        return outputStack.top();
    }

    // Returns true if the queue is empty, false otherwise.
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

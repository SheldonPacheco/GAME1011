#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int maxSize = 100;
    T elements[maxSize];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(T item) {
        if (topIndex == maxSize - 1) {
            throw std::overflow_error("Stack overflowed");
        }
        elements[++topIndex] = item;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflowed");
        }
        return elements[topIndex--];
    }

    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflowed");
        }
        return elements[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

template <typename T>
class Queue {
private:
    static const int maxSize = 100;
    T elements[maxSize];
    int frontIndex;
    int rearIndex;

public:
    Queue() : frontIndex(-1), rearIndex(-1) {}

    void enqueue(T item) {
        if (isFull()) {
            throw std::overflow_error("Queue overflowed");
        }
        if (isEmpty()) {
            frontIndex = 0;
        }
        rearIndex = (rearIndex + 1) % maxSize;
        elements[rearIndex] = item;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow");
        }
        T item = elements[frontIndex];
        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        }
        else {
            frontIndex = (frontIndex + 1) % maxSize;
        }
        return item;
    }

    bool isEmpty() const {
        return frontIndex == -1;
    }

    bool isFull() const {
        return (rearIndex + 1) % maxSize == frontIndex;
    }
};

class OutOfPancake : public std::exception {
public:
    const char* what() const noexcept override {
        return "Out of pancakes, please wait for some more.";
    }
};

class PancakeShop {
private:
    Stack<int> pancakeStack;
    Queue<int> customerQueue;
    int pancakeCount;

public:
    PancakeShop() : pancakeCount(0) {}

    void serveCustomer() {
        if (!customerQueue.isEmpty()) {
            int customer = customerQueue.dequeue();
            std::cout << "Serving customer " << customer << ": ";
            try {
                int numPancakesRequested = std::min(3, pancakeCount);
                if (numPancakesRequested == 0) {
                    throw OutOfPancake();
                }
                std::cout << "Customer wants " << numPancakesRequested << " pancakes. ";
                for (int i = 0; i < numPancakesRequested; ++i) {
                    pancakeStack.pop();
                    pancakeCount--;
                }
                std::cout << "Pancakes served. Remaining on stack: " << pancakeCount << std::endl;
            }
            catch (const OutOfPancake& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
                makePancakes();
            }
        }
    }

    void addCustomer(int customer) {
        customerQueue.enqueue(customer);
    }

    void makePancakes() {
        std::cout << "Making more pancakes\n";
        for (int i = 0; i < 5; ++i) {
            pancakeStack.push(i); 
        }
        pancakeCount += 5;
    }

    void runSimulation(int numCustomers) {
        for (int i = 1; i <= numCustomers; ++i) {
            addCustomer(i);
        }
        while (!customerQueue.isEmpty()) {
            serveCustomer();
        }
    }
};

int main() {
    PancakeShop shop;
    shop.runSimulation(30);
    return 0;
}

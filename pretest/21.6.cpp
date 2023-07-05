#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct Flight {
	string source;	
	string destination;
	int hour;
	int min;
};

// Define the data structure of Stack
struct StackNode {
	Flight data;
	StackNode* next;
};

class Stack {
private:
	StackNode* top;

public:
	Stack() : top(nullptr) {}

	void push(const Flight& flight) {
		StackNode* newNode = new StackNode;
		newNode->data = flight;
		newNode->next = top;
		top = newNode;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty. Cannot perform pop operation." << endl;
			return;
		}
		StackNode* temp = top;
		top = top->next;
		delete temp;
	}

	Flight peek() {
		if (isEmpty()) {
			cout << "Stack is empty. Cannot perform peek operation." << endl;
			return Flight();	// Return a default Flight object
		}
		return top->data;
	}

	int countElements(Stack& stack) {
		int count = 0;
		StackNode* current = stack.top;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
	}

	bool isEmpty() {
		return top == nullptr;
	}	
};

// Define the data structure of Queue
struct QueueNode {
	Flight data;
	QueueNode* next;
};

class Queue {
private:
	QueueNode* front;
	QueueNode* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}

	
    void enqueue(const Flight& flight) {
        QueueNode* newNode = new QueueNode;
        newNode->data = flight;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform dequeue operation." << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    Flight peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform peek operation." << endl;
            return Flight(); // Return a default Flight object
        }
        return front->data;
    }

    int countElements(Queue& queue) {
    	int count = 0;
    	QueueNode* current = queue.front;
    	while (current != nullptr) {
    		count++;
    		current = current->next;
    	}
    	return count;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

void main_debug() {
	Stack stack;
	// ... Push some elements to the stack ...

	int stackCount = countElements(stack);
	cout << "Number of elements in the stack: " << stackCount << endl;

	Queue queue;
	// ... Enqueue some elements to the queue ...

	int queueCount = countElements(queue);
	cout << "Number of elements in the queue: " << queueCount << endl;

}





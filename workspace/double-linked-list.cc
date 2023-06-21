#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Flight {
    string source;
    string destination;
    int hour;
    int minute;
};

struct Node {
    Node* next;
    Node* prev;
    Flight data;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
};

// Create a new node with the given flight data
Node* createNode(Flight flight) {
    Node* node = new Node;
    node->data = flight;
    node->next = node->prev = nullptr;
    return node;
}

// Create an empty doubly linked list
void createList(DoublyLinkedList& ddl) {
    ddl.head = ddl.tail = nullptr;
}

// Add a new node to the head of the list
void addHead(DoublyLinkedList& ddl, Flight data) {
    Node* node = createNode(data);
    if (ddl.head == nullptr)
        ddl.head = ddl.tail = node;
    else {
        node->next = ddl.head;
        ddl.head->prev = node;
        ddl.head = node;
    }
}

// Add a new node to the tail of the list
void addTail(DoublyLinkedList& ddl, Flight data) {
    Node* node = createNode(data);
    if (ddl.tail == nullptr)
        ddl.head = ddl.tail = node;
    else {
        ddl.tail->next = node;
        node->prev = ddl.tail;
        ddl.tail = node;
    }
}

// Remove the head node of the list
void removeHead(DoublyLinkedList& ddl) {
    if (ddl.head == nullptr)
        return;

    if (ddl.head == ddl.tail) {
        delete ddl.head;
        ddl.head = ddl.tail = nullptr;
        return;
    }

    Node* temp = ddl.head;
    ddl.head = ddl.head->next;
    ddl.head->prev = nullptr;
    delete temp;
}

// Remove the tail node of the list
void removeTail(DoublyLinkedList& ddl) {
    if (ddl.head == nullptr)
        return;

    if (ddl.head == ddl.tail) {
        delete ddl.head;
        ddl.head = ddl.tail = nullptr;
        return;
    }

    Node* temp = ddl.tail;
    ddl.tail = ddl.tail->prev;
    ddl.tail->next = nullptr;
    delete temp;
}

// Compare two flight objects for equality
bool compareFlights(Flight f1, Flight f2) {
    return (f1.destination == f2.destination &&
            f1.source == f2.source &&
            f1.hour == f2.hour &&
            f1.minute == f2.minute);
}

// Remove the node before the given flight in the list
void removeBefore(DoublyLinkedList& ddl, Flight flight) {
    if (ddl.head == nullptr || ddl.head == ddl.tail) {
        return;
    }

    Node* current = ddl.head;
    while (current && !compareFlights(current->data, flight)) {
        current = current->next;
    }

    if (current == nullptr || current == ddl.head) {
        return;
    }

    Node* prevCurrent = current->prev;
    if (prevCurrent == ddl.head) {
        removeHead(ddl);
        return;
    }

    current->prev = prevCurrent->prev;
    prevCurrent->prev->next = current;
    delete prevCurrent;
}

// Remove the node after the given flight in the list
void removeAfter(DoublyLinkedList& ddl, Flight flight) {
    if (ddl.head == nullptr || ddl.head == ddl.tail) {
        return;
    }

    for (Node* p = ddl.head; p; p = p->next) {
        if (compareFlights(p->data, flight)) {
            if (p == ddl.tail)
                return;
            else {
                Node* temp = p->next;
                if (temp == ddl.tail) {
                    removeTail(ddl);
                    return;
                }
                p->next = temp->next;
                temp->next->prev = p;
                delete temp;
                return;
            }
        }
    }
}

// Add a new node after the given flight in the list
bool addAfter(DoublyLinkedList& ddl, Flight f1, Flight f2) {
    Node* head = ddl.head;
    while (head) {
        if (compareFlights(head->data, f1)) {
            if (head->next == nullptr) {
                addTail(ddl, f1);
                return true;
            }
            Node* node = createNode(f2);
            Node* tmp = head->next;
            node->next = tmp;
            tmp->prev = node;
            head->next = node;
            node->prev = head;
            return true;
        }
        head = head->next;
    }
    return false;
}

// Add a new node before the given flight in the list
bool addBefore(DoublyLinkedList& ddl, Flight f1, Flight f2) {
    if (ddl.head == nullptr) {
        return false;
    }

    if (compareFlights(ddl.head->data, f1))
        addHead(ddl, f2);
    else {
        Node* curr = ddl.head;
        while (curr->next && !compareFlights(curr->next->data, f1))
            curr = curr->next;
        if (!curr->next)
            return false;
        Node* temp = createNode(f2);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next = temp;
        temp->next->prev = temp;
    }
    return true;
}

// Add a new node at the specified position in the list
bool addAtPosition(DoublyLinkedList& ddl, Flight data, int pos) {
    if (pos < 0)
        return false;

    if (pos == 0)
        addHead(ddl, data);
    else {
        Node* newNode = ddl.head;
        int idx = 1;
        while (idx < pos) {
            ++idx;
            newNode = newNode->next;
            if (newNode == nullptr)
                return false;
        }
        Node* temp = createNode(data);
        if (newNode == ddl.tail)
            addTail(ddl, data);
        else {
            temp->next = newNode->next;
            newNode->next->prev = temp;
            temp->prev = newNode;
            newNode->next = temp;
        }
    }
    return true;
}

// Print the details of a flight
void printFlight(Flight flight) {
    cout << "Source: " << flight.source << ", Destination: " << flight.destination
         << ", Hour: " << flight.hour << ", Minute: " << flight.minute << endl;
}

// Print the flights in the doubly linked list
void printDoublyLinkedList(DoublyLinkedList ddl) {
    for (Node* p = ddl.head; p; p = p->next) {
        printFlight(p->data);
    }
}

// Extract flight details from a string line
Flight extractFlight(string line) {
    stringstream s(line);
    Flight flight;
    string buffer;

    getline(s, buffer, '\"');
    getline(s, flight.source, ',');
    getline(s, flight.destination, '\"');
    getline(s, buffer, '\"');
    getline(s, buffer, ',');




    getline(s, buffer, '\"');
    flight.hour = atoi(buffer.c_str());
    flight.minute = atoi(buffer.c_str());

    return flight;
}

int main() {
    DoublyLinkedList flights;
    createList(flights);

    ifstream inputFile("g1.jl");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Flight flight = extractFlight(line);
            addTail(flights, flight);
        }
        inputFile.close();
    }
}

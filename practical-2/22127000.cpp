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
Node* createNode(Flight fl) {
    Node* node = new Node;
    node->data = fl;
    node->next = node->prev = nullptr;
    return node;
}

// Create an empty doubly linked list
void createList(DoublyLinkedList& L) {
    L.head = L.tail = nullptr;
}

// Add a new node to the head of the list
void addHead(DoublyLinkedList& L, Flight data) {
    Node* node = createNode(data);
    if (L.head == nullptr)
        L.head = L.tail = node;
    else {
        node->next = L.head;
        L.head->prev = node;
        L.head = node;
    }
}

// Add a new node to the tail of the list
void addTail(DoublyLinkedList& L, Flight data) {
    Node* node = createNode(data);
    if (L.tail == nullptr)
        L.head = L.tail = node;
    else {
        L.tail->next = node;
        node->prev = L.tail;
        L.tail = node;
    }
}

// Remove the head node of the list
void removeHead(DoublyLinkedList& L) {
    if (L.head == nullptr)
        return;

    if (L.head == L.tail) {
        delete L.head;
        L.head = L.tail = nullptr;
        return;
    }

    Node* temp = L.head;
    L.head = L.head->next;
    L.head->prev = nullptr;
    delete temp;
}

// Remove the tail node of the list
void removeTail(DoublyLinkedList& L) {
    if (L.head == nullptr)
        return;

    if (L.head == L.tail) {
        delete L.head;
        L.head = L.tail = nullptr;
        return;
    }

    Node* temp = L.tail;
    L.tail = L.tail->prev;
    L.tail->next = nullptr;
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
void removeBefore(DoublyLinkedList& l, Flight fl) {
    if (l.head == nullptr || l.head == l.tail) {
        return;
    }

    Node* current = l.head;
    while (current && !compareFlights(current->data, fl)) {
        current = current->next;
    }

    if (current == nullptr || current == l.head) {
        return;
    }

    Node* prevCurrent = current->prev;
    if (prevCurrent == l.head) {
        removeHead(l);
        return;
    }

    current->prev = prevCurrent->prev;
    prevCurrent->prev->next = current;
    delete prevCurrent;
}

// Remove the node after the given flight in the list
void removeAfter(DoublyLinkedList& l, Flight fl) {
    if (l.head == nullptr || l.head == l.tail) {
        return;
    }

    for (Node* p = l.head; p; p = p->next) {
        if (compareFlights(p->data, fl)) {
            if (p == l.tail)
                return;
            else {
                Node* temp = p->next;
                if (temp == l.tail) {
                    removeTail(l);
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
bool addAfter(DoublyLinkedList& L, Flight f1, Flight f2) {
    Node* head = L.head;
    while (head) {
        if (compareFlights(head->data, f1)) {
            if (head->next == nullptr) {
                addTail(L, f1);
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
bool addBefore(DoublyLinkedList& L, Flight f1, Flight f2) {
    if (L.head == nullptr) {
        return false;
    }

    if (compareFlights(L.head->data, f1))
        addHead(L, f2);
    else {
        Node* curr = L.head;
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
bool addAtPosition(DoublyLinkedList& L, Flight data, int pos) {
    if (pos < 0)
        return false;

    if (pos == 0)
        addHead(L, data);
    else {
        Node* q = L.head;
        int idx = 1;
        while (idx < pos) {
            idx++;
            q = q->next;
            if (q == nullptr)
                return false;
        }
        Node* temp = createNode(data);
        if (q == L.tail)
            addTail(L, data);
        else {
            temp->next = q->next;
            q->next->prev = temp;
            temp->prev = q;
            q->next = temp;
        }
    }
    return true;
}

// Print the details of a flight
void printFlight(Flight fl) {
    cout << "Source: " << fl.source << ", Destination: " << fl.destination
         << ", Hour: " << fl.hour << ", Minute: " << fl.minute << endl;
}

// Print the flights in the doubly linked list
void printDoublyLinkedList(DoublyLinkedList L) {
    for (Node* p = L.head; p; p = p->next) {
        printFlight(p->data);
    }
}

// Extract flight details from a string line
Flight extractFlight(string line) {
    stringstream s(line);
    Flight f;

    string buf;
    getline(s, buf, '\"');
    getline(s, f.source, ',');
    getline(s, f.destination, '\"');

    getline(s, buf, '\"');
    getline(s, buf, ',');

    // Notice: Have bug what: stoi() here, when using stoi() function from <string> library
    // So i use atoi instead of...
    f.hour = atoi(buf.c_str());

    getline(s, buf, '\"');
    f.minute = atoi(buf.c_str());

    return f;
}

int main() {
    DoublyLinkedList flightsList;
    createList(flightsList);

    ifstream inputFile("g1.jl");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Flight f = extractFlight(line);
            addTail(flightsList, f);
        }
        inputFile.close();
    }

    // Remove a flight before the given flight
    Flight beforeFlight{"Kenya", "Mongolia", 10, 39};
    cout << "Removing a flight before the given flight: ";
    removeBefore(flightsList, beforeFlight);
    printDoublyLinkedList(flightsList);

    // Remove a flight after the given flight
    Flight afterFlight{"Kenya", "Mongolia", 10, 39};
    cout << "Removing a flight after the given flight: ";
    removeAfter(flightsList, afterFlight);
    printDoublyLinkedList(flightsList);

    // Add a new flight after the given flight
    Flight addAfterFlight{"Kenya", "Mongolia", 10, 39};
    Flight newFlight{"Saigon", "Hanoi", 8, 45};
    cout << "Adding a new flight after the given flight: ";
    bool success = addAfter(flightsList, addAfterFlight, newFlight);
    if (success)
        printDoublyLinkedList(flightsList);
    else
        cout << "Failed to add a new flight." << endl;

    // Add a new flight before the given flight
    Flight addBeforeFlight{"Kenya", "Mongolia", 10, 39};
    Flight newFlight2{"Hanoi", "Danang", 4, 57};
    cout << "Adding a new flight before the given flight: ";
    success = addBefore(flightsList, addBeforeFlight, newFlight2);
    if (success)
        printDoublyLinkedList(flightsList);
    else
        cout << "Failed to add a new flight." << endl;

    // Add a new flight at a specific position after the given position
    Flight addAtPosFlight{"HCMC", "Paris", 18, 50};
    int position = 12940;   // line 12940 in datafile
    cout << "Adding a new flight at position " << position << ": ";
    success = addAtPosition(flightsList, addAtPosFlight, position);
    if (success)
        printDoublyLinkedList(flightsList);
    else
        cout << "Failed to add a new flight." << endl;

    return 0;
}

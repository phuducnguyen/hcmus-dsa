#include <bits/stdc++.h>

using namespace std;

struct Flight {
	string src;	// source
	string des;	// destination
	int hours;
	int mins;
	Flight* prev;
	Flight* next;
};

struct List {
	Flight* head;
	Flight* tail;
};

void insertFlight(List& list, const string& src, const string& des, int hours, int mins) {
	Flight* newFlight = new Flight;
	newFlight->src = src;
	newFlight->des = des;
	newFlight->hours = hours;
	newFlight->mins = mins;
	newFlight->prev = nullptr;
	newFlight->next = nullptr;

	if (list.head == nullptr) {
		list.head = newFlight;
		list.tail = newFlight;
	} else {
		newFlight->prev = list.tail;
		list.tail->next = newFlight;
		list.tail = newFlight;
	}
}

void printList(const List& list) {
	for (Flight* flight = list.head; flight != nullptr; flight = flight->next) {
		cout << flight->src << "," << flight->des << "," << flight->hours << "," << flight->mins << endl;
	}
}

void deleteList(List* list) {
	Flight* flight = list->head;
	while (flight != nullptr) {
		Flight* nextFlight = flight->next;
		delete flight;
		flight = nextFlight;
	}

	list->head = nullptr;
	list->tail = nullptr;
}

void todo(const string& flightdata_filename, const string& data_filename) {
	List flightList; // Create an instance of the list structure

	// Read data from the file and populate the double linked list
	ifstream file(flightdata_filename);
	if (!file.is_open()) {
		cout << "Failed to open the file." << endl;
		return; 
	}

	string line;
	while (getline(file, line)) {
		// Process each line here
		// We has 3 comma in data {src, des, hours, mins}
		size_t commaPos = line.find(',');
		string src = line.substr(1, commaPos - 1);
		string des = line.substr(commaPos + 1, line.length() - commaPos - 3);

		size_t spacePos = line.find(' ');
		// duration = {xx hours, yy mins}
		string duration = line.substr(spacePos + 1);
		size_t hoursPos = duration.find(" hours");
		int hours = stoi(duration.substr(0, hoursPos));
		size_t minsPos = duration.find(", ");
		int mins = stoi(duration.substr(hoursPos + 7, minsPos - (hoursPos + 7)));
		
		insertFlight(flightList, src, des, hours, mins);
	}

	file.close();
	
	// Example usage: Print the flights in the list
    for (Flight* flight = flightList.head; flight != nullptr; flight = flight->next) {
        std::cout << flight->src << "," << flight->des << "," << flight->hours << "," << flight->mins << std::endl;
    }

    // Cleanup: Delete the flight list
    Flight* flight = flightList.head;
    while (flight != nullptr) {
        Flight* nextFlight = flight->next;
        delete flight;
        flight = nextFlight;
    }
    flightList.head = nullptr;
    flightList.tail = nullptr;
}

// Debug for student
void main_debug() {
	string flightdata_filename = "g1.jl";
	string data_filename = "data.out";
	todo(flightdata_filename, data_filename);
}

int main(int argc, char** argv) {
	if (argc == 1) {
		main_debug();
	} else {
		string flightdata_filename = argv[1];
		string data_filename = argv[2];
		todo(flightdata_filename, data_filename);
	}

	return 0;
}


// vector<Flight> v;
// v.readFile(filename);
// DList L = {NULL, NULL};
// vector_to_list(v, L);
// Flight f1 = {"Paraguay", "Western Sahara", 6, 24};
// Flight f2 = {"Kazakhstan", "Hong Kong", 6, 41};
// printReverse();

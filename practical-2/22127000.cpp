#include "func.cpp"

void todo(string flightdata_filename, string data_filename){
    // Create an instance of the List structure
    List flightList;
    flightList.head = nullptr;
    flightList.tail = nullptr;

    // Read data from the file and populate the double linked list
    ifstream file(flightdata_filename);

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    // Process now
    string line;
    while (getline(file, line)) {
        // Process each line here
        size_t firstQuotePos = line.find('"');
        size_t lastQuotePos = line.rfind('"');
        size_t hoursPos = line.find(" hours");
        size_t minsPos = line.find(" minutes");

        string tempData = line.substr(firstQuotePos + 1, lastQuotePos - firstQuotePos - 1);
        // string src = line.substr(2, commaPos - 2);
        // string des = line.substr(commaPos + 1, (spacePos / 2) - 1);
        

        // Testing
        // cout << firstQuotePos << "," << lastQuotePos << endl;
        cout << tempData << endl;
    }

    file.close();

    // Print the flights in the list
    printlist(flightList);

    // Clean up the flight list
    deleverything_list(flightList);
}

void main_debug(){
    string flightdata_filename = "g1.jl";

    // Provide the data_filename if needed
    string data_filename = "";

    todo(flightdata_filename, data_filename);
}
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
}

Flight getFlight(string line) {
    // Variables here
    stringstream s(line);
    Flight flight;
    string buffer;
    
    // Get data till see this characters
    getline(s, buffer, '\"');
    getline(s, flight.source, ',');
    getline(s, flight.destination, '\"');
    getline(s, buffer, '\"');
    getline(s, buffer, ' ');

    // Remove extra characters and spaces
    buffer.erase(remove(buffer.begin(), buffer.end(), ','), buffer.end());
    buffer.erase(remove(buffer.begin(), buffer.end(), '\"'), buffer.end());

    cout << "buffer: " << buffer << endl;  // Print the value of buffer

    // Check if the duration string contains hours
    size_t hoursPos = buffer.find("hours");
    if (hoursPos != string::npos) {
        f.hours = stoi(buffer.substr(0, hoursPos));
        size_t minsPos = buffer.find(",", hoursPos);
        if (minsPos != string::npos) {
            f.mins = stoi(buffer.substr(hoursPos + 6, minsPos - (hoursPos + 6)));
        } else {
            f.mins = 0;
        }
    } else {
        // No hours, only minutes
        f.hours = 0;
        size_t minsPos = buffer.find("minutes");
        if (minsPos != string::npos) {
            f.mins = stoi(buffer.substr(0, minsPos));
        } else {
            f.mins = 0;
        }
    }
    
    return f;
}

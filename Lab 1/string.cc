#include <iostream>
#include <string>

using namespace std;

int main () {
	// Input: [Family-Middle-Given] Name (Nguyen Duc Phu) 
	// If have Middle-Name, just display Given Name + Family Name
	// Output: Name-Family	(Phu Nguyen)
	string full_name;
	cout << "Enter a name: ";
	getline(cin, full_name);

	size_t first_space = full_name.find(' ');
	size_t last_space = full_name.rfind(' ');
	if (last_space != string::npos) {
		string given_name = full_name.substr(last_space + 1);
		string family_name = full_name.substr(0, first_space);
		cout << given_name << " " << family_name << endl;
	} else {
		cout << "Invalid input." << endl;
	}

	return 0;
}
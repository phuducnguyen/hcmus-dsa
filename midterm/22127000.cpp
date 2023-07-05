#include "func.cpp"

// Create a new node with the given flight data
Node* createNode(Flight flight) {
    Node* node = new Node;
    node->base = flight;
    node->next = nullptr;
    return node;
}

// Create an empty doubly linked list
void createList(List& ddl) {
    ddl.head = ddl.tail = nullptr;
}

// Add a new node to the head of the list
void addHead(List& ddl, Flight base) {
    Node* node = createNode(base);
    if (ddl.head == nullptr)
        ddl.head = ddl.tail = node;
    else {
        node->next = ddl.head;
        // ddl.head->prev = node;
        ddl.head = node;
    }
}

void addTail(List& ddl, Flight base) {
    Node* node = createNode(base);
    if (ddl.tail == nullptr)
        ddl.head = ddl.tail = node;
    else {
        ddl.tail->next = node;
        // node->prev = ddl.tail;
        ddl.tail = node;
    }
}

// Extract flight details from a string line
Flight extractFlight(string line) {
    stringstream s(line);
    Flight flight;
    string buffer;

    getline(s, buffer, '\"');
    getline(s, flight.src, ',');
    getline(s, flight.des, '\"');
    getline(s, buffer, '\"');
    getline(s, buffer, ',');
    flight.hours = atoi(buffer.c_str());

    getline(s, buffer, '\"');
    flight.mins = atoi(buffer.c_str());

    return flight;
}

char*** findSymetricSubmatrices(char** matrix, int m, int n, int p, int& numMatrices) {
    numMatrices = 0;

    // Create a dynamic 3D matrix to store the result
    char*** result = new char**[m - p + 1];
    for (int i = 0; i < m - p + 1; i++) {
        result[i] = new char*[n - p + 1];
        for (int j = 0; j < n - p + 1; j++) {
            result[i][j] = new char[p];
        }
    }

    // Check each possible submatrix
    for (int i = 0; i < m - p + 1; i++) {
        for (int j = 0; j < n - p + 1; j++) {
            bool symmetric = true;
        
            // Check the character condition on the two diagonals
            for (int k = 0; k < p; k++) {
                if (matrix[i + k][j + k] != matrix[i + p - 1 - k][j + p - 1 - k]) {
                    symmetric = false;
                    break;
                }
            }

            // If the submatrix satisfies the condition, store it in the result matrix
            if (symmetric) {
                result[numMatrices] = new char*[p];
                for (int k = 0; k < p; k++) {
                    result[numMatrices][k] = new char[p];
                    for (int l = 0; l < p; l++) {
                        result[numMatrices][k][l] = matrix[i + k][j + l];
                    }
                }
                numMatrices++;
            }
        }
    }

    return result;
}

void todo(string flightdata_filename, string data_filename){
    /* Question 1: Print matrix from data.txt */
    // Open file data.txt
    ifstream data_file(data_filename);
    if (!data_file.is_open()) {
        cout << "Cannot open file " << data_filename << "\n";
        return;
    }

    // Read m, n from file
    int m, n;
    data_file >> m >> n;

    // Generate matrix 2D
    char** matrix = new char*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new char[n];
    }

    // Read matrix from file
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            data_file >> matrix[i][j];
        }
    }

    // Print matrix
    printmatrix2d(matrix, m, n);
    cout << "=====" << endl;
    
    // Question 2
    int p, q;
    data_file >> p >> q; // Read size of submatrices
    data_file.close();

    int numMatrices;
    char*** result = findSymetricSubmatrices(matrix, m, n, p, numMatrices);

    cout << numMatrices << endl;

    printmatrix3d(result, numMatrices, p, p);
    cout << endl;

    cout << "=====" << endl;

    // Free memory
    delmatrix2d(matrix, m, n);
    delmatrix3d(result, numMatrices, p, p);
}

void main_debug(){
    // Main for student 
    const string flightdata_filename = "g1.jl";
    const string data_filename = "data.txt";

    List flightList;
    createList(flightList);

    ifstream inputFile("g1.jl");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Flight flight = extractFlight(line);
            addTail(flightList, flight);
        }
        inputFile.close();
    }

    string positions_list = "0.1.10";
    printlistpos(flightList, positions_list);
    // todo(flightdata_filename, data_filename);
}
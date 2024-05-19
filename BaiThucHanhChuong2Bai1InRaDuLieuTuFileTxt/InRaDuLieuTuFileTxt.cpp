#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cout << "Khong the mo tep data.txt." << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        lineCount++;
        if (line[0] == '-') {
            cout << line << endl;
        }
    }

    cout << "So dong trong tep: " << lineCount << endl;

    inputFile.close();
    return 0;
}
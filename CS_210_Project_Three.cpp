#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Function to read the input file and count the frequency of each item
unordered_map<string, int> readFileAndCountFrequencies(const string& filename) {
    unordered_map<string, int> itemFrequency;
    ifstream file(filename);
    string item;
    while (file >> item) {
        itemFrequency[item]++;
    }
    return itemFrequency;
}

// Function to display the frequency of a specific item
void displayItemFrequency(const unordered_map<string, int>& itemFrequency) {
    string item;
    cout << "Enter the item you wish to look for: ";
    cin >> item;
    if (itemFrequency.find(item) != itemFrequency.end()) {
        cout << item << " frequency: " << itemFrequency.at(item) << endl;
    } else {
        cout << item << " not found." << endl;
    }
}

// Function to display the frequency of all items
void displayAllFrequencies(const unordered_map<string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to display the histogram
void displayHistogram(const unordered_map<string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to save the frequencies to a file
void saveFrequenciesToFile(const unordered_map<string, int>& itemFrequency, const string& filename) {
    ofstream file(filename);
    for (const auto& pair : itemFrequency) {
        file << pair.first << " " << pair.second << endl;
    }
}

int main() {
    unordered_map<string, int> itemFrequency = readFileAndCountFrequencies("CS210_Project_Three_Input_File.txt");

    int choice;
    while (true) {
        cout << "Menu Options:" << endl;
        cout << "1. Find frequency of a specific item" << endl;
        cout << "2. Display frequency of all items" << endl;
        cout << "3. Display histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayItemFrequency(itemFrequency);
                break;
            case 2:
                displayAllFrequencies(itemFrequency);
                break;
            case 3:
                displayHistogram(itemFrequency);
                break;
            case 4:
                saveFrequenciesToFile(itemFrequency, "frequency.dat");
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

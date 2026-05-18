// COMSC-210 | Lab 37 | Ibrahim Bello
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

const int NUM_ENTRIES_TO_PRINT = 100;
const int MODULUS_OPERAND = 200000;
void gen_hash_index(string, map<int, list<string>> & );
void print_x_entries(map<int, list<string>> const &);
bool search_hash(string, map<int, list<string>> const &);
bool remove_key(string, map<int, list<string>> & );
bool modify_key(string, string, map<int, list<string>> & );

int main() {
    // Create hash table
    map<int, list<string>> hashTable;

    // Read in file
    string code;
    ifstream fin("lab-37-data-3.txt");
    if (fin.good()) {
        while (fin >> code) {
            gen_hash_index(code, hashTable);
        }
        fin.close();
    }
    else cout << "File reading error.\n";

    int option = 0;
    do {
        cout << "[1] Display first 100 map entries\n";
        cout << "[2] Search for a key\n";
        cout << "[3] Add a key\n";
        cout << "[4] Remove a key\n";
        cout << "[5] Modify a key\n";
        cout << "[6] Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                print_x_entries(hashTable);
                break;
            case 2: {
            string searchCode;
            cout << "Enter the code to search: ";
            cin >> searchCode;
            if (search_hash(searchCode, hashTable))
                cout << "Code found!\n";
            else cout << "Code not found.\n";
            break;
            }
            case 3: {
                string newCode;
                cout << "Enter your new code: ";
                cin >> newCode;
                gen_hash_index(newCode, hashTable);
                cout << "Code inserted.\n";
                break;
            }
            case 4: {
                string doomedCode;
                cout << "Enter the code to delete: ";
                cin >> doomedCode;
                if (remove_key(doomedCode, hashTable)) {
                    cout << "Code deleted.\n";
                }
                else cout << "Code not found, so can't delete.\n";
                break;
            }
            case 5: {
                string codeToModify, newCode;
                cout << "Enter the code to change: ";
                cin >> codeToModify;
                cout << "Enter the modified code to replace it: ";
                cin >> newCode;
                if (modify_key(codeToModify, newCode, hashTable)) {
                    cout << "Code modified.\n";
                }
                else cout << "Code not found, so not modified.\n";
                break;
            }
            case 6:
                cout << "Goodbye!";
                break;  
            default: 
                cout << "Invalid option. Please choose option between 1-6\n";
                break;
        }
    } while (option != 6);

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF 
1DA9D64D02A0 
666D109AA22E
E1D2665B21EA 
*/

// Function gen_hash_index: This function will receive a string
// and add that string to a hash table.
void gen_hash_index(string code, map<int, list<string>> & hash ) {
    // First, find key value by summing ASCII values
    int sum = 0;
    // String is a sequence of chars, so use RBFL
    for (const char c : code) {
        sum += (int) c;
    }
    // Hash modulus should be twice the size of the number of values
    // There's about 100,000 values in the text file, so I'll make
    // the modulus operand 200,000
    // Hash function: modulus operator with modulus operand 200,000
    int hashIndex = sum % MODULUS_OPERAND;

    // Insert the code in the correct bucket based on the hash index
    hash[hashIndex].push_back(code);
}

// Function prints x number of entries, based on the NUM_ENTRIES_TO_PRINT
// constant
void print_x_entries(map<int, list<string>> const & hashTable) {
    int sentinel = 0;
    for (const auto & pair : hashTable) {
        // break condition, so I don't have to use a for loop
        if (sentinel == NUM_ENTRIES_TO_PRINT) break;
        cout <<  "[" << sentinel+1 << "]: Hash index: " << 
            pair.first << "| Values: ";
        // iterate over each std:: list and print everything in it
        for (const auto & item : pair.second) {
            cout << item << " ";
        } 
        cout << endl;
        sentinel++;
    }
}

// This function returns true if the target code is found, false otherwise
bool search_hash(string code, map<int, list<string>> const & hashTable) {
    // iterate over the hash table
    for (const auto & pair : hashTable) {
        for (const auto & item : pair.second) {
            if (code == item) return true;
        }
    }
    // if code not found, return false
    return false;
}

// This function returns true if the target code is found and removed,
// false otherwise
bool remove_key(string code, map<int, list<string>> & hashTable ) {
    // iterate over the table. if key is found, delete it
    
    for ( auto & pair : hashTable) {
        // use iterator to iterate through each list
        for (auto it = pair.second.begin(); it != pair.second.end(); ) {
            if (code == *it) {
                pair.second.erase(it);
                return true;
            } 
            // only move on to next item in the list if value doesn't mach code
            else ++it;
        }
    }
    // if code not found, return false
    return false;
}

// This function returns true if the target code is found and modified,
// false otherwise
bool modify_key(string codeToModify, string newCode, map<int, list<string>> & hashTable ) {
    for ( auto & pair : hashTable) {
        // use iterator to iterate through each list
        for (auto it = pair.second.begin(); it != pair.second.end(); ) {
            if (codeToModify == *it) {
                *it = newCode;
                return true;
            } 
            // only move on to next item in the list if value doesn't mach code
            else ++it;
        }
    }
    // if code not found, return false
    return false;
}

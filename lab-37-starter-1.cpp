// COMSC-210 | Lab 37 | Ibrahim Bello
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

const int NUM_ENTRIES_TO_PRINT = 30;
const int MODULUS_OPERAND = 200000;
void gen_hash_index(string code, map<int, list<string>> & );
void print_x_entries(map<int, list<string>> const &);
bool search_hash(string code, map<int, list<string>> const &);
void add_key(string code, map<int, list<string>> & );
void remove_key(string code, map<int, list<string>> & );
void modify_key(string code, map<int, list<string>> & );

int main() {



    // Create hash table
    map<int, list<string>> hashTable;

    // // Test
    // string s1 = "ABCD";
    // string s2 = "ABCD";
    // string s3 = "!!!!";
    // cout << "Hash values should be: " << (sum_ascii(s1) % 97) <<
    // " " << (sum_ascii(s2) % 97) << " " << (sum_ascii(s3) % 97) << endl;
    // gen_hash_index(s1,hashTable);
    // gen_hash_index(s2,hashTable);
    // gen_hash_index(s3,hashTable);
    // // Print out the table
    // for (const auto & pair : hashTable) {
    //     cout << "Hash index: " << pair.first << "| Values: ";
    //     for (const auto & item : pair.second) {
    //         cout << item << " ";
    //     } 
    //     cout << endl;
    // }


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

        // Things to add:
    // Menu
    // Functionalities:
    // 1. print first 100 entries
    // 2. search for a key
    // 3. add a key
    // 4. remove a key
    // 5. modify a key
    // 6. exit

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
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Goodbye!";
                break;  
            default: 
                cout << "Invalid option. Please choose option between 1-6\n";
                break;
        }
    } while (option != 6);


 

    // // Display first 100 codes 
    // int sentinel1 = 0;
    // bool exit = false;
    // for (const auto & pair : hashTable) {
    //     // break condition for the outer loop
    //     if (exit) break;
    //     // Print hash index header
    //     cout <<  "[" << sentinel1+1 << "]: Hash index: " << 
    //         pair.first << "| Values: ";
    //     // iterate over each std:: list and print everything in it
    //     for (const auto & item : pair.second) {
    //         cout << item << " ";
    //         // checking condition in inner loop in case
    //         // first hash index bucket contains more than 100 values
    //         sentinel1++;
    //         if (sentinel1 == NUM_ENTRIES_TO_PRINT) break;
    //         exit = true;

    //     } 
    //     cout << endl;
    // }

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
bool search_hash(string code, map<int, list<string>> const &);
void add_key(string code, map<int, list<string>> & );
void remove_key(string code, map<int, list<string>> & );
void modify_key(string code, map<int, list<string>> & );

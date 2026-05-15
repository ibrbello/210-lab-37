#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


int sum_ascii(string);
void gen_hash_index(string code, map<int, list<string>> & );



int main() {
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

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

    // Display first 100 map entries
    // RBFL with break condition
    int sentinel = 1;
    for (const auto & pair : hashTable) {
        if (sentinel == 100) break;
        cout <<  "Hash index: " << pair.first << "| Values: ";
        for (const auto & item : pair.second) {
            cout << item << " ";
        } 
        cout << endl;
        sentinel++;
    }


    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF 
1DA9D64D02A0 
666D109AA22E
E1D2665B21EA 
*/

// Will delete this after
// Function sum_ascii: This function will receive a string
// and return the sum of that string's ASCII values
int sum_ascii(string code) {
    int sum = 0; // Accumulator
    // String is a sequence of chars, so use RBFL
    for (const char c : code) {
        sum += (int) c;
    }
    return sum;
}

// Function gen_hash_index: This function will receive a string
// and add that string to a hash table.
void gen_hash_index(string code, map<int, list<string>> & hash ) {

    /*
    1.When codes are read from the file, send the code to your function.
     2.Receive its hash index that's returned from the function.
      3.Input that pair into the map (the hash index and the code string).
       4.Remember that the code string is going into a std::list, 
       so use the appropriate method to manipulate that std::list.
    */
    // First, find key value by summing ASCII values
    int sum = 0;
    // String is a sequence of chars, so use RBFL
    for (const char c : code) {
        sum += (int) c;
    }

    // Hash function: modulus operator with modulus operand 97
    int hashIndex = sum % 97;

    // Insert the code in the correct bucket based on the hash index
    hash[hashIndex].push_back(code);
   
}

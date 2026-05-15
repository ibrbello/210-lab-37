#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


int sum_ascii(string);
int gen_hash_index(string code, map<int, list<string>> & );



int main() {
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

    // Create hash table
    map<int, list<string>> hashTable;
    // Read in file
    string code;
    int ascii_total = 0;
    ifstream fin("lab-37-data-3.txt");
    if (fin.good()) {
        while (fin >> code) {
            ascii_total += sum_ascii(code);
        }
        fin.close();
    }
    else cout << "File reading error.\n";

    // Check correct output
    cout << "The correct total of all ASCII values in the file is 69893419\n";
    cout << "The calculated total of all ASCII values in the file is " <<
        ascii_total << endl;

    // Correct output verified
    cout << sum_ascii("1111") << endl;
    cout << sum_ascii("2222") << endl;
    cout << sum_ascii("ABCD") << endl;

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
int gen_hash_index(string code, map<int, list<string>> & hash ) {

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
    auto it = hash.find(hashIndex);
    
   
}

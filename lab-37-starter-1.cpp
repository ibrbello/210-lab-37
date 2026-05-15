#include <iostream>
#include <string>
using namespace std;

// Function sum_ascii: This function will receive a string
// and return the sum of that string's ASCII values
int sum_ascii(string);


int main() {
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

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

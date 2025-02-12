#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool containsOnlyAlphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string to check if it contains only alphabetic characters: ";
    getline(cin, input);

    bool result = containsOnlyAlphabetic(input);
    if (result) {
        cout << "The string contains only alphabetic characters." << endl;
    } else {
        cout << "The string contains non-alphabetic characters." << endl;
    }

    return 0;
}

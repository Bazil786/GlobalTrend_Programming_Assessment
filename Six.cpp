#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n < 0) {
        return 0;
    }
    
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int number;
    cout << "Enter a number to find its factorial: ";
    cin >> number;

    unsigned long long result = factorial(number);
    cout << "Factorial of " << number << " is: " << result << endl;

    return 0;
}

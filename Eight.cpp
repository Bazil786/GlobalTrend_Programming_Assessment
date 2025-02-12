#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers to find their GCD: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}

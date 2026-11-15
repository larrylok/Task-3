#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Which term do you want (N)? ";
    cin >> n;

    if (n < 1) {
        cout << "N must be 1 or more." << endl;
        return 0;
    }

    cout << "Term number " << n << " of the Fibonacci series is " << fib(n) << endl;
    return 0;
}

#include <iostream>
using namespace std;

void printFib(int count, int a, int b) {
    if (count == 0) {
        return;
    }
    cout << a << " ";
    printFib(count - 1, b, a + b);
}

int main() {
    int n;
    cout << "How many Fibonacci terms do you want? ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a number greater than 0." << endl;
        return 0;
    }

    cout << "The first " << n << " Fibonacci terms are: ";
    printFib(n, 0, 1);
    cout << endl;

    return 0;
}

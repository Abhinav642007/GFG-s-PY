#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Sum of first n natural numbers
    int sum = n * (n + 1) / 2;

    cout << sum;

    return 0;
}
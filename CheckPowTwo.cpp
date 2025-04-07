#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    // A power of two has only one bit set and is > 0
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two." << endl;
    } else {
        cout << num << " is NOT a power of two." << endl;
    }

    return 0;
}

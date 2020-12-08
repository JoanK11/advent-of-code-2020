#include <iostream>
using namespace std;

int totalfuel(int n) {
    if (n/3 - 2 < 1) return 0;
    else return (n/3 - 2) + totalfuel(n/3 - 2);
}

int main() {
    int total = 0, n;
    while (cin >> n) total += totalfuel(n);
    cout << total << endl;
}
        
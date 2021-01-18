#include <iostream>
using namespace std;

int main() {
    int min, max, total = 0;
    char letter, x;
    string pwd;
    while (cin >> min >> x >> max >> letter >> x >> pwd) {
        int count = 0, n = pwd.length();
        for (int i = 0; i < n; ++i) {
            if (pwd[i] == letter) ++count;
        }
        if (count >= min and count <= max) ++total;
    }
    cout << total << endl;
}

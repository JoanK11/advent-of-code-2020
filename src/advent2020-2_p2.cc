#include <iostream>
using namespace std;

int main() {
    int min, max, total = 0;
    char letter, x;
    string pwd;
    while (cin >> min >> x >> max >> letter >> x >> pwd) {
        if ((pwd[min-1] == letter and pwd[max-1] != letter)
        or (pwd[min-1] != letter and pwd[max-1] == letter)) ++total;
    }
    cout << total << endl;
}

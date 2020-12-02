#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int min, max, total = 0;
    char lletra, x;
    string codi;
    while (cin >> min >> x >> max >> lletra >> x >> codi) {
        if (((codi[min - 1] == lletra) and (codi[max - 1] != lletra))
        or ((codi[min - 1] != lletra) and (codi[max - 1] == lletra)))
            ++total;
    }
    cout << total << endl;
}

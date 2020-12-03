#include <iostream>
using namespace std;

int main () {
    string paraula;
    int count = 0, pos = 0;
    while (cin >> paraula) {
        if (pos > 30)
            pos = pos - 31;
        if (paraula[pos] == '#') ++count;
        pos += 3;
    }
    cout << count << endl;
}
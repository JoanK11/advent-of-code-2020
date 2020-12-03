#include <iostream>
using namespace std;

int main () {
    string word;
    int count = 0, pos = 0;
    while (cin >> word) {
        if (pos > 30) pos = pos - 31;
        if (word[pos] == '#') ++count;
        pos += 3;
    }
    cout << count << endl;
}

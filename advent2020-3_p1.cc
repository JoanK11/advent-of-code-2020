#include <iostream>
using namespace std;

int main () {
    string s;
    int count = 0, pos = 0;
    while (cin >> s) {
        if (pos > 30) pos -= 31;
        if (s[pos] == '#') ++count;
        pos += 3;
    }
    cout << count << endl;
}  

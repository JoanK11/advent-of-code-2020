#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    int n = 851;
    vector<int> v(n, 0);
    while (cin >> s) {
        int lrow = 0, rrow = 127;
        int lcol = 0, rcol = 7;
        
        // Calculate Column
        for (int i = 0; i < 7; ++i) {
            // Upper Half
            if (s[i] == 'B') lrow = (lrow + rrow)/2 + 1;
            // Lower Half
            else if (s[i] == 'F') rrow = (lrow + rrow)/2;
        } 
        
        // Calculate Row
        for (int i = 7; i < 10; ++i) {
            // Upper Half
            if (s[i] == 'R') lcol = (lcol + rcol)/2 + 1;
            // Lower Half
            else if (s[i] == 'L') rcol = (lcol + rcol)/2;
        }
        
        // Calculate Seat
        int seat = rrow*8 + rcol;
        ++v[seat - 1];
    }
    for (int i = n/4; i < 3*n/4; ++i) {
        if (v[i] == 0) cout << i + 1 << ' ';
    }
    cout << endl;
}

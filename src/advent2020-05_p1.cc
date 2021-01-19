#include <iostream>
using namespace std;

int main() {
    string s;
    int max = 0;
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
        
        // Calculate Maximum
        int seat = rrow*8 + rcol;
        if (seat > max) max = seat;
    }
    cout << max << endl;
 }

#include <iostream>
using namespace std;

int main () {
    string s;
    int pos1 = 0, pos3 = 0, pos5 = 0, pos7 = 0, pos1_2 = 0, total1 = 0;
    int total1_2 = 0, total3 = 0, total5 = 0, total7 = 0, count = 0;
    while (cin >> s) {
        // Right 1, down 1
        if (s[pos1] == '#') ++total1;
        // Right 3, down 1
        if (s[pos3] == '#') ++total3;
        // Right 5, down 1
        if (s[pos5] == '#') ++total5;
        // Right 7, down 1
        if (s[pos7] == '#') ++total7;
        // Right 1, down 2
        if (count%2 == 0 and s[pos1_2] == '#') ++total1_2;
        
        int n = s.length();
        pos1 += 1, pos3 += 3, pos5 +=5, pos7 += 7, count += 1;
        if (count%2 == 0) pos1_2 += 1;
        if (pos1 > n - 1) pos1 -= n;
        if (pos3 > n - 1) pos3 -= n;
        if (pos5 > n - 1) pos5 -= n;
        if (pos7 > n - 1) pos7 -= n;
        if (pos1_2 > n - 1) pos1_2 -= n;
    }
    long result = total1 * total3 * total5 * total7;
    result *= total1_2;
    cout << result << endl;
}

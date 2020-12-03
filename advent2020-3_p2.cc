#include <iostream>
using namespace std;

int main () {
    string word;
    int pos1 = 0, pos3 = 0, pos5 = 0, pos7 = 0, pos1_2 = 0, total1 = 0;
    int total1_2 = 0, total3 = 0, total5 = 0, total7 = 0, count = 0;
    while (cin >> word) {
        // Right 1, down 1
        if (word[pos1] == '#') ++total1;

        // Right 3, down 1
        if (word[pos3] == '#') ++total3;
        
        // Right 5, down 1
        if (word[pos5] == '#') ++total5;
        
        // Right 7, down 1
        if (word[pos7] == '#') ++total7;
        
        // Right 1, down 2
        if (count%2 == 0 and word[pos1_2] == '#') ++total1_2;
        
        int size = word.length();
        pos1 += 1, pos3 += 3, pos5 +=5, pos7 += 7, count += 1;
        if (count%2 == 0) pos1_2 += 1;
        if (pos1 > size - 1) pos1 -= size;
        if (pos3 > size - 1) pos3 -= size;
        if (pos5 > size - 1) pos5 -= size;
        if (pos7 > size - 1) pos7 -= size;
        if (pos1_2 > size - 1) pos1_2 -= size;
    }
    total7 -= 1;
    cout << total1 << ' ' << total3 << ' ' << total5 << ' ' << total7 << ' ' << total1_2 << endl;
    long result = total1 * total3 * total5 * total7;
    result *= total1_2;
    cout << result << endl;
}

/*
Right 1, down 1. asdad
Right 3, down 1 asdasd
Right 5, down 1. asdad
Right 7, down 1. asdasd
Right 1, down 2. asdad
*/

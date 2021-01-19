#include <iostream>
#include <vector>
using namespace std;

int search(const vector<string>& words, const vector<int>& numbers) {
    int i = 0, count = 0, n = words.size();
    while (i < n) {
            if (words[i] == "acc") {
                count += numbers[i];
                ++i;
            }
            else if (words[i] == "jmp") i += numbers[i];
            else ++i;
        }
        return count;
}

bool end(const vector<string>& words, const vector<int>& numbers) {
    int n = words.size(), i = 0;
    vector<int> count(n, 0);
    while (i < n) {
        if (count[i] == 1) return false;
        ++count[i];
        
        if (words[i] == "jmp") i += numbers[i];
        else ++i;
    }
    return true;
}

int main() {
    int n = 634;
    vector<string> words(n);
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) cin >> words[i] >> numbers[i];
    
    vector<string> copy = words;
    for (int i = 0; i < n; ++i) {
        if (words[i] == "jmp" or words[i] == "nop") {
            // Change
            copy = words;
            if (copy[i] == "jmp") copy[i] = "nop";
            else if (copy[i] == "nop") copy[i] = "jmp";
            // Check that it ends
            if (end(copy, numbers)) {
                cout << search(copy, numbers) << endl;
                break;
            }
        }
    }
}

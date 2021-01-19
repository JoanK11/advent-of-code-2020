#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 634;
    vector<string> words(n);
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) cin >> words[i] >> numbers[i];
    
    vector<int> count(n, 0);
    int total = 0, i = 0;
    while (count[i] == 0) {
        ++count[i];
        if (words[i] == "acc") {
            total += numbers[i];
            ++i;
        }
        else if (words[i] == "jmp") i += numbers[i];
        else ++i;
    }
    cout << total << endl;
}

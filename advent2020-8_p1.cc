#include <iostream>
#include <vector>
using namespace std;
// 634
int main() {
    vector<string> word(634);
    vector<int> number(634);
    for (int pos = 0; pos < 634; ++pos)
        cin >> word[pos] >> number[pos];
    
    vector<int> comptador(634, 0);
    int count = 0, i = 0;
    while (comptador[i] == 0) {
        ++comptador[i];
        if (word[i] == "acc") {
            count += number[i];
            ++i;
        }
        
        else if (word[i] == "jmp") i += number[i];
        
        else ++i;
    }
    cout << count << endl;
}
            
            

#include <iostream>
#include <vector>
using namespace std;

int procediment(const vector<string>& word, const vector<int>& number) {
    int i = 0, count = 0;
    while (i < word.size()) {
            if (word[i] == "acc") {
                count += number[i];
                ++i;
            }
            
            else if (word[i] == "jmp") i += number[i];
            else ++i;
        }
        return count;
}

bool acaba(const vector<string>& word, const vector<int>& number) {
    vector<int> comptador(word.size(), 0);
    int i = 0; 
    while (i < word.size()) {
        if (comptador[i] == 1) return false;
        ++comptador[i];
        
        if (word[i] == "jmp") i += number[i];
        else ++i;
    }
    return true;
}

int main() {
    vector<string> word(634);
    vector<int> number(634);
    
    for (int i = 0; i < word.size(); ++i) cin >> word[i] >> number[i];
    
    vector<string> copia = word;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == "jmp" or word[i] == "nop") {
            // Fem el canvi
            copia = word;
            if (copia[i] == "jmp") copia[i] = "nop";
            else if (copia[i] == "nop") copia[i] = "jmp";
            // Comprovem que acabi
            if (acaba(copia, number)) {
                cout << procediment(copia, number) << endl;
                break;
            }
        }
    }
}
            
            

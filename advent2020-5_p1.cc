#include <iostream>
using namespace std;

   int main() {
       string word;
       int maxim = 0;
       while (cin >> word) {
           int lrow = 0, rrow = 127;
           int lcolumn = 0, rcolumn = 7;
           
           // Calculem Columna
           for (int i = 0; i < 7; ++i) {
               // Upper Half
               if (word[i] == 'B') lrow = ((lrow + rrow)/2) + 1;
               // Lower Half
               else if (word[i] == 'F') rrow = (lrow + rrow)/2;
           }
           
           // Calculem Fila
           for (int i = 7; i < 10; ++i) {
               // Upper Half
               if (word[i] == 'R') lcolumn = ((lcolumn + rcolumn)/2) + 1;
               // Lower Half
               else if (word[i] == 'L') rcolumn = (lcolumn + rcolumn)/2;
           }
           
           // Calculem màxim
           int seient = rrow*8 + rcolumn;
           if (seient > maxim) maxim = seient;
       }
       cout << maxim << endl;
  }
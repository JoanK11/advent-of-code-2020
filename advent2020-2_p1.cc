#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int min, max, total = 0;
    char lletra, x;
    string codi;
    while (cin >> min >> x >> max >> lletra >> x >> codi){
        int count = 0;
        for (int i = 0; i < codi.length(); ++i) {
            if (codi[i] == lletra)
                ++count;
        }
        if ((count >= min) and (count <= max))
        ++total;
    }
    cout << total << endl;
}

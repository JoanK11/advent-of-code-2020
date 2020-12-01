#include <iostream>
#include <vector>
using namespace std;

int cerca(vector<int> vector, int x) {
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= x; ++k) {
            if (vector[i] + vector[j] + vector[k] == 2020)
                return vector[i] * vector[j] * vector[k];
        }
    }
    }
    return 0;
}


int main() {
    int x, pos = 0;
    vector<int> vector(1000);
    while (cin >> x) {
        vector[pos] = x;
        ++pos;
    }
    cout << cerca(vector, pos) << endl;
}


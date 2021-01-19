#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i] + v[j] == 2020) return v[i]*v[j];
        }
    }
    return 0;
}

int main() {
    int n = 1000;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << search(v, n) << endl;
}

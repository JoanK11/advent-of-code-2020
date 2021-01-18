#include <iostream>
#include <vector>
using namespace std;

void change(vector<int>& v, int x) {
    int n = v.size();
    for (int i = 1; i < n; ++i) v[i - 1] = v[i];
    v[n - 1] = x;
}

int search(vector<int>& v) {
    int x, n = v.size();
    while (cin >> x) {
        bool found = false;
        for (int i = 0; not found and i < n; ++i) {
            for (int j = 0; not found and j < n; ++j) {
                found = v[i] + v[j] == x;
            }
        }
        if (not found) return x;
        change(v, x);
    }
    return 0;
}

int main() {
    int n = 25;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int result = search(v);
    cout << result << endl;
}

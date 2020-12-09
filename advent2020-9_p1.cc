#include <iostream>
#include <vector>
using namespace std;

void canvi(vector<int>& v, int x) {
    for (int i = 1; i < v.size(); ++i) {
        v[i - 1] = v[i];
    }
    v[v.size() - 1] = x;
}

int search(vector<int>& v) {
    int x;
    while (cin >> x) {
        bool trobat = false;
        for (int i = 0; (not trobat) and (i < v.size()); ++i) {
            for (int j = 0; (not trobat) and (j < v.size()); ++j) {
                if ((v[i] + v[j]) == x) trobat = true;
            }
        }
        if (not trobat) return x;
        canvi(v, x);
    }
    return 0;
}

int main() {
    vector<int> v1(25);
    for (int i = 0; i < v1.size(); ++i) cin >> v1[i];
    int result = search(v1);
    cout << "Result: " << result << endl;
    return 0;
}
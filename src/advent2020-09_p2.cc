#include <iostream>
#include <vector>
using namespace std;

int maximum(const vector<int>& v, const int pos) {
    int max = v[pos], n = v.size();
    for (int i = pos + 1; i < n; ++i) {
        if (v[i] > max) max = v[i];
    }
    return max;
}

int minimum(const vector<int>& v, const int pos) {
    int min = v[pos], n = v.size();
    for (int i = pos + 1; i < n; ++i) {
        if (v[i] < min) min = v[i];
    }
    return min;
}

int sum(const vector<int>& v, const int pos) {
    int total = 0, n = v.size();
    for (int i = pos; i < n; ++i) total += v[i];
    return total;
}

int search(vector<int>& v, const int x, int& pos) {
    int n, total = sum(v, pos);
    while (total < x) {
        cin >> n;
        v.push_back(n);
        total += n;   
    }
    if (total == x and v.size() - pos >= 2)
        return maximum(v, pos) + minimum(v, pos);
    return search(v, x, ++pos);
}

int main() {
    int x = 675280050, pos = 0;
    vector<int> v;
    int result = search(v, x, pos);
    while (cin >> pos);
    cout << result << endl;
}

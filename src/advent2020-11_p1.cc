#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;

bool inside(int i, int j, int n) {
    return i >= 0 and i < n and j >= 0 and j < n;
}

bool empty(const Matrix& mat, int i, int j) {
    int n = mat.size();
    return ((not inside(i - 1, j, n) or mat[i-1][j] != '#') and
    (not inside(i - 1, j + 1, n) or mat[i-1][j+1] != '#') and
    (not inside(i, j + 1, n) or mat[i][j+1] != '#') and
    (not inside(i + 1, j + 1, n) or mat[i+1][j+1] != '#') and
    (not inside(i + 1, j, n) or mat[i+1][j] != '#') and
    (not inside(i + 1, j - 1, n) or mat[i+1][j-1] != '#') and
    (not inside(i, j - 1, n) or mat[i][j-1] != '#') and
    (not inside(i - 1, j - 1, n) or mat[i-1][j-1] != '#'));
}

bool adjacent(const Matrix& mat, int i, int j) {
    int n = mat.size(), count = 0;
    if (inside(i - 1, j, n) and mat[i-1][j] == '#') ++count;
    if (inside(i - 1, j + 1, n) and mat[i-1][j+1] == '#') ++count;
    if (inside(i, j + 1, n) and mat[i][j+1] == '#') ++count;
    if (inside(i + 1, j + 1, n) and mat[i+1][j+1] == '#') ++count;
    if (inside(i + 1, j, n) and mat[i+1][j] == '#') ++count;
    if (inside(i + 1, j - 1, n) and mat[i+1][j-1] == '#') ++count;
    if (inside(i, j - 1, n) and mat[i][j-1] == '#') ++count;
    if (inside(i - 1, j - 1, n) and mat[i-1][j-1] == '#') ++count;
    return count >= 4;
}

Matrix read_matrix(int n) {
    Matrix mat(n, Row(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> mat[i][j];
    }
    return mat;
}

int main() {
    int n = 92;
    Matrix mat = read_matrix(n);

    bool changed = true;
    while (changed) {
        changed = false;
        Matrix copy = mat;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (copy[i][j] == 'L' and empty(copy, i, j)) {
                    mat[i][j] = '#';
                    changed = true;
                }
                else if (copy[i][j] == '#' and adjacent(copy, i, j)) {
                    mat[i][j] = 'L';
                    changed = true;
                }
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (mat[i][j] == '#') ++total;
    }
    cout << total << endl;
}
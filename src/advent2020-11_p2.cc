#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;

bool outside(int i, int j, int n) {
    return i < 0 or i >= n or j < 0 or j >= n;
}

bool search(const Matrix& mat, int i, int j, int incri, int incrj) {
    int n = mat.size();
    i += incri, j += incrj;
    while (not outside(i, j, n)) {
        if (mat[i][j] == '#') return true;
        else if (mat[i][j] == 'L') return false;
        i += incri, j += incrj;
    }
    return false;
} 

int adjacent(const Matrix& mat, int i, int j) {
    int count = 0;
    if (search(mat, i, j, -1,  0)) ++count;
    if (search(mat, i, j, -1, +1)) ++count;
    if (search(mat, i, j,  0, +1)) ++count;
    if (search(mat, i, j, +1, +1)) ++count;
    if (search(mat, i, j, +1,  0)) ++count;
    if (search(mat, i, j, +1, -1)) ++count;
    if (search(mat, i, j,  0, -1)) ++count;
    if (search(mat, i, j, -1, -1)) ++count;
    return count;
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
                if (copy[i][j] == 'L' and adjacent(copy, i, j) == 0) {
                    mat[i][j] = '#';
                    changed = true;
                }
                else if (copy[i][j] == '#' and adjacent(copy, i, j) >= 5) {
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

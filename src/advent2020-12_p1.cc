#include <iostream>
using namespace std;

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    int east = 0, north = 0;
    char c;
    int x, dir = 90;
    while (cin >> c >> x) {
        if (c == 'N') north += x;
        else if (c == 'S') north -= x;
        else if (c == 'E') east += x;
        else if (c == 'W') east -= x;
        
        else if (c == 'L') {
            dir = (dir - x)%360;
            if (dir < 0) dir += 360;
        }
        else if (c == 'R') {
            dir = (dir + x)%360;
            if (dir < 0) dir += 360;
        }
        else if (c == 'F') {
            if (dir == 0) north += x;
            else if (dir == 90) east += x;
            else if (dir == 180) north -= x;
            else if (dir == 270) east -= x;
        }
    }
    cout << abs(east) + abs(north) << endl;
}

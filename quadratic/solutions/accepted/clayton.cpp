
#include <iostream>

using namespace std;

int x1, x2, c1, c2;

int main() {
    cin >> x1 >> c1 >> x2 >> c2;
    int a = x1 * x2;
    int b = x1 * c2 + x2 * c1;
    int c = c1 * c2;
    cout << a << " " << b << " " << c << endl;
}

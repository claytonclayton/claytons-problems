
#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int r = 0; r < n; r++) {
	for (int c = 0; c < n; c++) {	
	    if (r == n / 2)
		cout << '#';	
	    else if (c == n / 2)
		cout << '#';	
	    else
		cout << '.';
	}
	cout << endl;
    }
}

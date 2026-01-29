#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    string os = "ABDOPQRabdegopq04689";
    for (char c : s) {
	for (char d : os) {
	    if (c == d) {
		cout << "YES" << endl;
		return 0;
	    }
	}
    }
    cout << "NO" << endl;
}

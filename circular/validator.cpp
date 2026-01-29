#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;
string cs;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    cs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+= ";
    string s = inf.readLine();
    for (char c : s) {
	bool found = false;
	for (char d : cs) {
	    if (c == d) {
		found = true;
		break; 
	    }
	}
	ensuref(found, "invalid char used");
    }
    inf.readEof();
}

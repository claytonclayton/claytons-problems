#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10'000

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, MAX_N, "t");
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        inf.readInt(1, MAX_N);
	inf.readSpace();
	inf.readInt(1, MAX_N);
	inf.readEoln();
    }
    inf.readEof();
}

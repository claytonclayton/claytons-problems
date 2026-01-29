#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1, MAX_N = 1'000'000; 

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readSpace();
    int k = inf.readInt(MIN_N, MAX_N, "k");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        if (i != 0) inf.readSpace();
        int num = inf.readInt(MIN_N, n, "num");
    }
    inf.readEoln();
    inf.readEof();
}

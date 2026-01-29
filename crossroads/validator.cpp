
#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MIN_N = 1, MAX_N = 1'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    ensuref(n % 2 == 1, "n not odd");
    inf.readEoln();
    inf.readEof();
}

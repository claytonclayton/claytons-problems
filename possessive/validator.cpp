#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000; 

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, MAX_N, "n"); 
    inf.readEoln();
    string s = inf.readLine();
    inf.readEof();

    ensuref(s.size() == n, "input string is not size n");
    for (char c: s) {
        ensuref(c == ' ' || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'), "not letter or space");
    }

    ensuref(n < 1 || s.substr(0, 1) != " ", "starts with space");
    ensuref(n < 1 || s.substr(n-1, n) != " ", "ends with space");
    ensuref(s.find("  ") == string::npos, "contains double space");

    ensuref(n < 2 || s.substr(0, 2) != " ", "starts with of");
    ensuref(n < 2 || s.substr(n-2, n) != " ", "ends with of");
    ensuref(s.find("of of") == string::npos, "contains of of");

    ensuref(n < 6 || s.substr(0, 6) != "the of", "starts with the of");
    ensuref(n < 6 || s.substr(n-6, n) != "of the", "ends with of the");
    ensuref(s.find("of the of") == string::npos, "contains of the of");

    ensuref(n < 6 || s.substr(0, 6) != "The of", "starts with The of");
    ensuref(n < 6 || s.substr(n-6, n) != "of The", "ends with of The");
    ensuref(s.find("of The of") == string::npos, "contains of The of");

    #ifdef SUB1
        ensuref(s.find("the") == string::npos, "contains the");
    #endif
}

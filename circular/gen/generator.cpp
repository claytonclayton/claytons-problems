#include <iostream>
#include "../../testlib.h"
#include <string>
#include <algorithm>

using namespace std;

const int N = 1'000'000;
int n, k;
string s, os, nos;

void rand_s() {
    vector<int> hits;
    for (int i = 0; i < k; i++) {
	hits.push_back(rnd.next(0, n - 1));
    }

    sort(hits.begin(), hits.end(), greater<int>());
    unique(hits.begin(), hits.end());

    for (int i = 0; i < n; i++) {
	s[i] = rnd.any(nos);
	if (hits.size() && i == hits.back()) {
	    s[i] = rnd.any(os);
	    hits.pop_back();
	}
    }
}

void all_os() {
    for (int i = 0; i < n; i++) {
	s[i] = rnd.any(os);
    }
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    os = "ABDOPQRabdegopq04689";
    nos = "CEFGHIJKLMNSTUVWXYZcfhijklmnrstuvwxyz12357+= ";
    // os and nos size sum to 65 yay
    // 26 * 2 upper and lower case, 10 digits, and '+', '=' and ' '
  
    s = string(n, ' ');

    if (n == k) {
	all_os();
    } else {
	rand_s();
    }
    cout << s << endl; 
}

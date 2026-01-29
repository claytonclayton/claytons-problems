
#include "../../testlib.h"
#include <bits/stdc++.h>
using namespace std;

int l, r;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    l = atoi(argv[1]);
    r = atoi(argv[2]);

    for (int i = 0; i < 4; i++) {
	if (i != 0) cout << " ";
	cout << rnd.next(l, r);
    }
    cout << endl;
}

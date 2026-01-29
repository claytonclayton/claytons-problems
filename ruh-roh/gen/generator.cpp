#include <iostream>
#include "../../testlib.h"

using namespace std;

const int N = 1'000'000;
const int SMALL_MIN = 1, SMALL_MAX = 10;
// const int LARGE_MIN = 1000, LARGE_MAX = 10'000;
int n, k, type;
int a[N];

void generate_small() {
    for (int i = 0; i < n; i++) 
	a[i] = rnd.next(SMALL_MIN, SMALL_MAX);
}

// k large numbers are generated, n/k distance apart,
// allowing for a[] to be traversed in k jumps.
// of the k large numbers, if their a[i] < n/k, then
// they will not have an adequately large jump to get to
// the next large number, causing a -1 return. 
void generate_large() {
    int miss_i = rnd.next(0, k - 1);
    int dx = n/k;

    int i = 0, j = 0;
    for (; i < n; j++) {
	a[i] = dx - (type == 1 && j == miss_i);
	i += dx;
    }
}

void generate_medium() {
    for (int i = 0; i < n; i++) {
	a[i] = rnd.next(1, min(n, 1'000));
    }
}

void all_ones() {
    for (int i = 0; i < n; i++) {
	a[i] = 1;
    }
}

// case 'type' of
// 0 - large small numbers, numbers just large enough to prevent -1 return
// 1 - large small numbers, but with one missed jump
// 2 - small numbers
// 3 - medium numbers
// 4 - all 1s
// 5 - 1 jump
// 6 - 2 jumps
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    type = atoi(argv[3]);

    if (type <= 2) generate_small();
    if (type <= 1) generate_large();
    if (type == 3) generate_medium();
    if (type == 4) all_ones();
    if (type == 5 || type == 6) {
	all_ones();
	a[0] = n;
    }
    if (type == 6) a[0]--;

    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++) {
	if (i != 0) cout << " ";
	cout << a[i];
    } cout << endl;
}

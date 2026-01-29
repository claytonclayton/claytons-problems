#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include "../../testlib.h"

using namespace std;

const int N = 10'000;
const int M = 10'000;
int max_n, max_m;
int mins[M + 10];

// the ith line of mins is the minimum array size
// required to make i Ianuarian Triples
void read_min_file() {
    ifstream minfile("mins.txt");
    int line, i;
    for (i = 1; i <= M && (minfile >> line); i++) {
        mins[i] = line;
    }
    minfile.close();
}

void generate_in_file(int file_index, int t, int max_n, int max_m) {
    ofstream tst("../data/random/"+to_string(file_index)+".in");
    tst << t << endl;
 
    for (int i = 0; i < t / 3; i++) {
	int n = rnd.next(1, max_n);
	int m = rnd.next(1, max_m);

	// Testcase 1:
	// Since mins[m] is the minimum array size s to make m Ianuarian Triples,
	// then (mins[m], m) should always output YES
	// 
	// Testcase 2:
	// For the same reason as above, (mins[m] - 1, m) should always output NO 
	//
	// Testcase 3:
	// Choose a random number n and test (n, m)

	tst << mins[m]     << " " << m << endl;
	tst << mins[m] - 1 << " " << m << endl;
	tst << n           << " " << m << endl;
    }

    tst.close();
}

void generate_small_mins() {
    ofstream tst("../data/handcases/1.in");
    tst << 200 << endl;
    for (int i = 1; i <= 100; i++) {
        tst << mins[i]     << " " << i << endl;
        tst << mins[i] - 1 << " " << i << endl;
    }

    tst.close(); 
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    read_min_file();
    generate_small_mins();
    generate_in_file(1, 99, mins[M], M);
    generate_in_file(2, M - 1, mins[M], M);
    generate_in_file(3, M - 1, M, M);
}


#include <set>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int N = 3010;

vector<ti> coords;
multiset<int> rs, cs;
int R, C, K, grid[N][N];

int main() {
    cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			coords.emplace_back(grid[i][j], i, j);
		}
	}

	// Sort all grid numbers and scan over them in a k^2 sliding window
	// If all elements in the window are within a k^2 box in the grid,
	// then a tragic square exists 
	sort(coords.begin(), coords.end());
	for (int i = 0; i < coords.size(); i++) {
		auto[v, r, c] = coords[i];
		rs.insert(r);
		cs.insert(c);
		if (i >= K * K) {
			auto[_, pr, pc] = coords[i - K * K];
			rs.erase(rs.find(pr));
			cs.erase(cs.find(pc));
		}
		if (i >= K * K - 1 && *rs.rbegin() - *rs.begin() < K && *cs.rbegin() - *cs.begin() < K) {
			cout << *rs.begin() << " " << *cs.begin() << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}

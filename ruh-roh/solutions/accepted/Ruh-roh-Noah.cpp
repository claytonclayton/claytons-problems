#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;

int n, k;
int nums[N];
int calc(int st, int ed, int limit) {
    if (st == ed) return 0;
    int smallestJump = 1;
    if (nums[st] > limit) {
        smallestJump = nums[st] - limit;
    }
    if (st + smallestJump > ed) return -1;
    int jumpCount = 1;
    int l = st + smallestJump, r = st + nums[st];
    while (r < ed) {
        int nextR = r;
        for (int i = l; i <= r; i++) 
            nextR = max(nextR, nums[i]+i);
        
        l = r+1;
        r = nextR;
        jumpCount++;
    }

    return jumpCount;
}

bool check(int limit) {
    vector <int> indices;
    indices.push_back(1);
    bool hasHigher = false;
    for (int i = 1; i <= n; i++) {
        if (nums[i] > limit) {
            indices.push_back(i);
            hasHigher = true;
        }
    }
    if (!hasHigher) return true;
    indices.push_back(n+1);

    int jumpCount = 0;
    for (int i = 1; i < indices.size(); i++) {
        int curJump = calc(indices[i-1], indices[i], limit);
        if (curJump == -1) return false;
        jumpCount += curJump;
    }

    return jumpCount <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    int ans = 1e6;
    int l = 0, r = 1e6;
    if (calc(1, n+1, n+1) > k) {
        cout << "-1\n";
        return 0;
    }
    while (l <= r) {
        int mid = (l+r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << '\n';
}

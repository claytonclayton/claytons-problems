#include <iostream>
#include <tuple>

using namespace std;

const int N = 1'000'010;
int n, k, jumps;
int a[N];

typedef tuple<int, int, int> ti;

// on the first jump we can jump from r = 0 to
// any i in the range [1, a[0]].
// since we should maximise how far we jump, so
// we can remain within the k jumps threshold,
// the next jump should be from an r in [1, a[0]],
// such that r + a[r] is maximised.
// we must also meet the condition that all elements
// in A must not exceed 'target' (this is the
// variable that we search for in the bsearch).
// so if we encounter an a[i] > target, then we
// must jump from here to decrease it below target.
// thus from here we must jump at least a[i] - target
// units ahead. if during this jump we jump over
// another a[j] > target before jumping a[i] - target
// units, then the current target is impossible,
// so we return false.
// so the total possible locations we can jump to
// is in the range [l, r] where r is the previous
// maximal i + a[i] from the previous range of jumps
// and l is the minimum amount we have to jump such
// that the previous a[i] > target is reduced to
// target.
ti move(int cur, int l, int r, int target) {
    int next_l = 0;
    int next_r = 0;
    int i = cur;
    for (; i <= r; i++) {
        if (i >= n) return make_tuple(-2, -2, -2);	
        next_r = max(next_r, i + a[i]);
        if (a[i] > target) {
            if (i < l) return make_tuple(-1, -1, -1);
            next_l = i + (a[i] - target);
            return make_tuple(i + 1, next_l, next_r);
        }
    }
    next_l = i;
    return make_tuple(i, next_l, next_r);
}

// tests if we can jump from i = 0 to i = n in
// at most k jumps such that all elements in A
// are reduced to at most 'target'
// 'move' determines the range of possible
// indices we can jump to from the current 
// position
bool check(int target) {
    int i = 0, l = 0, r = 0;
    jumps = 0;
    for (; i < n; jumps++) {
        auto [next_i, next_l, next_r] = move(i, l, r, target);
        i = next_i; l = next_l; r = next_r;
        // cout << i << " " << l << " " << r << " " << endl;
        if (i == -2) return true;
        if (i == -1) return false;
        if (jumps >= k && i < n) return false;
    }
    return l <= n;
}

int main() {
    cin >> n >> k;
    int maxxer = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxxer = max(maxxer, a[i]);
    }
    // binary search from 0 to the max element of A
    int l = 0, r = maxxer + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (l > maxxer ? -1 : l) << endl;
}

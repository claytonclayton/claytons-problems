#include <bits/stdc++.h>
using namespace std;
// trans rights
#define ll long long
#define f first
#define s second
#define endl '\n'
#define all(x) begin(x), end(x)
int n;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n / 2 || j == n / 2) cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}
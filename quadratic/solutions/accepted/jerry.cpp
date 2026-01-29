#include <bits/stdc++.h>
using namespace std;
// trans rights
#define ll long long
#define f first
#define s second
#define endl '\n'
#define all(x) begin(x), end(x)
int a, b, c, d;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    cout<<a * c<<' '<<a * d + b * c<<' '<<b * d<<endl;
    return 0;
}
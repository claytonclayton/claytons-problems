#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s; 
    string abc = "abdegopq";
    string ABC = "ABDOPQR";
    set <char> circular;
    for (auto& c : abc+ABC) circular.insert(c);
    bool isCircular = false;
    while (cin >> s) {
        for (auto& c : s) {
            isCircular |= circular.count(c);
        }
    }
    
    cout << (isCircular ? "YES" : "NO") << '\n';
}

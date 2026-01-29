// Attribution: Ashley Clayton (2024)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int n;
unordered_map<string, vector<string>> dict;
unordered_map<string, bool> active;
unordered_map<string, bool> seen;
unordered_map<string, bool> cycled;

// All cycles or ancestors of cycles will not be learnable
void dfs(string cur) {
    if (seen[cur]) return;
    seen[cur] = true;
    active[cur] = true;

    for (string next : dict[cur]) {
        if (dict.count(next)) dfs(next);
        if (active[next] || cycled[next]) 
            cycled[cur] = true;
    }

    active[cur] = false;
}

int main() {
    cin >> n;
    vector<int> lens;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        lens.push_back(a);
    }

    // create DAG out of the dictionary
    // by drawing an edge from a parent word
    // to all other words in the dictionary
    // that belong in the parent's definition.
    // the parent will be learnable if
    // all its children are learnable
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        word.pop_back();

        for (int j = 0; j < lens[i] - 1; j++) {
            string cur; cin >> cur;
            dict[word].push_back(cur);
        }
    }

    // perform directed cycle checking dfs
    for (auto[word, _] : dict) {
        if (!seen[word]) dfs(word);
    }

    // all words that are not within cycles 
    // or are ancestors of cycles 
    // will be learnable
    int sol = 0;
    for (auto[word, _]: dict) {
        sol += cycled[word] == 0;
    }
    cout << sol << endl;
}

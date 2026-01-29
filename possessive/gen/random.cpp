
#include "../../testlib.h"
#include <bits/stdc++.h>

using namespace std;
using pq = priority_queue<int, vector<int>, greater<int>>;
using vi = vector<int>;

int n, p, q, r, m;
vi reg_len;
pq thes;
pq ofs;
string sentence;

string rand_word(int len) {
    string s = rnd.next("[a-zA-Z]{" + to_string(len) + "}");    
    if (s.size() != 2 || s.size() != 3) return s;
    string t;
    for (auto c : s) t += tolower(c);
    if (t == "of" || t == "the") return rand_word(len);
    return s;
}

void debug() {
    cout << "p: " << p << " " << reg_len.size() << endl;
    cout << "q: " << q << " " << thes.size() << endl;
    cout << "r: " << r << " " << ofs.size() << endl;
    cout << "m: " << m << " " << reduce(reg_len.begin(), reg_len.end()) << endl;
}

void make_regs() {
    if (p == 0) return; 

    vector<int> reg_cand;
    for (int i = 1; i < m; i++) 
        reg_cand.push_back(i); 
    
    shuffle(reg_cand.begin(), reg_cand.end());
    set<int> regs; 
    regs.insert(0);
    for (int i = 0; i < p - 1; i++) 
        regs.insert(reg_cand[i]);
   
    auto cur = regs.begin();
    auto pre = cur;
    cur++;
    for (; cur != regs.end(); cur++) {
        reg_len.push_back(*cur - *pre);
        pre = cur;
    } 
    reg_len.push_back(m - *pre); 

    assert(reduce(reg_len.begin(), reg_len.end()) == m);

    if (reg_len.size() != p) {
        debug();
        assert(reg_len.size() == p);
    }
}

void make_ofs() {
    vector<int> of_cand;
    for (int i = 1; i <= p - 1; i++) 
        of_cand.push_back(i);

    shuffle(of_cand.begin(), of_cand.end());
    for (int i = 0; i < r; i++)
        ofs.push(of_cand[i]);
   
    if (ofs.size() >= reg_len.size() && p != 0 && r != 0) {
        debug();
        assert(ofs.size() < reg_len.size());
    }

    if (ofs.size() != r) {
        debug();
        assert(ofs.size() == r);
    }
}

void make_thes() {
    for (int i = 0; i < q; i++)  
        thes.push(rnd.next(0, p + r));

    if (thes.size() != q) {
        debug();
        assert(thes.size() == q);
    }
}

void make_sentence() {
    // add ofs and regular words first
    vector<string> reg_of;
    int i = 0;   
    for (auto v : reg_len) {
        if (!ofs.empty() && ofs.top() == i) {
            reg_of.push_back("of"); 
            ofs.pop();
        }
        reg_of.push_back(rand_word(v));
        i++;
    }
    
    if (ofs.size() != 0) {
        debug();
        assert(ofs.size() == 0);
    }

    // then add thes 
    vector<string> words;
    i = 0;
    for (auto s : reg_of) {
        while (!thes.empty() && thes.top() == i) {
            words.push_back("the"); 
            thes.pop();
        }
        words.push_back(s);
        i++;
    }
    while (!thes.empty()) {
        words.push_back("the");
        thes.pop();
    }

    for (auto s : words)
        sentence += s + " ";

    // removing trailing whitespace.
    // beginnigs of sentences are
    // capitalised
    sentence.pop_back();
    sentence[0] = toupper(sentence[0]);

    if (!(sentence.size() == n || (p == 0 && sentence.size() < n))) {
        debug();
        assert(sentence.size() == n);
    }
}

// SORRY FOR COMPLICATED GENERATOR AS ALWAYS
// I JUST WANTED TO DO IT CORRECTLY

// OUTPUT
// creates a sentence of length n
// containing p random words
// with q randomly placed 'the' words (potentially placed consecutively)
// and with r randomly placed 'of' words (not placed consecutively)

// STRATEGY
// 1. Calculate m, the number of non-space characters belonging to
//    non-the and non-of words, call these 'regular words'.
// 2. In the range 1..m-1 pick p - 1 random numbers without replacement and split
//    the range 0..m at each of those points. This will create p ranges
//    that represent the random lengths of the p regular words.
//    Create this sentence by creating p regular words with lengths the
//    size of each range.
// 3. Assign a number to each gap between consecutive regular words and
//    pick r of them without replacement. Place an 'of' at each 
//    corresponding gap.
// 4. Again assign a number to each gap between consecutive regular words
//    and 'of' words (including at the very start and end of the sentence,
//    as leading and trailing 'the's are allowed). Pick q of them with
//    replacement (as consecutive 'the's are allowed) and place a 'the'
//    at each corresponding gap.
// 5. Now you have a sentence of length n that hopefully follows the
//    above constraints. Many asserts are placed to ensure this.
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    n = atoi(argv[1]);
    p = atoi(argv[2]); 
    q = atoi(argv[3]);
    r = atoi(argv[4]);

    assert(p <= n);
    assert(r < p || (p == 0 && r == 0));
    assert(n >= 2 * p + 4 * q + 3 * r - 1);

    m = n - p - 4 * q - 3 * r + 1;  

    make_regs();
    make_ofs(); 
    make_thes(); 
    make_sentence();

    cout << sentence.size() << endl;
    cout << sentence << endl;
}

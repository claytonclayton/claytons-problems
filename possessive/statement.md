**Time limit: 1 second** |
**Memory limit: 512 megabytes** |
**C++ Template ([view](/assets/possessive.cpp), [download](/assets/possessive.cpp){download=1})** |
**Python Template ([view](/assets/possessive.py), [download](/assets/possessive.py){download=1})**

America has voted and inefficiency is OUT.
Titles like "The President of America" are way too long and cumbersome.
Introducing the *possessive* form of a title.
Now the President can be much more quickly and succinctly referred to as "America's President".

Similarly:

- "The President of the Bank of America" becomes "America's Bank's President".
- "The Regional Manager of the Scranton Branch of the Bank of America" becomes "America's Bank's Scranton Branch's Regional Manager".

Formally, the possessive form of any title without the word "of" is the title itself,
and the possessive form of any title of the form "A of B" is "BB's AA",
where AA (respectively BB) is formed by removing the leading "the"/"The"
from A (respectively B) if it has one, then taking its possessive form.
It can be shown that under the given constraints, this uniquely defines the possessive form.

Write a program which, given a title consisting of $N$ characters, outputs its possessive form.

### Constraints and Scoring

For all test cases:

- $1 \leq N \leq 1000$.
- The title consists of only spaces, uppercase English letters and lowercase English letters.
- The title does not start with a space, end with a space nor contain consecutive spaces.
- The title does not start with "of", end with "of" or contain "of of".
- The title does not start with "the of", contain "of the of" nor end with "of the".
- The title does not start with "The of", contain "of The of" nor end with "of The".

Your program will be run on the 2 sample cases and 18 secret cases, each worth 5% of the points.

- For 50% of the test cases: the title does not contain "the" or "The".
- For 50% of the test cases: there are no further constraints.

### Input

- The first line contains one integer $N$, the number of characters in the title (including spaces).
- The second line contains the title, consisting of $N$ characters, each either a letter or a space.

### Output

Output the possessive form of the given title.

### Sample Input 1

```
36
The President of the Bank of America
```

### Sample Output 1

```
America's Bank's President
```

### Sample Input 2

```
72
the possessive form of any title without the word of is the title itself
```

### Sample Output 2

```
is the title itself's any title without the word's possessive form
```


# CPM-erriam Webster

**Program time limit: 1 second**

**Program memory limit: 512 MB**

The famous and reputable dictionary writing company CPM-erriam-Webster wants to revolutionise the dictionary market. Introducing, The CPM-erriam-Webster Abridged Dictionary, now with fewer words.

The genius idea behind CPM-erriam-Webster Abridged Dictionary is that it does not contain definitions of words that people with an intermediate reading level should already understand, reducing page count, creating ease of look up for experienced English speakers.

While developing this dictionary CPM notices something interesting. If a word's definition only contains words that are “obvious” (words that are not defined in the dictionary), then someone with an intermediate understanding could learn this new word by piecing together definitions they already know.

After these new words are learnt, even more words can be learned. A word is “learnable” if its definition only contains words that are either obvious or learnable.

Given a dictionary, how many words are learnable?

### Input

The first line contains the integer $N$, the number of entries in the dictionary

The next line contains $N$ integers where the $i^{th}$ integer denotes the number of words in the $i^{th}$ entry of the dictionary

Each of the next $N$ lines represent an entry in the dictionary, a word followed by a ": " followed by its definition, a number of space seperated words.

You should read from standard input.

### Output

Output a single integer, the number of words in the dictionary that are learnable.

### Constraints

For Subtask 1 (50 points):

- 2 ≤ N ≤ 1000 

For Subtask 2 (50 points):

- 2 ≤ N ≤ 20,000

For all test cases:

- Each line will contain 2 to 10 words
- Each word consists of 1 to 10 english characters

### Sample Input 1

```
3
9 6 5
portcullis: a strong heavy grating that blocks a gateway
heavy: difficult to lift or move
grating: sounding harsh and unpleasant
```

### Sample Output 1

```
3
```

### Explanation 1

None of the words in the definition for "heavy" have entries in the dictionary. The same is true for "grating". So both "heavy" and "grating" are learnable. All words in the definition for "portcullis" also do not have entries except for the words "heavy" and "grating", however these words are learnable, hence "portcullis" is learnable. All 3 words are learnable.

### Sample Input 2

```
5
5 5 5 6 4 
plumbus: a type of clumbus
clumbus: a type of glumbus
glumbus: a type of plumbus
type: a way to classify things
things: plural of thing
```

### Sample Output 2

```
2
```

### Explanation 2

There are only 2 words in the dictionary that are learnable: "things" and "type".

# Attribution
- problem design - Ashley Clayton
- problem statement - Ashley Clayton
- solutions - Ashley Clayton, Bat-Erdene Batsukh, Frank Zhang
- testcase data - Ashley Clayton
- validator - Ashley Clayton
- proofreaders - Bat-Erdene Batsukh

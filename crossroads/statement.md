**Program time limit: 1 second**

**Program memory limit: 512 MB**

The final rune is entered and the ancient city walls solemnly melt away, the magic that held them together now resolved.
Ahead of the entrance is yet another ancient defense, a dark chasm that blocks the path to 3 passageways in the distance.

Elspeth remembers that she can summon a levitating, glowing set of crossroads consisting of a horizontal and vertical road of odd length $n$, meeting at the center. For $n = 5$ it looks like this.

```
..#..
..#..
#####
..#..
..#..
```

Perhaps this can connect her to the distant passageways?

### Input

- The first and only line contains a single odd integer $n$, the size of the crossroads.

### Constraints

For all test cases:

- $1 \le n \le 999$.
- n is always odd.

### Output

Output the glowing crossroad of length $n$. The crossroads should consist of '#' symbols, and all empty space should consist of '.'

### Templates

You should read from standard input and write to standard output.

In Python, you could use the following code.

```py
# Taking inputs, already done! :D
N = int(input())

# Printing output
print("..#..") # Example top row for n = 5
```

In C or C++, you could use the following code.

```cpp
// Taking inputs, already done! :D
int N; scanf("%d", &N);

// Printing output
printf("..#..\n"); // Example top row for n = 5
```

### Sample Input 1

```
5
```

### Sample Output 1
```
..#..
..#..
#####
..#..
..#..
```

### Explanation 1
The glowing crossroads from the question, consisting of a horizontal and vertical road of length 5 meeting in the center.  

### Sample Input 2

```
3
```

### Sample Output 2 
```
.#.
###
.#.
```

### Explanation 2
A smaller set of glowing crossroads of size 3. 


### Scoring

Your program will be run on the sample cases and all secret cases one after another, and if it produces the correct output for **all** test cases, it solves this task. Recall that your final score on the task is the score of your highest scoring submission.

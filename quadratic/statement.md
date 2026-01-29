**Program time limit: 1 second**

**Program memory limit: 512 MB**

Elspeth looks up and notices some runes carved into the city wall.

$$(2x - 1)(x + 4)$$

"At last!" she exclaimed. "I knew year 9 maths would come in handy some day!".
Her prior knowledge tells her that the expression expands out to

$$2x^2 + 7x - 4$$

but after outputting each coefficient, more factorisations take its place.

Could this be key to unlocking the ancient city?
Help Elspeth expand the quadratics.

### Input

- The first line contains $4$ integers $x_1, c_1, x_2 and c_2$, where
    - $x_1$ is the coefficient of the first $x$ variable,
    - $c_1$ is the value of the first constant,
    - $x_2$ is the coefficient of the second $x$ variable, and
    - $c_2$ is the value of the second constant.

### Constraints

For all test cases:

- $-10,000 \le x_1, c_1, x_2, c_2 \le 10,000$.

### Output

Ouput each coefficient of the expanded quadratic onto one line separated by spaces (see the samples for reference).

### Templates

You should read from standard input and write to standard output.

In Python, you could use the following code.

```py
# Taking inputs, already done! :D
x1, c1, x2, c2 = map(int, input().split())

coeff1 = 0
coeff2 = 0
coeff3 = 0
# Write your code here


# Printing output
print(coeff1, coeff2, coeff3)
```

In C or C++, you could use the following code.

```cpp
// Taking inputs, already done! :D
int N; scanf("%d", &N);
int A[N]; for (int i = 0; i < N; i++) scanf("%d", &A[i]);
int B[N]; for (int i = 0; i < N; i++) scanf("%d", &B[i]);

int coeff1;
int coeff2;
int coeff3;
// Write your code here


// Printing output
printf("%d%d%d\n", coeff1, coeff2, coeff3);
```

### Sample Input 1

```
2 -1 1 4
```

### Sample Output 1

```
2 7 -4
```

### Explanation 1

This input and output corresponds to the example from the question. Expanding $(2x - 1)(x + 4)$ results in $2x^2 + 7x - 4$.

### Sample Input 2 

```
1 5 0 2
```

### Sample Output 2 

```
0 2 10 
```

### Explanation 2 

Some coefficients may be $0$. In this case expanding $(x + 5)(0x + 2)$ results in $2x + 10$.

### Scoring

Your program will be run on the sample cases and all secret cases one after another, and if it produces the correct output for **all** test cases, it solves this task. Recall that your final score on the task is the score of your highest scoring submission.

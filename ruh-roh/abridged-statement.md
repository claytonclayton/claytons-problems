**Program time limit: 1 second**

**Program memory limit: 512 MB**

You have an array, $\texttt{A}$ containing $n$ positive integers. Available to you are $k$ jumps. To jump from index $i$ to $i + \rho$, decrease $\texttt{A[i]}$ by $\rho$. $\rho$ cannot exceed $\texttt{A[i]}$. Begin at index 0 and end at index $n$ (the index after the final element in $\texttt{A}$) in at most $k$ jumps. Complete your journey while minimising the max value of $\texttt{A}$.  

### Input

- The first line contains two integers $n$ and $k$, the size of the array $\texttt{A}$ and the total number of jumps.
- The next line contains $n$ integers where the $i^{th}$ integer is $\texttt{A[i]}$

### Constraints

For all test cases:

- $1 \le n \le 10^6$.
- $1 \le k \le 10^6$.
- $1 \le \texttt{A[i]} \le 10^6$ for all $i$.

### Output

Output one integer, the minimum value of $\texttt{A}$ after completing your journey

### Sample Input 1

### Sample Output 1


### Explanation 1


### Scoring

For each subtask (worth 50% and 50% of points, as per the Constraints section),
your program will be run on multiple secret test cases one after another,
and if it produces the correct output for **all** test cases, it solves that subtask. 
Your program will receive the points for each subtask it solves.
Recall that your final score on the task is the score of your highest scoring submission.


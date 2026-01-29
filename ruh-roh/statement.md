**Program time limit: 1 second**

**Program memory limit: 512 MB**

<p align="center">
    <img src="/static/ro.png" width=50%>
</p>

Ro rows her rose row boat up the rows of a roiling river flow. Ro rows no oars, only Ro's rose is known to Ro, which Ro rows Ro's rose row boat with, rosily. Ro's rose is rosy and old and has only a few rose petals holding on, denoted by rho. Of Ro's woes, not only is there old rose, but rolicking roe cultures in each row that Ro's river flows. Each row has a number of roe denoted by rho. Roused by rampant roes, Ro dons Ro's rose to row Ro's rose row boat from row i to row i + rho, in turn reducing Ro's rose rho by one and reducing row i's roes rho by rho. Rho cannot exceed the current row's roe rho. Call the maximum roe rho of all rows, row roe rho. To put a close to Ro's roe woes, Ro began at the first row and rose up the flow rows with at most rose rho rows until she rowed to row $n$, the row after the final roe row. What is the minimum row roe rho of the roe rows that Ro's rose row boat rose?

### Input

- The first line contains two integers $n$ and $r$, the the number of rows and Ro's initial rose rho.
- The next line contains $n$ integers where the $i^{th}$ integer, $\texttt{row[i]}$ is the number of roe in the $i^{th}$ row 

### Constraints

For all test cases:

- $1 \le n \le 10^6$.
- $1 \le r \le 10^6$.
- $1 \le \texttt{row[i]} \le 10^6$ for all $i$.

### Output

- Output one integer, the minimum value of row roe rho after completing your journey.
- If the rows cannot be traversed in $r$ rows then output -1

### Sample Input 1
```
5 2
3 1 3 2 1
```

### Sample Output 1
```
2
```

### Explanation 1
The minimum row roe rho is 2 because after $r = 2$ optimal rows, which are from row 0 to row 2 to row n,
we will have reduced the roe rho of row 0 to 1 and row 2 to 0. The maximum roe row is now 2.

### Sample Input 2 
```
5 2
3 1 2 1 1
```

### Sample Output 2 
```
-1
```

### Explanation 2 
It is not possible to get to row 6 in under 2 rows, hence the output is -1



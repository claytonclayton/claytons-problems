
### Tragic Square
4128 Problem setters are trying to make a $r \times c$ grid of random numbers to be used as test case data in the final 4128 24T3 contest. It is the eve of contest and Isaiah is up diligently proof reading all 6741 test case files when he makes a tragic discovery. 

Test case random-51.in contains a $k \times k$ square where every number in some range $[a, a+k^2)$ is used exactly once i.e the square is composed of a series of consecutive numbers. This is not random test case data at all! Isaiah does a full reread and finds even more test cases with these squares.

The contest is deploying soon. Time is of the essence! Help Isaiah in his struggle to find all grids with tragic squares.   

I want to potentially rewrite the flavour so that the 4128 problem setting staff are out celebrating the creation of the contest. and then... "Isaiah is not quick to celebrate and instead dedicates his time proof reading all 6741 test case files."

### Input
The first line contains integers $r$, $c$ and $k$, the dimensions of the grid and the side length of a tragic square.

Each of the next $r$ lines contain $c$ integers, the $j^{th}$ number of the $i^{th}$ row representing the grid number in row $i$ and column $j$.

### Output
If a tragic square exists in the grid, output "YES" followed by two integers, the row and column number of the upper left corner of the tragic square. 

Otherwise, output "NO".

### Constraints
- $1 \le r, c \le 3000$
- $k \le min(r, c)$

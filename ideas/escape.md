
## Greatest Escape

There are n rooms placed left to right separated by n doors where the i^{th} door connects the i^{th} and (i + 1)^{th} rooms. The final door leads to the outside. Each door has some non negative integer time value t_{i}, where each t_{i} is zero or unique to all non-zero t_{i}. 

There is a prisoner in the first room and your objective is to construct a sufficiently dazzling escape for him, while installing the cheapedst doors possible. Before the escape begins you must replace all t_{i} == 0 doors with doors of some fixed time value p >= 1. The cost of replacing these doors is equal to p.

The escape begins! At each second of the escape you may choose to open zero or one doors. The i^{th} door will remain open for t_{i} seconds. If a door is opened in front of the prisoner, he will walk through it in one second, however if in front of him he sees several consecutive doors that are all open, he will dash through all of them in one second until he reaches a door that is closed. The escape ends when the prisoner reaches the outside. The dazzlingness of an escape is the maximum number of doors the prisoner goes though in one second throughout the duration of the escape.

Your sick twisted boss who is overseeing this strange operation wants the dazzlingness of the escape to be at least k, but you know that the company you work for that helps prisoners escape in dazzling fashion will go bankrupt if you buy the most expensive doors possible. Install the cheapest doors possible that admits an escape with dazzlingness of at least k.

## TL;DR Version.
You have an array t of size n containing non negative integers, where each t_{i} is either 0 or unique to all other non zero t_{i}. You must replace all t_{i} == 0 elements with some p >= 1 (after replacing there will be a number of elements == p equal to the number of elements == 0 where each element == 0 used to be). 

The dazzlingness of an array is the length of the longest subarray such that when you sort it, all elements in that new sorted subarray s have s_{j} >= j. Minimise p such that the dazzlingness of an array is at least k. 

### Inputs
The first line contains integers n and k, the size of the array t and the target dazzlingness respectively.
The next line contains n non-negative integers where the i^{th} integer is t_{i}.

### Constraints
- 1 <= n, k <= 10^5

### Output
The minimal p such that the dazzlingness of t is at least k.

### Solution
Consider an array with only unique integers. It will always have dazzlingness n, since in the worst case all elements in the range [1, n] are present in the array and so when it is sorted all s_{j} == j. Thus if there is a value p that has duplicate instances, then some s_{j} == p will be the first element in s that could have s_{j} < j. The position of the latest s_{j} == p is the number of elements <= p. Hence in order for a subarray to have the dazzling property, then the number of its elements <= p must be <= p. 

Replace the 0-elements with a fixed p. We can test if the array has a subarray of size k with the dazzling property by maintaining a sliding window of size k, maintaining a count of the number of elements <= p. If at any point the count is <= p then the array has a dazzlingness of at least k. 

Since the dazzling property is monotonic in p, then we can binary search the result. p will be at most the greatest element in t plus O(n), lets call this number T (I suspect there is a lower bound for T). Hence the algorithm runs in O(nlog(T)). 

### epic 3121 style monotonicity proof!!1!!11!!
For clarity, let the function dazzling(p) = true when t[0 := p] contains a subarray s of length k such that when s is sorted, all s_{j} >= j. Let dazzling(p) = false otherwise. The position of the the last p in the sorted subarray s will be number of its elements that are <= p. Let pos(p) be the number of elements in s that are <= p.

1. Prove dazzling(p) => dazzling(p + 1)
    If dazzling(p) then there exists a subarray of length k with pos(p) <= p. Since non 0-elements are unique, in that subarray there will either be at most one non 0-element == p and at most one non 0-element == p + 1. Hence in t[0 := p + 1] pos(p + 1) will be at most pos(p) + 1 <= p + 1. Hence dazzling(p) => dazzling(p + 1) 

2. Prove NOT dazzling(p) => NOT dazzling(p - 1)
    If NOT dazzling(p) then all subarrays of length k are such that pos(p) is > p. Again since non 0-elements are unique, in those subarrays there will either be at most one non 0-element == p and at most one non 0-element == p - 1. Hence in t[0 := p - 1], pos(p - 1) in any of those subarrays will be at least pos(p) - 1 > p - 1. Hence NOT dazzling(p) => NOT dazzling(p - 1). 

Hence dazzling(p) is monotonic in p and we can binary search for the least p such that dazzling(p) = true.


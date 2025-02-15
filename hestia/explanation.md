
## 2-pointer solution in $O(n^2)$:
Consider the simpler problem, "How many triples i, j, k are there in array a (where i < j < k is NOT necessarily true) such that a[i] * a[j] = a[k] ?". This question is effectively the same as the original except we are not constrained by the relative ordering of the triple (the search space is also larger since nC3 < nP3, but this does not matter). 

Since we know that if a[i] * a[j] = a[k], then we know that both a[i] and a[j] are <= a[k], hence if we know that if b = sort(a) and a b[k] belongs to a satisfying triple, then the other b[i], b[j] in this triple must satisfy i, j < k. We can use a two pointer method to find these b[i], b[j].

To find all satisfying i, j for a given k in a sorted array b = sort(a), consider the pair i = 1, j = k - 1 (1-indexed). We can repeatedly do the two pointer thing where we compare if i * j < k, then increase i, if i * j > k, then decrease j and if i * j == k, then a satisfying triple has been found (see solutions/accepted/clayton.cpp for further steps here). However the original question cares about the ordering of the triple. Fortunately we only need to store the index of each array element of the original array in the sorted array to account for this. As long as both i, j in b have lesser original index than the orignal index of k, then they form a satisfying triple in a.

The two pointer method takes O(n) and we need to calculate it for each k <= n, hence the algorithm is O(n^2)

## Slow hashmap/treeset solution in $O(n^2 logn) ?
You can do some wacky hashmap stuff to solve this, but you have to do O(n^2) queries with worst case O(logn) for each each query, so these solutions typically time out the test case data. But there are probably clever seed things you can do to minimise query times. 


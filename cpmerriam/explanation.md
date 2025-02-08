
## Explanation
A word will be learnable iff none of its dependecies are contained within cycles. 
More specifically, if we draw directed edges from each parent word to each child word contained within its parent's definition that is also contained in the dictionary (i.e not an obvious word), then if all a parent's child words are learnable then the parent is learnable. Thus, a word will not be learnable if the word's definition depends on itself, i.e it belongs to a cycle. Since these words cannot be learnt, then all of their ancestors cannot be learnt. 

Use dfs to find all learnable words. A word is not learnable if one of its descendents is an ancestor, or if dfs performed on any of its children outputs false.

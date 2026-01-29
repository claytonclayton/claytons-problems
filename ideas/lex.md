## Lex
You have a large string A, some k <= |A|, and an empty string B. You have one operation. Remove the first character of A and append it to the end of B followed by deleting some number p characters from the front of A where p <= k. Your goal is to make B as lexicographically small as possible, while ensuring that the first and last characters of A are the same as the first and last characters of B respectively. The first and last characters of A appear only once each in A.

## Initial Sol
In order for B to be as lexicographically small as possible, then it must have size as small as possible. Therefore it will have |A| // k + 1 characters (probably some off by one error here). Set rem = |A| mod k. Use a greedy approach to select the rightmost lexicographically smallest character at index p such that k - p <= rem. Set rem -= k - p and continue until the final character is reached. Kinda sucky explanation but i'm pretty sure it's right.

## Why this doesn't make sense
*In order for B to be as lexicographically small as possible, then it must have size as small as possible.* - THIS IS NOT TRUE

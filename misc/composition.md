
## "Composition is the essence of programming"

In the programming language Haskell we can compose two functions g and f by placing a dot inbetween them.

g ∘ f = g . f

We want to create a type-checking expression by composing the functions si, is, ii and ss each with types 

si :: String -> Int
is :: Int -> String
ii :: Int -> Int
ss :: String -> String

For example one of these expressions might be

si . is 

is takes in an Int, outputs a String, then gives that String to si, which then finally outputs an Int. 

A longer example might be

si . ss . is . ii . ii . si

If we can use the functions si, is, ii, and ss a total of n, m, p, and q times respectively how many unique expressions can we make?


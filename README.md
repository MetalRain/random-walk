# Generate random walk in constricted matrix

I saw some person asking for advise in homework and I thought that is nice problem for me to solve.

I don't have exact task definition anymore, but it was something like:

```
Create program that prints random walk A-Z in 10x10 matrix
Starting from random location
Walk must be contiguous
```

So essentially this is exercise in search and backtracking.

My solution tries to use least amount of memory, only storing offsets for the walk and some temporary variables.

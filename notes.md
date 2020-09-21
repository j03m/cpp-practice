# General tips

Consider questions carefully. 

Ask another way

Don't assume you have to take a hard route

> g++ -std=c++11 your_file.cpp -o your_program

# big o

* Remember to think about best and worst case scenarios. 

## space complexity 

* N is then number of variables

* A fixed number of variables is constant space o(1)
* When size of something scales with the input its o(n)
* The input is not taken into account. NEW storage only. a find function for example is constant storage (unless you are doing something crazy)


## N^2 avoidance

Can I use a map to avoid the 2nd inner loop? 2n is better than n^2
Are you considering balance? Can one loop with back storage solve the issue?
Look for an insight? Reverse the string first, what happens if we sort first?

* Using hash-based data structures, like unordered maps or unordered sets, is so common in coding challenge solutions, it should always be your first thought. Always ask yourself, right from the start: "Can I save time by using an unordered map?"


# Permutations

There are N! variations of permutations in a string. N choices for the first char times N-1 for the 2nd times N-2 for the 3rd etc etc. Brute forcing
gives us O(N!*N) 


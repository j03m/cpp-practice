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


# Shuffling

In the naive case where you randomly select a number from 0 to SIZE on each iteration, you will make SIZE calls to Rand(0, SIZE). This gives you a 
set of outcomes that is SIZE ^ SIZE each being equally probably. But our vector only has SIZE! permutations. (10! is less than 10^10). This indicates that our
shuffle is not uniform. This means "it is a mostly-uniform shuffle where an item is less likely to stay where it started than it is to end up in any 
given slot. Each item should have the same probability of ending up in each spot, including the spot where it starts.". See greedy/in-place-shuffle.cpp



# Partial sorts

When given a partially sorted array of two out of order chunks, you can assuming 0-N-1 are increasing in order and N-M are increasing in order and that
N is less than 0 (otherwise it would be sorted, or out of order in some other way). As such you the problem can be refrased as finding the first instance 
X where position X < position 0. Given [ "k","v","a","b","c","d","e","g","i" ] we are just looking for the first letter that is less than k since we know that 
positions 0-N (in this case 0 to 1) must be increasing. Therefore a is the rotation point of the partially sorted array.

# Trees

## Binary tree

If perfect: 

* Every level doubles the number of nodes. 0 = 2^0 = 1, 1 = 2^1 = 2, 2 = 2^2 = 4, 3 = 2^3 = 8 etc
* The last level is 1/2 + 1 the total nodes in the tree: if 3 levels 2 ^ 3 = 8 vs (1 + 2 + 4 = 7)

###  Traveral 

BFS - finds shortest path, may require more memory, uses queue

DFS - less memory, uses a stack
    inorder: left, then right which means we push the right onto the stack first
    postorder: right, then left which means we push the left onto the stack first 
consider: 
```
   1
  / \  
 2   3
      \
       4
```    

Iterative DFS, with stack, preorder: 1,2,3,4 (note preorder requires right first push)
```
    Stack starts: [1]  
    while(stack not empty)
        1st iteration:
            pop (stack[])
            write: 1
            push right (stack[3])
            push left (stack[3,2])
        2nd iteration:
            pop (stack[3])
            write: 2
            no child, continue
        2nd iteration:
            pop (stack[])
            write: 3
            push right (stack[4])
            no left 
        3rd iteration:
            pop(stack[])
            write: 4
        Stack remains empty, loop ends
 ```

Iterative BFS using a queue, preorder, left first add to queue
```
    queue starts: [1]  
    while(queue not empty)
        1st iteration:
            shift (stack[])
            write: 1
            add left (stack[2])
            add right (stack[2,3])
        2nd iteration:
            shift (stack[3])
            write: 2
            no children, continue
        2nd iteration:
            pop (stack[])
            write: 3
            push right (stack[4])
        3rd iteration:
            shift(stack[])
            write: 4
        Stack remains empty, loop ends
 ```

### Binary Search Trees

Binary tree with ordered nodes. 

BSTs are valid if:

* if a node is in the ancestor's left subtree, then it must be less than the ancestor, and
* if a node is in the ancestor's right subtree, then it must be greater than the ancestor.

Searching is binary search but instead of splitting in half, you walk in a direction.

Note, when checking if something is a bst you need to be careful. A node can be say, greater than its parent and on
the right, but also greater than the parents parent. For example:

                50
                /\
              30  80
              /\
            20   60
            
60 is > 50 and belongs in the right of the tree!
            
## Random Tree Thoughts

Sometimes you need a BST, sometimes you need a DST (and with varying thoughts on pre, in and post order traversals)

(TODO: get bullet proof on pre, post and in order definitions, basically is where you descend vs push/queue)

but also sometimes you just need to talk the tree. (find the largest for example)
            
            
## Graphs 


### Degrees

The degree of a node is the number of edges connected to the node.

The maximum degree of a graph is the highest degree of all the nodes

In a directed graph, nodes have an indegree and an outdegree.

### Coloring

Graph coloring is when you assign colors to the nodes in a graph.

A legal coloring means no adjacent nodes have the same color.

Edge coloring is less common, but it's also a thing. A legal edge coloring means no nodes have two edges with the same color.

"Legal coloring" depends on the number of colors and the edge factor. If the edge factor is D you need at least D+1 colors for legal coloring so 
that there is always one color not taken by neighbors.

### Paths

Both BFS and DFS will eventually find a path if one exists. The difference between the two is:
    
    BFS always finds the shortest path.
    DFS usually uses less space. 
    
    TODO: Next understand the runtime for graph coloring
    TODO: Move on to shortest path
    
    
### Recursion

A recursive stack of N gives you a memory cost of O(N)

Recursive fibonacci is 2^n because it forks out like a binary tree

Naive impl:
```
int fib(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
```

Re-review memoize in c++

### Stacks

You can always reverse a stack with another stack by popping off and pushing on stack 2
 

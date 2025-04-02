# Binary Trees

- Binary Tress are nonlinear and not positionally oriented  
- Traverse: Pre-order, inorder, Post-order  
- Perfect, Full and Complete trees (see Trees for more)  
- Time complexity : O(logn)  

## Removing a node:

- Removing a node is more involved than adding  
- First you must search the tree to find the node  
- After finding there are 3 possibilities: leaf, internal with one child, internal with two children

### Leaf:

1. Find it
2. Delete it
3. Set parent pointer to NULL

### Internal with 1 child:
1. Find Node
2. Have parent node point to the child  
3. Delete node

### Internal with 2 children:
1. Find Node  
2. Find another node that is easy to remove, a leaf or a node with one child.
3. Swap contents of the node
4. Remove node

## Binary Search Trees:

Binary trees have many great uses, however, searching for a particular item is NOT one of them.  

- Binary Search Trees (BST), which will organize data in the tree by value to faciliate more efficient searching  
- BST allows searching from left to right.
## TREE ADT

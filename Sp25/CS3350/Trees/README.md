# Trees

## Hierarchical Data Structure
A tree is a hierarchical data structure that represents relationships between elements. Some common examples include:

- **Family Tree** (parent-child relationships)
- **Organizational Charts** (supervisors and subordinates)
- **File Systems** (folders and files hierarchy)

## Nature View of a Tree
A tree in computer science is often visualized upside down compared to a natural tree:

- **Root** is at the top
- **Branches** are in the middle
- **Leaves** are at the bottom

## Tree Terminology

- **Root**: The top node without a parent
- **Internal Node**: A node with at least one child
- **External Node (Leaf)**: A node without children
- **Siblings**: Nodes at the same level with the same parent
- **Ancestors**: A node's parent, grandparent, great-grandparent, etc.
- **Descendants**: A node's child, grandchild, great-grandchild, etc.
- **Depth of a Node**: The number of ancestors (or edges from the root to the node)
- **Height of a Tree**: The maximum depth of any node in the tree
- **Edges**: The lines connecting nodes
- **Subtree**: A tree formed from a node and its descendants

## Applications of Trees

- **Organization Charts**
- **File Systems**
- **Data Compression (Huffman Encoding)**
- **Expression Trees (Compilers and Calculators)**
- **Search Operations (Binary Search Trees, B-Trees)**
- **Artificial Intelligence (Decision Trees)**

## Types of Trees

### General Tree
A tree where each node can have an arbitrary number of children.

### N-ary Tree
A tree where each node can have at most `n` children.

### Binary Tree
A tree with the following properties:

- Each node has at most **two** children: left and right.
- A binary tree consists of a root node and left/right subtrees.

#### Types of Binary Trees

1. **Full Binary Tree**: Each node has either `0` or `2` children.
2. **Perfect Binary Tree**: All internal nodes have exactly two children, and all leaves are at the same level.
3. **Complete Binary Tree**: All levels are completely filled except possibly the last level, which is filled from left to right.
4. **Balanced Binary Tree**: The height difference between the left and right subtrees of any node is at most `1`.
5. **Degenerate (or Skewed) Tree**: A tree where each parent node has only one child, making it resemble a linked list.

## Tree Traversal Methods

### Depth-First Traversal

1. **Preorder**: `Root → Left → Right`
2. **Inorder**: `Left → Root → Right`
3. **Postorder**: `Left → Right → Root`

### Breadth-First Traversal

- **Level Order Traversal**: Visits nodes level by level from top to bottom.


# Binary Search Tree (BST) Template Class in C++

## Project Overview

This project implements a Binary Search Tree (BST) as a template class in C++. The BST supports various operations such as insertion, removal, and searches using recursion. It is designed to follow the class declarations provided in the assignment specification.

## Class Specifications

- `BST.h`: Header file containing the template class definition and member function declarations.

## Features

- **Constructor**: Initializes an empty BST.
- **Destructor**: Removes all elements, deallocating memory.
- **Copy Constructor**: Clones a BST from another.
- **Overloaded Assignment Operator**: Assigns one BST to another.
- **Insert**: Adds elements to the BST (no duplicates).
- **Contains**: Searches for an element in the BST.
- **Remove**: Deletes an element from the BST.
- **Empty**: Checks if the BST is empty.
- **Size**: Returns the number of nodes.
- **GetLeafCount**: Counts leaf nodes (no children).
- **GetHeight**: Calculates the height of the tree.
- **GetLevel**: Finds the level of a given node.
- **Traversals**: InOrder, PreOrder, and PostOrder traversals returning a string representation.
- **GetAncestors**: Retrieves ancestors of a given node as a string.

## Implementation Details

- Recursion is used for `contains`, `insert`, and traversal methods.
- The `remove` method can be implemented iteratively or recursively.
- Node comparison supports primitive data types and strings.
- Size is determined by traversing the BST, not stored as a private variable.


## Testing

The included test driver (`p2.cpp`) interacts with the user to perform various operations on the BST and verify its functionality.


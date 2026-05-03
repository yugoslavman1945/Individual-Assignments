# BST Word Count Assignment

## 1. Project Overview

This program implements a custom binary search tree to count words in text files.
The project includes:
- A 'Node' class to represent individual nodes of the tree.
- A 'BST' class to use Nodes and setup the tree.
- A 'driver.cpp' to handle user interaction.
- A makefile to help with building the project.

## 2. How to Compile

```bash
make
```
To clean the build:
```bash
make clean
```

## 3. How to Run
```bash
./bst
```
You will then see a menu:
```
1.Insert
2.Find
3.Delete
4.Print
5.Min
6.Max
7.Save
8.Load File
0.Exit
```
## 4. Program Design

### 4.1 Node Class

The 'Node' class represents each element in the binary search tree.

Attributes:
- 'string key' = the word
- 'int data' = frequency count
- 'Node* left' = left child
- 'Node* right' = right child

Constructor:
Initializes the node with a key and value, and sets child pointers to 'nullptr'.

### 4.2 BST Class

This class manages the BST and provides all core functionality.

Private Members:
- Node* root = roote of the tree

Helper Functions:
- setHelper = recursive insertion
- findHelper = recursive search
- printHelper = in-order traversal
- deleteHelper = handles node deletion cases
- destroyTree = frees memory
- findMin / findMax = locate smallest / largest key
- saveHelper = writes tree contents to file

Public Functions:
- set(key, value) = insert/update value
- find(key) = return value for key
- remove(key) = delete a node
- print() = display all nodes (sorted)
- min() / max() = print smallest / largest key
- save_file(filename) = save contents to file
- operator[] = inserts key if missing and returns reference to value

### 4.3 Main Driver
The driver.cpp file provides a menu-driven interface.
It allows users to:
- Interact with the BST manually
- Load text files
- Perform operations dynamically

It also includes:
- cleanWord() function
  - Removes punctuation
  - Converts characters to lowercase
  - Ensures consistent word formatting

- loadFile() function
  - Reads words from a file
  - Cleans each word
  - Uses 'tree[word]++' to count occurences

### 4.4 File Storage

The program supports saving BST data to a file.
Format:
```
word count
example 5
tree 2
```

- Data is stored using in-order traversal
- Output is sorted alphabetically by key

## 5. Error Handling

- If a key is not found, find() returns 0.
- Empty tree operations (like min() or max()) are safely handled.
- File input is assumed valid (basic implementation).
- Memory is properly managed using a destructor to avoid leaks.

## 6. Challenges Encountered

- Implementing recursive tree operations correctly
- Handling all deletion cases:
  - Leaf Node
  - One child
  - Two children
- Designing 'operator[]' to both insert and return a reference
- Cleaning input text to ensure consistent word counting
- Managing dynamic memory safely

## 7. Files
```
project/
│──driver.cpp
│──BST.cpp
│──BST.h
│──Node.cpp
│──Node.h
│──makefile
└──README.md
```

## 8. References
- Previous assignments in class
- Course materials from instructor
- assignment source files from csci222

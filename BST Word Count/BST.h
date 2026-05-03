#ifndef BST_H
#define BST_H

#include "Node.h"
#include <string>
#include <fstream>
using namespace std;

class BinarySearchTree
{
private:
    Node* root;

    void setHelper(Node*& current, string key, int value);
    int findHelper(Node* current, string key);
    void printHelper(Node* current);
    void destroyTree(Node* current);
    void deleteHelper(Node*& current, string key);
    Node* findMin(Node* current);
    Node* findMax(Node* current);
    void saveHelper(Node* current, ofstream& out);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void set(string key, int value);
    int find(string key);
    void print();
    void min();
    void max();
    void save_file(string filename);
    void remove(string key);

    int& operator[](string key); // bonus
};

#endif

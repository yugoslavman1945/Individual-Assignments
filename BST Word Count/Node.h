#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
public:
    string key;
    int data;
    Node* left;
    Node* right;

    Node(string key, int value);
};

#endif

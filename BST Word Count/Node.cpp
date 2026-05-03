#include "Node.h"

Node::Node(string key, int value)
{
    this->key = key;
    this->data = value;
    left = nullptr;
    right = nullptr;
}

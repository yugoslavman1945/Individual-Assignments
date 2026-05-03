#include "BST.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

void BinarySearchTree::destroyTree(Node* current)
{
    if (!current) return;
    destroyTree(current->left);
    destroyTree(current->right);
    delete current;
}

// ---------- SET ----------
void BinarySearchTree::set(string key, int value)
{
    setHelper(root, key, value);
}

void BinarySearchTree::setHelper(Node*& current, string key, int value)
{
    if (!current)
    {
        current = new Node(key, value);
        return;
    }

    if (key < current->key)
        setHelper(current->left, key, value);
    else if (key > current->key)
        setHelper(current->right, key, value);
    else
        current->data = value;
}

// ---------- FIND ----------
int BinarySearchTree::find(string key)
{
    return findHelper(root, key);
}

int BinarySearchTree::findHelper(Node* current, string key)
{
    if (!current) return 0;

    if (key == current->key)
        return current->data;
    else if (key < current->key)
        return findHelper(current->left, key);
    else
        return findHelper(current->right, key);
}

// ---------- PRINT ----------
void BinarySearchTree::print()
{
    printHelper(root);
}

void BinarySearchTree::printHelper(Node* current)
{
    if (!current) return;
    printHelper(current->left);
    cout << current->key << ": " << current->data << endl;
    printHelper(current->right);
}

// ---------- MIN / MAX ----------
void BinarySearchTree::min()
{
    Node* current = findMin(root);
    if (current)
        cout << "Min: " << current->key << endl;
}

void BinarySearchTree::max()
{
    Node* current = findMax(root);
    if (current)
        cout << "Max: " << current->key << endl;
}

Node* BinarySearchTree::findMin(Node* current)
{
    while (current && current->left)
        current = current->left;
    return current;
}

Node* BinarySearchTree::findMax(Node* current)
{
    while (current && current->right)
        current = current->right;
    return current;
}

// ---------- DELETE ----------
void BinarySearchTree::remove(string key)
{
    deleteHelper(root, key);
}

void BinarySearchTree::deleteHelper(Node*& current, string key)
{
    if (!current) return;

    if (key < current->key)
        deleteHelper(current->left, key);
    else if (key > current->key)
        deleteHelper(current->right, key);
    else
    {
        if (!current->left && !current->right)
        {
            delete current;
            current = nullptr;
        }
        else if (!current->left)
        {
            Node* temp = current;
            current = current->right;
            delete temp;
        }
        else if (!current->right)
        {
            Node* temp = current;
            current = current->left;
            delete temp;
        }
        else
        {
            Node* temp = findMin(current->right);
            current->key = temp->key;
            current->data = temp->data;
            deleteHelper(current->right, temp->key);
        }
    }
}

// ---------- SAVE ----------
void BinarySearchTree::save_file(string filename)
{
    ofstream out(filename);
    saveHelper(root, out);
    out.close();
}

void BinarySearchTree::saveHelper(Node* current, ofstream& out)
{
    if (!current) return;
    saveHelper(current->left, out);
    out << current->key << " " << current->data << endl;
    saveHelper(current->right, out);
}

// ---------- OPERATOR[] ----------
int& BinarySearchTree::operator[](string key)
{
    Node* current = root;
    Node* parent = nullptr;

    while (current)
    {
        if (key == current->key)
            return current->data;
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    Node* newNode = new Node(key, 0);

    if (!parent)
        root = newNode;
    else if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return newNode->data;
}

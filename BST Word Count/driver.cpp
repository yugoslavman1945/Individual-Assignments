#include "BST.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

string cleanWord(string word)
{
    string result;
    for (char c : word)
    {
        if (isalpha(c) || c == '\'')
            result += tolower(c);
    }
    return result;
}

void loadFile(BinarySearchTree& tree, string filename)
{
    ifstream file(filename);
    string word;

    while (file >> word)
    {
        word = cleanWord(word);
        if (!word.empty())
            tree[word]++;
    }

    file.close();
}

int main()
{
    BinarySearchTree tree;
    int choice;
    string key, filename;
    int value;

    do
    {
        cout << "\n1.Insert\n2.Find\n3.Delete\n4.Print\n5.Min\n6.Max\n7.Save\n8.Load File\n0.Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Key: ";
                cin >> key;
                cout << "Value: ";
                cin >> value;
                tree.set(key, value);
                break;

            case 2:
                cout << "Key: ";
                cin >> key;
                cout << "Value: " << tree.find(key) << endl;
                break;

            case 3:
                cout << "Key: ";
                cin >> key;
                tree.remove(key);
                break;

            case 4:
                tree.print();
                break;

            case 5:
                tree.min();
                break;

            case 6:
                tree.max();
                break;

            case 7:
                cout << "Filename: ";
                cin >> filename;
                tree.save_file(filename);
                break;

            case 8:
                cout << "Filename: ";
                cin >> filename;
                loadFile(tree, filename);
                break;
        }

    } while (choice != 0);

    return 0;
}

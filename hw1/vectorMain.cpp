/***************************************************************
 * File: main.cpp
 * Description:
 *    Automated test driver for Vector class.
 *    Demonstrates:
 *      - push_back (1000+ elements)
 *      - operator[]
 *      - size()
 *      - assignment operator
 *      - copy constructor
 ***************************************************************/

#include <iostream>
#include "Vector.h"

using namespace std;

/***************************************************************
 * Helper Function: printVector
 * Description:
 *    Prints all elements of vector using size()
 ***************************************************************/
void printVector(Vector &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "===== Testing push_back with 1000 integers =====" << endl;

    Vector v;

    // Automatically push 1000 integers
    for (int i = 0; i < 1000; i++)
    {
        v.push_back(i);
    }

    cout << "Size after 1000 inserts: " << v.size() << endl;
    cout << "Capacity after growth: " << v.capacity() << endl;

    cout << "\n===== Testing operator[] modification =====" << endl;

    // Modify some elements using []
    v[0] = 9999;
    v[500] = 8888;

    cout << "First element: " << v[0] << endl;
    cout << "Element 500: " << v[500] << endl;

    cout << "\n===== Testing Copy Constructor =====" << endl;

    Vector copyVector(v);   // Copy constructor
    cout << "Copy size: " << copyVector.size() << endl;
    cout << "Copy first element: " << copyVector[0] << endl;

    cout << "\n===== Testing Assignment Operator =====" << endl;

    Vector assignedVector;
    assignedVector = v;     // Assignment operator

    cout << "Assigned size: " << assignedVector.size() << endl;
    cout << "Assigned element 500: " << assignedVector[500] << endl;

    cout << "\n===== Printing First 10 Elements =====" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "\nAll tests completed successfully." << endl;

    return 0;
}

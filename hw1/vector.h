/***************************************************************
 * File: Vector.h
 * Author: Your Name
 * Description:
 *    Header file for Vector class. Implements a simplified
 *    version of std::vector for integers.
 ***************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    int *vec_ptr;          // Points to the dynamic array
    int vec_size;          // Number of elements currently stored
    int vec_capacity;      // Allocated storage capacity

public:

    /***************************************************************
     * Method: Vector (Default Constructor)
     * Description:
     *    Initializes an empty vector.
     * Post-conditions:
     *    vec_ptr is NULL, vec_size = 0, vec_capacity = 0.
     ***************************************************************/
    Vector();

    /***************************************************************
     * Method: Vector (Copy Constructor)
     * Description:
     *    Creates a deep copy of another Vector.
     * Post-conditions:
     *    vec_ptr contains a copy of other's data,
     *    vec_size and vec_capacity match other.
     ***************************************************************/
    Vector(const Vector &other);

    /***************************************************************
     * Method: ~Vector (Destructor)
     * Description:
     *    Deallocates dynamic memory used by the vector.
     * Post-conditions:
     *    vec_ptr is deleted, vec_size = 0, vec_capacity = 0.
     ***************************************************************/
    ~Vector();

    /***************************************************************
     * Method: operator=
     * Description:
     *    Overloaded assignment operator.
     *    Performs deep copy of another Vector.
     * Post-conditions:
     *    vec_ptr contains copy of other's data.
     ***************************************************************/
    Vector& operator=(const Vector &other);

    /***************************************************************
     * Method: size
     * Description:
     *    Returns current number of elements in vector.
     ***************************************************************/
    int size();

    /***************************************************************
     * Method: capacity
     * Description:
     *    Returns current capacity of vector.
     ***************************************************************/
    int capacity();

    /***************************************************************
     * Method: push_back
     * Description:
     *    Adds an element to the end of the vector.
     *    If necessary, doubles the capacity first.
     ***************************************************************/
    void push_back(int element);

    /***************************************************************
     * Method: reserve
     * Description:
     *    Resizes capacity to at least n.
     *    Does nothing if n <= current capacity.
     * Post-conditions:
     *    Capacity >= n. Size unchanged.
     ***************************************************************/
    void reserve(int n);

    /***************************************************************
     * Method: operator[]
     * Description:
     *    Returns reference to element at given index.
     ***************************************************************/
    int& operator[](unsigned int index);
};

#endif

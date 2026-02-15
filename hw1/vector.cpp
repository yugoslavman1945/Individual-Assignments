/***************************************************************
 * File: Vector.cpp
 * Description:
 *    Implementation file for Vector class.
 ***************************************************************/

#include "Vector.h"

/***************************************************************
 * Default Constructor
 ***************************************************************/
Vector::Vector()
{
    // Initialize empty vector
    vec_ptr = NULL;
    vec_size = 0;
    vec_capacity = 0;
}

/***************************************************************
 * Copy Constructor
 ***************************************************************/
Vector::Vector(const Vector &other)
{
    // Copy size and capacity
    vec_size = other.vec_size;
    vec_capacity = other.vec_capacity;

    // Allocate new dynamic array if capacity > 0
    if (vec_capacity > 0)
    {
        vec_ptr = new int[vec_capacity];

        // Copy elements one-by-one
        for (int i = 0; i < vec_size; i++)
        {
            vec_ptr[i] = other.vec_ptr[i];
        }
    }
    else
    {
        vec_ptr = NULL;
    }
}

/***************************************************************
 * Destructor
 ***************************************************************/
Vector::~Vector()
{
    // Free dynamic memory
    delete[] vec_ptr;

    // Reset values
    vec_ptr = NULL;
    vec_size = 0;
    vec_capacity = 0;
}

/***************************************************************
 * Assignment Operator
 ***************************************************************/
Vector& Vector::operator=(const Vector &other)
{
    // Protect against self-assignment
    if (this == &other)
        return *this;

    // Free existing memory
    delete[] vec_ptr;

    // Copy size and capacity
    vec_size = other.vec_size;
    vec_capacity = other.vec_capacity;

    // Allocate new memory if needed
    if (vec_capacity > 0)
    {
        vec_ptr = new int[vec_capacity];

        // Copy elements
        for (int i = 0; i < vec_size; i++)
        {
            vec_ptr[i] = other.vec_ptr[i];
        }
    }
    else
    {
        vec_ptr = NULL;
    }

    return *this;
}

/***************************************************************
 * size()
 ***************************************************************/
int Vector::size()
{
    return vec_size;
}

/***************************************************************
 * capacity()
 ***************************************************************/
int Vector::capacity()
{
    return vec_capacity;
}

/***************************************************************
 * push_back()
 ***************************************************************/
void Vector::push_back(int element)
{
    // If no capacity yet, allocate 1
    if (vec_capacity == 0)
    {
        reserve(1);
    }
    // If size equals capacity, double capacity
    else if (vec_size == vec_capacity)
    {
        reserve(vec_capacity * 2);
    }

    // Insert new element at end
    vec_ptr[vec_size] = element;
    vec_size++;
}

/***************************************************************
 * reserve()
 ***************************************************************/
void Vector::reserve(int n)
{
    // Only reallocate if n > current capacity
    if (n <= vec_capacity)
        return;

    // Allocate new array of size n
    int *new_array = new int[n];

    // Copy old elements into new array
    for (int i = 0; i < vec_size; i++)
    {
        new_array[i] = vec_ptr[i];
    }

    // Delete old array
    delete[] vec_ptr;

    // Redirect pointer
    vec_ptr = new_array;
    vec_capacity = n;
}

/***************************************************************
 * operator[]
 ***************************************************************/
int& Vector::operator[](unsigned int index)
{
    return vec_ptr[index];  // No bounds checking (like std::vector[])
}

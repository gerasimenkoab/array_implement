/* Implementation of Array class
   Source file */
#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

#include <cstdlib>
using std::exit;
#include "Array.h"

Array::Array( int arraySize)
{
        //ctor
        arrSize = ( arraySize > 0 ? arraySize : 10 );

        ptr = new int[ arrSize ];
        for(int i = 0; i < arrSize; i++)
                ptr[ i ] = 0;
}

Array::Array(const Array& other)
{
        //copy ctor
        arrSize = other.arrSize;
        ptr = new int[ arrSize ];
        for(int i = 0; i < arrSize; i++)
        {
                ptr[ i ] = other.ptr[ i ];
        }
}

Array::~Array()
{
        //dtor
        delete [] ptr;

}

Array& Array::operator=(const Array& rhs)
{
        if (this == &rhs) return *this; // handle self assignment
        //assignment operator
        delete [] ptr;
        arrSize = rhs.arrSize;
        ptr = new int[ arrSize ];
        for( int i = 0; i < arrSize ; i++)
                ptr[ i ] = rhs.ptr[ i ];
        return *this;
}

const Array Array::operator+(const Array& addTerm)
{
        if( arrSize != addTerm.arrSize)
        {
                cerr << "Composition of arrays of not equal size." << endl;
                exit(1);
        }
        Array result( *this );
        for( int i = 0 ; i < arrSize ; i++)
            result.ptr[ i ] += addTerm.ptr[ i ];
        return result;
}

void Array::printArray()
{
        cout << "array: ";
        for( int i = 0; i < arrSize; i++)
                cout << ptr[i] << ", ";
        cout << endl;
}

istream & operator>>(istream & input, Array & a)
{
    for ( int i = 0 ; i < a.arrSize ; i++)
                input >> a.ptr[ i ];
    return input;
}

ostream & operator<< ( ostream & output, const Array & a)
{
        if (0 == a.arrSize)
        {
                cerr << "Error. Zero length array." << endl;
                exit(1);
        }
        output << "operator<< out array:";
        for(int i = 0; i < a.arrSize; i++)
                output << a.ptr[i] << ", ";
        output << endl;
        return output;
}

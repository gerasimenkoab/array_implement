/* Implementation of Array class
   header file */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::istream;
using std::ostream;

class Array
{
        friend istream & operator>> (istream &input, Array &);
        friend ostream & operator<< (ostream &output, const Array &);
        public:
                explicit Array ( int = 10);
                ~Array();
                Array (const Array& other);
                Array& operator= (const Array& other);
                const Array operator+ ( const Array &);
                void printArray();
        protected:
        private:
                int arrSize;
                int* ptr;
};

#endif // ARRAY_H

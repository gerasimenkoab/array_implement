/* Implementation of Array class.
   Class driver file. */

#include <iostream>
using namespace std;

#include "Array.h"


int main()
{
    Array first(3), sec(3), trd(3);
    first.printArray();
    cin >> first >> sec;
    first.printArray();
    sec.printArray();
    trd = first + sec;
    cout << first << sec <<trd;
    cout << "Hello world!" << endl;

    return 0;
}

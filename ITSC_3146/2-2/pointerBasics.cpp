#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Paul Atkins

int main()
{
    int myInt = 15;
    int * myPointer = &myInt;
    
    cout << "Memory Location of myInt: " << &myInt << endl;
    cout << "Value of myPointer: " << myPointer << endl;
    
    cout << "Value of myInt: " << myInt << endl;
    cout << "Value pointed to myPointer: " << *myPointer << endl;
    
    myInt = 10;
    myPointer = &myInt;
    
    cout << "\nMemory Location of myInt: " << &myInt << endl;
    cout << "Value of myPointer: " << myPointer << endl;
    
    cout << "Value of myInt: " << myInt << endl;
    cout << "Value pointed to: " << *myPointer << endl;
    
    
    return 0;
}
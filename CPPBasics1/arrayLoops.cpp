#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int myArray[10];
    cout << "Enter your 10 numbers." << endl;
    for(int x = 0; x < 10; x++)
    {
        cin >> myArray[x];
    }
    cout << "Here is the reverse order from how they were entered." << endl; 
    
    for(int x = 9; x > -1; x--)
    {
        cout << myArray[x] << " ";
    }
    cout << " " << endl;
    
    sort(myArray, myArray + 10);
    
    cout << "Here is the sorted array" << endl;
    
    for(int x = 0; x < 10; x++)
    {
        cout << myArray[x] << " ";
    }
}
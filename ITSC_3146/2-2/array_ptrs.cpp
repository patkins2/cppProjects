#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Paul Atkins

int main()
{
    int my_ints[4];
    
    cout << "Input 4 values into the array." << endl;
    
    for(int x = 0; x < 4; x++)
    {
        cin >> my_ints[x];
    }
    
    int *my_ptrs[4];
    
    for(int i = 0; i < 4; i++)
    {
        my_ptrs[i]= &my_ints[i];
    }
    
    
    int * placeHolder;
    int y = 0;
    
    do
    {
        for(int x = 0; x < 4; x++) 
        {
            if(*my_ptrs[y] < *my_ptrs[x])
            {
                placeHolder = my_ptrs[y];
                my_ptrs[y] = my_ptrs[x];
                my_ptrs[x] = placeHolder;
            }
        }
        y++;
    }
    while (y < 4);
    
    for(int x = 0; x < 4; x++) 
    {
        cout << *my_ptrs[x] << " ";
    }
    
}
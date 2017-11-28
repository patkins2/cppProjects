#include <iostream>
using namespace std;

//swapInts(int*, int*); 

void swapInts(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    cout << "Enter your two numbers." << endl;
    int num1, num2;
    cin >> num1;
    cin >> num2;
    cout << "Values before swapping: " << num1 << " " << num2;
    swapInts(&num1, &num2);
    cout << "\nSwapped Values: " << num1 << " " << num2 << endl;
    return 0;
}

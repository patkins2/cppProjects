#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Enter your score: ";
    cin >> input;
    int score = input;
    if(score < 60)
    {
        cout << "You got an F.";
    }
    if(score < 70 && score > 59)
    {
        cout << "You got an D.";
    }
    if(score < 80 && score > 69)
    {
        cout << "You got an C.";
    }
    if(score < 90 && score > 79)
    {
        cout << "You got an B.";
    }
    if(score > 89)
    {
        cout << "You got an A.";
    }
    return 0;
}
    
    
    
    
    
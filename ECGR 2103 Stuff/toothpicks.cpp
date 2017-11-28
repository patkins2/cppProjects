#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;

double calcNumOfPicks(double pickVol, double rad, double heigth);


const double pickVol = 0.009204; //volume of toothpick

int main()
{
    double logRad, logHeigth, volFormula, cost = 0; //setting up variables we will need
    
    
    char answer = ' ';
    
    while(answer != 'y')
    {
    
    cout << "\nEnter the Radius of the log in feet: "; //get radius and height from the user
    cin >> logRad;
    
    cout << "Enter the Heigth of the log in feet: "; 
    cin >> logHeigth;
    
    double volFormula = 3.14 * (pow((double)logRad, 2.0)) * (double)logHeigth; //formula for volume
    
    double numOfPicks = calcNumOfPicks(pickVol, logRad, logHeigth); //calculate the number of picks 
    cost = volFormula * 25.0; //calculate the cost
    
    cout << fixed << "You could make " << numOfPicks << " toothpicks." << endl; //output
    
    
    cout << "If this is not enough toothpicks, enter new dimensions." << endl; //ask if they want to enter new dimensions
    cout << "Is this enough toothpicks? Y or N: ";
    
    cin >> answer;
    }
  
 
    cout <<fixed << "This will cost you: $"; //display the cost
    
    printf("%.2f", cost); //rounding to 2 decimal places 
    
    cout << endl;
    
    return 0; //end
}

double calcNumOfPicks(double pickVol, double rad, double heigth)
{
    double volFormula = 3.14 * (pow((double)rad, 2.0)) * (double)heigth; //formula for volume
    
    double logVol = volFormula;
    double feetSqrToInchSqr = logVol * 114; //convert feet squared to inches squared
    
    double numOfPicks = feetSqrToInchSqr / pickVol; //the number of picks
    
    return numOfPicks; // return the number of picks
}
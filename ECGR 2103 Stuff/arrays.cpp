#include <iostream>
using namespace std;
 
int main() {
	int grades[37]; //setting up the array

	for(int x = 0; x < 37; x++) //populating the array
	{
		cout << "Input the grade for student " << x + 1 << ": ";
		cin >> grades[x];
	}
	
	cout << "Setting Student #3's grade to 90" << endl; //setting the third student's grade to 90;
	
	grades[2] = 90;
	
	cout << "Swapping the grades of Student #10 and Student #20" << endl; // completely swapping student 10 and 20
	int temp = grades[9];
	grades[9] = grades[19];
	grades[19] = temp;
 
	cout << "The grade of the last student: "  << grades[36] << endl; //print the grade of the last student
	
	cout << "Everyone's grades" << endl;
	for(int y = 0; y < 37; y++) //print the array
	{
		cout << "Student #" << y+1 << ": " << grades[y] << " " << "\t";
		if((y == 6) || (y == 12 ) || (y == 18) || (y == 24) || (y == 30)) //this is for formatting
		{                                                                 //I'm aware this isn't the best way but I got lazy
		    cout << "\n";
		}
	}
    cout << endl;
	return 0;
}
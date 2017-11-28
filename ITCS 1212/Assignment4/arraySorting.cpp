/**
 * Program: arraySorting.cpp
 * Author: Paul Atkins
 * Date: 12/9/15
 * Purpose: This program takes an arrays and sorts them in 4 different ways.
 *          Linear, Binary, Bubble, and Selection.
 */

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

//Function Prototypes

int menu(); //display the menu
int display(); // display parallel array in table format
void linearSearch();//apply linear search to book id
void binarySearch();//apply binary search to book id
void bubbleSort();//apply bubble sort to array
void selectionSort();//apply selection sort to array

int main() //main function
{
    int menuChoice;
    menuChoice = menu();

    if (menuChoice == 1)
        linearSearch();
    else if (menuChoice == 2)
        binarySearch();
    else if (menuChoice == 3)
        bubbleSort();
    else if (menuChoice== 4)
        selectionSort();
    else if (menuChoice == 5)
        return 0;

    return 0;
}

int menu()
{
    int choice;
    cout << "\n*** SEARCHING AND SORTING MENU ***";
    cout << "\n 1. Linear Search";
    cout << "\n 2. Binary Search";
    cout << "\n 3. Bubble Sort";
    cout << "\n 4. Selection Sort";
    cout << "\n 5. Quit" << endl;

    while (choice > 5 || choice < 1)
    {
        cout << "\nPlease Enter Your Choice: ";
        cin >> choice;
        //ends program with invalid input
        if(choice > 5 || choice < 1)
        {
            cout<< "Invalid Input." << endl;
            exit(0);
        }
    }

    return choice;
}

void linearSearch()
{
    //array of book titles
    string bookTitle[] = {"Starting out with C++","Java Programming","Software Structures",
    "Design and Analysis of Algorithms","Computer Graphics", "Artificial Intelligence: A Modern Approach",
    "Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};

    //Array of book ids
    int bookId[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};

    //array of book prices
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    int searchId;
    cout << "Enter ID to search for: ";
    cin >> searchId;

    int index = 0;
    int position = -1;
    bool bookFound = false;

    while (index < sizeof(bookId) && !bookFound)
    {
        if(bookId[index] == searchId)
        {
            bookFound = true;
            position = index;
        }
        index++;
    }
    if (position == -1)
    {
        cout << "ID not found"<< endl;
    }
    else
    {
        cout << "Position is " << position + 1 << endl;
        for(int i= 0; i < 10; i++)
        {
            if(searchId == bookId[i])
            {
             cout << bookTitle[i] << " $" << bookPrice[i];
            }
    }

    }
    cout << " " << endl;
    main();
}

void binarySearch()
{
    int idSearch;
    cout << "Enter book id to search: ";
    cin >> idSearch;

    //array of book titles
    string bookTitle[] = {"Starting out with C++","Java Programming","Software Structures",
    "Design and Analysis of Algorithms","Computer Graphics", "Artificial Intelligence: A Modern Approach",
    "Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};

    //Array of book ids
    int bookId[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};

    //array of book prices
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    int first = 0;
    int last = (sizeof(bookId)-1);
    int middle;
    int position = -1;
    bool bookFound = false;

    while (!bookFound && first <=last)
    {
        middle = (first + last)/2;

        if (bookId[middle] == idSearch)
        {
            bookFound = true;
            position = middle;
        }
        else if (bookId[middle] > idSearch)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    if (bookFound == false)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Position is "<< position +1 << endl;
        for(int i= 0; i < 10; i++)
        {
         if(idSearch == bookId[i])
         {
             cout << bookTitle[i] << " $" << bookPrice[i];
         }
    }
    }
    cout << " " << endl;
    main();
}
void bubbleSort()
{
    //create the array
    int size = 1000;
    int arraySort[size];

    //populate the array with random numbers
    int randomNumber;
    for (int i=0;i<size;i++)
    {
        randomNumber = 1 + rand()%500;
        arraySort[i] = randomNumber;
    }

    //display the unsorted array
    cout << "Unsorted Array :\n";
    for (int i=0; i<size;i++)
    {
        cout << arraySort[i] << " ";
    }

    // use bubble sort to sort the array
    bool swap;
    int number;
    do
    {
        swap = false;
        for (int i = 0; i < (size -1); i++)
        {
            if (arraySort[i] > arraySort[i+1])
            {
                number = arraySort[i];
                arraySort[i] = arraySort[i+1];
                arraySort[i+1]=number;
                swap = true;
            }
        }
    }
    while (swap);

    // display the sorted array
    cout << "\n Sorted Array\n";
    for (int i = 0; i<size;i++)
    {
        cout << arraySort[i] << " ";
    }

    main();

}

void selectionSort()
{
    //create the array
    int size = 1000;
    int arraySort[size];

    //Populate the array with random numbers
    int randNumber;

    for (int i=0;i<size;i++)
     {
         int randNumber = 1 + rand()%500;
         arraySort[i] = randNumber;
     }

    //Display unsorted array
    cout << "Unsorted Array \n" << endl;
    for (int i=0;i<size;i++)
    {
        cout << arraySort[i] << " ";
    }

    //use selection sort to sort the array
    int minIndex;
    int minNum;

    for (int i = 0; i < (size -1); i++)
    {
        minIndex = i;
        minNum = arraySort[i];
        for (int j=(i+i);j<size;j++)
        {
            if (arraySort[j] < minNum)
            {
                minNum = arraySort[j];
                minIndex = j;
            }
        }
        arraySort[minIndex] = arraySort[i];
        arraySort[i] = minNum;
    }

    //display sorted array
    cout << "\nSorted Array\n";

    for (int i=0;i<size;i++)
    {
        cout << arraySort[i]<<" ";
    }

    main();

}

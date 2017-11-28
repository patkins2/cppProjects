#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>


using namespace std;

/*
Function Prototypes
*/

int menu(); //menu for user
void display(); // display parallel array in table format
void linearSearch();//apply linear search to book id
void binarySearch();//apply binary search to book id
void bubbleSort();//apply bubble sort to array
void selectionSort();//apply selection sort to array

int main()
{
    int menuChoice; //call menu function from user and get their choice
    menuChoice = menu();

    if (menuChoice == 1) // call linear search
    {
        display();
        linearSearch();
    }
    else if (menuChoice == 2) // call binary search
    {
        display();
        binarySearch();
    }
    else if (menuChoice == 3) // call bubble sort
        bubbleSort();
    else if (menuChoice== 4) // call selection sort
        selectionSort();
    else if (menuChoice == 5) // exit program
        exit(0);

    return 0;
}

int menu() // menu for user choice in program
{
    int choice;
    cout << "\n*** SEARCHING AND SORTING MENU ***"<<endl;
    cout << "\n 1. Linear Search";
    cout << "\n 2. Binary Search";
    cout << "\n 3. Bubble Sort";
    cout << "\n 4. Selection Sort";
    cout << "\n 5. Quit" << endl;

    while (choice > 5 || choice < 1) // input validation
    {
        cout << "\nPlease Enter Choice: ";
        cin >> choice;
    }

    return choice;
}
void bubbleSort()
{
    clock_t timeElapsed; // function for timer
    timeElapsed=clock(); //start timer

    //create the array
    int size = 1000;
    int arraySort[size];

    //populate the array with random numbers
    int randomNumber;
    for (int i=0;i<size;i++)
    {
        randomNumber = 1 + rand()%500; // random numbers between 1-500
        arraySort[i] = randomNumber;
    }

    //display the unsorted array
    cout << "\nUnsorted Array :\n";
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
    } while (swap);

    // display the sorted array
    cout << "\n Sorted Array\n";
    for (int i = 0; i<size;i++)
    {
        cout << arraySort[i] << " ";
    }

    timeElapsed = clock() - timeElapsed; // end timer
    cout << "\nTime elapsed :" << ((float)timeElapsed)/CLOCKS_PER_SEC;

    main();
}
void selectionSort()
{
    clock_t timeElapsed; // function for timer
    timeElapsed=clock(); //start timer

    //create the array
    int size = 1000;
    int arraySort[size];

    //Populate the array with random numbers
    int randomNumber;
    for (int i=0;i<size;i++)
     {
         int randomNumber = 1 + rand()%500;
         arraySort[i] = randomNumber;
     }

    //Display unsorted array
    cout << "Unsorted Array \n" << endl;
    for (int i=0;i<size;i++)
    {
        cout << arraySort[i] << " ";
    }

    //use selection sort to sort the array
    int minIndex, minNum;

    for (int i = 0; i < (size -1); i++)
    {
        minIndex = i;
        minNum = arraySort[i];
        for (int j= i+1;j<size;j++)
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

    timeElapsed = clock() - timeElapsed; // end timer
    cout << "\nTime elapsed :" << ((float)timeElapsed)/CLOCKS_PER_SEC;

    main();

}
void binarySearch()
{
    clock_t timeElapsed; // function for timer
    timeElapsed=clock(); //start timer

    int idSearch; // book to search for
    cout << "\nEnter book id :";
    cin >> idSearch;

    int amount; // amount of books to purchase
    cout << "\nEnter amount to purchase: ";
    cin >> amount;

    //array of book titles
    string bookTitle[] = {"Starting out with C++","Java Programming","Software Structures",
"Design and Analysis of Algorithms","Computer Graphics", "Artificial Intelligence: A Modern Approach",
"Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};

    //Array of book ids
    int bookId[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};

    //array of book prices
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    //variables for sorting
    int first = 0;
    int last = (sizeof(bookId)-1);
    int middle;
    int position = -1;
    bool found = false;

    //loop through array
    while (!found && first <=last)
    {
        middle = (first + last)/2;

        if (bookId[middle] == idSearch)
        {
            found = true;
            position = middle;
        }
        else if (bookId[middle] > idSearch)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }

    if (found == false)
        cout << "Not found" << endl;
    else
    {
        cout << "\n Book ID: " << idSearch << "\n Title :" << bookTitle[position] << "\nAmount Purchased :" << amount <<
        "\nPrice :" << bookPrice[position] * amount << endl;
    }

    timeElapsed = clock() - timeElapsed; // end timer
    cout << "\nTime elapsed :" << ((float)timeElapsed)/CLOCKS_PER_SEC;

    main();
}
void linearSearch()
{
    clock_t timeElapsed; // function for timer
    timeElapsed=clock(); //start timer

    int searchId;
    cout << "\nEnter book id :";
    cin >> searchId;

    int amount;
    cout << "\nEnter amount to purchase: ";
    cin >> amount;

    //array of book titles
    string bookTitle[] = {"Starting out with C++","Java Programming","Software Structures",
"Design and Analysis of Algorithms","Computer Graphics", "Artificial Intelligence: A Modern Approach",
"Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};

    //Array of book ids
    int bookId[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};

    //array of book prices
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    int index = 0;
    int position = -1;
    bool found = false;
    //loop for search
    while (index < sizeof(bookId) && !found)
    {
        if(bookId[index] == searchId)
        {
            found = true;
            position = index;
        }
        index++;
    }
    if (position == -1)
    {
        cout << "ID not found"<< endl;
    }
    else
        cout << "\n Book ID: " << searchId << "\n Title :" << bookTitle[position] << "\nAmount Purchased :" << amount <<
        "\nPrice :" << bookPrice[position] * amount << endl;

    timeElapsed = clock() - timeElapsed; // end timer
    cout << "\nTime elapsed :" << ((float)timeElapsed)/CLOCKS_PER_SEC;

    main();
}

void display()
{
     string bookTitle[] = {"Starting out with C++","Java Programming","Software Structures",
"Design and Analysis of Algorithms","Computer Graphics", "Artificial Intelligence: A Modern Approach",
"Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};

    //Array of book ids
    int bookId[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};

    //array of book prices
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};

    cout << "\n\t\t ***BOOKS FOR SALE***" << right << "\nID \tTITLE \t\t\t\t\t\tPRICE" << endl;

    //display arrays
    for (int i=0; i<10; i++)
    {
        cout << bookId[i] << "\t"<< right<<  bookTitle[i]<< "\t\t\t\t" << "$ "<< bookPrice[i] << endl;
    }

}

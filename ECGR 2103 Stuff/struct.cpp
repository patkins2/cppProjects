#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>

using namespace std;

struct Position 
{
        float x;
        float y;
} a, b; 
    
void calcDistance(Position* p, Position* q)
{
    double distance = sqrt(pow(((*q).x - (*p).x), 2) + pow(((*q).y - (*p).y), 2));
    cout << "Distance: " << distance << endl;
}

int main() 
{
    Position a;
    Position * p;
    p = &a;
    Position b;
    Position * q;
    q = &b;
    
    cout << "Enter your first x and y coordinate: " << endl;
    cin >> p->x;
    cin >> p->y;
    
    cout << "Enter your second and y coordinate: " << endl;
    cin >> q->x;
    cin >> q->y;
    
    calcDistance(p, q); //calculates the distance. 
    
    return 0;
}



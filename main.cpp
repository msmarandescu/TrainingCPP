#include <iostream>
#include "Automobil.h"
#include "Audi.h"
#include "Mercedes.h"

void moveObj(Mercedes obj)
{
    cout << "   a object is destroyed:" << endl;
}

int main()
{
    {
        cout << "   create obj a and b:" << endl;
        Mercedes a("benzina", "berlina", "integrala", 220, "full", "4Y1SL65848Z411439","pneumatica");
        Mercedes b("benzina", "berlina", "integrala", 220, "full", "4Y1SL65848Z411439","pneumatica");
        
        cout << endl;
        cout << "   move constructor:"<< endl;
        moveObj(move(a));

        {
            cout << endl;
            cout << "   create object c:"<< endl;
            Mercedes c("", "", "", 0, "", "","");
            cout << "   move asignment operator:"<< endl;
            c = move(b);
            cout << endl;
            cout << "   c object is destroyed:" << endl;
        }cout << endl;

       cout << "   a and b objects are destroyed:" << endl; 
    }
    
    cout << "-----program end-----"<< endl;
    return 0;
}


#include <iostream>
#include "Automobil.h"
#include "Audi.h"
#include "Mercedes.h"



int main()
{
    {   //apelare constructor clasa Automobil:
        Automobil a("benzina", "berlina", "integrala", 220, "full", "4Y1SL65848Z411439");
        cout << "    obj class Automobil was created" << endl; 
    }cout << "end of scope obj Automobil" << endl << endl; 
    
    {   //apelare constructor clasa Audi:
        Audi audi("benzina", "berlina", "integrala", 220, "full", "4Y1SL65848Z411439", "Audi", "A4");
        cout << "   obj class Audi was created" << endl; 
    }cout << "end of scope obj Audi" << endl << endl; 

    {   //apelare constructor clasa Mercedes:
        Mercedes m("motorina", "coupe", "2x4", 180, "full", "5Z1BD65348Z412343", "Pneumatica");
        cout << "   obj class Mercedes was created" << endl; 
    }cout << "end of scope obj Mercedes" << endl << endl; 


    return 0;
}


#include <iostream>
#include "Automobil.h"
#include "Audi.h"
#include "Mercedes.h"



int main()
{
    {
        cout << "    create obj a:" << endl;
        Mercedes a("benzina", "berlina", "integrala", 220, "full", "4Y1SL65848Z411439", "pneumatica");
        cout << "    Initialize obj b with obj a:" << endl;
        Mercedes b { a };
        a.setSuspensie("air");
        cout << "    assign obj b to obj a:" << endl;
        b = a;
        b.PrintDetail();
    }cout << "    end of scope" << endl;


    return 0;
}


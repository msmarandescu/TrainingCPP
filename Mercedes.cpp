#include "Mercedes.h"

Mercedes::Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie) //parameterized constructor
                   :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    cout << "Mercedes()" << endl;
    Suspensie = new string(suspensie);
}

Mercedes::~Mercedes()
{
    std::cout << "~Mercedes()" << std::endl;
    delete Suspensie;
    Suspensie = nullptr;
}

const void Mercedes::PrintDetail()const
{
    Automobil::PrintDetail();
    std::cout << "Tip Suspensie: " <<  *Suspensie << std::endl;
}
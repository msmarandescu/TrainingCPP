#include "Mercedes.h"

Mercedes::Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie) //parameterized constructor
                   :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    cout << "Mercedes()" << endl;
    Suspensie = new string(suspensie);
}

Mercedes::Mercedes (const Mercedes &obj) // copy Constructor
:Automobil(*obj.Combustibil, *obj.Caroserie, *obj.Tractiune, *obj.Putere, *obj.Echipare, *obj.VIN_NR)
{
    cout << "Mercedes(copy Constructor)" << endl;
    Suspensie = new string(*obj.Suspensie);
}

Mercedes& Mercedes::operator=(const Mercedes &obj)// copy assignment operator
{
     cout << "Mercedes(copy assignment operator)" << endl;
    this->Caroserie = new string(*obj.Caroserie);
    this->Combustibil = new string(*obj.Combustibil);
    this->Tractiune = new string(*obj.Tractiune);
    this->Putere = new int(*obj.Putere);
    this->Echipare = new string(*obj.Echipare);
    this->VIN_NR = new string(*obj.VIN_NR);
    this->Suspensie = new string(*obj.Suspensie);

    return *this;
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

void Mercedes::setSuspensie(string s)
{
    if(Suspensie)
    {
        *Suspensie = s;
    }
}
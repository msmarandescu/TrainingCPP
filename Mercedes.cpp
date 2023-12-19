#include "Mercedes.h"

Mercedes::Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie) //parameterized constructor
                   :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    cout << "Mercedes()" << endl;
    Suspensie = new string(suspensie);
}

Mercedes::Mercedes (const Mercedes &obj) // copy Constructor
:Automobil(obj)
{
    cout << "Mercedes(copy Constructor)" << endl;
    Suspensie = new string(*obj.Suspensie);
}

Mercedes& Mercedes::operator=(const Mercedes &obj)// copy assignment operator
{
    if (this != &obj)
    {
        cout << "Mercedes(copy assignment operator)" << endl;
        Automobil::operator=(obj);
        delete Suspensie;
        Suspensie = new string(*obj.Suspensie);
    }
    return *this;
}

Mercedes::Mercedes (Mercedes &&obj) noexcept //move constructor
        :Automobil(move(obj))
{
    cout << "Mercedes(move constructor)" << endl;
    Suspensie = obj.Suspensie;
    obj.Suspensie = nullptr;
}

Mercedes& Mercedes::operator=(Mercedes &&obj) //move assignment operator
{
    cout << "Mercedes(move assignment operator)" << endl;
    if(this != &obj)
    {
        Automobil::operator=(move(obj));
        delete Suspensie;
        Suspensie = obj.Suspensie;
        obj.Suspensie = nullptr;
    }
    return *this;
}

Mercedes::~Mercedes()
{
    std::cout << "~Mercedes()" << std::endl;
    delete Suspensie;
}

const void Mercedes::PrintDetail()const
{
    Automobil::PrintDetail();
    std::cout << "Tip Suspensie: " <<  *Suspensie << std::endl;
}

void Mercedes::setSuspensie(string s)
{
    if(Suspensie != nullptr)
    {
        *Suspensie = s;
    }
}
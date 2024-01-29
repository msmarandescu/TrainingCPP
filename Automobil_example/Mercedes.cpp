#include "Mercedes.h"

Mercedes::Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie) //parameterized constructor
            : Automobil(combustibil, caroserie, tractiune, putere,
                echipare, vinNr)
{
    cout << "Mercedes()" << endl;
    Suspensie = make_unique<string>(suspensie);
}

Mercedes::Mercedes (const Mercedes &obj) // copy Constructor
:Automobil(obj)
{
    cout << "Mercedes(copy Constructor)" << endl;
    Suspensie = make_unique<string>(*obj.Suspensie);
}

Mercedes& Mercedes::operator=(const Mercedes &obj)// copy assignment operator
{
    if (this != &obj)
    {
        cout << "Mercedes(copy assignment operator)" << endl;
        Automobil::operator=(obj);
        Suspensie = make_unique<string>(*obj.Suspensie);
    }
    return *this;
}

Mercedes::Mercedes (Mercedes &&obj) noexcept //move constructor
        :Automobil(move(obj)),
        Suspensie(std::move(obj.Suspensie))
{
    cout << "Mercedes(move constructor)" << endl;
    obj.Suspensie = nullptr;
}

Mercedes& Mercedes::operator=(Mercedes &&obj) //move assignment operator
{
    cout << "Mercedes(move assignment operator)" << endl;
    if(this != &obj)
    {
        Automobil::operator=(std::move(obj));
        Suspensie = std::move(obj.Suspensie);
        obj.Suspensie = nullptr;
    }
    return *this;
}

Mercedes::~Mercedes()
{
    std::cout << "~Mercedes()" << std::endl;
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
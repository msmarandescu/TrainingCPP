#include "Audi.h"

static int objNr = 0;

Audi::Audi(std::string combustibil, std::string caroserie, std::string tractiune, int putere,
           std::string echipare, std::string vinNr, std::string marca, std::string model)
    : Automobil(combustibil, caroserie, tractiune, putere,
                echipare, vinNr)
{
    if(objNr < 1)
    {
        std::cout << "Audi()" << std::endl;
        Marca = make_unique<string>(std::move(marca));
        Model = make_unique<string>(std::move(model));
        objNr++;
    }
    else{
        cout << "Audi() Error: Audi class can have only one obj created!" << endl;
    }
    
}

Audi::Audi (const Audi &obj) // copy Constructor
:Automobil(obj)
{
    cout << "Audi(Copy Constructor)" << endl;
    Marca = std::make_unique<std::string>(*obj.Marca);
    Model = std::make_unique<std::string>(*obj.Model);
}

Audi& Audi::operator=(const Audi &obj) //copy assignment operator
{
    cout << "Audi(copy assignment operator)" << endl;
    if (this != &obj)
    {
        Automobil::operator=(obj);
        Marca = std::make_unique<std::string>(*obj.Marca);
        Model = std::make_unique<std::string>(*obj.Model);
    }
    return *this;
}

Audi::Audi (Audi &&obj)noexcept //move constructor
    : Automobil(std::move(obj)),
      Marca(std::move(obj.Marca)),
      Model(std::move(obj.Model))
{
    std::cout << "Audi(move constructor)" << std::endl;
    obj.Marca = nullptr;
    obj.Model = nullptr;

}

Audi& Audi::operator=(Audi &&obj) //move assignment operator
{
    cout << "Audi(move assignment operator)" << endl;
    if (this != &obj)
    {
        Automobil::operator=(std::move(obj));
        Marca = std::move(obj.Marca);
        Model = std::move(obj.Model);
        obj.Marca = nullptr;
        obj.Model = nullptr;
    }
    return *this;
}

Audi::~Audi() // distructor
{
    std::cout << "~Audi()" << std::endl;
    objNr--;
}

const void Audi::PrintDetail()const
{
    Automobil::PrintDetail();
    std::cout << "Marca: " <<  *Marca << std::endl;
    std::cout << "Model: " <<  *Model << std::endl;
}

const void Audi::printNrOfObjects()const{
    cout << "Number of objects of type Audi :" << objNr << endl;
}
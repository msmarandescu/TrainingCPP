#include "Audi.h"

static int objNr = 0;

Audi::Audi( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string marca, string model) //parameterized constructor
              :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    // std::cout << "Audi()" << std::endl;
    if(objNr < 2)
    {
        std::cout << "Audi()" << std::endl;
        Marca = new string(marca);
        Model = new string(model);
        objNr++;
    }else
    {
         throw string("Error: Audi class can have only one obj created!");
    }
}

Audi::Audi (const Audi &obj) // copy Constructor
:Automobil(*obj.Combustibil, *obj.Caroserie, *obj.Tractiune, *obj.Putere, *obj.Echipare, *obj.VIN_NR)
{
    cout << "Audi(copy Constructor)" << endl;
    Marca = new string(*obj.Marca);
    Model = new string(*obj.Model);
}

Audi& Audi::operator=(const Audi &obj) //copy assignment operator
{
    cout << "Audi(copy assignment operator)" << endl;
    if(this != &obj)
    {
        this->Caroserie = new string(*obj.Caroserie);
        this->Combustibil = new string(*obj.Combustibil);
        this->Tractiune = new string(*obj.Tractiune);
        this->Putere = new int(*obj.Putere);
        this->Echipare = new string(*obj.Echipare);
        this->VIN_NR = new string(*obj.VIN_NR);
        this->Marca = new string(*obj.Marca);
        this->Model = new string(*obj.Model);
    }
    return *this;
}

Audi::Audi (Audi &&obj)noexcept //move constructor
    :Automobil (move(obj))
{
    std::cout << "Audi(move constructor)" << std::endl;
    Marca = obj.Marca;
    Model = obj.Model;
    obj.Marca = nullptr;
    obj.Model = nullptr;

}

Audi& Audi::operator=(Audi &&obj) //move assignment operator
{
    cout << "Audi(move assignment operator)" << endl;
    if(this != &obj)
    {
        Automobil::operator=(move(obj));
        delete Marca;
        delete Model;
        Marca = obj.Marca;
        Model = obj.Model;
        obj.Marca = nullptr;
        obj.Model = nullptr;
    }
    return *this;
}

Audi::~Audi() // distructor
{
    std::cout << "~Audi()" << std::endl;
    delete Marca;
    delete Model;
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
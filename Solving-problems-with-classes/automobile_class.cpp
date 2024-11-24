#include <iostream>
#include <string>
using namespace std ;

class Automobile {
    public :
        //Constructors
        Automobile() ;
        Automobile(string newManufacturer, string newName, int newYear) ;

        //Manufacturer
        string Manufacturer() ;
        void SetManufacturer(string newManufcturer) ;

        //Name
        string Name() ;
        void SetName(string newName) ;

        //Year 
        int Year() ;
        void SetYear(int newYear) ;

        //Print
        void CompletePrint() ;

    private :

        int _Year ;
        string _Manufacturer ;
        string _Name ;
        bool IsValidYear(int Year) ;
}  ;

bool Automobile::IsValidYear(int Year) {
    return Year>=1886 ;
} ;

int Automobile::Year() {
    return _Year ;
} ;

void Automobile::SetYear(int newYear) {
    if (IsValidYear(newYear)) {
        _Year = newYear ;
    }
    else {
        std::cout << "Incorrect value" << std::endl ;
        _Year = -1 ;
    } 
} ;

string Automobile::Name() {
    return _Name ;
} ;

void Automobile::SetName(string newName) {
    _Name = newName ;
} ;

string Automobile::Manufacturer() {
    return _Manufacturer ;
} ;

void Automobile::SetManufacturer(string newManufacturer) {
    _Manufacturer = newManufacturer ;
} ;

Automobile::Automobile() {
    SetManufacturer("") ;
    SetName("") ;
    SetYear(-1) ;
} ;

Automobile::Automobile(string newManufacturer,string newName, int newYear) {
    SetManufacturer(newManufacturer) ;
    SetName(newName) ;
    SetYear(newYear) ;

} ;

void Automobile::CompletePrint() {
    std::cout << Automobile::Name() << " " << Automobile::Manufacturer() << " " << Automobile::Year() << std::endl ;
}

int main() {
    Automobile FirstCar("Ferrari","LaFerrari",2013) ;
    FirstCar.CompletePrint() ;
    std::cout << "Change of the year test : " ;
    FirstCar.SetYear(2019) ;
    std::cout << FirstCar.Year() << std::endl ;

} ;



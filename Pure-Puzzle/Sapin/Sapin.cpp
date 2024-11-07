#include <iostream> 
//le programme permet à l'utilisateur de faire 
//apparaitre un sapin de la taille demandée dans son terminal
int main() 
{
    const int sizemin =  5;
    const int sizemax = 100;
    int size = 5;
    std::cout << "Choissisez la taille de votre sapin entre 5 et 100" << std::endl ;
    std::cin >> size ;
    std::cin.ignore();
    while (size>sizemax || size<sizemin) 
    {
        std::cout << "la taille de votre sapin doit être entre 5 et 100" << std::endl ;
        std::cin >> size ;
        std::cin.ignore();
    }

    for (int i=1; i<=size ; ++i)
    {
        for (int j=1; j<=(size-i) ; ++j)
        {
            std::cout <<" " ;
        }
        for (int k=1;k<=i*2; ++k)
        {
            std::cout << "*" ;
        }
        for (int h=1 ; h<=(size-i-1) ; ++h) 
        {
            std::cout << " " ;
        }
        std::cout << " " << std::endl ;
    }
    
    return 0;
}

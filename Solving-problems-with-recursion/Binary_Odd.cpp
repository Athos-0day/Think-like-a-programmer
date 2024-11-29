#include <iostream>

int Iterative_Binary_Odd(int Arr[],int Size) {
    int total = 0 ;
    for (int i=0;i<Size;i++) {
        total += Arr[i] ; //we don't have to verify if Arr[i] is 1 or 0 because 0 doesn't change total
    }
    return total/2==0 ;
}

int Recursive_Total(int Arr[],int Size) {
        if (Size==0) {
            return 0 ;
        }
        else {
            return Arr[Size-1]+Recursive_Total(Arr,Size-1) ;
        }
    }

int Recursive_Binary_Odd(int Arr[],int Size) {
    return Recursive_Total(Arr,Size)/2==0 ;
}

//Same thing with the linked list

int main() {
    return 0 ;
}


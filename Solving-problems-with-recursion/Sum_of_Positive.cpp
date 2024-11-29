#include <iostream>

//Sum the positive number of an Array with an iterative solution and a recursive one 
int Iterative_Positive_Sum(int Arr[],int Size) {
    int sum = 0 ;
    for (int i=0; i<Size; i++) {
        if (Arr[i]>=0) {
            sum += Arr[i] ;
        }
    }
    return sum ;
}

int Recursive_Positive_Sum(int Arr[],int Size) {
    if (Size==0) {
        return 0 ;
    }
    else if (Arr[Size-1]>=0)
    {
        return Arr[Size-1] + Recursive_Positive_Sum(Arr,Size-1) ;
    }
    else {
        return Recursive_Positive_Sum(Arr,Size-1) ;
    }
}

//Same but with a linked list 
struct ListNode {
    int value ;
    ListNode * Next ;
} ;

typedef ListNode * LinkedList ;

int Iterative_Positive_Sum_Lca(LinkedList List) {
    if (List==NULL) {
        return 0 ;
    } 
    else if (List->value>=0) {
        return List->value + Iterative_Positive_Sum_Lca(List->Next) ;
    }
    else {
        return Iterative_Positive_Sum_Lca(List->Next) ;
    }

} 


int main() {
    int Arr[5] ;
    for (int i = 0; i<5; i++) {
        Arr[i] = i ;
        
    }
    Arr[2] = -2 ;
    std::cout << "Iterative : " << Iterative_Positive_Sum(Arr,5) <<" Recursive : " << Recursive_Positive_Sum(Arr,5) << std::endl ;
    return 0;
}

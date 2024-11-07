#include <iostream>
#include <string>
using namespace std ;

struct student {
    int grade ;
    int studentID ;
    string name ;
} ;

void quickSortgrade(student arr[],int low, int high) ;
int partition_student(student arr[],int low, int high) ;
void printArray(const student arr[], int size) ;

int partition_t(student arr[], int low, int high) {
    int pivot = arr[high].grade; // On choisit le dernier élément comme pivot
    int i = low - 1; // Index du plus petit élément

    for (int j = low; j < high; j++) {
        // Si l'élément courant est inférieur ou égal au pivot
        if (arr[j].grade <= pivot) {
            i++; // On incrémente l'index du plus petit élément
            swap(arr[i], arr[j]); // On échange les éléments
        }
    }
    swap(arr[i + 1], arr[high]); // On place le pivot à sa position correcte
    return i + 1; // Retourne l'index du pivot
}

void quickSort(student arr[], int low, int high) {
    if (low < high) {
        // Trouver l'index de partition
        int pivotIndex = partition_t(arr, low, high);

        // Trier les éléments séparément avant et après la partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



void printArray(const student arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "name : " << arr[i].name << endl ;
        cout << "grade : " << arr[i].grade  << endl ;
    }
    cout << endl;
}

int main() {
    student arr[] = {{10,25,"Didier"},{20,30,"Gregoire"},{15,65,"Simon"},{12,76,"Albert"}};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tableau avant le tri : ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    std::cout << "Tableau après le tri : ";
    printArray(arr, size);

    return 0;
}
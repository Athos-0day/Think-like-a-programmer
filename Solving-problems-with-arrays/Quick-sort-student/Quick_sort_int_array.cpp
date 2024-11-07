#include <iostream>

void quickSort(int arr[],int low, int high) ;
int partition_t(int arr[],int low, int high) ;
void printArray(const int arr[], int size) ;

int partition_t(int arr[], int low, int high) {
    int pivot = arr[high]; // On choisit le dernier élément comme pivot
    int i = low - 1; // Index du plus petit élément

    for (int j = low; j < high; j++) {
        // Si l'élément courant est inférieur ou égal au pivot
        if (arr[j] <= pivot) {
            i++; // On incrémente l'index du plus petit élément
            std::swap(arr[i], arr[j]); // On échange les éléments
        }
    }
    std::swap(arr[i + 1], arr[high]); // On place le pivot à sa position correcte
    return i + 1; // Retourne l'index du pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Trouver l'index de partition
        int pivotIndex = partition_t(arr, low, high);

        // Trier les éléments séparément avant et après la partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tableau avant le tri : ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    std::cout << "Tableau après le tri : ";
    printArray(arr, size);

    return 0;
}





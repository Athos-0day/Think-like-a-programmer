#include <iostream>

bool estTrie(const int arr[], int taille) {
    bool trie = true; // On suppose que le tableau est trié
    int i = 1;

    while (i < taille && trie) {
        if (arr[i] < arr[i - 1]) {
            trie = false; // On trouve un élément hors ordre
        }
        ++i; // Incrémente l'indice
    }
    return trie; // On renvoie le résultat après la boucle
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    if (estTrie(tableau, taille)) {
        std::cout << "Le tableau est trie." << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie." << std::endl;
    }

    return 0;
}
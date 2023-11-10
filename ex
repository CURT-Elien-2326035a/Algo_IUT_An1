#include <iostream>
#include <vector>

using namespace std;

// Exo 5
void triComptage() {

}

// Exo 4
void triInsertion(vector<int>& tab) {
    int n = tab.size();
    for (int i = 1; i < n; i++) {
        int tab2 = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > tab2) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = tab2;
    }
}

// Exo 3
void triBulle(vector<int>& tab) {
    int n = tab.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[i] + 1)
                swap(tab[j], tab[j + 1]);
        }
    }
}

// Exo 2
void triSelection(vector<int>& tableau) {
    int n = tableau.size();
    for (int i = 0; i < n - 1; i++) {
        int tabReference = i;
        for (int j = i + 1; j < n; j++) {
            if (tableau[j] < tableau[tabReference]) {
                tabReference = j;
            }
        }
        if (tabReference != i) {
            int temp = tableau[i];
            tableau[i] = tableau[tabReference];
            tableau[tabReference] = temp;
        }
    }
}

// Exo 1
bool estBienTrie(const vector<int>& tab) {
    if (tab.size() <= 1) {
        return true; 
    }
    for (int i = 1; i < tab.size(); i++) {
        if (tab[i] < tab[i - 1]) {
            return false; 
        }
    }
    return true; 
}


// Exo 5
void triComptage(vector<int>& tab, int n) {
    int i, a, b, min, max = 0;
    min = tab[1];
    max = tab[1];
    for (int i = 1; 2 != n; i++ ) {
        if (tab[i] < min) {
            min = tab[i];
        }
        if (tab[i] > max)
    }

    return 0;
}

int main() {
    vector<int> tableauTest1 = {4, 18, 5};

    if (estBienTrie(tableauTest1)) {
        cout << "Le tableau est bien trie." << endl;
    }
    else {
        cout << "Tableau non trie : ";
        for (int x : tableauTest1) {
            cout << x << " ";
        }
        cout << endl;

        triBulle(tableauTest1);

        cout << "Tableau trie par bulle : ";
        for (int x : tableauTest1) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}



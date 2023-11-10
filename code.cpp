#include <iostream>
#include <vector>

using namespace std;
vector<int> test{5,6,7,6,4,8,9,1};

void afficherTabTrié(vector<int>& tab){
    
    for (int i = 0; i < tab.size(); i++) {
          cout << tab[i] ;
    }
    
}
//EXERCICE2
void triSelection(vector<int>& tableau) {
    int n = tableau.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (tableau[j] < tableau[min]) {
                min = j;
            }
        }
        if (min != i) {
            int varHold = tableau[i];
            tableau[i] = tableau[min];
            tableau[min] = varHold;
        }
    }
        for (int i = 0; i < tableau.size(); i++) {
          cout << tableau[i] ;
        }
        //afficherTabTrié(tableau);
}

//EXERCICE4
void triInsertion(vector<int>& tab) {
    int n = tab.size();
    for (int i = 1; i < n -1; i++) {
        int x = tab[i];
        int j = i;
        while (j >= 0 && tab[j-1] > x) {
            tab[j] = tab[j-1];
            j = j - 1;
        }
        tab[j] = x;
    }
    //afficherTabTrié(tab);
}

int main ()
{
  triSelection(test);
  cout << endl;
  triInsertion(test);
    return 0;
}

// travail fait par Hugo Valente et Elien Curt


#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <thread>
#include <cassert>
 
using namespace std;
typedef vector <vector<double>> CMatrix;
 
CMatrix Mat;
 
void selectSort (vector <unsigned> & tab){
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
}
 
void insertSort (vector <unsigned> & vUint)
{
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
}
 
void bubbleSort (vector <unsigned> & vUint)
{
 for(size_t i = size(vUint)-1; i > 0; i = i - 1){
        for(size_t j = 0; j < i; j+= 1){
            if(vUint[j+1] < vUint[j]){
                swap(vUint[j+1], vUint[j]);
            }
        }
    }
}
 
void countingSort (vector <unsigned> & vUint)
{
//TODO
}
 
void languageSort (vector<unsigned> & VUint)
{
    sort (VUint.begin(), VUint.end());
}
 
void initMat (unsigned NbColumns)
{
    Mat.resize(5, vector <double> (NbColumns));
}
 
//http://stackoverflow.com/questions/2962785/c-using-clock-to-measure-time-in-multi-threaded-programs
void protoGenericSort(void (*mySort) (vector <unsigned> & vUint), const vector <unsigned> & vUint, unsigned NbFois, unsigned PosMat, unsigned VectNum)
{
    for (unsigned i (0); i < NbFois; ++i)
    {
        vector <unsigned> copyVUint (vUint);
        struct timespec start, finish;
        double elapsed;
        clock_gettime(CLOCK_MONOTONIC, &start);
        mySort (copyVUint);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        Mat [PosMat][i + NbFois * VectNum] = elapsed;
    }
}
 
void traiterResultats (const unsigned & nbElemAEnlever)
{
    for (vector <double> & UneLigne : Mat)
    {
        //tri
        sort (UneLigne.begin(), UneLigne.end());
        //suppresion des éléments non significatifs
        UneLigne = vector <double> (UneLigne.begin() + nbElemAEnlever / 2, UneLigne.end() - nbElemAEnlever / 2 );
        //plus petit temps
        double min (UneLigne[0]);
        //plus grand temps
        double max (UneLigne[UneLigne.size()-1]);
        //temps median
        double med (UneLigne[UneLigne.size()/2]);
 
        //On assigne les valeurs memorisees aux 3 premières cases
        UneLigne[0] = min;
        UneLigne[1] = med;
        UneLigne [2] = max;
    }
    //Affichage
    cout << setw (20) << "Tri" << setw (10) << "Min" << setw (10) << "Med" << setw (10) << "Max" << endl;
    vector<string> VMetode {"Selection", "Insertion", "Bulles", "comptage", "Langage"};
    for (unsigned i (0); i < VMetode.size(); ++i)
        cout << setw (20) << VMetode[i] << setw (10) << setprecision(6) << Mat[i][0] << setw (10) << setprecision(6) << Mat[i][1] << setw (10) << setprecision(6) << Mat[i][2] << endl;
 
}
 
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "boulette !\n utilisation : " << argv [0] << " (1) NbElem par vecteur (2) Nb de vecteurs differents (3) Nb itérations par vecteur" << endl;
        return 1;
    }
 
    unsigned NbElem (stoul(argv[1]));
    unsigned NbVecteurs (stoul(argv[2]));
    unsigned NbFois (stoul(argv[3]));
 
    srand (time(NULL));
    vector <unsigned> VUInt (NbElem);
    initMat (NbFois * NbVecteurs);
 
 
    for (unsigned i (0); i < NbVecteurs; ++i)
    {
        for (auto & Val : VUInt)
            Val = rand () % (VUInt.size() * 10);
 
        thread th1 (protoGenericSort, selectSort, VUInt, NbFois, 0, i);
        thread th2 (protoGenericSort, insertSort, VUInt, NbFois, 1, i);
        thread th3 (protoGenericSort, bubbleSort, VUInt, NbFois, 2, i);
        thread th4 (protoGenericSort, countingSort, VUInt, NbFois, 3, i);
        thread th5 (protoGenericSort, languageSort, VUInt, NbFois, 4, i);
        th1.join();
        th2.join();
        th3.join();
        th4.join();
        th5.join();
        cout << i << "fini" << endl;
    }
 
    cout << "Taille des vecteurs : " << NbElem << "\nNb de vecteurs : " << NbVecteurs << "\nNb iterations par vecteur : " << NbFois << endl;
    //On traite les résultats en supprimant 10% des éléments
    traiterResultats (NbFois * NbVecteurs / 10);
    return 0;
}


#include <iostream>
#include <istream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main()
{

    int numIncremental = 1;
    int *vectorDinamico = new int[numIncremental];

    for(int i = 0; i < 10; i++){

        vectorDinamico[i] = i;
        //numIncremental++;


    }

    for (int j = 0 ; j < 10 ; j++){
        cout << "Valor: " << vectorDinamico[j];
        cout << "Direccion: " << &vectorDinamico[j] << "\n";


    }

    delete[] vectorDinamico;

 return 0;
}

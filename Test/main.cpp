#include <allegro.h>
#include <iostream>
#include <istream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main()
{

    int numIncremental = 1;
    int *vectorDinamico = new int[numIncremental];

    for(int i = 0; i < 5; i++){

        vectorDinamico[i] = i;
        numIncremental++;

        cout << vectorDinamico[i];

    }

    delete[] vectorDinamico;

 return 0;
}

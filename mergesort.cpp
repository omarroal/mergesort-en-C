#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

// OMAR RODRIGUEZ ALVAREZ 48679912-K

void mostrarVector(int *V, int n) // Solo para visualizar el vector antes y despues
{
    if (n+1 < 10)
    {
        for (int i = 1; i < n+1 ; i++)
        {
            cout << V[i] << " ";
        }
    }

    else
    {
        for (int i = 1; i < 11 ; i++)
        {
            cout << V[i] << " ";
        }
    }
    cout << endl;
}

void ordenardirectamente(int &x, int &y) // Como en practicas anteriores
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void combinar(int *V1, int *V2, int *V, int n1, int n2)
{
    int i1;
    int i2;
    int i;

    i1 = 1;
    i2 = 1;

    V1[n1+1] = 999999999; // Como infinito
    V2[n2+1] = 999999999; 

    for (i = 1; i <= n1+n2; i++)
    {
        if (V1[i1] < V2[i2])
        {
            V[i] = V1[i1];
            i1++;
        }
        else
        {
            V[i] = V2[i2];
            i2++;
        }
    }
}

void mergesort (int *V, int n)
{
    int nInf = n/2;
    int nSup = n-nInf;
    int aux = 1;

    int *V1 = new int [nInf+2];
    int *V2 = new int [nSup+2];

    if (V1 == NULL)
    // V1 == NULL || V2 == NULL 
    {
        cout << "ERROR DE MEMORIA" << endl; 
        return;
    }    

    if (n < 3)
    {
        if (n != 1)
        {
            if (V[1] > V[2])
            {
                ordenardirectamente(V[1], V[2]);
            }
        }        
    }

    else
    {
        for (int i = 1; i < nInf+1; i++)
        {
            V1[i] = V[i];
        }

        for (int j = nInf+1; j < n+1; j++)
        {
            V2[aux] = V[j];
            aux++;
        }

        mergesort(V1, nInf);
        mergesort(V2, nSup);
        combinar (V1, V2, V, nInf, nSup);
    }
}

int main()
{
    int *V;
    int n;
    int numero;

    cout << "Introduce el tamanyo del vector: ";
    cin >> n;    
    V = new int [n+1];

    if (V == NULL) 
    {
        cout << "ERROR DE MEMORIA" << endl; 
        return -1;
    }

    for(int i = 1; i < n+1; i++ )
    {
        cout << "Introduce un numero en la posicion " << i << ": " << endl;
        cin >> numero;
        V[i] = numero;
    }
    cout << endl << "Vector seleccionado " << endl; 
    mostrarVector(V, n);
    mergesort(V, n);
    cout << "Vector ordenado " << endl;
    mostrarVector(V, n);
}

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;


void swap(int &a, int &b)
{
    int aux;

    aux = a;
    a = b;
    b = aux;
}



int asamblare_pivot(int v[], int st, int dr)
{
    int pivot = v[dr], pozPivot = st;

    for(int i = st; i < dr; i++)
        if(v[i] <= pivot)
        {
            swap(v[i], v[pozPivot]);
            pozPivot++;
        }

    swap(v[pozPivot], v[dr]);
    return pozPivot;

}


void Quick(int v[], int st, int dr)
{
    int pozPivot;

    if(st < dr)
    {
        pozPivot = asamblare_pivot(v, st, dr);
        Quick(v, st, (pozPivot-1));
        Quick(v, (pozPivot+1), dr);
    }
}




void afisare(int v[], int n)
{
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << endl;
}



int main()
{
    ifstream fin("test3.txt");

    int n;
    fin >> n;

    int nrMax;
    fin >> nrMax;

    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = rand()%nrMax;

    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    Quick(v,0,(n-1));

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare Quick : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();

    return 0;
}

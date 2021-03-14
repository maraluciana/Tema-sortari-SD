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


void Bubble(int v[], int n)
{
    bool sorted = false;

    do{
        sorted = true;
        for(int i = 0; i < (n-1); i++)
            if(v[i] > v[i+1])
                {
                swap(v[i],v[i+1]);
                sorted = false;
                }
        n--;
    }while(!sorted);

}


void afisare(int v[], int n)
{
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << endl;
}


int main()
{
    ifstream fin("test.txt");

    int n;
    fin >> n;

    int nrMax;
    fin >> nrMax;

    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = rand()%nrMax;

    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    Bubble(v,n);

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "Timp sortare Bubble : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();

    return 0;
}


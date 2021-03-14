#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int max_vect(int v[], int n)
{
    int max = v[0];

    for(int i = 1; i < n; i++)
        if(v[i] > max)
            max = v[i];
    return max;
}


void CountRadix(int v[], int n, int poz)
{
    int viz[10] = {0}, vDigits[n], elem;

    for(int i = 0; i < n; i++)
        viz[(v[i] / poz) % 10]++;

    for(int i = 1; i < 10; i++)
        viz[i] += viz[i-1];

    for(int i = (n-1); i >= 0; i--)
    {
        elem = viz[(v[i] / poz) % 10];
        vDigits[elem - 1] = v[i];
        viz[(v[i] / poz) % 10]--;
    }

    for(int i = 0; i < n; i++)
        v[i] = vDigits[i];
}



void Radix(int v[], int n)
{

    int max = max_vect(v,n), maxCopy = max, maxDigits = 0, maxPoz = 1;


    while(maxCopy)
    {
        maxCopy /= 10;
        maxDigits++;
    }

    for(int i = 1; i <= maxDigits; i++)
        maxPoz *= 10;

    for(int poz = 1; poz <= maxPoz; poz *= 10)
        CountRadix(v,n,poz);
}



void afisare(int v[], int n)
{
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << endl;
}


int main()
{
    ifstream fin("test1.txt");


    int n;
    fin >> n;

    int nrMax;
    fin >> nrMax;

    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = rand()%nrMax;

    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    Radix(v,n);

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare Radix : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();

    return 0;
}

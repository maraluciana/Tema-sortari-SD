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


void Count(int v[], int n)
{
    int max, vsorted[n], contor = 0;

    max = max_vect(v,n);

    int viz[max] = {0};


    for(int i = 0; i < n; i++)
        viz[v[i]]++;


    for(int i = 0; i <= max; i++)
        for(int j = 1; j <= viz[i]; j++)
            vsorted[contor++] = i;

    for(int i = 0; i < n; i++)
        v[i] = vsorted[i];
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

    Count(v,n);

    auto end = chrono::high_resolution_clock::now();


    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare Count : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    fin.close();

    return 0;
}

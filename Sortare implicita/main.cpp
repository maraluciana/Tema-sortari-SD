#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>

using namespace std;


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

    sort(v, v + n);

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare implicita : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();

    return 0;
}

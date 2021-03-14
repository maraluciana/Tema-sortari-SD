#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;


void unire_vect(int st[], int nSt, int dr[], int nDr, int v[])
{
    int elemSt = 0, elemDr = 0, elemVect = 0;

    while(elemSt < nSt && elemDr < nDr)
    {
        if(st[elemSt] < dr[elemDr])
        {
            v[elemVect] = st[elemSt];
            elemSt++;
        }
        else
        {
            v[elemVect] = dr[elemDr];
            elemDr++;
        }

        elemVect++;
    }

    while(elemSt < nSt)
    {
        v[elemVect] = st[elemSt];
        elemSt++;
        elemVect++;
    }

    while(elemDr < nDr)
    {
        v[elemVect] = dr[elemDr];
        elemDr++;
        elemVect++;
    }
}



void Merge(int v[], int n)
{
    int mij, nSt, nDr;

    if (n > 1)
    {
        mij = n / 2;
        nSt = mij;
        nDr = n - mij;

        int st[nSt], dr[nDr];

        for(int i = 0; i < mij; i++)
            st[i] = v[i];
        for(int i = mij; i < n; i++)
            dr[i-mij] = v[i];

        Merge(st, nSt);
        Merge(dr, nDr);
        unire_vect(st, nSt, dr, nDr, v);
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
    ifstream fin("test2.txt");

    int n;
    fin >> n;

    int nrMax;
    fin >> nrMax;

    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = rand()%nrMax;

    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    Merge(v,n);

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afisare(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare Merge : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();

    return 0;
}

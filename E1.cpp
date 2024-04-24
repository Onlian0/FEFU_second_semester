#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{

    int n, res = 0;
    char a, b;

    fin >> n;
    fin >> a;

    for (int i = 1; i < n; ++i)
    {
        fin >> b;
        if (a != b)
        {
            res++;
            a = b;
        }
    }
    if (b == 'B')
        res++;

    fout << res;
}
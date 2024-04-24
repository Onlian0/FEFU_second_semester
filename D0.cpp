#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void rec(int n, int num)
{
    if (num >= 0)
    {
        rec(n, num - 1);
        for (int i = n - 1; i >= 0; --i)
        {
            fout << ((num >> i) & 1);
        }
        fout << endl;
    }
}

int main()
{
    int n;
    fin >> n;
    // rec(n, (1<<(n)) - 1);
    for (int i = 0; i < 1 << n; i += 0b1)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            fout << ((i >> j) & 1);
        }
        fout << endl;
    }
}
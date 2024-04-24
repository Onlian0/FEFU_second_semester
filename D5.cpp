// #include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define MAX 3000
#define DEL 1000000007

unsigned long long NOD(unsigned long long a, unsigned long long b)
{
    if (b == 0)
    {
        return a;
    }
    a = a % b;
    return NOD(b, a);
}

int main()
{
    unsigned long long numerator[MAX], denumerator[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        numerator[i] = 1;
        denumerator[i] = 1;
    }
    int xm, ym, zm, xb, yb, zb;
    fin >> xm >> ym >> zm >> xb >> yb >> zb;
    int x = abs(xm - xb);
    int y = abs(ym - yb);
    int z = abs(zm - zb);
    int j = 0;
    for (int i = 0; i < (x + y + z); ++i)
    {
        numerator[i] = i + 1;
        if (i < x)
        {
            denumerator[j] = i + 1;
            j++;
        }
        if (i < y)
        {
            denumerator[j] = i + 1;
            j++;
        }
        if (i < z)
        {
            denumerator[j] = i + 1;
            j++;
        }
    }
    for (int i = 0; i < (x + y + z); ++i)
    {
        for (int j = 0; j < (x + y + z); ++j)
        {
            unsigned long long t = NOD(numerator[i], denumerator[j]);
            if (t != 0)
            {
                numerator[i] = numerator[i] / t;
                denumerator[j] = denumerator[j] / t;
            }
        }
    }
    unsigned long long res = 1;
    for (int i = 0; i < (x + y + z); ++i)
    {
        res = ((res % DEL) * (numerator[i] % DEL)) % DEL;
    }
    fout << res;
    return 0;
}

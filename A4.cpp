#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int quicksort(vector<int> arr, int size, int k)
{
}

int main()
{
    int q, v, p, n, k;
    fin >> q >> v >> p >> n >> k;
    vector<int> arr(n);
    arr[0] = p;
    for (int i = 1; i < n; i++)
    {
        arr[i] = (arr[i - 1] * q) % v;
    }
    int ans = quicksort(arr, )
                  fout
              << arr[k - 1] << endl;
}

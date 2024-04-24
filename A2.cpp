#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{

    int n, queueTime, minTime = 0;
    fin >> n >> queueTime;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {

        fin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }

    minTime += (arr[0] + queueTime);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minTime)
        {
            minTime += queueTime;
        }
        else
        {
            minTime += ((arr[i] - minTime) + queueTime);
        }
    }
    fout << minTime;
}

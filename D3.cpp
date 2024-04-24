#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool check_num(int a, int b)
{
    int flag = 0;
    string a_str = to_string(a);
    string b_str = to_string(b);
    vector<int> arr1(128), arr2(128);
    for (int i = 0; i < a_str.size(); i++)
    {
        arr1[a_str[i]]++;
        arr2[b_str[i]]++;
    }
    for (int i = 47; i < 59; i++)
    {
        if (arr1[i] != arr2[i])
        {
            flag++;
        }
    }
    if (flag == 1 && (a_str.size() - b_str.size()) * (-1) == 1 || flag == 0)
    {
        return true;
    }

    return false;
}

void permute(string s, int b, int sum, int n, int h = 0)
{
    static int counter = 1;
    if (h == n)
        counter++;
    if (h == n && s[0] != '0' && check_num(sum - stoi(s), b))
    {
        fout << "YES" << endl;
        fout << stoi(s) << " " << sum - stoi(s) << endl;
        exit(0);
    }
    else
    {
        for (int thread = h; thread < n; thread++)
        {
            swap(s[h], s[thread]);
            permute(s, b, sum, n, h + 1);
            swap(s[h], s[thread]);
        }
    }
}

int main()
{
    int a, b, sum;
    fin >> a >> b >> sum;
    string A = to_string(a), B = to_string(b);
    permute(A, b, sum, A.size(), 0);
    fout << "NO";
}

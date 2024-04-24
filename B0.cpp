#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int flower[n];
    for (int i = 0; i < n; i++)
    {
        cin >> flower[i];
    }
    int pref[n];
    pref[0] = flower[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = flower[i] + pref[i - 1];
    }
    int L = 0, M = 0, R = 0, sum = 0;
    for (int m = 0; m < n - 1; m++)
    {
        int l = 0, r = n - 1;
        int left_sum = pref[m];
        int right_sum = pref[r] - pref[m];
        while (l <= m && r > m)
        {
            if (left_sum == right_sum)
            {
                if (left_sum > sum)
                {
                    sum = left_sum;
                    L = l + 1;
                    M = m + 1;
                    R = r + 1;
                }
                break;
            }
            else if (left_sum > right_sum)
            {
                right_sum -= flower[];
            }
            else
            {
                left_sum -= flower[l++];
            }
        }
    }
    if (sum > 0)
    {
        cout << L << " " << M << " " << R;
    }
    else
    {
        cout << "-1";
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int flower[n];
    for (int i = 0; i < n; i++)
    {
        cin >> flower[i];
    }
    int pref[n];
    pref[0] = flower[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + flower[i];
    }
    int L = 0, M = 0, R = 0, sum = 0;
    for (int m = 0; m < (n - 1); m++)
    {
        int l = 0, r = n - 1;
        int left_sum = pref[m];
        int right_sum = pref[r] - pref[m];
        while (l <= m && r > m)
        {
            if (left_sum == right_sum)
            {
                if (left_sum > sum)
                {
                    sum = left_sum;
                    L = l + 1;
                    M = m + 1;
                    R = r + 1;
                }
                break;
            }
            else if (left_sum < right_sum)
            {
                right_sum -= flower[r--];
            }
            else
            {
                left_sum -= flower[l++];
            }
        }
    }
    if (sum > 0)
        cout << L << " " << M << " " << R;
    else
        cout << "-1";
    return 0;
}

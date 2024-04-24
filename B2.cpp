#include <cstdio>
#include <malloc.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void up_MIN(vector<int> &vec, int size)
{
    int pivot = (size - 1) / 2;
    if ((vec[size] < vec[pivot]) && (pivot >= 0))
    {
        swap(vec[pivot], vec[size]);
        up_MIN(vec, pivot);
    }
}

void up_MAX(vector<int> &vec, int size)
{
    int pivot = (size - 1) / 2;
    if ((vec[size] > vec[pivot]) && (pivot >= 0))
    {
        swap(vec[pivot], vec[size]);
        up_MAX(vec, pivot);
    }
}

void down_MIN(vector<int> &vec, int size)
{
    int left = 2 * size + 1;
    int right = 2 * size + 2;
    int least = size;
    if (left < vec.size() && vec[left] < vec[least])
    {
        least = left;
    }
    if (right < vec.size() && vec[right] < vec[least])
    {
        least = right;
    }
    if (least != size)
    {
        swap(vec[least], vec[size]);
        down_MIN(vec, least);
    }
}

void down_MAX(vector<int> &vec, int size)
{
    int left = 2 * size + 1;
    int right = 2 * size + 2;
    int least = size;
    if (left < vec.size() && vec[left] > vec[least])
    {
        least = left;
    }
    if (right < vec.size() && vec[right] > vec[least])
    {
        least = right;
    }
    if (least != size)
    {
        swap(vec[least], vec[size]);
        down_MAX(vec, least);
    }
}

int extract_MIN(vector<int> &vec)
{
    int root = vec[0];
    vec[0] = vec[vec.size() - 1];
    vec.pop_back();
    down_MIN(vec, 0);
    return root;
}

int extract_MAX(vector<int> &vec)
{
    int root = vec[0];
    vec[0] = vec[vec.size() - 1];
    vec.pop_back();
    down_MAX(vec, 0);
    return root;
}

void insert_MIN(vector<int> &vec, int element)
{
    vec.push_back(element);
    up_MIN(vec, vec.size() - 1);
}

void insert_MAX(vector<int> &vec, int element)
{
    vec.push_back(element);
    up_MAX(vec, vec.size() - 1);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    vector<int> MIN_heap_R;
    vector<int> MAX_heap_LM;
    //  vector<int> medians;

    int num;
    for (int i = 0; i < n; i++)
    {
        fin >> num;

        if (MIN_heap_R.size() != 0)
        {

            int top_smallest = MIN_heap_R[0];
            if (num > top_smallest)
            {
                insert_MIN(MIN_heap_R, num);
                //                size_MIN_heap_R += 1;
            }
            else
            {
                insert_MAX(MAX_heap_LM, num);
                //                size_MAX_heap_LM += 1
            }
        }
        else
        {
            insert_MAX(MAX_heap_LM, num);
            //            size_MAX_heap_LM += 1
        }

        while (MIN_heap_R.size() > MAX_heap_LM.size())
        {
            insert_MAX(MAX_heap_LM, extract_MIN(MIN_heap_R));
            //            size_MAX_heap_LM += 1
            //            size_MIN_heap_R -= 1
        }

        while (MIN_heap_R.size() + 1 < MAX_heap_LM.size())
        {
            insert_MIN(MIN_heap_R, extract_MAX(MAX_heap_LM));
            //            size_MIN_heap_R += 1
            //            size_MAX_heap_LM -= 1
        }

        //        medians.push_back(MAX_heap_LM[0])
        fout << MAX_heap_LM[0] << " ";
    }

    fin.close();
    fout.close();

    return 0;
}
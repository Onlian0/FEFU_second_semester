#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
//Основой алгоритма является костыль того, что буквы - это цифры.
//Представим, что сhar - это 128-ая системы счисления и переведем наши слова в буферный массив
//Этот массив состоит из численных представлений наших слов
//Далее используем RadixSort на числах и дешифруем наши числа, обратно в слова
#include <iostream>
using namespace std;
 // Карманная сортировка из Интернета
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
 
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
 
    int m = getMax(arr, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
// 65-90

int main() {
    int size;
    fin >> size;
    string arr[size];
    int bufer[size];
    //Ввод
    for (int i = 0; i < size; i++) {
        fin >> arr[i]; 
        bufer[i] = ((int) arr[i][0]<<14) + ((int) arr[i][1]<<7) + ((int) arr[i][2]);
    }
    radixsort(bufer, size);
    for (int i = 0; i < size; i++) {
        arr[i][0] = (char) ((bufer[i]%(128*128*128)>>14));
        arr[i][1] = (char) ((bufer[i]%(128*128)>>7));
        arr[i][2] = (char) ((bufer[i]%128));
        fout << arr[i] << endl;
    }
}

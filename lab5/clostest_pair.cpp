#include <iostream>
#include <math.h>
using namespace std;
float min_L = 999999;
float min_R = 999999;
void merge(int arr[], int arr2[], int y, int m, int n)
{
    int tmp[n - y], tmp2[n - y];
    int i = y;
    int j = m;
    int k = 0;
    while (i < m && j < n)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            tmp2[k] = arr2[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            tmp2[k] = arr2[j];
            j++;
        }
        k++;
    }
    if (i == m)
    {
        for (int p = k; p < n - y; p++)
        {
            tmp[p] = arr[j];
            tmp2[p] = arr2[j];
            j++;
        }
    }
    else
    {
        for (int p = k; p < n - y; p++)
        {
            tmp[p] = arr[i];
            tmp2[p] = arr2[i];
            i++;
        }
    }
    k = 0;
    for (int p = y; p < n; p++)
    {
        arr[p] = tmp[k];
        arr2[p] = tmp2[k];
        k++;
    }
}
void mergeSort(int X[], int Y[], int n)
{
    if (n < 2)
    {
        return;
    }
    int i = 1;
    while (i < n)
    {
        int j = 0;
        while (j < n - i)
        {
            if (n < j + (2 * i))
            {
                merge(X, Y, j, j + i, n);
            }
            else
            {
                merge(X, Y, j, j + i, j + (2 * i));
            }

            j += 2 * i;
        }
        i *= 2;
    }
}
void loop_copy(int X[], int Y[], int XXA[], int YYA[], int XXB[], int YYB[], int S_XXA, int S_XXB, int tmp)
{
    for (int i = 0; i < S_XXA; i++)
    {
        XXA[i] = X[tmp];
        YYA[i] = Y[tmp];
        tmp++;
    }
    for (int i = 0; i < S_XXB; i++)
    {
        XXB[i] = X[tmp];
        YYB[i] = Y[tmp];
        tmp++;
    }
}
void clostest(int X[], int Y[], int l, int n, int p)
{
    int S_XXA = (n / 2) - l, S_XXB = n - (n / 2);
    int XXA[S_XXA], YYA[S_XXA];
    int XXB[S_XXB], YYB[S_XXB];
    loop_copy(X, Y, XXA, YYA, XXB, YYB, S_XXA, S_XXB,l);
    int c = 0;
    if (n > 1)
    {

        if (n == 2)
        {
            float dis = sqrt(pow(X[0] - X[1], 2) + pow(Y[0] - Y[1], 2));
            if (p == -1 && dis < min_L)
            {
                min_L = dis;
            }
            else if (p == 1 && dis < min_R)
            {
                min_R = dis;
            }
        }
        clostest(XXA, YYA, 0, S_XXA, -1);
        clostest(XXB, YYB, 0, S_XXB, 1);
    }
}
int main()
{
    int min_A = 99999999;
    int d;
    int n;
    cin >> n;
    int X[n], Y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    mergeSort(X, Y, n);
    clostest(X, Y, 0, n - 1, 0);
}
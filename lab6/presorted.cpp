#include <iostream>
using namespace std;
void merge(int arr[], int y, int m, int n)
{
    int tmp[n - y];
    int i = y;
    int j = m;
    int k = 0;
    while (i < m && j < n)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i == m)
    {
        for (int p = k; p < n - y; p++)
        {
            tmp[p] = arr[j];
            j++;
        }
    }
    else
    {
        for (int p = k; p < n - y; p++)
        {
            tmp[p] = arr[i];
            i++;
        }
    }
    k = 0;
    for (int p = y; p < n; p++)
    {
        arr[p] = tmp[k];
        k++;
    }
}
void mergesort(int arr[], int n)
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
                merge(arr, j, j + i, n);
            }
            else
            {
                merge(arr, j, j + i, j + (2 * i));
            }

            j += 2 * i;
        }
        i *= 2;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, n);
    int op[n];
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            op[j] = arr[i];
            j++;
        }
        if (arr[i] != arr[i + 1])
        {
            op[j] = arr[i + 1];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << op[i] << " ";
    }
    cout << endl;
}
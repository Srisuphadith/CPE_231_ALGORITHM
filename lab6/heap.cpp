#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        int k = i;
        int v = arr[k];
        bool heap = false;
        while (!heap && (2 * k) <= n)
        {
            int j = 2 * k;
            if (j < n)
            {
                if (arr[j] > arr[j + 1])
                {
                    j++;
                }
            }
            if (v <= arr[j])
            {
                heap = true;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}
void heapsort(int arr[], int n)
{
    heapify(arr, n);
    for (int j = 1; j <= n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    for (int i = n; i >= 1; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1);
    }
    for (int j = 1; j <= n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, n);
}
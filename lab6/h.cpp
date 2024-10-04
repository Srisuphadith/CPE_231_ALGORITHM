#include <iostream>
using namespace std;
void heapify(int arr[], int n)
{
    for (int i = n-1; i >0; i--)
    {
        int k = i;
        int v = arr[k];
        bool heap = false;
        while (!heap && (2 * k+1) < n)
        {
            int j = 2 * k;
            if (j < n)
            {
                if (arr[j] < arr[j + 1])
                {
                    j++;
                }
            }
            if (v >= arr[j])
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


        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
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
    heapify(arr, n);


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
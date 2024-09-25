#include <iostream>
#include <algorithm>
using namespace std;

int HoarePatition(int arr[], int l, int r)
{
    int p = arr[l], i = l, j = r+1;
    while (i < j)
    {
        while (i<r)
        {
           i++;
           if(arr[i] >=p ){
            break;
           }
        }
        while (j>l)
        {
           j--;
           if(arr[j] <=p){
            break;
           }
           
           
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    return j;
}
void Quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int s = HoarePatition(arr, l, r);
        Quicksort(arr, l, s - 1);
        Quicksort(arr, s + 1, r);
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
    Quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
#include <iostream>
using namespace std;
int maxx = 0;

void wish(int arr[], int l, int r)
{
    if (r > 1)
    {
        int sum = 0;
        int s_a = (r / 2) - l, s_b = r - (r / 2), tmp = 0;
        int a[s_a];
        int b[s_b];
        for (int i = 0; i < s_a; i++)
        {
            a[i] = arr[tmp];
            sum += arr[tmp];
            tmp++;
        }
        if (sum > maxx)
        {
            maxx = sum;
        }
        sum = 0;
        for (int i = 0; i < s_b; i++)
        {
            b[i] = arr[tmp];
            sum += arr[tmp];
            tmp++;
        }
        if (sum > maxx)
        {
            maxx = sum;
        }
        sum = 0;
        for (int i = 0; i <= r; i++)
        {
            sum += arr[i];
        }
        if (sum > maxx)
        {
            maxx = sum;
        }
        wish(a, 0, s_a - 1);
        wish(b, 0, s_b - 1);
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
    wish(arr, 0, n - 1);
    cout << maxx;
}
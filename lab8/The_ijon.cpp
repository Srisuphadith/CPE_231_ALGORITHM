#include <iostream>
using namespace std;

int Knapsack(int arr[], int w[], int i, int j)
{

    if ((i == 0 && j >= 0) || (j == 0 && i >= 0))
    {
        return 0;
    }

    if (j - w[i-1] >= 0)
    {
        return max(Knapsack(arr, w, i - 1, j), arr[i-1] + Knapsack(arr, w, i - 1, j - w[i-1]));
    }
    else if (j - w[i-1] < 0)
    {
        return Knapsack(arr, w, i - 1, j);
    }
    return 0;
}

int main()
{
    int n, p;
    cin >> n;
    int arr[n];
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> arr[i];
    }
    cin >> p;
    int matrix[n + 1][p + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            matrix[i][j] = Knapsack(arr, w, i, j);
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= p; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << matrix[n][p] << endl;
}
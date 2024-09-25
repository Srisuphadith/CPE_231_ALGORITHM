#include <iostream>
#include <algorithm>
using namespace std;
int CCI(char arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            return 1;
        }
    }
    return 0;
}
int FLG(char arr[], int n, int i)
{
    for (int j = n - 1; j >= i + 1; j--)
    {
        if (arr[i] < arr[j])
        {
            return j;
        }
    }
    return 0;
}
int FLI(char arr[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            return i;
        }
    }
    return 0;
}
void reverse(char str[], int l, int h)
{
    h--;
    while (l < h)
    {
        swap(str[l], str[h]);
        l++;
        h--;
    }
}
void Lexico(char arr[], int n, char ch[], int k)
{
    int z = 1;
    int prob[k];

    for (int b = 0; b < k; b++)
    {
        int f = 0, m = 0;
        for (int g = 0 + n * b; g < n + n * b; g++)
        {
            if (arr[f] == ch[g])
            {
                m++;
            }
            f++;
        }
        if (m == n)
        {
            prob[b] = z;
        }
    }
    //+++++++
    while (CCI(arr, n) == 1)
    {
        int i = FLI(arr, n);
        int j = FLG(arr, n, i);
        swap(arr[i], arr[j]);
        reverse(arr, i + 1, n);
        //+++++++++++++++++++++++++
        z++;
        for (int b = 0; b < k; b++)
        {
            int f = 0, m = 0;
            for (int g = 0 + n * b; g < n + n * b; g++)
            {
                if (arr[f] == ch[g])
                {
                    m++;
                }
                f++;
            }
            if (m == n)
            {
                prob[b] = z;
            }
        }
        //+++++++++++++++++++++++++
    }
    for (int i = 0; i < k; i++)
    {
        cout << prob[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    char arr[n * m];
    char list[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J','K'};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0 + n * (i - 1); j < n + n * (i - 1); j++)
        {
            cin >> arr[j];
        }
    }
    Lexico(list, n, arr, m);
}
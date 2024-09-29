#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = 0, k = 2,sum = 0;
    while (k < n)
    {
        int c = n-k;
        for (int i = 0; i < c; i++)
        {
            int g = i+k;
            for (int j = i; j < g; j++)
            {
                sum += arr[j];
            }
            if(sum > max){
                max = sum;
            }
            sum = 0;
        }
        k++;
    }
    cout << max<< endl;
}
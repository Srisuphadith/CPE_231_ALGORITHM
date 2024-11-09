#include <iostream>
using namespace std;

int dp(int arr[], int i, bool logic)
{
    i--;
    bool state;
    int count = 1;
    if (logic == true)
    {
        state = true;
    }
    else
    {
        state = false;
    }

    for (int j = i; j >= 0; j--)
    {
        bool tmp = state;
        for (int k = j - 1; k >= 0; k--)
        {
            if (state == true && arr[j] > arr[k])
            {
                state = !state;
                j = k;
                count++;
            }
            else if (state == false & arr[j] < arr[k])
            {
                state = !state;
                j = k;
                count++;
            }
        }
        if(state == tmp && count == 1){
            break;
        }
    }
    return count;
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
    for (int i = 1; i <= n; i++)
    {
        cout << dp(arr, i, true) << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dp(arr, i, false) << " ";
    }
    cout << endl;
}
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
float maax = 0;
void permute(vector<int> a, int l, int r,vector<vector<float> > matrix)
{
    // Base case
    if (l == r)
    {
        float sum = 0;
        for(int i = 0;i<r+1;i++){
            sum += matrix[i][a[i]-1];
            //cout << matrix[i][a[i]-1]<< " ";
        }
        //cout << endl;
        //cout << sum << endl;
        if(sum > maax){
            maax = sum;
        }
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r,matrix);

            // backtrack
            swap(a[l], a[i]);
        }
    }
}
int main()
{
    float n, tmp;
    cin >> n;
    vector<vector<float> > matrix(n);

    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(n);
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }


    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(i + 1);
    }
    permute(a, 0, n - 1,matrix);
    cout << maax;
}
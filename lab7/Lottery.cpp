#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    char lottery[m];
    char buy[n];
    vector<int> shift;
    for (int i = 0; i < 26; i++)
    {
        shift.push_back(n);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> lottery[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> buy[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int tmp = buy[i];
        tmp -= 65;
        if (shift[tmp] == n)
        {
            shift[tmp] = n - i - 1;
        }
    }
    // for(auto p:shift){
    //     cout << p << " ";
    // }
    int found = 0;
    int sh_sum = 0;
    int fst;
    for (int i = n - 1; i < m; i++)
    {
        int sum = 0;
        if (buy[n - 1] == lottery[i])
        {
            int y = i + 1;
            for (int j = n - 1; j >= 0; j--)
            {
                y--;
                if (buy[j] == lottery[y])
                {
                    sum++;
                }
                else
                {
                    sum = 0;
                    break;
                }
            }
            if (sum == n)
            {
                found = 1;
                fst = y;
                break;
            }
            else
            {
                i += shift[y]-1;
                sh_sum += 1;
                
            }
        }
        else
        {
            int tmp = lottery[i];
            tmp -= 65;
            i += shift[tmp]-1;
            sh_sum += 1;
        }
    }
    if(found == 1){
        cout << "YES "<< sh_sum <<" "<<fst<< endl;
    }else{
        cout << "NO " << sh_sum << " -1" << endl;
    }
}
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string dec_to_bin(int nBit, int n)
{
    vector<bool> bin(nBit, 0);
    int i = nBit - 1;
    string txt;
    while (i >= 0)
    {
        bin[i] = n % 2;
        n /= 2;
        i--;
    }
    int x = 0;
    for (auto p : bin)
    {
        txt[x] = p;
        x++;
        // cout << p;
    }
    // cout << endl;
    return txt;
}
int main()
{
    int x, y, even = 0, odd = 0;

    cin >> x;
    cin >> y;

    string bin;
    int c = pow(2, x);
    vector<int> sample;

    for (int i = 1; i <= x; i++)
    {
        sample.push_back(i);
    }

    for (int i = 0; i < c; i++)
    {

        bin = dec_to_bin(x, i);
        int k = 0, m = 0, sum = 0;
        vector<int> buff;
        for (int q = 0; q < x; q++)
        {

            if (bin[q] == 1)
            {
                buff.push_back(sample[m]);
                k++;
            }
            m++;
        }
        for (auto p : buff)
        {
            // cout << p;
            sum += p;
        }
        if (sum == y)
        {
            for (auto p : buff)
            {
                if (p % 2 == 0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
        }
    }
    cout << odd << endl
         << even << endl;
}
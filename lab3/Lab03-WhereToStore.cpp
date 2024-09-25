// 66070501052 Srisuphadith Rattanaprasert
#include <iostream>
#include <vector>
#include <string.h>
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
    string txt, bin_code;
    cin >> txt;
    int nBit = 0, n;

    for (auto c : txt)
    {
        nBit++;
    }

    n = pow(2, nBit);

    int j = nBit - 1;
    vector<pair<string, int> > palin_st;
    for (int i = 0; i < n; i++)
    {
        bin_code = dec_to_bin(nBit, i);
        int k = 0, m = 0;
        string buff;
        for (int q = 0; q < nBit; q++)
        {
            if (bin_code[q] == 1)
            {
                buff.push_back(txt[m]);
                // cout << txt[m];
                k++;
            }
            m++;
        }
        // cout << buff;
        int state = 0;
        int f = k - 1;
        if (k > 1)
        {
            for (int w = 0; w < k; w++)
            {
                if ((k % 2) != 0)
                {
                    if (buff[w] != buff[f])
                    {
                        break;
                    }
                    if (w == f)
                    {
                        state = 1;
                        break;
                    }
                }
                else
                {
                    if (buff[w] != buff[f])
                    {
                        break;
                    }
                    if (w + 1 == f)
                    {
                        state = 1;
                        break;
                    }
                }

                f--;
            }
        }
        palin_st.push_back(make_pair(buff, state));
        k = m = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (i != k && palin_st[i].first == palin_st[k].first && palin_st[i].second == 1 && palin_st[k].second == 1)
            {
                palin_st[i].second = 0;
            }
        }
    }
    int palin_count = 0;
    for (auto pt : palin_st)
    {
        if (pt.second == 1)
        {
            // cout << pt.first << "--state->" << pt.second << endl;
            palin_count++;
        }
    }
    cout << palin_count << endl;
}
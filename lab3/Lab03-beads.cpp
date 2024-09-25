// 66070501052 Srisuphadith Rattanaprasert
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string txt, F, S;
    int p;
    int c = 0, out = 0, st = 0;
    cin >> txt;
    cin >> F;
    cin >> S;
    cin >> p;
    int txt_len = txt.size();

    for (int i = 0; i < txt_len; i++)
    {
        if (txt[i] == F[0])
        {
            st = 1;
            c++;
            if (p == 1)
            {
                out++;
            }
        }
        for (int k = i + 1; k < txt_len; k++)
        {
            if (st == 1)
            {
                c++;
            }
            if (txt[k] == S[0] && st == 1)
            {
                if (c >= p)
                {
                    out++;
                }
            }
        }
        c = 0;
        st = 0;
    }
    cout << out << endl;
}
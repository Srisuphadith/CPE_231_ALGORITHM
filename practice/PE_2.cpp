#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int rough(int n, vector<int> test)
{
    int sum_rough = 0;
    for (int q = 0; q < n - 1; q++)
    {
        sum_rough += abs(test[q] - test[q + 1]);
    }
    return sum_rough;
}
string bin_to_dec(int nBit, int val)
{
    vector<bool> bin(nBit, 0);
    string txt;
    int i = nBit - 1;
    while (i >= 0)
    {
        bin[i] = val % 2;
        val /= 2;
        i--;
    }
    for (int i = 0; i < nBit; i++)
    {
        txt[i] = bin[i];
    }
    return txt;
}
int main()
{
    int n, buff, l, m, r;
    vector<int> h_space; // ----ที่ดิน-----
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> buff;
        h_space.push_back(buff);
    }
    cin >> l >> m >> r;
    int stuff_size = 2 * m - l - r + 1; // ขนาดของดินที่จะเอามาถม
    vector<int> stuff(stuff_size, 0);   // ดินที่จะถม
    int tmp = l;
    //--------------สร้างดิน------------------
    for (int i = 0; i < m - l + 1; i++)
    {
        stuff[i] = tmp;
        tmp++;
    }
    tmp -= 2;
    for (int i = m - l + 1; i < stuff_size; i++)
    {

        stuff[i] = tmp;
        tmp--;
    }
    //--------------สร้างดิน------------------

    vector<int> test = h_space;    // ทดลองถม
    int move = n - stuff_size + 1; // จำนวนที่สามารถถมได้
    int s = 0, min_rough = 99999, sum_rough = 0;

    // หาค่า rough---------------------------ตอนยังไม่ถม
    sum_rough = rough(n, test);
    if (sum_rough < min_rough)
    {
        min_rough = sum_rough;
    }
    //cout << sum_rough<<endl;
    // หาค่า rough---------------------------ตอนยังไม่ถม
    int pn = pow(2, move);
    string txt;
    for (int j = 0; j < pn; j++)
    {
        txt = bin_to_dec(move, j);
        for (int k = 0; k < move; k++)
        {
            if (txt[k] == 1)
            {
                // ถม-----------
                for (int j = k; j < k + stuff_size; j++)
                {
                    test[j] += stuff[s];
                    s++;
                }
                s = 0;
                // ถม-----------
            }
        }
                //cout << endl;
        //  หาค่า rough---------------------------
        sum_rough = rough(n, test);
        if (sum_rough < min_rough)
        {
            min_rough = sum_rough;
        }
        //cout << "--"<< sum_rough<< "--"<<endl;
        // หาค่า rough---------------------------
         test = h_space;
    }
    cout << min_rough << endl;
}
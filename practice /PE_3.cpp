#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, tmp, d, min = 999, t;
    cin >> n;
    vector<int> fake;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        fake.push_back(tmp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            t = fake[j] - fake[i];
            if (t < min)
            {
                min = t;
            }
        }
    }
    cout << 0 << " ";
    for (int i = 0; i < n - 1; i++)
    {
        d = fake[i + 1] - fake[i] - min;
        fake[i + 1] = fake[i] + min;
        cout << d << " ";
    }
}
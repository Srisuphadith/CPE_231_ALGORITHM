#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    int n, code, score;
    cin >> n;
    vector<pair<int, int> > unsorted;
    vector<int> order;
    for (int i = 0; i < n; i++)
    {
        cin >> code >> score;
        unsorted.push_back(make_pair(code, score));
        order.push_back(i + 1);
    }
    int min, index;
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (unsorted[j].second > unsorted[max].second)
            {
                max = j;
            }
        }
        if (i != max)
        {
            int tmp = unsorted[i].second;
            unsorted[i].second = unsorted[max].second;
            unsorted[max].second = tmp;

            tmp = unsorted[i].first;
            unsorted[i].first = unsorted[max].first;
            unsorted[max].first = tmp;

            tmp = order[i];
            order[i] = order[max];
            order[max] = tmp;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int p = j;
        for (int k = j + 1; k < n; k++)
        {
            if (unsorted[j].second == unsorted[k].second)
            {
                j = k;
            }
            else
            {
                break;
            }
        }
        //cout << p << " " << j << endl;
        if (p != j)
        {
            for (int i = p; i <= j; i++)
            {
                int max = i;
                for (int q = i + 1; q <= j; q++)
                {
                    if (order[q] < order[max])
                    {
                        max = q;
                    }
                }
                if (i != max)
                {

                    int tmp = unsorted[i].second;
                    unsorted[i].second = unsorted[max].second;
                    unsorted[max].second = tmp;

                    tmp = unsorted[i].first;
                    unsorted[i].first = unsorted[max].first;
                    unsorted[max].first = tmp;

                    tmp = order[i];
                    order[i] = order[max];
                    order[max] = tmp;
                }
            }
        }
    }

    for (int i = 0;i<n;i++)
    {
        cout << unsorted[i].first <<endl;
    }
}
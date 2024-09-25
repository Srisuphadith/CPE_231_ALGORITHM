#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int n, a_tmp, b_tmp, min_mean_index;
    float a1, a2, b1, b2;
    vector<pair<int, int> > antenna;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a_tmp >> b_tmp;
        antenna.push_back(make_pair(a_tmp, b_tmp));
    }

    float sum = 0, mean = 999, index;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                a1 = antenna[i].first;
                a2 = antenna[j].first;
                b1 = antenna[i].second;
                b2 = antenna[j].second;
                //cout << a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
                sum += (abs(a1 - a2) / (abs(a1) + abs(a2))) + (abs(b1 - b2) / (abs(b1) + abs(b2)));
            }
        }
        //cout << "sum--" <<sum<< endl;
        sum = sum / (n - 1);
        if (sum < mean)
        {
            mean = sum;
            index = i;
            //cout <<"mean--" << mean <<"--"<<endl;
        }
        sum = 0;
    }
    cout << antenna[index].first << " " << antenna[index].second << endl;
    // int p = abs(a1-a2)/(abs(a1)+abs(a2))+abs(b1-b2)/(abs(b1)+abs(b2))
}
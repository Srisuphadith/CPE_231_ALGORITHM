//66070501052 Srisuphadith Rattanaprasert
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int p1, p2, p3, p4, n, d1, d2, d3, d4, sum;
    vector<int> my_array;
    int time_complex = 0;
    //รับค่าจำนวนไม้ในเเต่ละกล่อง
    cin >> p1;
    cin >> p2;
    cin >> p3;
    cin >> p4;
    //รับค่ามากที่สุดที่สามารถซื้อได้
    cin >> n;
    //หารหาจำนวนการวนรอบ
    d1 = n / p1;
    d2 = n / p2;
    d3 = n / p3;
    d4 = n / p4;
    my_array.assign(n, 0);
    //loop เเล้วเปลี่ยนค่าใน vecter ถ้าผลบวกไม่เกิน n ให้เปลี่ยนค่าจาก 0 เป็น 1 ที่ตำเเหน่งผลบวกนั้นๆ
    for (int i = 0; i <= d1; i++)
    {
        for (int j = 0; j <= d2; j++)
        {
            for (int k = 0; k <= d3; k++)
            {
                for (int m = 0; m <= d4; m++)
                {
                    sum = p1 * i + p2 * j + p3 * k + p4 * m;
                    time_complex++;
                    if (sum <= n and sum >= 0)
                    {
                        my_array[sum] = 1;
                    }
                }
            }
        }
    }
    //วนลูปหาจำนวนมากสุดที่เป็นไปไม่ได้ที่จะซื้อ
    for (int i = n; i >= 0; i--)
    {
        if (my_array[i] == 0)
        {
            //ปริ้นค่ามากที่สุดที่ไม่สามารถซื้อได้
            cout << i << endl;
            break;
        }
    }
    //ปริ้นค่า time_complexity
    cout << "time_complex = " << time_complex << endl;
}
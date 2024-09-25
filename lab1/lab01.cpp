#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
bool cmp1(int a, int b)
{
    return a < b ? 1 : 0;
}
bool cmp2(int a, int b)
{
    return a > b ? 1 : 0;
}
int main()
{
    int n, b;
    vector<int> p;
    vector<int> t;
    vector<int> sum_height;
    int total_sum = 0;
    //1.รับค่าจำนวนกระถางเเละต้นไม้
    cin >> n;
    //2.รับ input ความสูงกระถาง
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        p.push_back(b);
    }
    //3.รับ input ความสูงต้นไม้
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        t.push_back(b);
    }
    //4.sort ความสูงกระถางจาก มากไปน้อย
    sort(p.begin(), p.end(), cmp1);
    //5.sort ความสูงต้นไม้จาก น้อยไปมาก
    sort(t.begin(), t.end(), cmp2);
    //6.นำมาบวกกันตามลำดับจนหมด
    for (int i = 0; i < n; i++)
    {
        sum_height.push_back(p[i] + t[i]);
    }
    //**ขั้นตอนที่เกินจากที่เขียนในกระดาษ->ตอนเขียนไม่ได้นึกถึงว่าต้องเรียงก่อนนำมาหาผลต่าง->ถ้าไม่มีจะทำให้ผลลัพธ์ผิดผลาด->เรียงลำดับความสูงรวม จาก มากไปน้อย
    sort(sum_height.begin(), sum_height.end(), cmp1);
    //7.รวมผลค่าความต่างความสูง
    for (int i = 0; i < n - 1; i++)
    {
        total_sum += abs(sum_height[i] - sum_height[i + 1]);
    }
    //8.ปริ้นค่าความต่างความสูงที่น้อยที่สุด
    cout << total_sum<<endl;

    return 0;
}

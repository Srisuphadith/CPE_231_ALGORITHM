// 66070501052 Srisuphadith Rattanaprasert
#include <iostream>
using namespace std;
int time_complex = 0;
// ฟังก์ชันหาค่า factorial
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    time_complex++;
    return factorial(n - 1) * n;
}
int main()
{

    int n, p, s;
    int v;
    // รับค่า นศ เเละ อจ
    cin >> n;
    // รับค่าตำเเหน่ง อจ วี
    cin >> p;
    // รับค่ารหัส นศ
    for (int i = 0; i < n; i++)
    {
        cin >> s;
    }
    // รับค่าจำนวนคนไม่เอาอาจาร์วี
    cin >> v;
    // รับค่ารหัส นศ ที่ไม่เอาอาจารย์วี
    for (int i = 0; i < v; i++)
    {
        cin >> s;
    }
    // คำนวณวิธีที่เป็นไปได้
    n = (n - v) * factorial(n - 1);
    // ปริ้นจำนวนวิธี
    cout << n << endl;
    // ปริ้น time_complexity
    cout << "time_complex = " << time_complex << endl;
}
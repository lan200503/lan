#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

typedef long double lb;

vector<lb> a;

lb A, B, C1,C2, e1, e2;

void Print()
{
    cout << "==============================" << endl;
    cout << "1:计算A类不确定度" << endl;
    cout << "2:计算B类不确定度" << endl;
    cout << "3:合成不确定度(直接测量)" << endl;
    cout << "4:计算相对不确定度E" << endl;
    cout << "5:计算不确定度(间接测量)" << endl;
    cout << "6:计算相对误差" << endl;
    cout << "7:求某组数据的平均值" << endl;
    cout << "0:退出程序" << endl;
}

void Cin()
{
    vector<lb>().swap(a);
    cout << "请输入待处理数据的个数" << endl;
    int n;
    cin >> n;
    cout << "请输入数据" << endl;
    for (int i = 0; i < n; i++)
    {
        lb num;
        cin >> num;
        a.push_back(num);
    }
}

lb ave(vector<lb> a)
{
    lb sum = 0;

    for (lb n : a)
    {
        sum += n;
    }

    lb average = sum / a.size();

    cout << "数据的平均值为:" << average << endl;

    return average;
}

lb Ua()
{
    Cin();
    lb average = ave(a);
    lb Sq = 0;

    for (lb i : a)
    {
        Sq += pow(i - average, 2);
    }

    return sqrt(Sq / (pow(a.size(), 2) - a.size()));
}

lb Ub()
{
    cout << "请输入仪器最小分度值,无需计算填0" << endl;
    lb b;
    cin >> b;
    return b / sqrt(3);
}

lb Uc()
{
    lb p, q;
    cout << "请输入A类不确定度和B类不确定度" << endl;
    cin >> p >> q;
    return sqrt(pow(p, 2) + pow(q, 2));
}

lb Uc2()
{
    lb p, q;
    cout << "请输入相对不确定度E和平均值" << endl;
    cin >> p >> q;
    return p*q;
}

lb E1()
{
    cout << "请输入平方和的个数" << endl;
    int n;
    cin >> n;
    lb e = 0.0;
    for (int i = 0; i < n; i++)
    {
        lb p, q;
        cout << "请输入p(不确定度),q(平均值)" << endl;
        cin >> p >> q;
        e += pow(p / q, 2);
    }

    return sqrt(e);
}

lb E2()
{
    cout << "请输入理论值和计算值" << endl;
    lb p, q;
    cin >> p >> q;
    return abs(p - q) / p;
}

int main()
{

    while (true)
    {
        Print();
        cout << "退出请输入0,否则继续请输入数字操作：";
        char c;
        cin >> c;
        switch (c)
        {
        case '0':
            cout << "再见" << endl;
            exit(0);
            break;
        case '1':
            A = Ua();
            cout << "A类不确定度为:" << A << endl;
            break;
        case '2':
            B = Ub();
            cout << "B类不确定度为:" << B << endl;
            break;
        case '3':
            C1 = Uc();
            cout << "不确定度(直接)为:" << C1 << endl;
            break;
        case '4':
            e1 = E1();
            cout << "相对不确定度为:" << e1 << endl;
            break;
        case '5':
            C2 = Uc2();
            cout << "不确定度(间接)为:" << C2 << endl;
            break;
        case '6':
            e2 = E2();
            cout << "相对误差为:" << e2 * 100 << "%" << endl;
            break;
        case '7':
            Cin();
            ave(a);
            break;
        }
    }
    return 0;
}

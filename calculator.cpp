//Calculation.cpp : 定义控制台应用程序的入口点。
//
//#include"stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

int Test(string as)
{
    string::size_type len = as.size();
    string::size_type i = 0;
    int k = 0;
    while (i < len)
    {
        if (!((as[i] >= '0' && as[i] <= '9') || as[i] == '+' || as[i] == '-' || as[i] == '*' || as[i] == '/' || as[i] == '.' || as[i] == '(' || as[i] == ')'))
        {
            cout << "输入的表达式错误，请重新输入！" << endl;
            return 0;
        }
        if (as[i] == '/' && as[i + 1] == '0')
        {
            cout << "分母不能为零！" << endl;
            return 0;
        }
        if (as[i] == '(')
            k++;
        else if (as[i] == ')')
        {
            k--;
            if (k < 0)
                return 0;
        }
        i++;
    }
    if (k != 0)
    {
        cout << "括号输入错误！" << endl;
        return 0;
    }
    return 1;
}

string stringtoarr(const string str) //将一个字符串转化成两个数组，一个为数字数组保存数字，另一个为字符数组，保存符号
{                                    //此函数将用于无括号的计算。
    int i = 0, z = 0, s, temp;
    float rate = 10.0, itemp = 0.0;
    float valueStr = 0.0;
    float a[40];
    char b[20];
    for (i = 0; i < 40; i++)
        a[i] = 0.0; //对数组a[20]初始化
    for (i = 0; i < 20; i++)
        b[i] = ' '; //对数组b[10]初始化
    i = 0;          //把0赋给i
    for (i = 0; i < str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9') //如果字符串str.GetAt(i)的内容是整数
        {
            if (rate == 10.0)                          //整数部分
                itemp = itemp * rate + (str[i] - '0'); //获得整数
            else                                       //小数部分
            {
                itemp = itemp + rate * (str[i] - '0'); //获得小数
                rate = rate / 10;                      //每次让rate小10倍
            }
        }
        else if (str[i] == '.') //如果str.GetAt(i)是小数点
            rate = 0.1;         //让rate=0.1，开始计算小数部分
        else if (str[i] == '+') //如果str.GetAt(i)是加号
        {
            a[z] = itemp;
            itemp = 0;   //把itemp的值放入双精度数组a中，并把itemp的值改为0
            z++;         //让z自加一次
            b[z] = '+';  //把加号放入字符数组b中
            z++;         //让z自加一次
            rate = 10.0; //把10赋给rate，确保读取下个数字时，先计算整数部分
        }
        else if (str[i] == '-') //如果str.GetAt(i)是减号
        {
            a[z] = itemp;
            itemp = 0;   //把itemp的值放入双精度数组a中，并把itemp的值改为0
            z++;         //让z自加一次
            b[z] = '-';  //把减号放入字符数组b中
            z++;         //让z自加一次
            rate = 10.0; //把10赋给rate，确保读取下个数字时，先计算整数部分
        }
        else if (str[i] == '*') //如果str.GetAt(i)是乘号
        {
            a[z] = itemp;
            itemp = 0;   //把itemp的值放入双精度数组a中，并把itemp的值改为0
            z++;         //让z自加一次
            b[z] = '*';  //把减号放入字符数组b中
            z++;         //让z自加一次
            rate = 10.0; //把10赋给rate，确保读取下个数字时，先计算整数部分
        }
        else if (str[i] == '/') //如果str.GetAt(i)是除号
        {
            a[z] = itemp;
            itemp = 0;   //把itemp的值放入双精度数组a中，并把itemp的值改为0
            z++;         //让z自加一次
            b[z] = '/';  //把除号放入字符数组b中
            z++;         //让z自加一次
            rate = 10.0; //把10赋给rate，确保读取下个数字时，先计算整数部分
        }
    }
    a[z] = itemp; //把最后一个整数itemp的值放入双精度数组a中
    s = z;        //把z的值赋给变量s，用来控制计算结果的循环中的条件,s即为数与值的大小。
    for (i = 0; i <= s; i++)
    {
        if (b[i] == '/') //当循环遇到除号时
        {
            a[i + 1] = 1 / a[i + 1]; //把a[i+1]的值改为1/a[i+1]
            b[i] = '*';              //把b[i]的值改为乘号
        }
    }
    for (i = 0; i <= s; i++)
    {
        while (b[i] == '*') //当循环遇到乘号时
        {
            a[i - 1] = a[i - 1] * a[i + 1];
            for (temp = i + 1; temp + 2 < 40; temp++)
                a[temp] = a[temp + 2];
            for (temp = i; temp + 2 < 20; temp++)
                b[temp] = b[temp + 2];
        }
    }
    valueStr = a[0];
    for (i = 0; i < s; i++)
    {
        if (b[i] == '+')
            valueStr += a[i + 1];
        else if (b[i] == '-')
            valueStr -= a[i + 1];
    }
    char svalue[16];
    sprintf(svalue, "%f", valueStr);
    string ssavalue(svalue);
    return ssavalue;
}

string trims(const string &sub)
{
    string s1, s2, s3, sp, ss;
    int i;
    int counter = 0;
    int left, right;
    if (string::size_type pos1 = sub.find(")") == string::npos)
        return sub;
    for (i = 0; sub[i]; i++)
        if (sub[i] == '(')
        {
            left = i;
            counter++;
            break;
        }
    for (i = left + 1; sub[i]; i++)
    {
        if (sub[i] == '(')
            counter++;
        else if (sub[i] == ')')
            counter--;
        if (counter == 0)
        {
            right = i;
            break;
        }
    }
    s1 = sub.substr(0, left);
    sp = sub.substr(left + 1, right - left - 1);
    s2 = stringtoarr(trims(sub.substr(left + 1, right - left - 1)));
    s3 = trims(sub.substr(right + 1));
    ss = s1 + s2 + s3;
    return ss;
}

void calcation(string &str1)
{
    int stTe;
    if ((stTe = Test(str1)) <= 0)
    {
        cout << "输入字符串有误，请重新输入！！！" << endl;
        return;
    }
    string sk = trims(str1);
    string ssk = stringtoarr(sk);
    cout << ssk << endl;
    cout << "--------------------" << endl;
}

int main()
{
    string input_str;
    int p = 1;
    int tsTest;
    //string tss;
    while (1)
    {
        cout << "请输入表达式(退出请输入小写exit):" << endl;
        cin >> input_str;
        cout << endl;
        if (input_str.compare("exit") == 0)
            break;
        if ((tsTest = Test(input_str)) == 1)
        {
            calcation(input_str);
            //tss=trims(input_str);
            //cout<<stringtoarr(tss)<<endl;
        }
    }
    cout << "Close this calculation！" << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

/*
You’re given n  dates in format DD-MM-YYYY . Sort them in ascending and print in te same format.
*/
struct date {
    int day;
    int month;
    int year;
};

bool cmp(date a, date b){
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;    
}

int main() {
    
    int n;
    date d[1005];
    string s;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        /*
        这是一个将字符数字转换为整数的经典技巧。它取出字符串的第 0 位和第 1 位（代表“天”），
        通过减去字符 '0' 的 ASCII 值将它们转换为数字，然后组合成一个完整的整数。
        例如，对于 "25"，它会计算 ('2'-'0')*10 + ('5'-'0')，即 2*10 + 5 = 25。
        */
        int _day = (s[0] - '0') * 10 + (s[1] - '0');
        int _month = (s[3] - '0') * 10 + (s[4] - '0');
        int _year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
        d[i].day = _day;
        d[i].month = _month;
        d[i].year = _year;
    }
    sort(d + 1, d + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        if(d[i].day < 10) cout << 0 << d[i].day << '-';
        else cout << d[i].day << '-';
        if(d[i].month < 10) cout << 0 << d[i].month << '-';
        else cout << d[i].month << '-';
        cout << d[i].year << '\n';
    }
    
    return 0;
}
/*************************************************************************
	> File Name: EP19.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Jun 2020 06:05:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int is_val(int year, int month, int day) {
    if (month < 3) {
        year -= 1;
        month += 12;
    }
    int week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400);
    week %= 7;
    return week == 6;
}

int main() {
    int sunday = 0;
    for (int year = 1901; year < 2001; year++) { 
        for (int month = 1; month <= 12; month++) {
            if (!is_val(year, month, 1)) continue;
            sunday += 1;
        }
    }
    cout << sunday << endl;
    return 0;
}

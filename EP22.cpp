/*************************************************************************
	> File Name: EP22.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jun 2020 02:38:41 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#include "names.txt"

bool cmp(string a, string b) {
    return a < b;
}

typedef long long ll;

int add_to_num(string str, int n) {
    int ret = 0;
    for (int i = 0; str[i]; i++) {
        ret += str[i] - 'A' + 1;
    }
    return ret * n;
}

int main() {
    int n = 0;
    ll sum = 0;
    for (int i = 0; name[i] != "\0"; i++) n++;
    sort(name, name + n, cmp);
    for (int i = 0; i < n; i++) {
        sum += add_to_num(name[i], i+ 1);
    }
    cout << sum << endl;
    return 0;
}

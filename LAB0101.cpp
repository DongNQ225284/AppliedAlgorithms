/*
Problem: LAB.01.01 - Telco Data check & query
Description
Write a C program to perform some queries on a telco Data (comming from stdin) with the following format:
The first block of Data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under 
the form: 
        call <from_number> <to_number> <date> <from_time> <end_time> 
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, 
terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, 
the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
 
The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) 
and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) val 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the Data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output
1
2
4
398
120
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Data {
    string from_num; //key
    string to_num;
    string date;
    string from_time;
    string end_time;
    ll total_time;
    bool is_correct;
    Data(string input) {
        istringstream ss(input);
        string cmd;
        ss >> cmd >> from_num >> to_num >> date >> from_time >> end_time;
    
        char chr;
        istringstream str1(from_time);
        ll h1, m1, s1;
        str1 >> h1 >> chr >> m1 >> chr >> s1;
        
        istringstream str2(end_time);
        ll h2, m2, s2;
        str2 >> h2 >> chr >> m2 >> chr >> s2;

        if (s2 < s1) {
            s2 += 60;
            m2 --;
        }
        if (m2 < m1) {
            m2 += 60;
            h2--;
        }
        total_time = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
        is_correct = from_num.length() == 10 && to_num.length() == 10;
    }
};

multimap<string, Data> List;
ll incorrect = 0;

void input() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;;
        Data tel(line);
        incorrect += !tel.is_correct;
        List.insert({tel.from_num, tel});
    }
}

ll query(string format) {
    istringstream ss(format);
    string cmd, val;
    ss >> cmd >> val;
    if (cmd == "?check_phone_number") {
         return incorrect == 0;
    } else if (cmd == "?number_calls_from") {
        return List.count(val);
    } else if (cmd == "?number_total_calls") {
        return List.size();
    } else if (cmd == "?count_time_calls_from") {
        auto range = List.equal_range(val);
        ll sum = 0;
        for (auto it = range.first; it != range.second; it++) {
            Data tel = it->second;
            sum += tel.total_time;
        }
        return sum;
    } else {
        return -1;
    }
}

void solve() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;
        cout << query(line) << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}


/*
Problem: LAB.01.01 - Telco data check & query
Description
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under 
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
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
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
using namespace std;

class Telcodata {
private:
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;

public:
    Telcodata(string telcodate) {
        istringstream ss(telcodate);
        string command, from_number, to_number, date, from_time, end_time;
        ss >> command >> from_number >> to_number >> date >> from_time >> end_time;
        this->from_number = from_number;
        this->to_number = to_number;
        this->date = date;
        this->from_time = from_time;
        this->end_time = end_time;
    }

    bool isCorrect() {
        return from_number.length() == 10 && to_number.length() == 10;
    }

    string get_fromNumber() {
        return this->from_number;
    }

    size_t get_totalTime() {
        char chr;
        istringstream str1(this->from_time);
        size_t h1, m1, s1;
        str1 >> h1 >> chr >> m1 >> chr >> s1;
        istringstream str2(this->end_time);
        size_t h2, m2, s2;
        str2 >> h2 >> chr >> m2 >> chr >> s2;

        if (s2 < s1) {
            s2 += 60;
            m2 --;
        }
        if (m2 < m1) {
            m2 += 60;
            h2--;
        }
        return (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
    }
};
class Solution {
private:
    multimap<string, Telcodata> list; //<key = from_number, value = Telcodate>
    vector<string> query_list;
    vector<int> result;
    bool isCorrect = true;

public:
    void init(bool inputFromFile = false) {
        if (inputFromFile) {
            ifstream file("LAB0101.txt");
            string line;
            while (getline(file, line)) {
                if (line == "#") break;
                Telcodata telcodate(line);
                isCorrect = telcodate.isCorrect();
                list.insert({telcodate.get_fromNumber(), telcodate});
            }
            while (getline(file, line)) {
                if (line == "#") break;
                query_list.push_back(line);
            }
        } else {
            string line;
            while (getline(cin, line)) {
                if (line == "#") break;;
                Telcodata telcodate(line);
                isCorrect = telcodate.isCorrect();
                list.insert({telcodate.get_fromNumber(), telcodate});
            }
            while (getline(cin, line)) {
                if (line == "#") break;
                query_list.push_back(line);
            }
        }
    }
    int query(string format) {
        istringstream ss(format);
        string command, value;
        ss >> command >> value;
        if (command == "?check_phone_number") {
             return this->isCorrect;
        } else if (command == "?number_calls_from") {
            return this->list.count(value);
        } else if (command == "?number_total_calls") {
            return list.size();
        } else if (command == "?count_time_calls_from") {
            auto range = this->list.equal_range(value);
            int total_times = 0;
            for (auto it = range.first; it != range.second; it++) {
                Telcodata tel = it->second;
                total_times += tel.get_totalTime();
            }
            return total_times;
        } else {
            return -1;
        }
    }
    void solve(bool debug = false) {
        for (string line : query_list) {
            result.push_back(query(line));
            if (debug) {
                cout << line << endl;
                printf("ans: %d\n", query(line));
                char chr; cin >> chr;
            }
        }
    }

    void show() {
        for (const int& val: result) {
            cout << val << endl;
        }
    }
};

int main() {
    Solution solution;
    bool inputFromFile = true; //set
    bool debug = false; //debug?
    bool clock = false; //want to measure time?
    solution.init(inputFromFile);
    auto start = chrono::high_resolution_clock::now();
    solution.solve(debug);
    solution.show();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    if (clock) cout << "Runtimes: " << 1000 * elapsed.count() << "ms\n";
    return 0;
}
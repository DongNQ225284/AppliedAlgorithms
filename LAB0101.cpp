/*
LAB.01.01 - Kiểm tra & truy vấn dữ liệu viễn thông
Mô tả
Viết một chương trình để thực hiện một số truy vấn trên dữ liệu viễn thông (được nhập từ stdin) với định dạng như sau:

Khối dữ liệu đầu tiên
Gồm nhiều dòng (kết thúc bằng một dòng chứa dấu #, tổng số dòng có thể lên đến 100.000),
mỗi dòng có dạng:
call <from_number> <to_number> <date> <from_time> <end_time>
Nghĩa là một cuộc gọi từ số điện thoại <from_number> đến <to_number> vào ngày <date>,
bắt đầu lúc <from_time> và kết thúc lúc <end_time>.

Giải thích chi tiết:
<from_number> và <to_number> là chuỗi gồm 10 ký tự
(một số điện thoại là hợp lệ nếu chỉ chứa các chữ số từ 0 đến 9, nếu có ký tự khác thì không hợp lệ).

<date> có dạng YYYY-MM-DD (ví dụ: 2022-10-21)

<from_time> và <to_time> có dạng hh:mm:ss (ví dụ: 10:07:23)

Khối truy vấn thứ hai
Gồm nhiều dòng (kết thúc bằng một dòng chứa dấu #, tổng số dòng có thể lên đến 100.000),
mỗi dòng là một truy vấn thuộc một trong các loại sau:

?check_phone_number
→ In ra 1 nếu không có số điện thoại nào sai định dạng, ngược lại là 0.

?number_calls_from <phone_number>
→ In ra số lần gọi được thực hiện từ số điện thoại <phone_number>.

?number_total_calls
→ In ra tổng số cuộc gọi trong toàn bộ dữ liệu.

?count_time_calls_from <phone_number>
→ In ra tổng thời gian gọi (tính bằng giây) từ số điện thoại <phone_number>.

Ví dụ
Input:
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
Output:
1
2
4
398
120
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Cấu trúc lưu trữ
struct Data {
    string from_num; //key
    string to_num;
    string date;
    string from_time;
    string end_time;
    ll total_time;
    bool is_correct; //dữ liệu có hợp lệ?

    Data(string input) {
        //tách dữ liệu vào các trường
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

        //tính total_time
        if (s2 < s1) {
            s2 += 60;
            m2 --;
        }
        if (m2 < m1) {
            m2 += 60;
            h2--;
        }
        total_time = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
        //kiểm tra dữ liệu có hợp lệ không?
        is_correct = from_num.length() == 10 && to_num.length() == 10;
    }
};

//sử dụng map để lưu trữ
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
        //lấy ra các phần tử có key là from_num, thực hiện tính tổng total_time
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


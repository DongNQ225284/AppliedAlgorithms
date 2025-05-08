/*
LAB.04.04 - Khai thác vàng

Mô tả
Vương quốc ALPHA có n kho vàng nằm dọc theo một đường thẳng và được đánh số từ 1 đến n.
Mỗi kho vàng thứ i có số lượng vàng là ai (ai là số nguyên không âm) và nằm ở tọa độ i.
Nhà vua của vương quốc ALPHA mở một cuộc thi dành cho các thợ săn vàng. Nhiệm vụ của họ là chọn ra một tập con các kho vàng sao cho tổng lượng vàng là lớn nhất, đồng thời thỏa mãn điều kiện sau:
Khoảng cách giữa hai kho vàng bất kỳ được chọn phải nằm trong khoảng [L₁, L₂], tức là lớn hơn hoặc bằng L₁ và nhỏ hơn hoặc bằng L₂.

Input
Dòng 1: Gồm 3 số nguyên: n, L₁, L₂ (1 ≤ n ≤ 1.000.000, 1 ≤ L₁ ≤ L₂ ≤ n)
Dòng 2: Gồm n số nguyên a₁, a₂, ..., aₙ — đại diện cho lượng vàng tại mỗi kho (0 ≤ ai)

Output
In ra một số nguyên duy nhất là tổng lượng vàng lớn nhất có thể thu được theo quy tắc chọn trên.

Ví dụ
Input:
6 2 3
3 5 9 6 7 4
Output:
19
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX 50
#define INF 1e9

using namespace std;

struct Place{
    ll x, y;
    bool rotated;
    Place() {
        this->x = this->y = 0;
        this->rotated = 0;
    }
    Place(ll x, ll y, ll rotated) {
        this->x = x;
        this->y = y;
        this->rotated = rotated;
    }
};
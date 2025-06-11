#pragma once
#include <bits/stdc++.h>
using namespace std;

const int q = 7681;

pair<int,int> GS(int a, int b, int fac){
    int u = (a+b);
    int s2 = (a-b+q);
    int v = (s2*fac)%q;
    return {u,v};
}
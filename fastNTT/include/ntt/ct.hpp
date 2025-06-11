#pragma once
#include <bits/stdc++.h>
using namespace std;

const int q = 7681;


pair<int,int> CT(int a, int b, int fac){
    int bp = (b*fac)%q;
    int u = (a+bp)%q;
    int v = (a -bp + q)%q;
    return {u,v};
}
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "DisjointSet.h"

int main() {
    int n,m;
    std::cin>>n>>m;
    DisjointSet set(n);
    for (int i = 0; i < m; ++i) {
        int a,b;
        std::cin>>a>>b;
        a--;
        b--;
        set.connect(a,b);
    }
    int q;
    std::cin>>q;
    for (int i = 0; i < q; ++i) {
        int a,b,c;
        std::cin>>a>>b>>c;
        b--;
        c--;
        if(a==2){
            set.connect(b,c);
        }else{
            std::cout<<set.connected(b,c);
        }
    }

    return 0;
}

using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>


int main(){

    freopen("beautiful_strings.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    getchar();
    for (int run = 1; run <= T; ++run) {
        char c;
        vector<int> v(26,0);
        while((c=getchar()) != '\n') {
            if( c >= 'a' && c <= 'z' )
                v[c -'a']++;
            else if( c >= 'A' && c <= 'Z' )
                v[c -'A']++;
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0LL;
        for(int i = 0 ;i < 26 ; ++i)
            ans = ans + v[i]*(26LL-i);
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}
        cout<<"Case #"<<tt<<": " <<count<<endl;
    }

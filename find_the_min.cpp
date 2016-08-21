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

    freopen("find_the_min.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    getchar();
    for (int run = 1; run <= T; ++run) {
       int n, k, a, b, c, r;
       cin >> n >> k >> a >> b >> c >> r;
       vector<int> m(k+1,0);
       multiset<int> ss;
       m[1] = a;
       ss.insert(a);
       for(int i = 2 ; i <= k ; ++i){
            m[i] = (b*(long long)m[i-1]  +  (long long)c)%r;
            ss.insert(m[i]);
       }
       set<int> s2;
       for(int i = 0 ; i <= k ; ++i){
            if(ss.find(i) == ss.end() )
                   s2.insert(i);
       }
       n  = (n-k-1)%(k+1);
       int ans =  *(s2.begin());
       s2.erase(ans);
       ss.insert(ans);
       for(int i = 1 ; i <= n ; ++i ){
            s2.insert(m[i]);
            multiset<int>::iterator it = ss.find(m[i]);
            ss.erase( it );
            while(1){
                ans =  *(s2.begin());
                s2.erase(ans);
                if(ss.find(ans) == ss.end()){
                    ss.insert(ans);
                    break;
                }
            }
       }
       cout<<"Case #"<<run<<": " << ans <<endl;
    }
    return 0;
}


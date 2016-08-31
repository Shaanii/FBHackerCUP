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
#include<limits.h>
#include <stack>
#include <list>
#include <map>
#include <set>
#define mod 1000000007

int main(){
    freopen("laundro_matt.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        long long l, m, n, d;
        cin >> l >> n >> m >> d;
        vector<int> v(n);
        m = min(n,m);
        priority_queue <pair<long long, int> > q;
        for(int i = 0 ; i < n ; ++i){
            cin >> v[i];
            q.push(make_pair(-1LL*v[i], i));
        }
        vector<long long> awash(l,0LL);
        for(int i = 0  ; i < l ; ++i){
            pair<long long, int > temp  = q.top();
            q.pop();
            awash[i] = abs(temp.first);
            temp.first += -1LL*v[temp.second];
            q.push(temp);
        }
        queue<long long> dry;
        for(int  i = 0; i < m ; ++i)
            dry.push(0LL);
        long long ans = 0LL;
        for(int  i = 0; i < l ; ++i){
            long long temp = dry.front();
            dry.pop();
            ans = max( ans,  (awash[i] + max(0LL, temp - awash[i]) + d)  );
            dry.push(temp + d);
        }
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}

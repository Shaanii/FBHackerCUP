
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
#define mod 1000000007
vector<long long> fact,infact;
long long raise(long long x, long long y) {
    if(x == 1LL)
        return x;
    if( y == 1LL)
        return x;
    long long temp = raise(x,y/2LL);
    temp =  ( temp * temp )%mod;
    if( y & 1LL)
        return (temp * x)%mod;
    else
        return temp;
}
long long func(long long i , long long k) {

    return ( ( ( (fact[i]*infact[k] )%mod ) * infact[i-k] )%mod ) ;
}
int main(){
    freopen("card_game.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        int n, k;
        cin >> n >> k;
        vector<long long> v(n, 0LL);
        for(int i = 0 ; i < n ; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        fact.resize(n+1);
        infact.resize(n+1);
        fact[0] = 1LL;
        infact[0]  = 1LL;
        for(int i = 1; i <= n ; ++i){
            fact[i] = (fact[i-1]*(long long)i )%mod;
            infact[i] = raise(fact[i],mod-2LL);
        }
        long long ans = 0LL;
        for(int i = k-1 ;  i < n ; ++i)
            ans =  ( (ans + ((v[i]*func(i,k-1))%mod) )%mod );
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}


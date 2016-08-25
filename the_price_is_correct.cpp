
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
    freopen("the_price_is_correct.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        int n;
        long long p;
        cin >> n >> p;
        vector<long long> v(n);
        for(int i = 0 ; i < n ; ++i)
            cin >> v[i];
        long long sum = 0LL;
        int left = 0, right = 0;
        long long ans = 0LL;
        while( right < n){
            if(sum + v[right] > p){
               ans += right - left;
               sum  -=  v[left];
               ++left;
            }
            else
                sum = sum + v[right++];
        }
        while(left < n) {
            ans += (long long)n-left;
            ++left;
        }
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}

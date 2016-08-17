#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<set>
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
//#define LLONG_MAX (ll)10000000007*(ll)10000000007
using namespace std;

bool static comp(string a, string b ){
    return a+b <  b+a;
}
int main()
{
    freopen("turn_on_the_lights.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        int r,c;
        cin >> r >> c;
        vector<string> v(r);
        for(int i = 0 ; i < r ; ++i)
            cin >> v[i];
        int  k = (1<<c);
        int ans = INT_MAX;
        for(int i = 0 ; i < k  ; ++i) {
            int temp = 0;
            string curr = v[0], next, prev;
            if(r > 1)
                next = v[1];
            for(int  j = 0; j < c ; ++j)
                 if( ( ( (1<<j) & i )  &&  curr[c-1-j] == '.'  ) ||     (  (!( (1<<j) & i) )  && curr[c-1-j] == 'X' )  ){
                        ++temp;
                        if(j-1 >= 0)
                            curr[j-1] = (curr[j-1] == 'X') ? '.' : 'X';
                        if(j+1 < c)
                            curr[j+1] = (curr[j+1] == 'X') ? '.' : 'X';
                        curr[j] = (curr[j] == 'X') ? '.' : 'X';
                        if( r > 1)
                            next[j] = (next[j] == 'X') ? '.' : 'X';
            }
        //    cout<<"temp  "<<temp<<endl;
            prev = curr;
            for(int a = 1 ; a < r ; ++a){
                curr = next;
                if( a+1 < r)
                    next = v[a+1];
                for(int b = 0 ; b < c ; ++b) {
                    if(prev[b] == '.') {
                        ++temp;
                        if(b-1 >= 0)
                            curr[b-1] = (curr[b-1] == 'X') ? '.' : 'X';
                        if(b+1 < c)
                            curr[b+1] = (curr[b+1] == 'X') ? '.' : 'X';
                        curr[b] = (curr[b] == 'X') ? '.' : 'X';
                        if(a+1 <  r)
                            next[b] = (next[b] == 'X') ? '.' : 'X';
                    }
               }
               prev = curr;
            }
            int b;
            for( b = 0 ; b < c ; ++b )
                if(prev[b] == '.')
                    break;
            if(b == c)
                ans = min(ans, temp);
        }
     if(ans == INT_MAX)
        ans = -1;
     cout<<"Case #"<<tt<<": " <<ans<<endl;
    }
    return 0;
}

/* freopen("A-small-practice.in","r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        int n;
        cin >> n;
        for(int i = 0; i< n ; ++i){
            int j, w;
            cin >> j >> w;
            for(int k = 1 ; k < j ; ++k){



            }
        }
        cout<<"Case #"<<tt<<": " <<count<<endl;
    }
 

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

int main()
{
    freopen("squished_status.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        int m;
        string str;
        cin>> m;
        cin >> str;
        str = '#' + str;
        int ans = 0;
        int n = str.length();
        vector<long long> v(n,0);
        v[0] = 1;
        if ( (str[1]-'0') <= m  &&  (str[1] - '0') > 0)
            v[1] = 1;
        for(int i = 2 ; i < n ; ++i) {
           int  num1 = (int)(str[i]-'0');
           if ( num1 <= m  &&  num1 > 0)
                v[i] = v[i-1];
           int num2 = (int)(str[i-1]-'0')*10 + num1;
           if ( num2 <= m  &&  num2 > 0   && str[i-1] != '0')
                v[i] = (v[i] + v[i-2])% 4207849484;
           if(i-2 >= 1){
                int num3 = (int)(str[i-2]-'0')*100 + num2;
                if ( num3 <= m  &&  num3 > 0  && str[i-2] != '0'){
                    v[i] = (v[i] + v[i-3])% 4207849484;
                }
           }
        }
        cout<<"Case #"<<tt<<": " <<v[n-1]<<endl;
    }
    return 0;
}

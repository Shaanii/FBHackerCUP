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
    freopen("billboards.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ;++tt) {
        int w,h;
        cin>>w>>h;
        getchar();
        char c;
        vector<int> v;
        string str = "";
        while( ( c = getchar() ) != '\n' ) {
            if(c == ' '){
                v.push_back(str.length());
                str.clear();
            }
            else
                str = str + c;
        }
        v.push_back(str.length());
       int i;
        for( i = 1000 ; i >= 1 ; --i) {
            int wu = w, hw = h, k = 0;
            for(; k < v.size() ; ++k ){
                if(hw < i)
                    break;
                if( wu - v[k]*i < 0 ){
                    if(hw - i < 0)
                        break;
                    else{
                        k--;
                        wu = w;
                        hw = hw - i;
                    }
                }
                else {
                    wu = wu - v[k]*i;
                    if(wu > 0)
                        wu =  wu-i;
                }
            }
            if(k == v.size())
                break;
        }
        cout<<"Case #"<<tt<<": " <<i<<endl;
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


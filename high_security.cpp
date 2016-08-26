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
    freopen("high_security.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
       int n;
       cin >> n;
       string str1, str2;
       cin >> str1 >> str2;
       int i = 0;
       vector<vector<int> >  v(2, vector<int>(n,0));
       int ans = 0;
       bool flag = false;
       for( i = 0 ; i < n ; ++i){
            if(str1[i] == '.'  &&  !flag){
                flag = true;
                ++ans;
                v[0][i] = ans;
             }
            else if( str1[i]  != '.')
                flag = false;
            else
                v[0][i] = ans;
       }
       flag = false;
       for( i = 0 ; i < n ; ++i){
            if(str2[i] == '.'  &&  !flag){
                flag = true;
                ++ans;
                v[1][i] = ans;
             }
            else if( str2[i]  != '.')
                flag = false;
            else
                v[1][i] = ans;
       }
       for(int i = 0 ; i < n ; ++i){
         if(v[0][i] > 0   &&  ( i == 0  || (i-1 >= 0  &&  v[0][i-1] <= 0) )  &&  ( ( i+1 < n && v[0][i+1] <= 0) ||  i+1 >= n )  && v[1][i] > 0 ){
            v[0][i] = -1;
            --ans;
            int temp = v[1][i];
            int j = i;
            while( j < n  && v[1][j] == temp){
                v[1][j] = -1;
                ++j;
            }
            j = i-1;
            while( j >= 0   && v[1][j] == temp){
                v[1][j] = -1;
                --j;
            }
         }

       }
        for(int i = 0 ; i < n ; ++i){
         if(v[1][i] > 0   &&  ( i == 0  || (i-1 >= 0  &&  v[1][i-1] <=  0) )  &&  ( ( i+1 < n && v[1][i+1] <= 0) ||  i+1 >= n )  && v[0][i] > 0 ){
            v[1][i] = -1;
            --ans;
            int temp = v[0][i];
            int j = i;
            while( j < n  && v[0][j] == temp){
                v[0][j] = -1;
                ++j;
            }
            j = i-1;
            while( j >= 0   && v[0][j] == temp){
                v[0][j] = -1;
                --j;
            }
         }
       }

     cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}

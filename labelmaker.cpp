
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

int main(){
    freopen("labelmaker.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        string str;
        cin >> str;
        long long n = str.length();
        long long a;
        cin >> a;
        string ans = "";
        while(a > 0){
            long long rem = a%n;
            if( rem == 0LL){
                rem = n - 1LL;
                a = (a/n )-1LL;
            }
            else{
                rem--;
                a = a /n;
            }
            ans = str[rem] + ans;
        }
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}


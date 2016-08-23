
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
    //freopen("laser_maze.txt","r",stdin);
    //freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        int n,m;
        cin >> n >> m;
        map<char,char> mp;
        mp['>'] = 'v';
        mp['v'] = '<';
        mp['<'] = '^';
        mp['^'] = '>';
        pair<int,int> src;
        char block[4][n][m];
        for(int i = 0; i < n ; ++i)
            for(int j = 0; j < m ; ++j){
                cin >> block[0][i][j];
                if( block[0][i][j] == 'S')
                    src = make_pair(i,j);
            }
        for(int k = 0 ; k < 3 ; ++k)
            for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < m ; ++j)
                    if(  mp.find( block[k][i][j]  ) != mp.end() )
                        block[k+1][i][j] = mp[  block[k][i][j]  ];
                    else
                         block[k+1][i][j] = block[k][i][j] ;

        for(int k = 0 ; k <= 3 ; ++k)
            for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < m ; ++j){
                        if( block[k][i][j] ==  'v'){
                                block[k][i][j] = '#';
                                for(int p = i+1 ; ( p < n   && (block[k][p][j] == 'G' ||  block[k][p][j] == 'S' || block[k][p][j] == '.' ) )  ; ++p)
                                       block[k][p][j] = '#';
                        }
                        if( block[k][i][j] ==  '^') {
                                block[k][i][j] = '#';
                                for(int p = i-1 ; ( p >= 0   && (block[k][p][j] == 'G' ||  block[k][p][j] == 'S' || block[k][p][j] == '.' ) ) ; --p)
                                       block[k][p][j] = '#';
                        }
                        if( block[k][i][j] ==  '>') {
                                block[k][i][j] = '#';
                                for(int p = j+1 ; ( p < m  && (block[k][i][p] == 'G' ||  block[k][i][p] == 'S' || block[k][i][p] == '.' )) ; ++p)
                                       block[k][i][p] = '#';
                        }
                        if( block[k][i][j] ==  '<') {
                                block[k][i][j] = '#';
                                for(int p = j-1 ;  ( p >= 0   &&  (block[k][i][p] == 'G' ||  block[k][i][p] == 'S' || block[k][i][p] == '.') ) ; --p)
                                       block[k][i][p] = '#';
                        }
                }

        queue<pair<int,int> > q;
        queue<int> st;
        q.push(src);
        st.push(0);
        block[0][src.first][src.second] = '#';
        bool flag = false;
        int xdir[4] = {1,-1,0,0};
        int ydir[4] = {0,0,-1,1};
        int count;
        while( !q.empty()){
            if(flag)
                break;
            pair<int, int> temp = q.front();
            count = st.front()+1;
            int k = (count)%4;
            st.pop(); q.pop();
            for(int a = 0 ; a < 4 ;++a) {
                        int i = temp.first + xdir[a];
                        int j = temp.second + ydir[a];
                        if( flag ||   i < 0  ||  i >= n    ||   j  < 0  || j >= m )
                            continue;
                        if( block[k][i][j] != '#' ) {
                            if( block[k][i][j] == 'G' ){
                                flag = true;
                                cout<<"Case #"<<run<<": " <<count<<endl;
                                }
                            else{
                                    q.push(make_pair(i, j ));
                                    st.push(count);
                                    block[k][i][j] ='#';
                                }
                        }
                    }
         }
        if(!flag)
            cout<<"Case #"<<run<<": " <<"impossible"<<endl;
    }
    return 0;
}

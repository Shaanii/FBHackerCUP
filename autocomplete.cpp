
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
int ans;
struct node{
    char val;
    struct node* child[26];
 public:
     node (char c) {
       val = c;
       for(int i = 0; i < 26; ++i)
          child[i] = NULL;
    }
};
class Trie{
    struct node *root;
public:
    Trie(){
        root  = new struct node('#');
    }
    void insert(string str){
        struct node* temp =  root;
        int k  = 0 ;
        while(k < str.length()){
            int i;
            for( i = 0; i< 26 ; ++i){
                if(temp->child[i]  && temp->child[i]->val == str[k]){
                    temp =  temp->child[i];
                    ++k;
                    break;
                }
            }
            if( i == 26)
                break;
         }
        ans += k;
        if(k < str.length()) {
               ++ans;
               while( k < str.length()){
                   //cout<<"creating node  "<< str[k]<<endl;
                   struct node* tt = new struct node(str[k]);
                   temp->child[ str[k]- 'a' ] = tt;
                   temp = tt;
                   ++k;
               }
        }
    }
};
int main(){
    freopen("autocomplete.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for (int run = 1; run <= T; ++run) {
        ans = 0;
        Trie *t = new Trie();
        int n;
        cin>> n;
        for(int i =0 ; i < n ; ++i){
            string str;
            cin>>str;
            t->insert(str);
        }
        free(t);
        cout<<"Case #"<<run<<": " <<ans<<endl;
    }
    return 0;
}

 

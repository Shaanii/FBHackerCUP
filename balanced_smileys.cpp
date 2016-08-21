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
#define  ll unsigned long long
#define mod 1000000007
using namespace std;
//anuj code 

int main() {
	int t,test;
	cin>>test;
	char ch,p;
	getchar();
	for(t=1;t<=test;t++){   
        int s,f,o;
		s=f=o=0;
		p='p';
		bool isDone=1;
		while((ch=getchar())!='\n'){
			if(ch=='(' && p==':')
				f++;
			if(ch==')' && p==':')
				s++;
			if(ch=='(')
				o++;
			else if(ch==')') {
				if(o) {
					o--;
					if(f>o)
						f=o;
				}
				else if(s)
					s--;
				else isDone=0;
			}
			p=ch;
		}
		if(o<=f && isDone)
			printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
	return 0;
}

// mycode
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

int main(){

    freopen("balanced_smileys.txt","r",stdin);
    freopen("out.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    getchar();
    for (int run = 1; run <= T; ++run) {
        char c;
        int count = 0, fr = 0,sm = 0;
        bool prev = false, flag = true;
        while((c=getchar()) != '\n') {
            if(c == '('){
                if(prev)
                    fr++;
                else
                    count++;
                prev = false;
            }
            else if( c == ')'){
                if(prev  && count > 0)
                        sm++;
                else if(!prev) {
                    if(count  == 0){
                        if( fr > 0)
                            fr--;
                        else
                            flag =  false;
                    }
                    else{
                        --count;
                        if(count == 0)
                            sm = 0;
                    }
                }
                prev = false;
            }
            else if(c == ':')
                prev = true;
            else
                prev = false;
        }
        if(flag){
            while(count  && sm){
                sm--;
                count--;
            }
            if(count)
                flag = false;
        }
        if(flag)
            cout<<"Case #"<<run<<": " <<"YES"<<endl;
        else
            cout<<"Case #"<<run<<": " <<"NO"<<endl;
    }
    return 0;
}
 

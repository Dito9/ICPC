#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <ctime>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define sz size

using namespace std;

vector< pair <int,int> > tesoros;
int dp[31][1010];
int recojido[31][1010];
int w;
vector<int> recuperar;

int solve(int i,int t){

    if (i>=tesoros.size()) return 0;

    if (dp[i][t]!=-1) return dp[i][t];
    else {
        if ((t-(3*w*tesoros[i].first))>=0){
        int a= tesoros[i].second+solve(i+1,t-(3*w*tesoros[i].first));
        int b=solve(i+1,t);
        if (a>b){
            recojido[i][t]=1;
        }
        return dp[i][t]=max(a,b);
        } else {
            return dp[i][t]=max(0,solve(i+1,t));
       }
    }
}

int main(){
    int t;
    int caso=0;
    while (cin>>t>>w){
        recuperar.clear();
        memset(recojido,0,sizeof(recojido));
        tesoros.clear();
        for (int i=0;i<31;i++){
            for (int j=0;j<1010;j++){
            dp[i][j]=-1;
            }
        }

        int n;
        cin >>n;

        for (int i=0;i<n;i++){
            int a,b;
            cin >>a>>b;
            tesoros.push_back(make_pair(a,b));
        }
        int maximo = solve(0,t);

        if (caso) {
            cout <<endl;
        }
        caso++;
        cout << maximo<<endl;
        int cont=0;

        int i=0;
        int j=t;

        while (maximo>0){
            if ( recojido[i][j]==1){
                maximo=maximo-(tesoros[i].second);
                recuperar.push_back(i);
                j=j-(3*w*tesoros[i].first);
                i++;
            }else{
                i++;
            }
        }
        cout << recuperar.size()<<endl;
        for (int i=0;i<recuperar.size();i++){
            cout << tesoros.at(recuperar.at(i)).first << " " <<tesoros.at(recuperar.at(i)).second<<endl;
        }
    }
	return 0;
}

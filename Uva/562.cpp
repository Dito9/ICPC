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

vector<int> valor;
int dp[101][50001];

//int minGlobal=999999999;

int solve(int moneda, int persona1, int persona2){

    if (moneda>=valor.size()) return abs(persona1-persona2);
    else {
     if (dp[moneda][persona1]!=-1) return dp[moneda][persona1];
     else return dp[moneda][persona1]=min(solve(moneda+1, persona1+valor[moneda],persona2),solve(moneda+1, persona1,persona2+valor[moneda]));
    }
}

int main(){

    int test;
    cin >> test;

    while(test--){

        for (int i=0;i<101;i++){
            for (int j=0;j<50001;j++){
                    dp[i][j]=-1;
            }
        }


        valor.clear();
        int coins;
        cin >> coins;
        for (int i=0;i<coins;i++){
            int a;
            cin >>a;
            valor.push_back(a);
        }

        int minGlobal = solve(0,0,0);
        cout << minGlobal<<endl;

    }


	return 0;

}


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

int main(){
    int n;
    cin >> n;
    vector <int> arreglo;
    for (int i=0;i<n;i++){
        int a;
        cin >>a;
        arreglo.push_back(a);
    }
    int minimo=100000;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int val = __gcd(arreglo.at(i),arreglo.at(j));
            arreglo.at(i)=val;
            arreglo.at(j)=val;
            if (val < minimo) minimo=val;
        }
    }

    cout << minimo*n<<endl;
	return 0;

}

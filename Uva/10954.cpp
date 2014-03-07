	#include <cstdlib>
    #include <cstdio>
    #include <iostream>
    #include <sstream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <deque>
    #include <queue>
    #include <stack>
    #include <map>
    #include <set>
    #include <algorithm>
    #include <numeric>
    #include <functional>
    #include <utility>
    #include <bitset>
    #include <cmath>
    #include <ctime>

    using namespace std;

    #define all(v) (v).begin(), (v).end()
    #define rall(v) (v).rbegin(), (v).rend()
    #define pb push_back
    #define f(i,x,y) for(int i=x; i<y; i++)
    #define FOR(it, A) for(typeof A.begin() it = A.begin(), it!=A.end(); it++)
    #define quad(x) (x)*(x)
    #define mp make_pair
    #define clr(x,y) memset(x, y, sizeof x)
    #define fst first
    #define snd second

    typedef pair<int, int>II;
    typedef long long LL;
    typedef long double LD;

    int main(void){

while (1){
   int lectura;
   scanf("%d",&lectura);

if (lectura==0) return 0;
else {
int a;
    priority_queue<int, vector<int> , greater<int> > pq;
    for (int i=0;i<lectura;i++){
    scanf("%d",&a);
    pq.push(a);
}
    int sum=0;
   while (pq.size()>1){
    int suma=0;
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    suma = a+b;
    sum+=suma;
    pq.push(suma);
   }
    printf("%d\n",sum);
}

}

}

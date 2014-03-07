#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

while(1){

    int a,b;
    scanf("%d %d",&a,&b);
    if (a==0 && b==0) break;
    map<int,int> primero;

    for (int i=0; i<a;i++){
        int lec;
        scanf("%d",&lec);
        primero[lec]=1;
    }

    int rpt=0;

    for (int i=0; i<b;i++){
        int lec;
        scanf("%d",&lec);
        if ( primero.count(lec) ){
                rpt++;
        }
    }
    printf("%d\n",rpt);

}


return 0;

}

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

    while(1)
    {
    int n;
    cin >>n;
    if (n==0) break;

    int cont=0;
    for (int i=1;i<((n/2)+1);i++){

        if (__gcd(i,n)==1){
            cont+=2;
        }

    }

    cout << cont<<endl;
    }


    return 0;
}

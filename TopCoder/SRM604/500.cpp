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
#include <cstring>
using namespace std;

class PowerOfThreeEasy {
public:
	string ableToGet(int, int);
};
int steps[100000000];
bool backtrack(int p,int x,int y,int x1,int y1){


    if (x1>= x || y1>=y){
        if ((x==x1 && y==y1)|| x==y1 && y==x1 ) {

        return true;
        }
        else return false;
    }
else {
           //0 derecha
           //1 abajo


            x1=x1+steps[p];

            bool a;
            a= backtrack(p+1,x,y,x1,y1);
            if (a) return true;
            x1=x1-steps[p];


            y1=y1+steps[p];
             a= backtrack(p+1,x,y,x1,y1);
              if (a) return true;
              y1=y1-steps[p];


        }
        		return false;
}

string PowerOfThreeEasy::ableToGet(int x, int y) {
    memset(steps,0,sizeof(steps));
    int sum=1;

    for (int i=0;i<100000000;i++){
        steps[i]=sum;
        sum=sum*3;
    }
    int x1=0,y1=0;
    bool rpt;
    rpt = backtrack(0,x,y,x1,y1);

	if (rpt) return "Possible";
	else return "Impossible";

}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

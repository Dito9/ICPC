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

class FoxAndWord {
public:
	int howManyPairs(vector <string>);
};

int FoxAndWord::howManyPairs(vector <string> words) {
		int cont=0;
	for (int i=0;i<(int)words.size()-1;i++){
        for (int j=i+1;j<(int)words.size();j++){
            string s,t,a,b;
            s=words.at(i);
            t=words.at(j);
            for (int x=0;x<(int)s.size()-1;x++){
                    a=b="";
                for (int y=0;y<=x;y++){
                    a += s.at(y);
                }
                for (int y=x+1;y<s.size();y++){
                    b += s.at(y);
                }
            string ab,ba;
            ab = a+b;
            ba=b+a;
            //cout <<"a: " << a <<endl;
            //cout <<"b: " << b <<endl;

            if ( ab.compare(s)==0 && ba.compare(t)==0 ){
                cont++;
                break;
            }

            }
        }
	}
    return cont;

}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

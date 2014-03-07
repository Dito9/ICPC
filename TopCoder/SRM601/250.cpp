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

class WinterAndMandarins {
public:
	int getNumber(vector <int>, int);


};

int WinterAndMandarins::getNumber(vector <int> bags, int K) {


		sort(bags.begin(),bags.end());
		int minimo=2000000000;
		int dif;

		for (int i=0; i<(int)bags.size()-(K-1);i++){

			dif = bags.at(i+K-1) - bags.at(i);
			if ( dif < minimo){
			minimo=dif;
			}
		}


	    return minimo;
}


//Powered by [KawigiEdit] 2.0!

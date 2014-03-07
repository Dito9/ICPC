
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
    #include <locale>

    using namespace std;

    typedef pair<int, int>II;
    typedef long long LL;
    typedef long double LD;

    int main(void){
        string palabra;
        map<string,int> mapa;
        while (cin >> palabra){
        std::locale loc;
        string finalstring="";

            for (int i=0;i<palabra.size();i++){
                palabra[i]=tolower(palabra[i],loc);
            }

            for (int i=0;i<palabra.size();i++){
                if (*((char*)(&(palabra[i]))) >='a' && ( *((char*)(&(palabra[i])))<='z' ) ){
                    finalstring.append( &(palabra[i]),sizeof(char));
                }
            else {

                    if (finalstring.size()>0){
                    if (mapa.count(finalstring)==0) mapa[finalstring]=1;
                    finalstring.clear();

                }
            }
            }


            if (finalstring.size()>0){
                    if (mapa.count(finalstring)==0) mapa[finalstring]=1;
            }
        finalstring.clear();
        palabra.clear();
        }
        map<string,int>::iterator it;

        for ( it=mapa.begin();it!=mapa.end();it++){
            cout << it->first << endl;
        }


    }

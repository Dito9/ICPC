#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


int main(){

    int test;
    cin >> test;

    while(test--){
    vector< string > matriz;
    string linea;

    cin >> linea;
    matriz.push_back(linea);

    for (int i=1;i<linea.size();i++){
    cin >> linea;
    matriz.push_back(linea);
    }
    int maxSubRect =0;
    int subRect=0;
    int s=linea.size();
    for (int i=0;i<s;i++){
        for (int j=0;j<s;j++){
            for (int k=i; k<s;k++){
                for (int l=j;l<s;l++){
                    subRect=0;
                    int elemento=0;
                    for (int a=i;a<=k;a++){
                        for (int b=j;b<=l;b++){
                            elemento = (int)(char)(matriz.at(b).at(a))-'0';
                            if (elemento>0)subRect= subRect + elemento;
                            else {
                                subRect=0; break;
                            }
                        }
                        if (elemento==0) break;
                    }
                    maxSubRect=max(maxSubRect,subRect);
                }
            }
        }
    }
    cout << maxSubRect<<endl;
    if (test) cout <<endl;
    }
    return 0;
}

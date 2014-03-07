#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int dp[100][100];
int main(){

    int n;
    int matriz[100][100];
    int elemento;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> elemento;
            matriz[i][j]=elemento;
            if (i>0) matriz[i][j]+= matriz[i-1][j];
            if (j>0) matriz[i][j]+= matriz[i][j-1];
            if (i>0 && j>0) matriz[i][j] -= matriz[i-1][j-1];
        }
    }

    int maxSubRect =0;
    int subRect=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=i; k<n;k++){
                for (int l=j;l<n;l++){
                    subRect=matriz[k][l];
                    if (i>0) subRect-= matriz[i-1][l];
                    if (j>0) subRect-= matriz[k][j-1];
                    if(i>0 && j>0) subRect+= matriz[i-1][j-1];
                    maxSubRect=max(maxSubRect,subRect);
                }
            }
        }
    }
    cout << maxSubRect<<endl;
    return 0;
}

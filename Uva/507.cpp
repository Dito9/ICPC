#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main(){
    int N,n,i,j,imax,jmax,ac,aux,ans;
    scanf("%d",&N);
    for(int l=1;l<=N;l++){
        scanf("%d",&n);
        ac=ans=i=j=imax=jmax=0;
        for(int k=1;k<n;k++){
            j=k;
            scanf("%d",&aux);
            ac+=aux;
            if(ac>=ans){
                if(ac>ans or (ac==ans and j-i>jmax-imax) ){
                    imax=i;
                    jmax=j;
                    ans=ac;
                }
            }
            if(ac<0){
                ac=0;
                i=k;
            }

        }
        if (ans)printf("The nicest part of route %d is between stops %d and %d\n",l,imax+1,jmax+1);
        else printf("Route %d has no nice parts\n",l);
    }
    return 0;
}

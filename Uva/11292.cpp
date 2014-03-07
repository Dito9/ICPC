#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,h[20000],k[20000];

    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0) break;

        for(int i = 0;i < n;++i) scanf("%d",&h[i]);
        for(int i = 0;i < m;++i) scanf("%d",&k[i]);

        int ans = 0;
        bool muerte = true;

        sort(h,h + n);
        sort(k,k + m);

        for(int i = 0,j = 0;i < n && muerte;++i){
            while( (j < m) && (k[j] < h[i])) ++j;

            if(j == m) muerte = false;
            else ans += k[j++];
        }

        if(!muerte) puts("Loowater is doomed!");
        else printf("%d\n",ans);
    }

    return 0;
}

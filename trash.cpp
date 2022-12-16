#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

int main(){	
    int N; cin >> N;	
    int up = 1;	
    int down = N;	
    int left = 1;	
    int right = N;
    vector<int> ans(N+1)
    rep(i, N+1){
        ans[i] = i;
    }

    // まず上と下について	
    while(down!=up){	
        int mid = (down+up)/2;	
        // cout << "?" << " " << up << " " << mid << " " << 1 << " " << N << endl;	
        if(ans[mid]<mid - up + 1){	
            up = mid+1;	
        } else {	
            down = mid;	
        }	
        cout << mid << endl;
    }	

    
}
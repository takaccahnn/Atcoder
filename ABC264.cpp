#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

void swap(int* a, int* b){
    int x = *a;
    *a = *b; *b = x;
}

void swapChar(char* a, char* b){
    char x = *a;
    *a = *b; *b = x;
}

// A問題
/*int main(){
    int L, R; cin >> L >> R;
    string S = "atcoder";

    FOR(i, L-1, R-1){
        cout << S[i];
    }
    cout << endl;


    return 0;
}*/

// B問題
/*int main(){
    int R, C; cin >> R >> C;
    vector<vector<char>> mas(15, vector<char>(15, 'b'));
    // 黒は'b'、白は'w'として表すこととする
    rep(i, 4){
        FOR(j, 1+i*2, 14-(1+i*2)){
            mas[1+i*2][j] = 'w';
            mas[14-(1+i*2)][j] = 'w';
            mas[j][1+i*2] = 'w';
            mas[j][14-(1+i*2)] = 'w';
        }
    }

    if(mas[R-1][C-1] == 'b') cout << "black" << endl;
    else cout << "white" << endl;


    return 0;
}*/

// C問題
// 行と列を削除するのはムズイ。ここで注目すべきは行と列の上限がせいぜい10であること
// このことに注意すればbit全探索を用いてもせいぜい0(2^20)の100万くらいの情報量で処理できる
int main(){
    int H1, W1, H2, W2; cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(o, H1){
        rep(p, W1) cin >> A[o][p];
    }
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(o, H2){
        rep(p, W2) cin >> B[o][p];
    }

    for(int i=0; i<(1<<H1); i++){
        for(int j=0; j<(1<<W1); j++){
            // 行はraw, 列はcolum
            vector<int> raw;
            vector<int> colum;
            for(int k=0; k<H1; k++){
                if(!(i & (1<<k))) raw.push_back(k);
            }
            for(int l=0; l<W1; l++){
                if(!(j & (1<<l))) colum.push_back(l);
            }
            if(!((raw.size() == H2) and (colum.size() == W2))) continue;
            bool jud = true;
            rep(m, raw.size()){
                if(!jud) break;
                rep(n, colum.size()){
                    if(B[m][n]!=A[raw[m]][colum[n]]){
                        jud = false;
                        break;
                    }
                }               
            }
            if(jud){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return;
}

// D問題
// 転倒数を用いる
// BITを用いた(区間和を計算する際に用いる)
/*struct BIT{
    private:
        vector<int> bit;
        int N;
    public:
        BIT(int size){
            N = size;
            bit.resize(size + 1);
        }
        // 一点更新(aは入れる位置、wは入れる値)
        void add(int a, int w){
            for(int i=a; i<=N; i += i&-i){
                bit[i] += w;
            }
        }
        // 和を求める
        int sum(int a){
            int ret = 0;
            for(int i=a; i>0; i-=i&-i){
                ret += bit[i];
            }
            return ret;
        }
        
};

int main(){
    string s; cin >> s;
    vector<int> order(7);
    rep(i, 7){
        if(s[i]=='a') order[i] = 1;
        if(s[i]=='t') order[i] = 2;
        if(s[i]=='c') order[i] = 3;
        if(s[i]=='o') order[i] = 4;
        if(s[i]=='d') order[i] = 5;
        if(s[i]=='e') order[i] = 6;
        if(s[i]=='r') order[i] = 7;
    }
    int ans = 0;
    BIT cal(7);
    rep(i, 7){
        ans += i - cal.sum(order[i]);
        cal.add(order[i], 1);
    }

    cout << ans << endl;

    return 0;
}*/

// D問題(別解: 幅優先探索を用いる場合)
/*unordered_map<string, int> mp;

int switchString(string s, int time){
    int ans = 0;
    if(!mp.count(s)) mp[s] =  time;
    if(s == "atcoder") return time;
    rep(i, 6){
        string S = s;
        swapChar(&S[i], &S[i+1]);
        switchString(S, time+1);
    }
}

// D問題
int main(){
    string s; cin >> s;
    queue<string> que;
    vector<vector<string>> child(10000);
    int index = 0;
    child[index].push_back(s);
    que.push(s);
    if(s == "atcoder"){
        cout << "0" << endl;
        return 0;
    }
    while(true){
        index++;
        while(!que.empty()){
            string temp = que.front();
            que.pop();
            rep(i, 6){
                string s_swapped = temp;
                swapChar(&s_swapped[i], &s_swapped[i+1]);
                if(mp.count(s_swapped)) continue; else {
                    mp[s_swapped] = index;
                    child[index].push_back(s_swapped);
                    if(s_swapped == "atcoder"){
                        cout << index << endl;
                        return 0;
                    }
                }
            }
        }
        rep(i, child[index].size()) que.push(child[index][i]);
    }
    return 0;
}*/

// 以下はソートについての復習
// バブルソート(知っておくべき)
/*int main(){
    vector<int> v(N);
    rep(i, N){
        v[i] = N-i;
    }
    int res = 0;
    // 計算量を出力する
    int sort = 1;
    while(sort){
        sort = 0;
        rep(i, N-1){
            if(v[i]>v[i+1]){
                sort++;
                swap(v[i], v[i+1]);
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}*/

// 選択ソート
/*int main(){
    vector<int> v(N);
    rep(i, N){
        v[i] = N-i;
    }
    // 計算量を出力する
    rep(i, N){
        int mini = v[i];
        int index = i;
        for(int j=i+1; j<N; j++){
            if(mini>v[j]){
                mini = v[j];
                index = j;
            }
        }
        swap(v[i], v[index]);
    }
}*/

// 挿入ソート
/*int main(){
    vector<int> v(N);
    rep(i, N){
        v[i] = N-i;
    }
    FOR(i, 1, N-1){
        int pos = i;
        if(v[pos-1]>v[pos]){
            for(int j=pos; j>=1; j--){
                if(v[j-1]>v[j]) swap(v[j-1], v[j]);
            }
        }
    }
}*/

// クイックソート(知っておくべき)(分割統治法)
/*void quickSort(vector<int> &A){
    if(!A.size()){
        return;
    }

    vector<int> left, right;

    int jud = A[A.size()/2];
    rep(i, A.size()) 
        if(i==A.size()/2) cotinue;
        if(A[i]<jud) {
            left.push_back(A[i]) 
        } else { 
            right.push_back(A[i]);
        }

    quickSort(left);
    quickSort(right);

    L.push_back(A[A.size()/2]);
    L.insert(left.end(), right.begin(), right.end());
    A = L;
}

int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    quickSort(A);
    rep(i, N) cout << A[i] << " ";
    cout << endl;

    return 0;
}*/

// マージソート(知っておくべき)(分割統治法) 
/*void mergeSort(vector<int> &arr){
    if(arr.size()<=1) return;
    
    int mid = arr.size()/2;
    vector<int> left, right;
    rep(i, mid) left.push_back(arr[i]);
    FOR(i, mid, arr.size()-1) right.push_back(arr[i]);

    mergeSort(left);
    mergeSort(right);

    queue<int> L;
    rep(i, left.size()) L.push(left[i]);
    queue<int> R;
    rep(i, right.size()) R.push(right[i]);

    vector<int> ans;
    while(!(R.empty() & L.empty())){
        if(R.empty()){
            ans.push_back(L.front());
            L.pop();
            continue;
        }
        if(L.empty()){
            ans.push_back(R.front());
            R.pop();
            continue;
        }
        if(L.front()<R.front()){
            ans.push_back(L.front());
            L.pop();
        } else {
            ans.push_back(R.front());
            R.pop();
        }
    }
    arr = ans;
} 

int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    mergeSort(A);

    rep(i, N) cout << A[i] << " ";
    cout << endl;

    return 0;
}*/





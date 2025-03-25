#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ll ILL=2167167167167167167;
const int INF=2100000000;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> int LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> int UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
bool yneos(bool a,bool upp=false){if(a){cout<<(upp?"YES\n":"Yes\n");}else{cout<<(upp?"NO\n":"No\n");}return a;}
template<class T> void vec_out(vector<T> &p,int ty=0){
    if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
    else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){T ans=T(0);for(auto &x:a) ans+=x;return ans;}
int pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> T square(T a){return a * a;}


set<char> skip = {' ', '"', '\n'};
char start_char = '{';
char end_char = '}';
string decc_input(string S){
    vector<string> T = {""};
    vector<int> index;
    stack<int> st;
    st.push(0);
    index = {-1};
    rep(i, 0, S.size()){
        if (skip.count(S[i])) continue;
        bool add = false;
        if (S[i] == start_char){
            add = true;
            st.push(index.size());
            index.push_back(-1);
        }
        else if (S[i] == end_char) add = true, st.pop();
        else if (S[i] == ','){
            add = true;
            index[st.top()]--;
        }
        else{
            if (T.back().empty()){
                index.push_back((int)T.size() - 1);
            }
            T.back() += S[i];
        }
        if (add && !T.back().empty()){
            T.push_back("");
        }
    }
    string res;
    for (auto x : index){
        if (x < 0) res += (to_string(-x));
        else res += T[x];
        res += "\n";
    }
    return res;
}



stringstream CIN;
void solve();
// CITRUS CURIO CITY / FREDERIC
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string ex = "{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,1,2,3,4,50,11,49,48,12,47,46,45,6,7,8,9,10,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,5},\n"
                "{26,31,36,41,46,27,32,37,42,47,28,33,38,43,48,29,34,39,44,49,30,35,40,45,50,1,2,3,4,5,26,27,6,7,8,9,10,11,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,12,13,14,15,16,17,18,19,20,21,22,23,24,25,28,29,30},\n"
                "{11,21,31,41,1,22,32,42,2,12,33,43,3,13,23,44,4,14,24,34,46,47,48,49,50,46,47,48,6,16,26,11,7,17,27,12,8,18,28,13,5,21,22,15,14,9,19,29,50,49,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,25,24,23,20,10,4,3,2,1}";
    string main = "{43,18,35,34,46,15,8,49,29,19,44,37,7,30,14,13,11,39,27,6,23,36,22,21,50,4,2,27,26,33,10,18,28,42,14,41,17,49,21,23,48,32,35,3,20,12,9,43,8,50,22,40,31,7,1,45,47,44,5,39,37,38,36,29,15,46,24,30,16,11,25,6,34,19,13},\n"
                  "{8,43,9,29,6,13,47,5,40,27,48,50,10,11,35,44,1,12,3,16,42,33,21,24,2,49,43,27,31,5,20,28,19,32,4,15,48,1,7,29,22,14,10,13,25,35,3,21,12,2,36,40,39,46,44,18,9,8,23,30,16,34,26,45,37,41,17,50,6,38,24,42,11,33,47},\n"
                  "{39,38,36,24,1,32,45,47,50,48,40,31,30,34,49,41,33,42,25,44,29,28,37,46,43,15,20,41,27,23,1,11,2,10,9,22,31,4,7,16,3,26,5,8,6,47,17,12,43,18,13,46,19,14,33,35,38,28,37,24,42,34,32,36,29,49,21,30,50,25,44,39,48,45,40}";
    // input test
    // cout << decc_input(ex) << "\n";
    // return 0;
    CIN << decc_input(main);
    int t;
    CIN >> t;
    rep(i, 0, t){
        solve();
        cout << (i + 1 == t ? "\n" : ",");
    }
}

void solve(){
    int X;
    CIN >> X;
    assert(X == 75);
    int all_sum = 0;
    vector<int> ex(51, -1);
    vector<int> ban(25);
    rep(i, 0, 25){
        CIN >> ban[i];
        all_sum += ban[i];
        ex[ban[i]] = i;
    }
    vector<int> q;
    rep(i, 0, 5){
        q.push_back((1 << (5 * i)) * (31));
    }
    {
        int tmp = 0;
        rep(i, 0, 5) tmp += (1 << (5 * i));
        rep(i, 0, 5) q.push_back(tmp << i);
    }
    {
        int tmp = 0;
        rep(i, 0, 5) tmp += (1 << (i * 6));
        q.push_back(tmp);
    }
    {
        int tmp = 0;
        rep(i, 0, 5) tmp += (1 << (4 * (i + 1)));
        q.push_back(tmp);
    }
    vector<unordered_set<int>> m(3);
    m[0].insert(0);
    int ans = 0;
    vector<int> seen(1 << 25);
    vector<int> sum(1 << 25);
    rep(i, 0, 1 << 25) for (auto x : q) if ((i & x) == x){
        sum[i] = all_sum;
        seen[i] = 1;
        rep(j, 0, 25) if (i & (1 << j)) sum[i] -= ban[j];
        continue;
    }
    rep(i, 0, 50){
        int num;
        CIN >> num;
        vector<unordered_set<int>> n_m(3);
        rep(j, 0, 3){
            for (auto x : m[j]){
                if (seen[x]){
                    chmax(ans, sum[x]);
                    continue;
                }
                if (ex[num] != -1 && (x & (1 << ex[num])) == 0){
                    n_m[0].insert(x + (1 << ex[num]));
                }
                else if (j < 2){
                    n_m[j + 1].insert(x);
                }
                else{
                    rep(k, 0, 25) if ((x & (1 << k)) == 0){
                        n_m[0].insert(x + (1 << k));
                    }
                }
            }
        }
        swap(n_m, m);
    }
    cout << ans;
}

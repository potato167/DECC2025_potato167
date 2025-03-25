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


    string ex = "{4,7,1,2,6},\n"
                "{11,7,13,1,13},\n"
                "{58,54,72,77,81}";
    string main = "{34,49,44,42,20},\n"
                  "{11,28,67,49,46},\n"
                  "{99,99,99,99,99}";
    // input test
    // cout << decc_input(ex) << "\n";
    CIN << decc_input(main);
    int t;
    CIN >> t;
    rep(i, 0, t){
        solve();
        cout << (i + 1 == t ? "\n" : ",");
    }
}

void solve(){
    const int L = 100;
    int N;
    CIN >> N;
    vector<int> p(N);
    rep(i, 0, N) CIN >> p[i];
    auto f = [&](int num, int wei, vector<vector<int>> base = {}) -> vector<vector<int>> {
        vector dp(L + 15, vector(L + 15, vector<int>(L + 15, INF)));
        if (base.empty()) dp[0][0][0] = 0;
        else{
            rep(i, 0, L) rep(j, 0, L) dp[0][i][j] = base[i][j];
        }
        rep(i, 0, L) rep(j, 0, L) rep(k, 0, L){
            rep(a, 0, (80 / wei) + 1) rep(b, 0, INF){
                if (a * wei + b * 9 > 80) break;
                rep(c, 0, INF){
                    if (a * wei + b * 9 + c * 6 > 80) break;
                    chmin(dp[(i + a)][(j + b)][k + c], dp[i][j][k] + 1);
                }
            }
        }
        return dp[num];
    };
    auto tmp = f(p[0], 10);
    auto tmp2 = f(p[3], 13, tmp);
    auto tmp3 = f(p[4], 16, tmp2);
    // cout << (p[0] * 10 + p[1] * 9 + p[2] * 6 + p[3] * 13 + p[4] * 16 + 79)/80 << ".";
    cout << tmp3[p[1]][p[2]];
}

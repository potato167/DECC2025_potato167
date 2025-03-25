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


    string ex = "{1,10},\n"
                "{30,39},\n"
                "{100,150}";
    string main = "{1,100},\n"
                  "{300,399},\n"
                  "{12345,54321}";
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
    int a;
    CIN >> a;
    int A, B;
    CIN >> A >> B;
    auto f = [&](int b) -> int {
        if (b % 3 == 0) return 1;
        while (b){
            if (b % 10 == 3) return 1;
            b /= 10;
        }
        return 0;
    };
    ll sum = 0;
    int C = 0;
    rep(i, A, B + 1){
        if (f(i)){
            C++;
            if (C % 3 != 0) sum += i;
        }
    }
    cout << sum;
}

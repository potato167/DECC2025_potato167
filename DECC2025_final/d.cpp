#include <bits/stdc++.h>
using namespace std;
using ll=long long;
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
// https://github.com/kth-competitive-programming/kactl/tree/main/content/geometry
template<class T> ll sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct Point {
    using P = Point;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    T dist() const { return sqrtl(dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }  // makes dist()=1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};
using ld = long double;

vector<vector<pair<ld, ld>>> inp = {
        {{-300, 800}, {-200, 800}, {-100, 800}, {0, 800}, {100, 800}, {200, 800}, {300, 800}, {-300, 900}, {-200, 900}, {-100, 900}, {0, 900}, {100, 900}, {200, 900}, {300, 900}, {-300, 1000}, {-200, 1000}, {-100, 1000}, {0, 1000}, {100, 1000}, {200, 1000}, {300, 1000}}
};

struct STA{
    int Ir; // 板の傾き (5.000 - 45.000)
    int Rr; // 方向の傾き (-25.000 - 25.000)
};

const ld Start_High = 700;
const ld PI = acosl(-1);
const ld e = 0.9;
const ld g = 9800;
const ld eps = 0.05;

STA calc(ld zh, Point<ld> target){
    ld tmp = asinl((ld)(target.x) / (ld)(target.y));
    tmp /= PI;
    tmp *= 180 * 1000;
    int Rr = (int)roundl(tmp);
    // chmin(Rr, 25000);
    // chmax(Rr, -25000);
    assert(abs(Rr) <= 25000);
    int best = 5 * 1000;
    ld score = INF;
    ld v = sqrtl(2 * g * (Start_High - zh));
    ld H = zh - 12.7;
    ld dist = target.dist();
    ld best_D = 0;
    // hoge
    for (int Ir = 5 * 1000; Ir <= 45 * 1000; Ir += 1){
        ld theta = PI * ((ld)(Ir) / (ld)(180 * 1000));
        ld baseVA = sinl(theta) * v;
        ld baseVB = cosl(theta) * v * e;
        // ld vz = sinl(theta) * v;
        // ld vx = cosl(theta) * v;
        ld vz = cosl(theta) * baseVB - sinl(theta) * baseVA;
        ld vx = cosl(theta) * baseVA + sinl(theta) * baseVB;
        // 1/2 * g * t^2 - vz * t - H = 0
        // t =
        ld time = (vz + sqrtl(vz * vz + 2 * g * H)) / g;
        ld D = time * vx;
        if (abs(D - dist) < eps){
            best = Ir, best_D = D;
            // break;
        }
    }
    // cout << best_D << " " << dist << "\n";
    return {best, Rr};
}

void solve(int idx){
    int N = (int)inp[idx].size();
    vector<Point<ld>> target(N);
    rep(i, 0, N) target[i].x = inp[idx][i].first, target[i].y = inp[idx][i].second;
    // 単位はミリメートルで固定する。
    /*
    vector<int> order(N);
    rep(i, 0, N) order[i] = i;
    sort(all(order), [&](int l, int r){
        return target[l].dist2() > target[r].dist2();
    });
    rep(i, 0, 21 - N){
        cout << "1,5000,0,0,2000\n";
    }
    if (false){
        cout << "1,5000,0,0,4000;\n";
        return;
    }
    rep(i, 0, N){
        auto ans = calc((i + 21 - N) * 20, target[order[i]]);
        cout << order[i] + 1 << "," << ans.Ir << "," << ans.Rr << "," << 1 << "," << 2000;
        if (i + 1 == N){
            cout << ";\n";
        }
        else{
            cout << "\n";
        }
    }*/
    vector<int> dp(1 << N);
    vector tmp_score(N, vector<int>(N));
    vector<int> fr(1 << N, -1);
    rep(i, 0, N) rep(j, 0, N){
            // cout << i << " " << j << endl;
            tmp_score[i][j] = calc(i * 20, target[j]).Ir;
        }
    rep(i, 0, 1 << N){
        int pc = pop_count(i);
        rep(k, 0, N) if ((i & (1 << k)) == 0){
                if (chmax(dp[i + (1 << k)], dp[i] + tmp_score[pc][k])){
                    fr[i + (1 << k)] = k;
                }
            }
    }
    vector<int> order;
    {
        int tmp = (1 << N) - 1;
        while (tmp){
            order.push_back(fr[tmp]);
            tmp -= (1 << fr[tmp]);
            // cout << tmp << endl;
        }
        std::reverse(order.begin(), order.end());
    }
    // output
    rep(i, 0, N){
        auto ans = calc((i + 21 - N) * 20, target[order[i]]);
        if (order[i] % 7 == 6) ans.Rr -= 100;
        if (order[i] % 7 == 0) ans.Rr += 100;
        cout << order[i] + 1 << "," << ans.Ir << "," << ans.Rr << "," << 1 << "," << 2000;
        if (i + 1 == N){
            cout << ";\n";
        }
        else{
            cout << "\n";
        }
    }
}
// CITRUS CURIO CITY / FREDERIC
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rep(i, 0, 1) solve(i);
}

// taisaku
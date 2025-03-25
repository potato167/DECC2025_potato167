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
         {
                 {
                         0, 950}, {
                                          0, 850}, {
                                                           0, 750}, {
                                                                            0, 650}, {
                                                                                             0, 550}, {
                                                                                                              0, 450}, {
                                                                                                                               0, 350}, {
                                                                                                                                                0, 250}}
        ,{
                 {
                         0, 850}, {
                                          100, 850}, {
                                                           -100, 850}, {
                                                                            200, 850}, {
                                                                                             -200, 850}, {
                                                                                                              300, 850}, {
                                                                                                                               -300, 850}}
        ,{
                 {
                         0, 350}, {
                                          -100, 550}, {
                                                           100, 550}, {
                                                                            -200, 750}, {
                                                                                             0, 750}, {
                                                                                                              200, 750}, {
                                                                                                                               -300, 950}, {
                                                                                                                                                -100, 950}, {
                                                                                                                                                                    100, 950}, {
                                                                                                                                                                                       300, 950}}
        ,{
                 {
                         -300, 650}, {
                                          300, 650}, {
                                                           -255, 550}, {
                                                                            255, 550}, {
                                                                                             -210, 450}, {
                                                                                                              210, 450}, {
                                                                                                                               -165, 350}, {
                                                                                                                                                165, 350}, {
                                                                                                                                                                    -120, 250}, {
                                                                                                                                                                                       120, 250}}
        ,{
                 {
                         -300, 350}, {
                                          -175, 350}, {
                                                           -50, 350}, {
                                                                            75, 350}, {
                                                                                             200, 350}, {
                                                                                                              325, 350}, {
                                                                                                                               -325, 550}, {
                                                                                                                                                -200, 550}, {
                                                                                                                                                                    -75, 550}, {
                                                                                                                                                                                       50, 550}, {
                                                                                                                                                                                                         175, 550}, {
                                                                                                                                                                                                                            300, 550}, {
                                                                                                                                                                                                                                               -300, 750}, {
                                                                                                                                                                                                                                                                   -175, 750}, {
                                                                                                                                                                                                                                                                                       -50, 750}, {
                                                                                                                                                                                                                                                                                                          75, 750}, {
                                                                                                                                                                                                                                                                                                                            200, 750}, {
                                                                                                                                                                                                                                                                                                                                               325, 750}}
};

struct STA{
    int Ir; // 板の傾き (5.000 - 45.000)
    int Rr; // 方向の傾き (-25.000 - 25.000)
};

const ld Start_High = 700;
const ld PI = acosl(-1);
const ld e = 0.9;
ld g = 9807;

STA calc(ld zh, Point<ld> target){
    ld tmp = asinl((ld)(target.x) / (ld)(target.y));
    tmp /= PI;
    tmp *= 180000;
    int Rr = (int)roundl(tmp);
    chmin(Rr, 25000);
    chmax(Rr, -25000);
    // assert(abs(Rr) <= 25000);
    int best = 5000;
    ld score = INF;
    ld v = sqrtl(2 * g * (Start_High - zh));
    ld H = zh - 12.7;
    ld dist = target.dist();
    for (int Ir = 5000; Ir <= 45000; Ir += 100){
        ld theta = PI * ((ld)(Ir) / (ld)(180000));
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
        if (chmin(score, abs(D - dist))) best = Ir;
    }
    // cout << score << " " << dist << "\n";
    return {best, Rr};
}

void solve(int idx){
    int N = (int)inp[idx].size();
    vector<Point<ld>> target(N);
    rep(i, 0, N) target[i].x = inp[idx][i].first, target[i].y = inp[idx][i].second;
    // 単位はミリメートルで固定する。
    vector<int> order(N);
    rep(i, 0, N) order[i] = i;
    sort(all(order), [&](int l, int r){
        return target[l].dist2() < target[r].dist2();
    });
    rep(i, 0, 21 - N){
        cout << "1,5000,0,0,4000\n";
    }
    if (false){
        cout << "1,5000,0,0,4000;\n";
        return;
    }
    rep(i, 0, N){
        auto ans = calc((i + 21 - N) * 20, target[order[i]]);
        cout << order[i] + 1 << "," << ans.Ir << "," << ans.Rr << "," << 1 << "," << 4000;
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

    rep(i, 0, 5) solve(i);
}


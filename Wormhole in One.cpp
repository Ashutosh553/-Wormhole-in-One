#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

// REINITIALIZE ARRAYS BETWEEN TCs

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

typedef ll T;
int sgn(T a) { return (a>0)-(a<0); }
T sq(T a) { return a*a; }

namespace Point {
	typedef pair<T,T> P; typedef vector<P> vP;
	T norm(const P& p) { return sq(p.f)+sq(p.s); }
	T abs(const P& p) { return sqrt(norm(p)); }
	T arg(const P& p) { return atan2(p.s,p.f); }
	P conj(const P& p) { return P(p.f,-p.s); }
	P perp(const P& p) { return P(-p.s,p.f); }
	P dir(T ang) { return P(cos(ang),sin(ang)); }
	
	P operator-(const P& l) { return P(-l.f,-l.s); }
	P operator+(const P& l, const P& r) { 
		return P(l.f+r.f,l.s+r.s); }
	P operator-(const P& l, const P& r) { 
		return P(l.f-r.f,l.s-r.s); }
	P operator*(const P& l, const T& r) { 
		return P(l.f*r,l.s*r); }
	P operator*(const T& l, const P& r) { return r*l; }
	P operator/(const P& l, const T& r) { 
		return P(l.f/r,l.s/r); }
	P operator*(const P& l, const P& r) { 
		return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
	P operator/(const P& l, const P& r) { 
		return l*conj(r)/norm(r); }
	P& operator+=(P& l, const P& r) { return l = l+r; }
	P& operator-=(P& l, const P& r) { return l = l-r; }
	P& operator*=(P& l, const T& r) { return l = l*r; }
	P& operator/=(P& l, const T& r) { return l = l/r; }
	P& operator*=(P& l, const P& r) { return l = l*r; }
	P& operator/=(P& l, const P& r) { return l = l/r; }
	
	P unit(const P& p) { return p/abs(p); }
	T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
	T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
	T cross(const P& p, const P& a, const P& b) {
		return cross(a-p,b-p); }
	P reflect(const P& p, const P& a, const P& b) { 
		return a+conj((p-a)/(b-a))*(b-a); }
	P foot(const P& p, const P& a, const P& b) { 
		return (p+reflect(p,a,b))/(T)2; }
	bool onSeg(const P& p, const P& a, const P& b) { 
		return cross(a,b,p) == 0 && dot(p-a,p-b) <= 0; }
	ostream& operator<<(ostream& os, const P& p) {
		return os << "(" << p.f << "," << p.s << ")"; }
};
using namespace Point;

int N;
vP v;

void inp(vi& v) { // common way to reduce amount of input
	v.rsz(1); ll A,B,C; re(v,A,B,C);
	while (sz(v) < N) v.pb((A*v.back()+B)%C+1);
}

P slope(P a, P b) {
	a -= b; ll g = __gcd(abs(a.f),abs(a.s));
	a /= g;
	a = min(a,-a);
	return a;
}
ll eval(P a, P b) {
	return -a.s*b.f+a.f*b.s;
}

int get(vi v) {
	int sum = 0, odds = 0; 
	trav(t,v) {
		sum += t;
		odds += t&1;
	}
	// if odd # of odds
	if (odds&1) sum ++;
	else sum += 2;
	return min(N,sum);
}

void solve(int caseNum) {
	// cerr << "Doing #" << caseNum << "\n";
	re(N); v.rsz(N); re(v);
	map<P,map<ll,set<int>>> huh;
	F0R(i,N) FOR(j,i+1,N) {
		P p = slope(v[i],v[j]);
		ll x = eval(p,v[i]); assert(x == eval(p,v[j]));
		huh[p][x].insert(i);
		huh[p][x].insert(j);
	}
	int mx = min(2,N);
	trav(t,huh) {
		vi tmp;
		trav(u,t.s) tmp.pb(sz(u.s));
		ckmax(mx,get(tmp));
	}
	ps(mx);
}

int main() {
	// setIO("A");
	int T; re(T);
	FOR(i,1,T+1) {
		pr("Case #",i,": ");
		solve(i);
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/


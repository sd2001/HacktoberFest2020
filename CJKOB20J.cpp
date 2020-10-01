#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;

/*/-----------------------------Code begins----------------------------------/*/

const ll N = 1e5 + 10;
ll do_1(vector<ll>& a){
	__int128 high = 0;


	int iter = 0;

	for(auto e: a){
		high += e;
	}
	ll n = a.size();
	pair<__int128,ll> ans = {high,0};
	ll cnt = n;
	for(int i = 1; i <= N; ++i){
		while(iter < n && a[iter] <= i){
			high -= 2*a[iter];
			cnt -= 2;
			++iter;
		}
		ans = min(ans,{high - cnt*i ,i});
	}

    assert(ans.first >= 0);


	return ans.second;


}

ll do_2(vector<ll>& a){
	__int128 sq_sum = 0, sum = 0;

	for(auto e: a){
		sq_sum += e*e;
		sum += e;
	}

	pair<__int128,ll> ans = {sq_sum,0};
	ll n = a.size();
	for(__int128 i = 1; i <= N; ++i){
		ans = min(ans, {i * i * n + sq_sum - 2*i*sum,i});
	}
    assert(ans.first >= 0);

	return ans.second;
}

ll do_3(vector<__int128>& a){
	__int128 cube_sum = 0, sq_sum =0, sum = 0;

	for(auto e: a){
		sq_sum += e*e;
		sum += e;
		cube_sum += e*((__int128 )(1))*e*e;
	}
	pair<__int128,ll> ans = {cube_sum,0};
	__int128 n = a.size();
	__int128 cnt = n;


	int iter = 0;


	for(__int128 i = 1; i <= N; ++i){
		while(iter < n && a[iter] <= i){
			cube_sum -= 2* a[iter] * ((__int128) 1)*a[iter] * a[iter];
			sq_sum -= 2* a[iter]*a[iter];
			sum -= 2* a[iter];
			cnt -= 2;
			++iter;
		}


		__int128 curr = cube_sum - (cnt * i * i *i) + (3 * i * i * sum) - (3* i * sq_sum);
		ans = min(ans,{curr,i});
	}

    assert(ans.first >= 0);
	return ans.second;

}



void solve(){

	int n,k;
	cin >> n >> k;
	vector<ll> a(n);
	cin >> a;

	sort(all(a));

    assert(a[0] >= 1 && a.back() < N);


	if (k == 1){
		cout << do_1(a) << endl;
		return;
	}
	if (k == 2){
		cout << do_2(a) << endl;
		return;
	}

	if (k == 3){
        vector<__int128> b;
        for(auto e: a){
            b.push_back(e);
        }
		cout << do_3(b) << endl;
		return;
	}

    assert(false);

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
}

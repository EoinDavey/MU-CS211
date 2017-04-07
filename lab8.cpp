#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>

typedef long long ll;

using namespace std;


struct state{
    int n;
    ll  s;
    state(int _n, ll _s) : n(_n), s(_s){}
    state(){}
    bool operator < (state r) const {
        if(n!=r.n) return n < r.n;
        return s < r.s;
    }
    bool operator == (state r) const {
        return (n==r.n&&s==r.s);
    }
};

const int mx_n = 44;
int N;
bool stop = false;
ll sum;
ll tsum = 0;
int mCur=-1;
ll tgt;
ll res;
ll a[mx_n];
ll cnt = 0;
ll limit = 3000;
ll best;
map<state,ll> memo;

int out[mx_n];

ll cost(ll s){
    return s-tgt;
}


int dp(int cur, ll sum){
    cnt++;
    state s = state(cur,sum);
    map<state,ll>::iterator i = memo.find(s);
    if(i!=memo.end())
        return memo[s];
    if(cur == N || sum > tgt)
        return memo[s] = cost(sum);
    ll take,leave;
    take = leave = sum;
    if(!stop){
        take = dp(cur+1, sum+a[cur]);
        leave = dp(cur+1,sum);
    }
    ll ans = (abs(take) < abs(leave)) ? take : leave;
    memo[s] = ans;
    if(abs(ans) < best)
        best=abs(ans),printf("new best: %lld\n",ans);
    if(abs(best) < limit)
        stop = true;
    if(stop){
        memo[s] = 0;
    }
    return ans;
}

void print(int cur, ll sum){
    if(cur==N)
        return;
    state s(cur+1,sum+a[cur]);
    map<state,ll>::iterator i = memo.find(s);
    if(i!=memo.end() && memo[state(cur+1,sum+a[cur])]==best){
        out[cur] = 1;
        tsum+=a[cur];
        print(cur+1,sum+a[cur]);
    } else {
        tsum-=a[cur];
        out[cur] = -1;
        print(cur+1,sum);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    tgt = (sum+1L)/2L;
    printf("tgt:%lld\n",tgt);
    ll min = best = sum;
    ll ans;
    ll temp;
    res = dp(0,0);
    printf("Total recursions: %lld, res:%lld\n",cnt,res);
    print(0,0);
    printf("TSum %lld\n",tsum);
    for(int i = 0; i < N; i++)
        printf("%d,",out[i]);
    cout << endl;
    return 0;
}

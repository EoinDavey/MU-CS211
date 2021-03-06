#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
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
ll tgt;
ll res;
ll a[mx_n];
ll cnt = 0;
ll best;
map<state,ll> memo;

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
    ll take = dp(cur+1, sum+a[cur]);
    ll leave = dp(cur+1,sum);
    ll ans = (abs(take) < abs(leave)) ? take : leave;
    memo[s] = ans;
    if(abs(ans) < best)
        best=abs(ans),printf("new best: %lld\n",ans);
    return ans;
}

void print(int cur, ll sum){
    if(cur==N)
        return;
    if(memo[state(cur+1,sum+a[cur])]==res){
        printf("%lld ",a[cur]);
        print(cur+1,sum+a[cur]);
    } else 
        print(cur+1,sum);
}

int main(){
    cin >> N;
    ll sum = 0;
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
    printf("Total recursions: %lld\n",cnt);
    print(0,0);
    cout << endl;
    /*for(int i = 0; i < N; i++){
        memo.clear();
        temp = a[i];
        a[i] = -1;
        res = dp(0,0);
        printf("Ignoring %d gives %d\n",temp,res);
        if(res < min)
            min = res,ans=i;
        a[i] = temp;
    }
    printf("%d, %d\n",min,ans);*/
    return 0;
}

#include<cstdio>
#include<queue>
#include<vector>
typedef long long ll;

using namespace std;

priority_queue<ll> q;
vector<ll> right;
vector<ll> left;
vector<ll> trash;
int N;
const int mx_n = 44;
ll a[mx_n];

void rec(){
    if(q.size()==1){
        right.push_back(q.top());
        return;
    } 
    int v1 = q.top(); q.pop();
    int v2 = q.top(); q.pop();
    int dif = v1-v2;
    printf("%d,%d\n",v1,v2);
    q.push(dif);
    if(dif!=0)
        rec();
    else
        right.push_back(0);
    bool found = false;
    for(int i = 0; i < right.size()&&!found; i++){
        if(right[i]==dif){
            right.erase(right.begin() + i);
            found = true;
            right.push_back(v1);
            left.push_back(v2);
        }
    }
    for(int i = 0; i < left.size()&&!found; i++){
        if(left[i]==dif){
            left.erase(left.begin() + i);
            found = true;
            left.push_back(v1);
            right.push_back(v2);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i =0; i < N; i++){
        scanf("%lld",&a[i]);
        q.push(a[i]);
    }
    rec();
    ll lsum,rsum;
    lsum=rsum=0;
    printf("Left:");
    for(int i = 0; i < left.size(); i++){
        lsum+=left[i];
        printf(" %lld",left[i]);
    }
    printf("\nRight:");
    for(int i = 0; i < right.size(); i++){
        rsum+=right[i];
        printf(" %lld",right[i]);
    }
    printf("\n");
    printf("left sum:%lld, right sum:%lld, dif:%lld\n",lsum,rsum,lsum-rsum);
    return 0;
}

#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;

vector<ll> q;
vector<ll> right;
vector<ll> left;
vector<ll> trash;
int N;
const int mx_n = 44;
ll a[mx_n];
ll mn_dif;
bool final = false;

void rec(){
    if(q.size()==1){
        right.push_back(q[0]);
        return;
    } 
    ll mn; bool mnb = false; int mn_pos;
    sort(q.begin(), q.end());
    for(int i = 0; i < q.size(); i++)
        printf("%lld ",q[i]);
    printf("\n");
    for(int i = 0; i < q.size()-1; i++){
        if(q[i+1]-q[i] < mn || !mnb){
            mn = q[i+1] - q[i];
            mnb = true;
            mn_pos = i;
        }
    }
    ll v1 = q[mn_pos+1];
    ll v2 = q[mn_pos];
    ll dif = v1-v2;
    printf("%lld - %lld: %lld\n",v1,v2,dif);
    q.erase(q.begin()+mn_pos);
    q.erase(q.begin()+mn_pos);
    q.push_back(dif);
    if(dif < mn_dif)
        mn_dif = dif;
    if(final){
        if(dif!=mn_dif)
            rec();
        else
            right.push_back(dif);
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
    } else 
        rec();
}

int main(){
    scanf("%d",&N);
    for(int i =0; i < N; i++){
        scanf("%lld",&a[i]);
        mn_dif+=a[i];
        q.push_back(a[i]);
    }
    rec();
    q.clear();
    printf("mn_dif:%lld\n",mn_dif);
    final = true;
    left.clear();
    right.clear();
    for(int i = 0; i < N; i++){
        q.push_back(a[i]);
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

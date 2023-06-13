#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> SC={1,10,100,1000,10000};
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=si(S);
        vector<vector<int>> po(5);
        for(int i=0;i<N;i++){
            po[S[i]-'A'].push_back(i);
        }
        ll ans=-(1LL<<60);
        
        auto calc=[&](){
            int ma=-1;
            ll sum=0;
            for(int i=N-1;i>=0;i--){
                ll x=SC[S[i]-'A'];
                if((S[i]-'A')>=ma) sum+=x;
                else sum-=x;
                chmax(ma,(S[i]-'A'));
            }
            chmax(ans,sum);
            return;
        };
        
        for(int i=0;i<5;i++){
            if(si(po[i])==0) continue;
            int x=po[i][0];
            char sv=S[x];
            for(char c='A';c<='E';c++){
                S[x]=c;
                calc();
            }
            S[x]=sv;
        }
        
        for(int i=0;i<5;i++){
            if(si(po[i])==0) continue;
            int x=po[i].back();
            char sv=S[x];
            for(char c='A';c<='E';c++){
                S[x]=c;
                calc();
            }
            S[x]=sv;
        }
        
        cout<<ans<<"\n";
    }
}

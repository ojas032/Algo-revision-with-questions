#include<bits/stdc++.h>
#include<algorithm>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define vi vector
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000007
#define pb push_back
#define ll long long int
#define db double
#define all(v) v.begin(),v.end()
#define inf 10000000000


using namespace std;

/*

ll expo(ll n){
    ll t;
    if(n==0)return 1;
    else if(n==1) return 2;
    t=expo(n/2);
    if(n%2){
        return t*t*2;
    }
    else return t*t;
}

//ffrom geek for geek
ll exponentMod(ll A, ll B, ll C)  
{  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
    ll y;  
    if (B % 2 == 0) {  
        y = exponentMod(A, B / 2, C);  
        y = (y * y) % C;  
    }  
    else {  
        y = A % C;  
        y = (y * exponentMod(A, B - 1, C) % C) % C;  
    }  
  
    return (ll)((y + C) % C);  
}

*/
/*
class dsu{
public:    
vi<ll> v;


void init(ll n){
    v.assign(n+1,-1);
}

 
ll dsufind(ll x){
    if(v[x]<0){
        return x;
    }
    v[x]=dsufind(v[x]);
    return v[x];
}
 
void dsujoin(ll x,ll y){
    x=dsufind(x);
    y=dsufind(y);
    
    if(x==y)
    return;
    if(v[x]>v[y])swap(x,y);
    v[y]+=v[x];
    v[x]=y;
}

};
*/



char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

bool u[111],w[111],q=true;
vector<int> v[111];
int m1,m2,tot=0,a[111],j;



void dfs(int i){

    u[i]=true;
    w[i]=true;
    for(int j=0;j<v[i].size();j++){
        int k=v[i][j];
        if(!u[k])dfs(k);
        else if(w[k])q=false;
    }
    w[i]=false;
    a[++tot]=i;
}



        
int main(){
    IOS;
    ll t;
    t=1;
   //cin>>t;
    while(t--){
        ll n;cin>>n;
        string s[n+1];
        FOR(i,n)cin>>s[i];
        FORE(i,1,n-1){
            m1=s[i-1].length();
            m2=s[i].length();
            for(j=0;j<m1 && j<m2 && s[i-1][j]==s[i][j];j++);
            if(j<m1 && j<m2)v[s[i-1][j]-'a'].pb(s[i][j]-'a');
            else if(m1>m2)
            q=false;
        }
        for(int i=0;i<26;i++)if(!u[i])dfs(i);
        if(q){
            for(int i=tot;i>0;i--){
                cout<<char(a[i]+'a');
            }
        }
        else{
            cout<<"Impossible\n";
        }

    }
    return 0;
} 

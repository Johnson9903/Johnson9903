#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+7;
const int mod=1e9+7;
#define ll long long
ll fac[MAX];

ll quickmi(ll a,ll b,ll mod){//×î¶ÌÐ´·¨
    ll ans=1;
    for(a%=mod;b;b>>=1,a=a*a%mod)
        if(b&1)
            ans=ans*a%mod;
    return ans;
}
ll CC(ll n,ll m){
    if(n==m || m==0){
        return 1;
    }
    if(n>1e6){
        ll inv=quickmi(fac[m],mod-2,mod);
        ll ans=1;
        for(ll i=n;i>=n-m+1;i--){
            ans=ans*i%mod;
        }
        return ans*inv%mod;
    }else{
        ll inv=quickmi(fac[m]*fac[n-m]%mod,mod-2,mod);
        return fac[n]*inv%mod;
    }
}
int main(){
    ll i,j,k,a,h,n,m,T;
    fac[0]=1;
    for(i=1;i<=1e6;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        ll cc=CC(m,k);
        ll ans=0;
        for(i=2;i<=k;i++){
            a=(k-i+2)*quickmi(k-i+1,n-1,mod)%mod*CC(k,k-i+2)%mod;
            if(i%2==1)
                a=-a+mod;
            ans=(ans+a)%mod;
        }
        ans=ans*cc%mod;
        if(n==1){
            printf("%lld\n",m);
        }else{
            printf("%lld\n",ans);
        }
    }
return 0;}


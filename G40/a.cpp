#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;

   	ll n=s.length()+1;
   	ll arr[n];
   	ll leftarr[n];
   	ll rightarr[n];

   	for(int i=0;i<n;i++){
   		arr[i]=leftarr[i]=rightarr[i]=0;
   	}

   	for(int i=1;i<n;i++){
   		if(s[i-1]=='<'){
   			leftarr[i]=leftarr[i-1]+1;
   		}
   		else{
   			leftarr[i]=0;   			
   		}
   	}

   	for(int i=n-1;i>=0;i--){
   		if(s[i]=='>'){
   			rightarr[i]=rightarr[i+1]+1;
   		}
   		else{
   			rightarr[i]=0;
   		}
   	}

   	ll ans=0;
   	for(int i=0;i<n;i++){
   		// cout<<i<<" "<<leftarr[i]<<" "<<rightarr[i]<<endl;
   		arr[i]=max(leftarr[i],rightarr[i]);
   		ans+=arr[i];
   	}

   	cout<<ans<<endl;

}

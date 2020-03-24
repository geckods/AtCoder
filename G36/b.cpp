#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200001
int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,k;
   	cin>>n>>k;

   	ll a[n];
   	for(int i=0;i<n;i++){
   		cin>>a[i];
   	}

   	ll prevhash[MAXN];

   	for(int i=0;i<MAXN;i++){
   		prevhash[i]=-1;
   	}

   	ll prev[n];

   	for(int i=0;i<n;i++){
   		prev[i]=prevhash[a[i]];
   		prevhash[a[i]]=i;
   	}

   	ll starts[n];
   	ll ends[n];
   	memset(starts,0,sizeof(starts));
   	memset(ends,0,sizeof(ends));

   	for(int i=0;i<n;i++){
   		if(prev[i]==-1)prev[i]=i;
   	}


   	int curr=n-1;

   	int z=0;
   	while(1){
   		z++;
   		ends[curr]=z;
   		curr=prev[curr]-1;
   		if(curr==-1){
   			curr=n-1;
   		}
 	  	starts[curr]=z;
   		if(curr==n-1){
   			break;
   		}
   	}

   	for(int i=0;i<n;i++){
   		cout<<starts[i]<<" "<<ends[i]<<endl;
   	}

   	cout<<z<<endl;

}
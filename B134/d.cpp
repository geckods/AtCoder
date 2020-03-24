#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	int arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	vector<int> toadd;

   	int solarr[n];
   	memset(solarr,0,sizeof(solarr));

   	for(int i=n;i>=1;i--){
   		int curr=0;
   		for(int j=2;i*j<=n;j++){
   			curr^=solarr[i*j-1];
   		}

   		if(curr==arr[i-1]){
   			solarr[i-1]=0;
   		}
   		else{
   			solarr[i-1]=1;
   			toadd.push_back(i);
   		}
   	}

   	cout<<toadd.size()<<endl;
   	for(int i=0;i<toadd.size();i++){
   		cout<<toadd[i]<<" ";
   	}
   	cout<<endl;
}
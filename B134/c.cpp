#include <bits/stdc++.h>
using namespace std;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	int arr[n];

   	int maxval = INT_MIN;
   	int secmax = INT_MIN;

   	for(int i=0;i<n;i++){
   		cin>>arr[i];

   		if(arr[i]>maxval){
   			secmax=maxval;
   			maxval=arr[i];
   		}
   		else if (arr[i]>secmax){
   			secmax=arr[i];
   		}
   	}

   	for(int i=0;i<n;i++){
   		if(arr[i]==maxval){
   			cout<<secmax<<endl;
   		}
   		else{
   			cout<<maxval<<endl;
   		}
   	}
}


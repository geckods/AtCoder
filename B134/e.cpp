#include <bits/stdc++.h>
using namespace std;

int mnis(int arr[], int n) 
{ 
    multiset<int> last; 
  
    for (int i = 0; i < n; i++) {   
        multiset<int>::iterator it = last.lower_bound(arr[i]);   
        if (it == last.begin()) 
            last.insert(arr[i]);   
        else { 
            it--; 
            last.erase(it);
            last.insert(arr[i]);
        } 
    } 
    return last.size();
} 


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

   	cout<<mnis(arr,n)<<endl;
}
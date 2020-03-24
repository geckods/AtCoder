#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string s;
   	cin>>s;
   	int n=s.length();

   	int i=0;
   	string ministring;
   	string prevstring;
   	int ans=0;
   	while(i<n){
   		ministring+=s[i];
   		if(ministring!=prevstring){
   			prevstring=ministring;
	   		ministring="";
   			ans++;
   		}
   		i++;
   	}

   	cout<<ans<<endl;
}

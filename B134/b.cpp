#include <bits/stdc++.h>
using namespace std;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,d;
   	cin>>n>>d;

   	d = 2*d + 1;

   	cout<<ceil((double)n/d)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (ll i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll s;
   	cin>>s;

   	cout<<0<<" "<<0<<" ";

   	ll sq = sqrt(s);

   	ll bx,cy,cx,by;

   	bx = cy = sq;

   	bool done=false;

   	if(bx*cy==s){
   		cx=by=0;
   		done=true;
   	}

   	if(!done){
   		bx++;
   		cy++;
   		cx=1;
   		by=(bx*cy-s)/1;
   	}

   	cout<<bx<<" "<<by<<" "<<cx<<" "<<cy<<endl;

}

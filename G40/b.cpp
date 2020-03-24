#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

bool compare(intpair a, intpair b){
	return a.second>b.second;
}

bool compare2(intpair a, intpair b){
	return a.second-a.first>b.second-b.first;
}

bool compare3(intpair a, intpair b){
	return a.second+a.first>b.second+b.first;
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	//idea:
   	//take the smallest one. remove all that completely encapsulate it
   	//now there's four types:
   	//l,r below, l,r above, l below and r in range, l in range and r above
   	//if there exists types 1 and 2 or 1 and 4, then the answer is zero

   	//else, for simplicity, we can consider l,r below and l below and r in range
   	//take all l,r below. If they are disjoint, then the answer is zero


   	//lets try thinking from largest
   	//take the largest, put it in a. 

   	//in terms of maxl, minr
   	//if maxl<=minr, answer is straightforward
   	//else, you either got to delete minrs or maxls. While doing so, check what you can form with them until you reach maxl<=minr. If you form zero, just make it the biggest thing


   	//greedily maximize one set for size x from 1 to n-1, add size of other set



   	/*
   	you are either going to zero one of them, or not going to zero one of them
   	If you are, then your answer is just maximum size
   	
   	else, take all minimal ls, rs, such that there doesn't exist a pair that completely encapsulates
		if there's more than one break, it's impossible
		else
			if there's one break, use that break
			else(there's zero breaks)
				try everything



	to do the minimal thing, put in set, use lower/upper bounds to check that they aren't completely inside
	*/

	ll n;
	cin>>n;

	ll ans=0;

	vector<intpair> myVec;

	intpair maxPair;
	maxPair.first=0;
	maxPair.second=-1;

	for(int i=0;i<n;i++){
		intpair myPair;
		cin>>myPair.first>>myPair.second;
		myVec.push_back(myPair);

		if(myPair.second-myPair.first>maxPair.second-maxPair.first){
			maxPair=myPair;
		}
	}
	ans=max(ans,maxPair.second-maxPair.first+1);

	sort(myVec.begin(),myVec.end(),compare3);
	//myVec is in decending order of size
	// set<intpair> mySet;

	// for(int i=n-1;i>=0;i--){
		// cout<<myVec[i].first<<" "<<myVec[i].second<<endl;
		// intpair currPair = myVec[i];
		// if((!mySet.empty()) && mySet.lower_bound(currPair)!=mySet.end() && mySet.lower_bound(currPair)->second <= currPair.second){
			// cout<<mySet.lower_bound(currPair)
		// }
		// else{
			// mySet.insert(currPair);
		// }
	// }

	// cout<<mySet.size()<<endl;

	// if(mySet.size()==1){
	// 	ans+=mySet.begin()->second-mySet.begin()->first+2;
	// 	cout<<ans<<endl;
	// 	return 0;
	// }

	vector<intpair> newVec=myVec;
	// for(set<intpair>::iterator si = mySet.begin();si!=mySet.end();si++){
	// 	newVec.push_back(*si);
	// }

	int m = newVec.size();
	//make prefix l,r
	//make suffix l,r

	vector<intpair> prefix;
	ll currmin=1;
	ll currmax=1e9;

	for(int i=0;i<m;i++){
		currmin=max(currmin,newVec[i].first);
		currmax=min(currmax,newVec[i].second);
		prefix.push_back(make_pair(currmin,currmax));
	}

	vector<intpair> suffix;
	currmin=1;
	currmax=1e9;

	for(int i=m-1;i>=0;i--){
		currmin=max(currmin,newVec[i].first);
		currmax=min(currmax,newVec[i].second);
		suffix.push_back(make_pair(currmin,currmax));
	}

	reverse(suffix.begin(),suffix.end());

	for(int i=0;i<m-1;i++){
		// cout<<i<<" "<<prefix[i].first<<" "<<prefix[i].second<<" "<<suffix[i+1].first<<" "<<suffix[i+1].second<<endl;
		ans=max(ans,max(-1ll,prefix[i].second-prefix[i].first)+max(-1ll,suffix[i+1].second-suffix[i+1].first)+2);
	}


	// vector<intpair> newVec;

	// for(set<intpair>::iterator si = mySet.begin();si!=mySet.end();si++){
	// 	newVec.push_back(*si);
	// }

	// sort(newVec.begin(),newVec.end(),compare);

	// // int m = newVec.size();
	// //make prefix l,r
	// //make suffix l,r

	// // vector<intpair> prefix;
	// prefix.clear();
	// suffix.clear();
	// currmin=1;
	// currmax=1e9;

	// for(int i=0;i<m;i++){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	prefix.push_back(make_pair(currmin,currmax));
	// }

	// // vector<intpair> suffix;
	// currmin=1;
	// currmax=1e9;

	// for(int i=m-1;i>=0;i--){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	suffix.push_back(make_pair(currmin,currmax));
	// }

	// reverse(suffix.begin(),suffix.end());

	// for(int i=0;i<m-1;i++){
	// 	// cout<<i<<" "<<prefix[i].first<<" "<<prefix[i].second<<" "<<suffix[i+1].first<<" "<<suffix[i+1].second<<endl;
	// 	ans=max(ans,max(-1ll,prefix[i].second-prefix[i].first)+max(-1ll,suffix[i+1].second-suffix[i+1].first)+2);
	// }


	// sort(newVec.begin(),newVec.end(),compare2);

	// // int m = newVec.size();
	// //make prefix l,r
	// //make suffix l,r

	// // vector<intpair> prefix;
	// prefix.clear();
	// suffix.clear();
	// currmin=1;
	// currmax=1e9;

	// for(int i=0;i<m;i++){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	prefix.push_back(make_pair(currmin,currmax));
	// }

	// // vector<intpair> suffix;
	// currmin=1;
	// currmax=1e9;

	// for(int i=m-1;i>=0;i--){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	suffix.push_back(make_pair(currmin,currmax));
	// }

	// reverse(suffix.begin(),suffix.end());

	// for(int i=0;i<m-1;i++){
	// 	// cout<<i<<" "<<prefix[i].first<<" "<<prefix[i].second<<" "<<suffix[i+1].first<<" "<<suffix[i+1].second<<endl;
	// 	ans=max(ans,max(-1ll,prefix[i].second-prefix[i].first)+max(-1ll,suffix[i+1].second-suffix[i+1].first)+2);
	// }

	// sort(newVec.begin(),newVec.end(),compare3);

	// // int m = newVec.size();
	// //make prefix l,r
	// //make suffix l,r

	// // vector<intpair> prefix;
	// prefix.clear();
	// suffix.clear();
	// currmin=1;
	// currmax=1e9;

	// for(int i=0;i<m;i++){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	prefix.push_back(make_pair(currmin,currmax));
	// }

	// // vector<intpair> suffix;
	// currmin=1;
	// currmax=1e9;

	// for(int i=m-1;i>=0;i--){
	// 	currmin=max(currmin,newVec[i].first);
	// 	currmax=min(currmax,newVec[i].second);
	// 	suffix.push_back(make_pair(currmin,currmax));
	// }

	// reverse(suffix.begin(),suffix.end());

	// for(int i=0;i<m-1;i++){
	// 	// cout<<i<<" "<<prefix[i].first<<" "<<prefix[i].second<<" "<<suffix[i+1].first<<" "<<suffix[i+1].second<<endl;
	// 	ans=max(ans,max(-1ll,prefix[i].second-prefix[i].first)+max(-1ll,suffix[i+1].second-suffix[i+1].first)+2);
	// }





	cout<<ans<<endl;
}
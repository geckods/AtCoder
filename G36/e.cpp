#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);


	string s;
	cin>>s;

	string ans;

	ans+=s[0];

	// cerr<<"HI"<<endl;
	for(int i=1;i<s.length();i++){
		if(s[i]!=s[i-1])
			ans+=s[i];
	}

	int n=ans.length();

	// int acount=0,bcount=0,ccount=0;
	// for(int i=0;i<ans.length();i++){
	// 	if(ans[i]=='A')acount++;
	// 	if(ans[i]=='B')bcount++;
	// 	if(ans[i]=='C')ccount++;
	// }


	// string finalans;

	// int themin = min(min(acount,bcount),ccount);
	// int atodelete=acount-themin;
	// int btodelete=bcount-themin;
	// int ctodelete=ccount-themin;

	// for(int i=0;i<ans.length();i++){
	// 	if(ans[i]=='A'){
	// 		if(atodelete>0){
	// 			atodelete--;
	// 		}
	// 		else{
	// 			finalans+='A';
	// 		}
	// 	}
	// 	else if (ans[i]=='B'){
	// 		if(btodelete>0){
	// 			btodelete--;
	// 		}
	// 		else{
	// 			finalans+='B';
	// 		}
	// 	}
	// 	else{
	// 		if(ctodelete>0){
	// 			ctodelete--;
	// 		}
	// 		else{
	// 			finalans+='C';
	// 		}
	// 	}
	// }

	// int dp[n][3][2];

	// int firsta=0,firstb=0,firstc=0;
	// while(firsta<n && ans[firsta]!='A')firsta++;
	// while(firstb<n && ans[firstb]!='B')firstb++;
	// while(firstc<n && ans[firstc]!='C')firstc++;

	// dp[0][0][0]=firsta;
	// dp[0][1][0]=firstb;
	// dp[0][2][0]=firstc;


	// int x=1;
	// while(1){
	// 	for(int j=0;j<3;j++){
	// 		dp[x][j][0]=n;
	// 		int min=n;
	// 		for(int k=0;k<3;k++){
	// 			// cerr<<j<<" "<<k<<endl;
	// 			if(j==k)continue;
	// 			int currpointer=dp[x-1][k][0]+1;
	// 			while(currpointer<n && (((j==0) && ans[currpointer]!='A')||((j==1)&&ans[currpointer]!='B')||((j==2)&&ans[currpointer]!='C')))currpointer++;
	// 			if(currpointer<min){
	// 				min=currpointer;
	// 				dp[x][j][0]=currpointer;
	// 				dp[x][j][1]=k;
	// 			}
	// 		}
	// 	}

	// 	if(dp[x][0][0]==n && dp[x][1][0]==n && dp[x][2][0]==n){
	// 		break;
	// 	}

	// 	cerr<<x<<" "<<dp[x][0][0]<<" "<<dp[x][1][0]<<" "<<dp[x][2][0]<<endl;

	// 	x++;
	// }
	// cout<<x<<endl;

	//

	int dp[(n/3)+1];


	// cout<<finalans<<endl;
}
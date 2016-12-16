
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int main(){
	
	int n;
	ll k;
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a + n);
	int maxLen = 1,ans = a[n - 1];
	int j = n - 1,i = n - 1;
	ll temp = 0;
	while(j >= 0){
		while(i >= 0){
			if(temp + a[j] - a[i] <= k){
				temp += (a[j] - a[i]);
				i--;
			}else{
				break;
			}
			cout<<temp<<" "<<j<<" "<<i<<endl;
		}
		cout<<"temp "<<temp<<endl;
		if(maxLen <= j - i){
			maxLen = j - i;
			ans = a[j];
		}
		if(j > 0){
			temp -= (j - i - 1)*(a[j] - a[j - 1]);
		}
		j--;
		i++;
		cout<<"temp1 "<<temp<<endl;
		cout<<"maxLen "<<maxLen<<endl;
	}
	cout<<"hello "<<maxLen<<" "<<ans<<endl;
	return 0;
}
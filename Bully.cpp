
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
int sieve[10000005];
map<int,int> mymap;
void fun(int n){
	set<int> fac;
	while(sieve[n] != -1){
		fac.insert(sieve[n]);
		n /= sieve[n]; 
	}
	if(n >= 2)
	fac.insert(n);
    int maxi = 0;
    for(set<int>::iterator it = fac.begin();it != fac.end();it++){
    	if(mymap.find(*it) != mymap.end()){
    		maxi = max(maxi,mymap[*it]);
    	}
    }
    for(set<int>::iterator it = fac.begin();it != fac.end();it++){	
    	mymap[*it] = maxi + 1;
    }
}
int main(){
	
	int t;
	scanf("%d",&t);
	for(int i = 0;i < 10000005;i++){
		sieve[i] = -1;
	}
	for(int i = 2;i < 10000005;i++){
		if(sieve[i] == -1){
			for(int j = i*2;j < 10000005;j = j + i){
				sieve[j] = i;
			}
		}
	}
	while(t--){
		int n;
		scanf("%d",&n);
		mymap.clear();
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
		}
		for(int i = n - 1;i >= 0;i--){
			fun(a[i]);
		}
		int ans = 1;
		for(map<int,int>::iterator it = mymap.begin();it != mymap.end();it++){
			ans = max(ans,it->second);
		}
		printf("%d\n",ans);
	}
	return 0;
}
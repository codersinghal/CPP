//in-out dp algorithm
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5;

vector<ll> g[N];

int in[N], out[N];

// compute in[] array
ll dfs1(ll node, ll par){
	in[node] = 0LL;
	for(auto child: g[node]){
		if(child == par)continue;
		dfs1(child, node);
		in[node] = max(in[node], 1+in[child]);
	}
}

// compute out[] array
ll dfs2(ll node, ll par){
	ll mx1 = -1;
	ll mx2 = -1;
	
	for(auto child: g[node]){
		if(child == par) continue;
		if(in[child] >= mx1) mx2 = mx1, mx1 = in[child];
		else if(in[child] > mx2) mx2 = in[child];
	}
	
	for(auto child: g[node]){
		if(child == par) continue;
		ll use = mx1;
		if(mx1 == in[child]) use = mx2;		
		out[child] = max(1LL+out[node], 2LL+use);
		dfs2(child, node);
	}
}

int main(){
	std::ios_base::sync_with_stdio(0);
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	ll n;
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);	
	}
	dfs1(1, 0);
	dfs2(1, 0);
	
	for(ll i=1;i<=n;i++) cout << max(in[i], out[i]) <<" ";	
}

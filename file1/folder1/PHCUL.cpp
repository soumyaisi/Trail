#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
	int t;
	int n,m,k;
	ll a,b;
	pair<ll, ll>target;
	map<pair<ll,ll>, pair<ll, ll>>m1;
	map<pair<ll,ll>, pair<ll, ll>>m2;
	map<pair<ll,ll>, pair<ll, ll>>m3;
	map<pair<ll,ll>, pair<ll, ll>>m4;
	cin >> t;
	while(t--){
		m1.clear();
		m2.clear();
		m3.clear();
		m4.clear();
		cin >> a >> b;
		cin >> n >> m >> k;
		target = make_pair(a,b);
		vector<pair<ll, ll>>set1;
		vector<pair<ll, ll>>set2;
		vector<pair<ll, ll>>set3;
		ll c,d;
		for(int i = 0; i < n; i++){
			cin >> c >> d;
			set1.push_back(make_pair(c,d));
		}
		for(int i = 0; i < m; i++){
			cin >> c >> d;
			set2.push_back(make_pair(c,d));
		}
		for(int i = 0; i < k; i++){
			cin >> c >> d;
			set3.push_back(make_pair(c,d));
		}
		ll dist1 = LONG_MAX;
		ll dist2 = LONG_MAX;
		ll dist3 = LONG_MAX;
		ll dist4 = LONG_MAX;
		ll dist5 = LONG_MAX;
		ll dist6 = LONG_MAX;
		ll x1,x2,y1,y2,x_d, y_d;
		for(int i = 0; i < n; i++){
			x2 = set1[i].first;
			y2 = set1[i].second;
			for(int j = 0; j < m; j++){
				x1 = set2[j].first;
				y1 = set2[j].second;
				ll w3 = pow((x1-x2), 2) + pow((y1-y2), 2);
				if(w3 <= dist3){
					x_d = x1;
					y_d = y1;
					dist3 = w3;
				}
				//dist3 = min(dist3, w3);
			}
			m1.insert({make_pair(x2, y2), make_pair(x_d, y_d)});
		}
		for(int i = 0; i < m; i++){
			x2 = set2[i].first;
			y2 = set2[i].second;
			for(int j = 0; j < n; j++){
				x1 = set1[j].first;
				y1 = set1[j].second;
				ll w6 = pow((x1-x2), 2) + pow((y1-y2), 2);
				if(w6 <= dist6){
					x_d = x1;
					y_d = y1;
					dist6 = w6;
				}
				//dist3 = min(dist3, w3);
			}
			m4.insert({make_pair(x2, y2), make_pair(x_d, y_d)});
		}
		for(int i = 0; i < n; i++){
			x2 = set1[i].first;
			y2 = set1[i].second;
			for(int j = 0; j < k; j++){
				x1 = set3[j].first;
				y1 = set3[j].second;
				ll w4 = pow((x1-x2), 2) + pow((y1-y2), 2);
				if(w4 <= dist4){
					x_d = x1;
					y_d = y1;
					dist4 = w4;
				}
				//dist4 = min(dist4, w4);
			}
			m2.insert({make_pair(x2, y2), make_pair(x_d, y_d)});
		}
		for(int i = 0; i < m; i++){
			x2 = set2[i].first;
			y2 = set2[i].second;
			for(int j = 0; j < k; j++){
				x1 = set3[j].first;
				y1 = set3[j].second;
				ll w5 = pow((x1-x2), 2) + pow((y1-y2), 2);
				if(w5 <= dist5){
					x_d = x1;
					y_d = y1;
					dist5 = w5;
				}
				//dist5 = min(dist5, w5);
			}
			m3.insert({make_pair(x2, y2), make_pair(x_d, y_d)});
		}
		long double ans1;
		for(int i = 0; i < n; i++){
			x1 = target.first;
			y1 = target.second;
			x2 = set1[i].first;
			y2 = set1[i].second;
			map<pair<ll,ll>, pair<ll, ll>>:: iterator it1;
			map<pair<ll,ll>, pair<ll, ll>>:: iterator it2;
			it1 = m1.find(make_pair(x2, y2));
			it2 = m3.find(make_pair((it1->second).first, (it1->second).second));
			ll w1 = pow((x1-x2), 2) + pow((y1-y2), 2) + pow((x2-(it1->second).first), 2) + pow((y2-(it1->second).second), 2)
			 + pow(((it1->second).first-(it2->second).first), 2) + pow(((it1->second).second-(it2->second).second), 2);
			if(w1 <= dist1){
				dist1 = w1;
				ans1 = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2)) + sqrt(pow((x2-(it1->second).first), 2) + pow((y2-(it1->second).second), 2))
			 + sqrt(pow(((it1->second).first-(it2->second).first), 2) + pow(((it1->second).second-(it2->second).second), 2));
				
			}
			//dist1 = min(dist1, w1);
		}
		long double ans2;
		for(int i = 0; i < n; i++){
			x1 = target.first;
			y1 = target.second;
			x2 = set2[i].first;
			y2 = set2[i].second;
			map<pair<ll,ll>, pair<ll, ll>>:: iterator it3;
			map<pair<ll,ll>, pair<ll, ll>>:: iterator it4;
			it3 = m4.find(make_pair(x2, y2));
			it4 = m2.find(make_pair((it3->second).first, (it3->second).second));
			ll w2 = pow((x1-x2), 2) + pow((y1-y2), 2) + pow((x2-(it3->second).first), 2) + pow((y2-(it3->second).second), 2)
			 + pow(((it3->second).first-(it4->second).first), 2) + pow(((it3->second).second-(it4->second).second), 2);
			if(w2 <= dist2){
				dist2 = w2;
				ans2 = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2)) + sqrt(pow((x2-(it3->second).first), 2) + pow((y2-(it3->second).second), 2))
			 + sqrt(pow(((it3->second).first-(it4->second).first), 2) + pow(((it3->second).second-(it4->second).second), 2));
				
			}
			//dist2 = min(dist2, w2);
		}

		if(ans1 < ans2){
			//long double ans1 = sqrt(dist1)+sqrt(dist3)+sqrt(dist5);
			printf("%.10Lf\n",ans1);
		}
		else{
			//long double ans2 = sqrt(dist3)+sqrt(dist2)+sqrt(dist4);
			printf("%.10Lf\n",ans2);
		}
	}
	return 0;
}

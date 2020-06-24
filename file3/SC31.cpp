#include<bits/stdc++.h>


using namespace std;


int main(){
	int t,n;
	
	cin >> t;
	while(t--){
		cin >> n;
		vector<string> vec;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			vec.push_back(s);
		}
		//string d = "0000011";
		//stringstream q(d);
		//int r = 0;
		//q >> r;
		//cout << r << endl;
		if(n == 1){
			char arr3[10];
			//stringstream no3(vec[0]);
			//int x3 = 0;
			//no3 >> x3;
			for(int i = 9; i >= 0; i--){
				//int rem2 = x3 % 10;
				//int div2  = x3 / 10;
				//arr3[i] = rem2;
				arr3[i] = vec[0][i];
			}
			int count1 = 0;
			for(int i = 0; i < 10; i++){
				if(arr3[i] == '1'){
					count1++;
				}
			}
			cout << count1 << endl; 
		}
		else{
			int n1 = 1;
			char arr1[10];
			//stringstream no(vec[0]);
			//int x1 = 0;
			//no >> x1;
			//cout << x1 << endl;
			for(int i = 9; i >= 0; i--){
				//int rem = x1 % 10;
				//int div  = x1 / 10;
				//arr1[i] = rem;
				arr1[i] = vec[0][i];
			} 
			while(n1 < n){
				char arr2[10];
				//stringstream on(vec[n1]);
				//int x2 = 0;
				//on >> x2;
				//cout << x2 << endl;
				for(int i = 9; i >= 0; i--){
					//int rem1 = x2 % 10;
					//int div1 = x2 / 10;
					//arr2[i] = rem1;
					arr2[i] = vec[n1][i];
				}

				for(int i = 0; i <= 9; i++){
					if(arr2[i] == '1' &&  arr1[i] == '1'){
						arr1[i] = '0';
					}
					else if(arr1[i] == '0' && arr2[i] == '0'){
						arr1[i] = '0';
					}
					else{
						arr1[i] = '1';
					}
				}
				n1++;
			}
			int count = 0;
			for(int i = 0; i < 10; i++){
				if(arr1[i] == '1'){
					count++;
				}
			}
			cout << count << endl;
		}
	}
	return 0;
}
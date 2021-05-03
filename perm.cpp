#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <map>


const int N = 5, R = 3;

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	map<string, uint64_t> m;
	map<string, uint64_t>::iterator it;
	vector<bool> v(N);
	fill(v.end() - R, v.end(), true); 
	int a[N], val[N], b[R];
	for(int i = 0; i < N; i++)
		a[i] = i;

	
	do{

		int counter = 0;
		for(int i = 0; i < N; i++){
			if(v[i]){
				b[counter] = a[i];
				cout << b[counter] << "\t";
				counter++;
			}
		}
		cout << endl;
		do{
			for(int i = 0; i < N; i++)
				val[i] = i;
			for(int i = 0; i < R - 1; i++){
				if(b[i] > b[i+1]){
					val[b[i+1]] = val[b[i]];
				} else {
					val[b[i]] = val[b[i+1]];
				}
			}
			for(int i = 0; i < R; i++)
				cout << b[i];
			cout << "\t";
			for(int i = 0; i < R; i++)
				cout << val[b[i]];
			cout << endl;
			string res = "000";
			for(int i = 0; i < R; i++){
				res[i] = val[b[i]] + '0';
			}
			m[res]++;
		} while (next_permutation(b, b + R));
	} while (next_permutation(v.begin(), v.end()));

	int counter = 0;
	for(it = m.begin(); it != m.end(); it++)
		if(it->second > 0){
			cout << it->first << "\t" << it->second <<endl;
			counter++;
		}
	cout << counter << endl;
	return 0;
}


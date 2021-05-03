#include <algorithm>
#include <iostream>
#include <string> 
#include <map>

const int N = 10, tenfact = 3628800;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	map<string, uint64_t> m;
	map<string, uint64_t>::iterator it;
	int a[N], val[N];
	for(int i = 0; i < N; i++)
		a[i] = i;

	do{
		for(int i = 0; i < N; i++)
			val[i] = i;
		for(int i = 0; i < N-1; i++){
			if(a[i] > a[i+1]){
				val[a[i+1]] = val[a[i]];
			} else {
				val[a[i]] = val[a[i+1]];
			}
		}
		for(int i = 0; i < N; i++)
			cout << a[i];
		cout << "\t";
		for(int i = 0; i < N; i++)
			cout << val[i];
		cout << endl;
		uint64_t res = 0;
		for(int i = 0; i < N; i++){
			res *= 10;
			res += val[i];
		}
		string temp = to_string(res);
		m[temp]++;
	} while (next_permutation(a, a + N));
	int counter = 0;
	for(it = m.begin(); it != m.end(); it++)
		if(it->second > 0){
			cout << it->first << "\t" << it->second <<endl;
			counter++;
		}
	cout << counter << endl;
	return 0;
}


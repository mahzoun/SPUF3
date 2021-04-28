#include <iostream>
#include <algorithm>
#include <map>
const int N = 3;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	map<uint64_t, uint64_t> m;
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
		m[res]++;
	} while (next_permutation(a, a + N));
	int counter = 0;
	for(int i = 0; i < m.size(); i++)
		if(m[i] > 0){
			cout << i << "\t" << m[i] <<endl;
			counter++;
		}
	cout << counter << endl;
	return 0;
}


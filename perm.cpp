#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>


const int N = 4, R = 3;

using namespace std;

void perm_exp(){
	map<string, uint64_t> m;
	map<string, uint64_t>::iterator it;
	vector<bool> v(N);
	fill(v.end() - R, v.end(), true); 
	int a[N], val[N], b[R];
	for(int i = 0; i < N; i++)
		a[i] = i;
	
	int total_ch = 0;
	
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
			total_ch++;
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
				cout << b[i] << " ";
			cout << "\t";
			for(int i = 0; i < N; i++)
				cout << val[i] << " ";
			cout << endl;
			string res = "";
			for(int i = 0; i < N; i++)
				res += "0";
			for(int i = 0; i < N; i++){
				res[i] = val[i] + '0';
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
	cout << total_ch << "\t" << counter << endl;
}

void seq_exp(){
	uint64_t counter = 0, num_of_exps = 0;
	uint8_t a[2*N], b[2*R];
	map<string, uint64_t> m;
	map<string, uint64_t>::iterator it;
	int val[N];
	do{
		counter++;
		//init a
		uint64_t temp = counter;
		for(int i = 2 * R - 1; i >= 0; i--){
			b[i] = temp % N;
			temp /= N;
		}
		//check if a is valid
		bool valid = true;
		for(int i = 2 * R - 1; i > 0; i--){
			if((i%2 == 1) & (b[i] == b[i-1]))
				valid = false;
			if(i > 2){
				if(b[i] == b[i-2] & b[i-1] == b[i-3])
					valid = false;
				if(b[i] == b[i-3] & b[i-1] == b[i-2])
					valid = false;
			}
			if(valid == false)
				break;
		}
		if(valid == false)
			continue;
		num_of_exps++; //number of valid sequences
		for(int i = 0; i < N; i++)
			val[i] = i;
		for(int i = 0; i < 2 * R; i+=2){
			if(val[b[i]] > val[b[i+1]]){
				val[b[i+1]] = val[b[i]];
			} else {
				val[b[i]] = val[b[i+1]];
			}
		}
		for(int i = 0; i < 2 * R; i++)
			cout << (int)b[i];
		cout << "\t";
		for(int i = 0; i < 2 * R; i++)
			cout << val[b[i]];
		cout << endl;
		string res = "*****";
		for(int i = 0; i < 2*R; i++){
			res[b[i]] = val[b[i]] + '0';
		}
		m[res]++;



	} while (counter < pow(N, 2*R));
	int uniq_seq_counter = 0;
	for(it = m.begin(); it != m.end(); it++)
		if(it->second > 0){
			cout << it->first << "\t" << it->second <<endl;
			uniq_seq_counter++;
		}
	cout << num_of_exps << "\t" << uniq_seq_counter << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	perm_exp(); // set N, R for experiments based on permutations
	//seq_exp();
	return 0;
}


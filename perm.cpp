#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>


const int N = 4, R = 3;

using namespace std;

void perm_exp(){
	vector<bool> v[2];
	v[0].resize(N, 0);
	v[1].resize(N, 0);
	fill(v[0].end() - R, v[0].end(), true); 
	fill(v[1].end() - R, v[1].end(), true); 
	int a[2][N], val[2][N], b[2][R];
	for(int i = 0; i < N; i++) {
		a[0][i] = i;
		a[1][i] = i;
	}
	
	int total_ch = 0;
	
	do{

		map<string, uint64_t> m;
		map<string, uint64_t>::iterator it;
		int counter = 0;
		for(int i = 0; i < N; i++){
			if(v[0][i]){
				b[1][counter] = a[1][i];
				//cout << b[0][counter] << "\t";
				counter++;
			}
		}
		do{
			int counter = 0;
			for(int i = 0; i < N; i++){
				if(v[0][i]){
					b[0][counter] = a[0][i];
					//cout << b[1][counter] << "\t";
					counter++;
				}
			}
			do{
				for(int i = 0; i < N; i++){
					val[0][i] = i;
					val[1][i] = i;
				}

				for(int i = 0; i < R - 1; i++){
					if(b[0][i] > b[0][i+1]){
						val[0][b[0][i+1]] = val[0][b[0][i]];
					} else {
						val[0][b[0][i]] = val[0][b[0][i+1]];
					}

					if(b[1][i] > b[1][i+1]){
						val[1][b[1][i+1]] = val[1][b[1][i]];
					} else {
						val[1][b[1][i]] = val[1][b[1][i+1]];
					}

				}
				for(int i = 0; i < R; i++)
					cout << b[0][i] << " ";
				cout << "\t";
				for(int i = 0; i < R; i++)
					cout << b[1][i] << " ";
				cout << "\t";
				string res = "";
				for(int i = 0; i < 2*N; i++)
					res += "0";
				for(int i = 0; i < N; i++){
					res[i] = val[0][i] + '0';
				}
				for(int i = 0; i < N; i++){
					res[N + i] = val[1][i] + '0';
				}
				cout << res << endl;
				m[res]++;
				total_ch++;
				//second columns
			} while (next_permutation(b[0], b[0] + R));
		} while (next_permutation(v[0].begin(), v[0].end()));
		counter = 0;
		for(it = m.begin(); it != m.end(); it++)
			if(it->second > 0){
				cout << it->first << "\t" << it->second <<endl;
				counter++;
			}
		cout << total_ch << "\t" << counter << endl;
		cout << endl;
	} while (next_permutation(a[1], a[1] + N));

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


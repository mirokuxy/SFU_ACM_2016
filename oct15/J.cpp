#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

const int MAXH = 1000000 + 5;

int height, bottom, top;
int sizes[3];
ull DP[MAXH];

int main(){
	while(scanf("%d %d %d %d %d %d", &height, &bottom, &top, &sizes[0], &sizes[1], &sizes[2]) > 0 ){
		DP[0] = 0;
		for(int h=1; h<= height; h++){
			DP[h] = 0;

			for(int j=0;j<3;j++){
				int size = sizes[j];

				if(size <= h){
					ull width = ull(height-h) * ull(bottom-top) / ull(height) + top;
					ull count = width / size;
					ull volumn = (count * count) * ( ull(size) * ull(size) * ull(size) );
					ull tot_volumn = DP[h-size] + volumn;
					if(tot_volumn > DP[h]){
						DP[h] = tot_volumn;
					}

				}
			}
		}

		ull max_volumn = 0;
		for(int h=1;h<= height; h++){
			max_volumn = max_volumn > DP[h] ? max_volumn : DP[h];
		}

		cout << max_volumn << "\n";
	}

	return 0;
}

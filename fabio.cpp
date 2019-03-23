#include "definitions.h"

int fabio(vec<si> stanze) {
	si i = 0, N=stanze.size();
	si spostamenti = 0;
	while (1) {
		sort(stanze.begin() + i, stanze.end());
		while (i<N && stanze[i]==0) ++i;
		if(i>=N-1) break;

		//for(auto&& st : stanze) cout << st << " "; cout << "\n";

		bool finished = false;
		for(int p = i; p != N-1; ++p) {
			if (stanze[p] == stanze[p+1]) {
				stanze[p]--;
				stanze[p+1]++;
				finished = true;
				break;
			}
		}
		
		if (!finished) {
			stanze[i]--;
			stanze[i+1]++;
		}
		++spostamenti;
	}
	return spostamenti;
}
#include "definitions.hpp"
#include "radix_sort.hpp"

int fabio(vec<si> stanze) {
	si i = 0, N=stanze.size();
	si spostamenti = 0;
	while (1) {
		SORT(stanze.begin() + i, stanze.end());
		while (i<N && stanze.at(i)==0) ++i;
		if(i>=N-1) break;

		//for(auto&& st : stanze) cout << st << " "; cout << "\n";

		bool finished = false;
		for(int p = N-1; p != i; --p) {
			if (stanze.at(p-1) == stanze.at(p)) {
				stanze.at(p-1)--;
				stanze.at(p)++;
				finished = true;
				break;
			}
		}

		if (!finished) {
			stanze.at(i)--;
			stanze.at(i+1)++;
		}
		++spostamenti;
	}
	return spostamenti;
}

#include "definitions.hpp"
#include "radix_sort.hpp"

int fabio2(vec<si> stanze) {
	si i = 0, N=stanze.size();
	si spostamenti = 0;
	while (1) {
		radix_sort<vec<si>::iterator, SiMax>(stanze.begin() + i, stanze.end());
		while (i<N && stanze[i]==0) ++i;
		if(i>=N-1) break;

		//for(auto&& st : stanze) cout << st << " "; cout << "\n";

		bool foundDouble = false;
		for(int p = N-1; p != i; --p) {
			if (stanze[p] == stanze[p+1]) {
				stanze[p]--;
				stanze[p+1]++;
				foundDouble = true;
				break;
			}
		}

		if (!foundDouble) {
			break;
		}
		++spostamenti;
	}

	for(vec<si>::iterator it = stanze.begin() + i; it != stanze.end(); ++it) {
		spostamenti += (stanze.end()-it-1) * (*it);
	}

	return spostamenti;
}

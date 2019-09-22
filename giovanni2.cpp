#include "definitions.hpp"

array<array<si,                         100>, 100> mem2{};
array<array<array<si,             100>, 100>, 100> mem3{};
array<array<array<array<si, 100>, 100>, 100>, 100> mem4{};

si _giovanni2_impl(vec<si> V) {
	SORT(V.begin(),V.end());
	if (V.size() == 2 && mem2.at(V[0]).at(V[1]) >= 0) {
		return mem2.at(V[0]).at(V[1]);
	}
	if (V.size() == 3 && mem3.at(V[0]).at(V[1]).at(V[2]) >= 0) {
		return mem3.at(V[0]).at(V[1]).at(V[2]);
	}
	if (V.size() == 4 && mem4.at(V[0]).at(V[1]).at(V[2]).at(V[3]) >= 0) {
		return mem4.at(V[0]).at(V[1]).at(V[2]).at(V[3]);
	}

	si firstNonZero=0;
	while(firstNonZero<V.size() && V.at(firstNonZero)==0) firstNonZero++;

	si l=-1;
	for(int i=firstNonZero+1;i<V.size();i++){
		V.at(i-1)--;
		V[i]++;
		l=max(l,_giovanni2_impl(vec<si>(V.begin()+firstNonZero, V.end())));
		V.at(i-1)++;
		V[i]--;
	}

	if (V.size() == 2) {
		mem2.at(V[0]).at(V[1]) = l+1;
	}
	if (V.size() == 3) {
		mem3.at(V[0]).at(V[1]).at(V[2]) = l+1;
	}
	if (V.size() == 4) {
		mem4.at(V[0]).at(V[1]).at(V[2]).at(V[3]) = l+1;
	}
	return l+1;
}

si giovanni2(vec<si> V) {
	static bool initialized = false;
	if (!initialized) {
		cout<<" (giovanni2 init) "<<flush;
		initialized = true;

		for(auto&& arr : mem2) {
			for(auto&& el : arr) {
				el = -1;
			}
		}

		for(auto&& arr : mem3) {
			arr = mem2;
		}
		for(auto&& arr : mem4) {
			arr = mem3;
		}
	}

	return _giovanni2_impl(V);
}
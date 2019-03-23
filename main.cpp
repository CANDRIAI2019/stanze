#pragma optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using si = long long;
using ui = unsigned long long;
using flt = long double;
using ch = char;
using str = string;
template<class T>
using vec = vector<T>;

ifstream in{"input.txt"};
ofstream out{"output.txt"};

#include "fabio.cpp"
#include "giovanni.cpp"

constexpr si maxv = 10, maxn = 3;

vec<si> getVals(si N) {
	vec<si> res;
	for(si n = 0; n<N; ++n)
		res.push_back(rand()%maxv);
	return res;
}

int main() {
	while (1) {
		vec<si> vals = getVals(maxn);

		for (auto v : vals) cout << v << " ";
		cout << flush;

		si fabio_res = fabio(vals);
		cout << "\nfabio: " << fabio_res << flush;

		si giovanni_res = giovanni(vals);
		cout << " -- giovanni: " << giovanni_res << "\n\n" << flush;
		assert(fabio_res==giovanni_res);
	}
}
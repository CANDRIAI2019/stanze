#include "definitions.h"

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
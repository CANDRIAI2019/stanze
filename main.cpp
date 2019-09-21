#pragma optimize("O3")
#include "definitions.hpp"

#include "fabio.cpp"
#include "fabio2.cpp"
#include "giovanni.cpp"

enum class TestMode { ones, random, time };
constexpr TestMode mode = TestMode::ones;
constexpr si maxv = 11, maxn = 3;

vec<si> getVals(si N) {
	vec<si> res;
	for(si n = 0; n<N; ++n)
		res.push_back(rand()%maxv);
	return res;
}

void test(const vec<si>& vals) {
	si fabio_res = fabio(vals);
	cout << "\nfabio: " << fabio_res << flush;

	si fabio2_res = fabio2(vals);
	cout << " -- fabio2: " << fabio2_res << flush;

	si giovanni_res = giovanni(vals);
	cout << " -- giovanni: " << giovanni_res << "\n\n" << flush;
	assert(fabio_res==giovanni_res && fabio2_res==giovanni_res);
}

template<class F, class... Args>
void time(F function, Args... args) {
	chrono::time_point tp1 = chrono::high_resolution_clock::now();
	si res = function(args...);
	chrono::time_point tp2 = chrono::high_resolution_clock::now();

	float time = chrono::duration_cast<chrono::microseconds>(tp2-tp1).count() / 1000000.f;
	cout << "time = " << setprecision(time < 1 ? 5 : 6) << time <<
		"  -->  result = " << res << "\n";
}

int main() {
	switch (mode) {
		case TestMode::ones:
			for(int i=1;; ++i)
				test(vec<si>(i,1));
			break;
		case TestMode::random:
			while(1)
				test(getVals(rand() % maxn + 1));
			break;
		case TestMode::time:
			for(int n = 100;; n+=100) {
				cout<<"MIGLIORATO --> n = "<<n<<" ";
				time(fabio2, vec<si>(n, 1));
				cout<<"ORIGINALE  --> n = "<<n<<" ";
				time(fabio, vec<si>(n, 1));
				cout<<"\n";
			}
			break;
	}
}
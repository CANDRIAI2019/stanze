#include "definitions.hpp"

#include "fabio.cpp"
#include "fabio2.cpp"
#include "giovanni.cpp"
#include "giovanni2.cpp"

enum class TestMode { ones, random, time, custom, specific };
TestMode mode = TestMode::custom;
constexpr si maxv = 24, maxn = 4;

vec<si> getRandomVals(si maxN, si maxV) {
	si N = rand()%maxN + 1;
	vec<si> res;
	for(si n = 0; n<N; ++n)
		res.push_back(rand()%maxV);
	return res;
}

void test(const vec<si>& vals) {
	cout<<"\nsize = "<<vals.size()<<" -- ";
	for(auto&& val : vals) cout<<val<<" ";
	cout<<"--> "<<flush;


	si fabio_res = fabio(vals);
	cout<<"fabio: "<<fabio_res<<flush;

	si fabio2_res = fabio2(vals);
	cout<<" -- fabio2: "<<fabio2_res<<flush;

	si giovanni_res = giovanni2(vals);
	cout<<" -- giovanni: "<<giovanni_res<<flush;
	
	si giovanni2_res = giovanni2(vals);
	cout<<" -- giovanni2: "<<giovanni2_res<<flush;

	cout<<"\n\n"<<flush;
	assert(fabio_res==giovanni_res);
	assert(fabio2_res==giovanni_res);
	assert(giovanni2_res==giovanni_res);
}

template<class F, class... Args>
void time(F function, Args... args) {
	chrono::time_point tp1 = chrono::high_resolution_clock::now();
	si res = function(args...);
	chrono::time_point tp2 = chrono::high_resolution_clock::now();

	float time = chrono::duration_cast<chrono::microseconds>(tp2-tp1).count() / 1000000.f;
	cout<<"time = "<<setprecision(time < 1 ? 5 : 6)<<time<<
		"  -->  result = "<<res<<"\n";
}

vec<si> getCustomData() {
	vec<si> vals;
	cout<<"Insert integers separated by spaces: ";

	str line;
	getline(cin, line);
	stringstream ss{line};

	si val;
	while(ss>>val)
		vals.push_back(val);
	return vals;
}

si getSkip() {
	si skip;
	cout<<"Insert skip: ";
	cin>>skip;
	return skip;
}

int main(int argc, char const* argv[]) {
	if (argc == 2) {
		str m = argv[1];
		if (m=="ones") mode=TestMode::ones;
		else if (m=="random") mode=TestMode::random;
		else if (m=="time") mode=TestMode::time;
		else if (m=="custom") mode=TestMode::custom;
		else if (m=="specific") mode=TestMode::specific;
	}

	switch (mode) {
		case TestMode::ones: {
			si skip = getSkip();
			for(int i=skip;; i+=skip)
				test(vec<si>(i,1));
			break;
		} case TestMode::random: {
			si maxN, maxV;
			cout<<"Insert the maximum N and the maximum value separated by a space: ";
			cin>>maxN>>maxV;

			while(1)
				test(getRandomVals(maxN, maxV));
			break;
		} case TestMode::time: {
			si skip = getSkip();
			for(int n = skip;; n+=skip) {
				cout<<"MIGLIORATO --> n = "<<n<<" ";
				time(fabio2, vec<si>(n, 1));
				cout<<"ORIGINALE  --> n = "<<n<<" ";
				time(fabio, vec<si>(n, 1));
				cout<<"\n";
			}
			break;
		} case TestMode::custom: {
			while (1) {
				vec<si> vals = getCustomData();
				if (vals.empty()) break;
				test(vals);
			}
			break;
		} case TestMode::specific: {
			while (1) {
				str sfunc;
				cout<<"Insert function (fabio, fabio2, giovanni, giovanni2): ";
				cin>>sfunc;

				function<si(vec<si>)> func;
				if (sfunc=="fabio") func=fabio;
				else if (sfunc=="fabio2") func=fabio2;
				else if (sfunc=="giovanni") func=giovanni;
				else if (sfunc=="giovanni2") func=giovanni2;

				vec<si> vals = getCustomData();
				if (vals.empty()) break;
				cout << "Result = " << func(vals) << "\n";
			}
			break;
		}
	}
}
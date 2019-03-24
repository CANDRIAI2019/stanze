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
		for(int p = N-1; p != i; --p) {
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
vec<si> getVals(si N) {
	vec<si> res;
	for(si n = 0; n<N; ++n)
		res.push_back(rand()%maxv);
	return res;
}
int main() {

    int n;
    cin>>n;
    vector<si> a(n);
    for(auto i:a)
        cin>>i;
    cout<<fabio(a)<<endl;
	/*while (1) {
		vec<si> vals = getVals(maxn);

		for (auto v : vals) cout << v << " ";
		cout << flush;

		si fabio_res = fabio(vals);
		cout << "\nfabio: " << fabio_res << flush;

		//si giovanni_res = giovanni(vals);
		//cout << " -- giovanni: " << giovanni_res << "\n\n" << flush;
		//assert(fabio_res==giovanni_res);
	}*/
}

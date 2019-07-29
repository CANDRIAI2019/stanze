#include "definitions.hpp"

si N;
vec<si>V;
//vec<pair<si,si>>perc;

si risolvi(){
    si l=0;
    si i=1;
    while(V[i-1]<=0){
        i++;
    }
    vector<si>tmp=V;

    for(;i<N;i++){

        //perc.push_back(make_pair(V[i-1],V[i]));
        V[i-1]--;
        V[i]++;
        sort(V.begin(),V.end());
        l=max(l,1+risolvi());
        V=tmp;
        //perc.pop_back();
    }
    /*if(l==0 and perc.size()==8){
        for(auto coso : perc)
            out<<coso.first<<" "<<coso.second<<" - ";
        out<<endl;
    }*/
    return l;
}


int giovanni(vec<si> v){
    V = v;
    N = v.size();
    sort(V.begin(),V.end());
    return risolvi();
}

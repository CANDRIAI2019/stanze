#include "definitions.hpp"

si _giovanni_impl(vec<si>& V){
    si l=0;
    si i=1;

    radix_sort<vec<si>::iterator, SiMax>(V.begin(),V.end());
    while(V[i-1]<=0) i++;
    vec<si>tmp=V;

    for(;i<V.size();i++){
        V[i-1]--;
        V[i]++;
        l=max(l,1+_giovanni_impl(V));
        V=tmp;
    }
    return l;
}


int giovanni(vec<si> v){
    return _giovanni_impl(v);
}

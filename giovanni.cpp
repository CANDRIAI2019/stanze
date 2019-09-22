#include "definitions.hpp"

si _giovanni_impl(vec<si>& V){
    si l=0;
    si i=1;

    SORT(V.begin(),V.end());
    while((i-1)<V.size() && V.at(i-1)<=0) i++;
    vec<si>tmp=V;

    for(;i!=V.size();i++){
        V.at(i-1)--;
        V.at(i)++;
        l=max(l,1+_giovanni_impl(V));
        V=tmp;
    }
    return l;
}


int giovanni(vec<si> v){
    return _giovanni_impl(v);
}

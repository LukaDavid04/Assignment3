#pragma once
#include <iostream>
#include <utility>
#include <set>

using namespace std;

template <typename type, typename type1, typename type2>
class MappingRelation {
private:
    set <pair<type1, type2>> relations;
    set <type> root;
    int size;
public:
    MappingRelation();
    MappingRelation(const MappingRelation&);
    ~MappingRelation();
    int cardinality();
    bool add_element(pair <type1, type2>);
    bool add_to_set(type);
    void remove_element(pair <type1, type2>);
    bool is_member(pair <type1, type2>);
    bool equal(MappingRelation);
    bool reflexive();
    bool irreflexive();
    bool symmetric();
    bool asymmetric();
    bool transitive();
    bool is_function();
    MappingRelation inverse();
    MappingRelation combination();
    template <typename typex, typename typey, typename typez>
    friend ostream& operator << (ostream&, const MappingRelation<typex, typey, typez>&);
};
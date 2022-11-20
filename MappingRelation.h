#pragma once
#include <iostream>
#include <utility>
#include <set>
#include <list>
#include <vector>

using namespace std;

template <typename type1, typename type2>
class MappingRelation {
private:
    set <pair<type1, type2>> relations;
    set <type1> root1;
    set <type2> root2;
    int size;
public:
    MappingRelation();
    MappingRelation(const MappingRelation&);
    ~MappingRelation();
    int cardinality();
    bool add_element(type1, type2);
    void add_to_set(type1, type2);
    void remove_element(type1, type2);
    bool is_member(type1, type2);
    bool operator ==(MappingRelation);
    MappingRelation& operator +(MappingRelation);
    MappingRelation& operator -(MappingRelation);
    vector<type2> operator[](type1);
    bool is_function();
    MappingRelation& intersection(MappingRelation);
    MappingRelation inverse();
    MappingRelation combination();
    template <typename typex, typename typey>
    friend ostream& operator << (ostream&, const MappingRelation<typex, typey>&);
};
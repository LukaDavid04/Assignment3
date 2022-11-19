#include <iostream>
#include "Relation.h"
#include <vector>
#include <set>
#include <utility>
#include "Relation.h"

using namespace std;

template <typename type>
ostream& operator <<(ostream& out, set<pair<type, type>>& s) {
    // set<pair<type,type>>::iterator ssi;
    // out << "{";

    // for (ssi = s.relations.begin(); ssi != s.relations.end(); ++ssi) 
    // {
    //     cout << *ssi << " ";
    // }

    // out << "}";


    return out;
}

template <typename type>
Relation<type>::Relation() {
    int size = 0;
    set <pair<type, type>> relations;
    set <type> root;
}

template <typename type>
Relation<type>::Relation(const Relation& r) {
    relations = r.relations;
    root = r.root;
    size = r.size;
}

template <typename type>
Relation<type>::~Relation() {
    relations.clear();
    root.clear();
}

template <typename type>
int Relation<type>::cardinality() {
    return size;
}

template <typename type>
bool Relation<type>::add_element(type e1, type e2) {
    int i;

    if (root.count(e1) < 1 || root.count(e2) < 1)
        return false;

    pair <type, type> p(e1, e2);
    relations.insert(p);
    size += 1;

}

template <typename type>
bool Relation<type>::add_to_set(int i) {

}

template <typename type>
void Relation<type>::remove_element(type, type) {

}

template <typename type>
bool Relation<type>::is_member(type, type) {

}

template <typename type>
bool Relation<type>::equal(Relation r) {

}
template <typename type>
bool Relation<type>::symmetric() {

}
template <typename type>
bool Relation<type>::asymmetric() {

}
template <typename type>
bool Relation<type>::reflexive() {

}
template <typename type>
bool Relation<type>::irreflexive() {

}


template <typename type>
bool Relation<type>::transitive() {

}
template <typename type>
bool Relation<type>::is_function() {

}


template <typename type>
Relation<type>Relation<type>::inverse() {

}
template <typename type>
Relation<type>Relation<type>::combination() {

}


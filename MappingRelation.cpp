#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "MappingRelation.h"

using namespace std;

template <typename typex, typename typey, typename typez>
ostream& operator << (ostream& out, const MappingRelation<typex, typey, typez>& s) {
    typename set<pair<typex, typex>>::iterator it;

    out << "{ ";
    for (it = s.relations.begin(); it != s.relations.end(); it++) {
        cout << "(";
        cout << it->first << "," << it->second;
        if (it != prev(s.relations.end())) cout << "),";
        else cout << ")";
        if (it != --s.relations.end()) {
            cout << " ";
        }
    }
    out << " }";
    return out;
}

template <typename type, typename type1, typename type2>
MappingRelation<type, type1, type2>::MappingRelation() {
    int size = 0;
    set <pair<type, type>> relations;
    set <type> root;
}

template <typename type, typename type1, typename type2>
MappingRelation<type, type1, type2>::MappingRelation(const MappingRelation& r) {
    relations = r.relations;
    root = r.root;
    size = r.size;
}

template <typename type, typename type1, typename type2>
MappingRelation<type, type1, type2>::~MappingRelation() {
    relations.clear();
    root.clear();
}

template <typename type, typename type1, typename type2>
int MappingRelation<type, type1, type2>::cardinality() {
    return size;
}

template <typename type, typename type1, typename type2>
bool MappingRelation<type, type1, type2>::add_element(pair<type1, type2> p) {
    int i;

    if (root.count(p.first) < 1 || root.count(p.second) < 1)
        return false;

    relations.insert(p);
    size += 1;
    return true;
}

template <typename type, typename type1, typename type2>
bool MappingRelation<type, type1, type2>::add_to_set(type i) {
    if (root.count(i) > 0) return false;
    else root.insert(i);
    return true;
}

template <typename type, typename type1, typename type2>
void MappingRelation<type, type1, type2>::remove_element(pair<type1, type2> p) {
    /*relations.erase(p);
    typename set <pair<type, type>>::iterator pi;
    for (pi = relations.begin(); pi != relations.end(); ++pi)
    {
        if (pi.count(pi.first) < 2 ) root.erase(pi.first);
        if (pi.count(pi.second) < 2) root.erase(pi.second);

    }
    root.erase(p);
    --size;*/
}

template <typename type, typename type1, typename type2>
bool MappingRelation<type, type1, type2>::is_member(pair <type1, type2> p) {
    if (relations.count(p) > 0) return true;
    return false;
}

template <typename type, typename type1, typename type2>
bool MappingRelation<type, type1, type2>::equal(MappingRelation r) {
    typename set <pair<type, type>>::iterator pi;
    for (pi = relations.begin(); pi != relations.end(); ++pi)
    {
        cout << "Cool";

    }
    return true;
}

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::symmetric() {

// }

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::asymmetric() {

// }

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::reflexive() {

// }

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::irreflexive() {

// }

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::transitive() {

// }

// template <typename type, typename type1, typename type2>
// bool MappingRelation<type, type1, type2>::is_function() {

// }

// template <typename type, typename type1, typename type2>
// MappingRelation<type, type1, type2>MappingRelation<type, type1, type2>::inverse() {

// }

// template <typename type, typename type1, typename type2>
// MappingRelation<type, type1, type2>MappingRelation<type, type1, type2>::combination() {
    
// }

int main() {
    MappingRelation <int, int, int> R;

    pair <int, int> p;
    R.add_to_set(15);
    R.add_to_set(7);
    R.add_to_set(8);
    R.add_to_set(9);
    R.add_to_set(6);

    pair <int, int> p1(15,7);
    pair <int, int> p2(6,9);
    R.add_element(p1);
    R.add_element(p2);

    MappingRelation <int, int, int> P(R);

    cout << R << endl;
    cout << P << endl;


    return 0;
}
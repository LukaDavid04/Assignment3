#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "Relation.h"

using namespace std;

template <typename typex>
ostream& operator << (ostream& out, const Relation<typex>& s) {
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
bool Relation<type>::add_element(pair<type, type> p) {
    int i;

    if (root.count(p.first) < 1 || root.count(p.second) < 1)
        return false;

    relations.insert(p);
    size += 1;
}

template <typename type>
bool Relation<type>::add_to_set(type i) {
    if (root.count(i) > 0) return false;
    else root.insert(i);
    return true;
}

template <typename type>
void Relation<type>::remove_element(pair<type, type> p) {
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

template <typename type>
bool Relation<type>::is_member(pair <type, type> p) {
    if (relations.count(p) > 0) return true;
    return false;
}

template <typename type>
bool Relation<type>::equal(Relation r) {
    typename set <pair<type, type>>::iterator pi;
    for (pi = relations.begin(); pi != relations.end(); ++pi)
    {
        cout << "Cool";

    }
    return true;
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

int main() {
    Relation <int> R;

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

    Relation <int> P(R);

    cout << R << endl;
    cout << P << endl;


    return 0;
}
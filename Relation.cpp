#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "Relation.h"

using namespace std;

template <typename typex>
ostream& operator << (ostream& out, const Relation<typex>& s) {
    // typename set <typex>::iterator si;
    typename set<pair<typex,typex>>::iterator it;

    out << "{";
    for (it = s.relations.begin(); it != s.relations.end(); it++){
        cout << "(";
        cout << it->first << "," << it->second;
        cout << ")";
        if (s.relations.size() > 1){
            cout << " ";
        }
    }   
    out << "}";
    
    
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
    return true;

}

template <typename type>
bool Relation<type>::add_to_set(type i) {
    if (root.count(i) > 0) return false;
    else root.insert(i);
    return true;
}

// template <typename type>
// void Relation<type>::remove_element(type, type) {

// }

// template <typename type>
// bool Relation<type>::is_member(type, type) {

// }

// template <typename type>
// bool Relation<type>::equal(Relation r) {

// }
// template <typename type>
// bool Relation<type>::symmetric() {

// }
// template <typename type>
// bool Relation<type>::asymmetric() {

// }
// template <typename type>
// bool Relation<type>::reflexive() {

// }
// template <typename type>
// bool Relation<type>::irreflexive() {

// }


// template <typename type>
// bool Relation<type>::transitive() {

// }
// template <typename type>
// bool Relation<type>::is_function() {

// }


// template <typename type>
// Relation<type>Relation<type>::inverse() {

// }
// template <typename type>
// Relation<type>Relation<type>::combination() {

// }

int main() {
    Relation <int> R;
    pair <int, int> p;
    pair <int, int> q;
    p.first = 21;
    p.second = 21;
    q.first = 15;
    q.second = 7;

    R.add_to_set(15);
    R.add_to_set(7);
    R.add_to_set(21);
    
    R.add_element(p);
    R.add_element(q);

    cout << R << endl;

    return 0;
}
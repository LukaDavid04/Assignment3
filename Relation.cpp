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
bool Relation<type>::add_element(type e1, type e2) {
    int i;

    if (root.count(e1) < 1 || root.count(e2) < 1)
        return false;

	pair <type,type> p(e1, e2);

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
void Relation<type>::remove_element(type e1, type e2) {
	pair <type, type> p(e1, e2);
    relations.erase(p);
}

template <typename type>
bool Relation<type>::is_member(type e1, type e2) {
	pair <type, type> p(e1, e2);
    if (relations.count(p) > 0) return true;
    return false;
}

template <typename type>
bool Relation<type>::operator ==(Relation r) {
	if (relations == r.relations) return true;
	else return false;
}

template <typename type>
vector<type> Relation<type>::operator[](type x) {
	typename set<pair<type, type>>::iterator it;
	vector<type> v;

	for (it = relations.begin(); it != relations.end(); it++) {
		if (it->first == x) {
			v.push_back(it->second);
		}
	}
	return v;
}

template <typename type>
bool Relation<type>::symmetric() {
	typename set<pair<type, type>>::iterator it;

	for (it = relations.begin(); it != relations.end(); it++) {
		if (!is_member(it->second, it->first)) return false;
	}
	return true;
}

template <typename type>
bool Relation<type>::asymmetric() {
	typename set<pair<type, type>>::iterator it;

	for (it = relations.begin(); it != relations.end(); it++) {
		if (is_member(it->second, it->first) && it->first != it->second) return false;
	}
	return true;
}

template <typename type>
bool Relation<type>::reflexive() {
	typename set <type>::iterator it;

	for (it = root.begin(); it != root.end(); it++) {
		if (!is_member(*it, *it)) return false;
	}
	return true;
}

template <typename type>
bool Relation<type>::irreflexive() {
	typename set <type>::iterator it;

	for (it = root.begin(); it != root.end(); it++) {
		if (is_member(*it, *it)) return false;
	}
	return true;
}

template <typename type>
bool Relation<type>::transitive() {
	typename set<pair<type, type>>::iterator it;
	typename set<pair<type, type>>::iterator it2;


	for (it = relations.begin(); it != relations.end(); it++) {
		for (it2 = relations.begin(); it2 != relations.end(); it2++) {
			if (it->second == it2->first) {
				if (!is_member(it->first, it2->second)) return false;
			}
		}
	}
	return true;
}

template <typename type>
bool Relation<type>::is_function() {
	typename set<pair<type, type>>::iterator it;
	typename set<pair<type, type>>::iterator it2;


	for (it = relations.begin(); it != relations.end(); it++) {
		for (it2 = relations.begin(); it2 != relations.end(); it2++) {
			if (it->first == it2->first && it->second != it2->second) {
				return false;
			}
		}
	}
	return true;
}

template <typename type>
Relation<type>Relation<type>::inverse() {
	typename set<pair<type, type>>::iterator it;
	typename set<type>::iterator it2;
	Relation <type> rev;

	for (it2 = root.begin(); it2 != root.end(); it2++) {
		rev.add_to_set(*it2);
	}

	for (it = relations.begin(); it != relations.end(); it++) {
		rev.add_element(it->second, it->first);
	}

	return rev;
}

template <typename type>
Relation<type>Relation<type>::combination( Relation r) {
	typename set<pair<type, type>>::iterator it;
	typename set<pair<type, type>>::iterator it2;
	typename set<type>::iterator it3;

	Relation <type> result;

	for (it3 = root.begin(); it3 != root.end(); it3++) {
		result.add_to_set(*it3);
	}
	for (it3 = r.root.begin(); it3 != r.root.end(); it3++) {
		result.add_to_set(*it3);
	}

	for (it = relations.begin(); it != relations.end(); it++) {
		for (it2 = r.relations.begin(); it2 != r.relations.end(); it2++) {
			if (it->second == it2->first) result.add_element(it->first, it2->second);
		}
	}

	return result;
}
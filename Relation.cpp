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
    R.add_element(15,7);
    R.add_element(6,9);

    Relation <int> P(R);

    // P.remove_element(15, 7);

    //if (R == P) cout << "Cool" << endl;
    // cout << P << endl;


	Relation <string> r1, r2;

	r1.add_to_set("apple");
	r1.add_to_set("orange");
	r1.add_to_set("banana");
	r1.add_to_set("cherry");

	r2.add_to_set("apple");
	r2.add_to_set("orange");
	r2.add_to_set("banana");
	r2.add_to_set("cherry");

	r1.add_element("apple", "apple");
	r1.add_element("orange", "orange");
	r1.add_element("banana", "banana");
	r1.add_element("cherry", "cherry");
	r1.add_element("apple", "banana");

	//Testing Cardinality
	if (r1.cardinality() == 5) cout << "Cardinality - Test 1 - Passed." << endl;
	else cout << "Cardinality - Test 1 - Failed!" << endl;

	if (r2.cardinality() == 0) cout << "Cardinality - Test 2 - Passed." << endl;
	else cout << "Cardinality - Test 2 - Failed!" << endl;

	r2.add_element("cherry", "banana");
	if (r2.cardinality() == 1) cout << "Cardinality - Test 3 - Passed." << endl;
	else cout << "Cardinality - Test 3 - Failed!" << endl;

	////Testing is_member
	if (r1.is_member("apple", "apple")) cout << "is_member - Test 1 - Passed." << endl;
	else cout << "is_member - Test 1 - Failed!" << endl;

	if (!r1.is_member("cherry", "banana")) cout << "is_member - Test 2 - Passed." << endl;
	else cout << "is_member - Test 2 - Failed!" << endl;

	if (!r2.is_member("cherry", "cherry")) cout << "is_member - Test 3 - Passed." << endl;
	else cout << "is_member - Test 3 - Failed!" << endl;

	if (r2.is_member("cherry", "banana")) cout << "is_member - Test 4 - Passed." << endl;
	else cout << "is_member - Test 4 - Failed!" << endl;

	////Testing add_element
	r1.add_element("orange", "banana");
	if (r1.is_member("orange", "banana")) cout << "add_element - Test 1 - Passed." << endl;
	else cout << "add_element - Test 1 - Failed!" << endl;

	r2.add_element("apple", "cherry");
	if (r2.is_member("apple", "cherry")) cout << "add_element - Test 2 - Passed." << endl;
	else cout << "add_element - Test 2 - Failed!" << endl;

	if (!r2.is_member("apple", "orange")) cout << "add_element - Test 3 - Passed." << endl;
	else cout << "add_element - Test 3 - Failed!" << endl;

	////Testing remove_element
	r1.remove_element("orange", "banana");
	if (!r1.is_member("orange", "banana")) cout << "remove_element - Test 1 - Passed." << endl;
	else cout << "remove_element - Test 1 - Failed!" << endl;

	r2.remove_element("banana", "apple");
	if (!r2.is_member("banana", "apple")) cout << "remove_element - Test 2 - Passed." << endl;
	else cout << "remove_element - Test 2 - Failed!" << endl;

	r1.remove_element("orange", "cherry");
	if (!r1.is_member("orange", "cherry")) cout << "remove_element - Test 3 - Passed." << endl;
	else cout << "remove_element - Test 3 - Failed!" << endl;

	////Testing reflexive
	if (r1.reflexive()) cout << "reflexive - Test 1 - Passed." << endl;
	else cout << "reflexive - Test 1 - Failed!" << endl;

	if (!r2.reflexive()) cout << "reflexive - Test 2 - Passed." << endl;
	else cout << "reflexive - Test 2 - Failed!" << endl;

	r2.add_element("apple", "apple");
	r2.add_element("cherry", "cherry");
	r2.add_element("banana", "banana");
	if (!r2.reflexive()) cout << "reflexive - Test 3 - Passed." << endl;
	else cout << "reflexive - Test 3 - Failed!" << endl;

	////Testing Irreflexive
	if (!r1.irreflexive()) cout << "irreflexive - Test 1 - Passed." << endl;
	else cout << "irreflexive - Test 1 - Failed!" << endl;

	if (!r2.irreflexive()) cout << "irreflexive - Test 2 - Passed." << endl;
	else cout << "irreflexive - Test 2 - Failed!" << endl;

	r2.remove_element("apple", "apple");
	r2.remove_element("cherry", "cherry");
	r2.remove_element("banana", "banana");
	if (r2.irreflexive()) cout << "irreflexive - Test 3 - Passed." << endl;
	else cout << "irreflexive - Test 3 - Failed!" << endl;

	////Testing symmetric
	r1.add_element("banana", "apple");
	if (r1.symmetric()) cout << "symmetric - Test 1 - Passed." << endl;
	else cout << "symmetric - Test 1 - Failed!" << endl;

	if (!r2.symmetric()) cout << "symmetric - Test 2 - Passed." << endl;
	else cout << "symmetric - Test 2 - Failed!" << endl;

	r2.add_element("banana", "banana");
	if (!r2.symmetric()) cout << "symmetric - Test 3 - Passed." << endl;
	else cout << "symmetric - Test 3 - Failed!" << endl;

	////Testing asymmetric
	r2.remove_element("banana", "apple");
	if (!r1.asymmetric()) cout << "asymmetric - Test 1 - Passed." << endl;
	else cout << "asymmetric - Test 1 - Failed!" << endl;

	r2.remove_element("cherry", "apple");
	r2.remove_element("banana", "cherry");
	r2.add_element("cherry", "cherry");
	r2.add_element("apple", "apple");
	if (r2.asymmetric()) cout << "asymmetric - Test 2 - Passed." << endl;
	else cout << "asymmetric - Test 2 - Failed!" << endl;

	r2.add_element("banana", "apple");
	r2.add_element("apple", "banana");
	if (!r2.asymmetric()) cout << "asymmetric - Test 3 - Passed." << endl;
	else cout << "asymmetric - Test 3 - Failed!" << endl;

	////Testing transitive
	if (r1.transitive()) cout << "transitive - Test 1 - Passed." << endl;
	else cout << "transitive - Test 1 - Failed!" << endl;

	r2.add_element("cherry", "cherry");
	if (!r2.transitive()) cout << "transitive - Test 2 - Passed." << endl;
	else cout << "transitive - Test 2 - Failed!" << endl;

	r1.add_element("banana", "orange");
	if (!r1.transitive()) cout << "transitive - Test 3 - Passed." << endl;
	else cout << "transitive - Test 3 - Failed!" << endl;

	////Testing is_funciton
	if (!r1.is_function()) cout << "is_function - Test 1 - Passed." << endl;
	else cout << "is_function - Test 1 - Failed!" << endl;

	if (!r2.is_function()) cout << "is_function - Test 2 - Passed." << endl;
	else cout << "is_function - Test 2 - Failed!" << endl;

	r2.remove_element("apple", "apple");
	r2.remove_element("apple", "banana");
	r2.remove_element("banana", "banana");
	r2.remove_element("cherry", "banana");
	if (r2.is_function()) cout << "is_function - Test 3 - Passed." << endl;
	else cout << "is_function - Test 3 - Failed!" << endl;

	Relation <string> r3 = r1.inverse();

	////Testing operator ==
	if (r3 == r1.inverse()) cout << "operator == - Test 1 - Passed." << endl;
	else cout << "operator == - Test 1 - Failed!" << endl;

	if (!(r1 == r2)) cout << "operator == - Test 2 - Passed." << endl;
	else cout << "operator == - Test 2 - Failed!" << endl;

	////Testing operator []
	int i;
	vector <string> v = r1["apple"];
	if (v[0] == "apple" && v[1] == "banana" && v.size() == 2) cout << "operator [] - Test 1 - Passed." << endl;
	else cout << "operator [] - Test 1 - Failed!" << endl;

	v = r2["orange"];
	if (v.size() == 0) cout << "operator [] - Test 2 - Passed." << endl;
	else cout << "operator [] - Test 2 - Failed!" << endl;

	Relation <string> r4 = r2.inverse();
	Relation <string> r5 = r1.combination(r2);
	Relation <string> r6 = r2.combination(r1);

	cout << "r1 = " << r1 << endl;
	cout << "r2 = " << r2 << endl;

	cout << "r1-inverse = " << r3 << endl;
	cout << "r2-inverse = " << r4 << endl;

	cout << "R1oR2 = " << r5 << endl;
	cout << "R2oR1 = " << r6 << endl;

	/*Should be printed
	r1 = { (apple, apple), (apple, banana), (banana, apple), (banana, banana), (banana, orange), (cherry, cherry), (orange, orange) }
	r2 = { (apple, cherry), (banana, apple), (cherry, cherry) }
	r1-inverse = { (apple, apple), (apple, banana), (banana, apple), (banana, banana), (cherry, cherry), (orange, banana), (orange, orange) }
	r2-inverse = { (apple, banana), (cherry, apple), (cherry, cherry) }
	R1oR2 = { (apple, apple), (apple, cherry), (banana, apple), (banana, cherry), (cherry, cherry) }
	R2oR1 = { (apple, cherry), (banana, apple), (banana, banana), (cherry, cherry) }
	*/
	return 0;
}
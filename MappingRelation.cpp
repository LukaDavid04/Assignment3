#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "MappingRelation.h"
#include <list>
#include <vector>

using namespace std;

template <typename typex, typename typey>
ostream& operator << (ostream& out, const MappingRelation<typex, typey>& s) {
    typename set<pair<typex, typey>>::iterator it;

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

template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation() {
    int size = 0;
    set <pair<type1, type2>> relations;
    set <type1> root1;
    set <type2> root2;
}

template <typename type1, typename type2>
MappingRelation<type1, type2>::MappingRelation(const MappingRelation& r) {
    relations = r.relations;
    root1 = r.root1;
    root2 = r.root2;
    size = r.size;
}

template <typename type1, typename type2>
MappingRelation<type1, type2>::~MappingRelation() {
    relations.clear();
    root1.clear();
    root2.clear();
}

template <typename type1, typename type2>
int MappingRelation<type1, type2>::cardinality() {
    return relations.size();
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::add_element(type1 x, type2 y) {
    pair<type1, type2> temp;
    temp.first = x;
    temp.second = y;
    relations.insert(temp);
    size += 1;
    return true;
}

template <typename type1, typename type2>
void MappingRelation<type1, type2>::add_to_set(type1 x, type2 y) {
    root1.insert(x);
    root2.insert(y);
}

template <typename type1, typename type2>
void MappingRelation<type1, type2>::remove_element(type1 x, type2 y) {
    pair <type1, type2> p(x, y);
    relations.erase(p);
}

template <typename type1, typename type2>
bool MappingRelation<type1, type2>::is_member(type1 x, type2 y) {
    typename set<pair<type1, type2>>::iterator it;
    for (it = relations.begin(); it != relations.end(); it++) if (it->first == x && it->second == y)return true; return false;
}

template <typename type1, typename type2>
bool MappingRelation<type1,type2>::operator ==(MappingRelation<type1, type2> x){
    typename set<pair<type1, type2>>::iterator it;
    typename set<pair<type1, type2>>::iterator it2;

    for (it = x.relations.begin(); it != x.relations.end(); it++){
        for (it2 = relations.begin(); it2 != relations.end(); it++){
            if (it != relations.end()) return false;
        }
    }
    return true;
}

template <typename type1, typename type2>
MappingRelation<type1, type2>& MappingRelation<type1,type2>::operator +(MappingRelation<type1, type2> x){

    typename set<pair<type1, type2>>::iterator it;
    pair <type1, type2> p;

    for (it = x.relations.begin(); it != x.relations.end(); it++){
        
        p.first = it->first;
        p.second = it->second;

        relations.insert(p);
    } 

    return (*this);
}

template <typename type1, typename type2>
MappingRelation<type1, type2>& MappingRelation<type1,type2>::operator -(MappingRelation<type1, type2>){

}

template <typename type1, typename type2>
vector<type1> MappingRelation<type1, type2>::operator [](type1 x){
    vector<type1> temp;
    typename set<pair<type1, type2>>::iterator it;
    for (it = relations.begin(); it != relations.end(); it++){
        
        if (it->first == x){
            temp.push_back(it->second);
        } 
    } 
    return temp;
}

// template <typename type1, typename type2>
// bool MappingRelation<type1, type2>::intersection() {

// }

// template <typename type1, typename type2>
// bool MappingRelation<type1, type2>::is_function() {

// }

// template <typename type1, typename type2>
// MappingRelation<type1, type2>MappingRelation<type1, type2>::inverse() {

// }

// template <typename type1, typename type2>
// MappingRelation<type1, type2>MappingRelation<type1, type2>::combination() {
    
// }

// int main() {
//     MappingRelation <int, int> R;

//     pair <int, int> p;
//     pair <int, int> p1(15,7);
//     pair <int, int> p2(6,9);
//     R.add_element(p1.first, p1.second);
//     R.add_element(p2.first, p2.second);

//     MappingRelation <int, int> P(R);

//     cout << R << endl;
//     cout << P << endl;


//     return 0;
// }
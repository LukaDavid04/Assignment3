#include <iostream>
#include "Relation.h"
#include <vector>
#include <set>
#include <utility>

using namespace std;

template <typename typex>
ostream& operator <<(ostream& out, set<pair<typex,typex>>& s){
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
Relation<type>::Relation(){
    
}
template <typename type>
Relation<type>::Relation(const Relation& r){
    relations = r.relations;
}
template <typename type>
Relation<type>::~Relation() {
    relations.clear();
}
template <typename type>
int Relation<type>::cardinality(){
    
}
template <typename type>
bool Relation<type>::add_element(type, type){
    
}
template <typename type>
bool Relation<type>::add_to_set(int i){

}
template <typename type>
void Relation<type>::remove_element(type, type){
    
}
template <typename type>
bool Relation<type>::is_member(type, type){
    
}

template <typename type>
bool Relation<type>::equal(Relation r){
    
}
template <typename type>
bool Relation<type>::symmetric(){
    
}
template <typename type>
bool Relation<type>::asymmetric(){
    
}
template <typename type>
bool Relation<type>::reflexive(){
    
}
template <typename type>
bool Relation<type>::irreflexive(){
    
}


template <typename type>
bool Relation<type>::transitive(){
    
}
template <typename type>
bool Relation<type>::is_function(){
    
}


template <typename type>
Relation<type>Relation<type>::inverse(){

}
template <typename type>
Relation<type>Relation<type>::combination(){

}
int main(){
    
}

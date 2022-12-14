// Michael Bosciglio 300135179
// Luka David 300134324

#pragma once
#include <iostream>
#include <utility>
#include <set>

using namespace std;

template <typename type>
class Relation {
private:
    set <pair<type, type>> relations;
    set <type> root;
    int size;
public:
    Relation();
    Relation(const Relation&);
    ~Relation();
    int cardinality();
    bool add_element(type, type);
    bool add_to_set(type);
    void remove_element(type, type);
    bool is_member(type, type);
    bool operator ==(Relation);
    vector<type> operator[](type x);
    bool reflexive();
    bool irreflexive();
    bool symmetric();
    bool asymmetric();
    bool transitive();
    bool is_function();
    Relation inverse();
    Relation combination(Relation);
    template <typename typex>
    friend ostream& operator << (ostream&, const Relation<typex>&);
};
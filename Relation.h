#pragma once
#include <iostream>
#include <utility>

using namespace std;

template <typename type>
class Relation{
    private:
        set<pair<type,type>> relations;
    public:
        Relation();
        Relation(const Relation&);
        ~Relation();
        int cardinality();
        bool add_element(type, type);
        bool add_to_set(int);
        void remove_element(type, type);
        bool is_member(type, type);
        bool equal(Relation);
        bool reflexive();
        bool irreflexive();
        bool symmetric();
        bool asymmetric();
        bool transitive();
        bool is_function();
        Relation inverse();
        Relation combination();
        template <typename typex> 
        friend ostream& operator <<(ostream&, set<pair<typex, typex>>&);



};
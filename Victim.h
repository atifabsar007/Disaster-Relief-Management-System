#ifndef VICTIM_H
#define VICTIM_H

#include <bits/stdc++.h>
using namespace std;

struct Victim {
    string name, gender, condition, shelter;
    int age;
    Victim* next;
};

class VictimList {
public:
    Victim* head = NULL;

    void add(string n,int a,string g,string c,string s){
        Victim* v=new Victim();
        v->name=n;
        v->age=a;
        v->gender=g;
        v->condition=c;
        v->shelter=s;
        v->next=head;
        head=v;
    }

    void show(){
        cout<<"\n🏠 VICTIMS LIST\n";
        for(Victim* t=head;t;t=t->next){
            cout<<t->name<<" | "<<t->age
                <<" | "<<t->gender
                <<" | "<<t->condition
                <<" | "<<t->shelter<<endl;
        }
    }

    void search(string name){
        for(Victim* t=head;t;t=t->next){
            if(t->name==name){
                cout<<"\n🔍 FOUND VICTIM\n";
                cout<<"Name: "<<t->name<<endl;
                cout<<"Age: "<<t->age<<endl;
                cout<<"Condition: "<<t->condition<<endl;
                cout<<"Shelter: "<<t->shelter<<endl;
                return;
            }
        }
        cout<<"❌ Not Found\n";
    }

    int count(){ int c=0; for(auto t=head;t;t=t->next) c++; return c; }

    int critical(){
        int c=0;
        for(auto t=head;t;t=t->next)
            if(t->condition=="Critical") c++;
        return c;
    }
};

#endif

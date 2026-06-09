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
        cout<<"\n🏠 VICTIMS\n";
        for(Victim* t=head;t;t=t->next){
            cout<<t->name<<" | "<<t->age
            <<" | "<<t->condition
            <<" | "<<t->shelter<<endl;
        }
    }

    // 🧩 SEARCH SYSTEM (NEW)
    void search(string name){
        Victim* t=head;
        while(t){
            if(t->name==name){
                cout<<"\n🔍 VICTIM FOUND\n";
                cout<<"Name: "<<t->name<<endl;
                cout<<"Age: "<<t->age<<endl;
                cout<<"Gender: "<<t->gender<<endl;
                cout<<"Condition: "<<t->condition<<endl;
                cout<<"Shelter: "<<t->shelter<<endl;
                return;
            }
            t=t->next;
        }
        cout<<"❌ Not Found\n";
    }

    int count(){
        int c=0;
        for(Victim* t=head;t;t=t->next) c++;
        return c;
    }

    int countCritical(){
        int c=0;
        for(Victim* t=head;t;t=t->next)
            if(t->condition=="critical") c++;
        return c;
    }
};
#endif

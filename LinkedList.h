// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(string s) {
        Node* n = new Node();
        n->data = s;
        n->next = head;
        head = n;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

#endif

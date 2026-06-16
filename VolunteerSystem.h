#pragma once
#include <iostream>
#include <string>

using namespace std;

struct VolNode {
    string name;
    string skill;
    VolNode *left, *right;
    VolNode(string n, string s) : name(n), skill(s), left(NULL), right(NULL) {}
};

class VolunteerSystem {
    VolNode* root = NULL;
    int volCount = 0;

    void insertRec(VolNode*& node, string n, string s) {
        if (!node) { node = new VolNode(n, s); return; }
        if (n < node->name) insertRec(node->left, n, s);
        else insertRec(node->right, n, s);
    }

    void inorder(VolNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->name << " | " << node->skill << endl;
        inorder(node->right);
    }

public:
    void add() {
        string n, skill; int c;
        cout << "\nVOLUNTEER NAME: "; cin >> n;
        cout << "SELECT SKILL:\n1. Medical\n2. Rescue\n3. Logistics\nChoice: "; cin >> c;
        if (c == 1) skill = "Medical"; else if (c == 2) skill = "Rescue"; else skill = "Logistics";

        insertRec(root, n, skill);
        volCount++;
        cout << "Volunteer Added (Sorted in BST)\n";
    }

    void show() {
        cout << "\nVOLUNTEERS (Alphabetical Order)\n";
        cout << "----------------------------------------\n";
        inorder(root);
    }

    int size() { return volCount; }
};

#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

/* 🌳 NODE STRUCTURE */
struct BSTNode {
    string city;
    int severity;
    BSTNode *left, *right;
};

/* 🌳 BST CLASS */
class BST {
public:
    BSTNode* root;

    BST() {
        root = NULL;
    }

    /* 🔹 INSERT NODE */
    BSTNode* insert(BSTNode* node, string city, int severity) {

        if(node == NULL) {
            BSTNode* temp = new BSTNode();
            temp->city = city;
            temp->severity = severity;
            temp->left = temp->right = NULL;
            return temp;
        }

        if(severity < node->severity)
            node->left = insert(node->left, city, severity);
        else
            node->right = insert(node->right, city, severity);

        return node;
    }

    /* 🔹 INORDER DISPLAY (SORTED BY SEVERITY) */
    void inorder(BSTNode* node) {

        if(node == NULL) return;

        inorder(node->left);

        cout << "---------------------------------\n";
        cout << "📍 City      : " << node->city << endl;
        cout << "⚠ Severity   : " << node->severity << "/10\n";

        if(node->severity >= 8)
            cout << "🚨 Priority   : CRITICAL\n";
        else if(node->severity >= 5)
            cout << "⚠ Priority   : MODERATE\n";
        else
            cout << "🟢 Priority   : LOW\n";

        inorder(node->right);
    }
};

#endif

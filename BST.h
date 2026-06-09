// BST.h

#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    string city;
    int severity;
    BSTNode *left, *right;
};

class BST {
public:
    BSTNode* root;

    BST() {
        root = NULL;
    }

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

    void inorder(BSTNode* node) {

        if(node == NULL) return;

        inorder(node->left);

        cout << "📍 City: " << node->city
             << " | ⚠ Severity: " << node->severity << endl;

        inorder(node->right);
    }
};

#endif

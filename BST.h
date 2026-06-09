// BST.h

#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int severity;
    int city;
    BSTNode *left, *right;
};

class BST {
public:
    BSTNode* root;

    BST() {
        root = NULL;
    }

    BSTNode* insert(BSTNode* node, int severity, int city) {
        if(node == NULL) {
            BSTNode* temp = new BSTNode();
            temp->severity = severity;
            temp->city = city;
            temp->left = temp->right = NULL;
            return temp;
        }

        if(severity < node->severity)
            node->left = insert(node->left, severity, city);
        else
            node->right = insert(node->right, severity, city);

        return node;
    }

    void inorder(BSTNode* node, string cityName[]) {
        if(node == NULL) return;

        inorder(node->left, cityName);

        cout << "City: " << cityName[node->city]
             << " | Severity: " << node->severity << endl;

        inorder(node->right, cityName);
    }
};

#endif

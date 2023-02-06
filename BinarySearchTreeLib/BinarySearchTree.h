#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <iomanip>
#include <iostream>
#include <sstream>


static int level = 0;

template<typename KeyType, typename DataType>
class BinarySearchTree
{
private:
    struct node {
        DataType data;
        KeyType key;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == nullptr)
            return nullptr;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return nullptr;
    }

    node* insert(KeyType key, DataType data,  node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = data;
            t->key = key;
            t->left = t->right = NULL;
        }
        else if(key < t->key)
            t->left = insert(key, data, t->left);
        else if(key > t->key)
            t->right = insert(key, data, t->right);
        else{
            t->data = data;
        }
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* remove(KeyType key, node* t) { // t = root
        node* temp;
        if(t == NULL)
            return NULL;
        else if(key < t->key)
            t->left = remove(key, t->left);
        else if(key > t->key)
            t->right = remove(key, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    node* search(node* t, KeyType key) {
        if(t == NULL)
            return NULL;
        else if(key < t->key)
            return search(t->left, key);
        else if(key > t->key)
            return search(t->right, key);
        else
            return t;
    }

    void toString(node* t) const{
        if(t == NULL)
            return;
        toString(t->left);
        std::cout <<"[" << t->key << "," << t->data << "],";
        toString(t->right);
    }

    void print2D(node const* t, int which)
    {
        if(!t)
            return;
        std::string p;
        if(which == 2)
            p = "L: ";
        else if(which == 3)
            p = "R: ";
        for (int i = 0; i < level; ++i) std::cout << "    ";
        std::cout << p << "[" << t->key << ", " << t->data << "]" << std::endl;
        ++level;
        if (t->left)
        {
            print2D(t->left, 2);
            --level;
        }
        if (t->right)
        {
            print2D(t->right, 3);
            --level;
        }
    }

    int size(node *t){
        if(t == NULL)
            return 0;
        else
            return(size(t->left) + 1 + size(t->right));
    }

public:

    BinarySearchTree() {
        root = NULL;
    }


    ~BinarySearchTree() {
        root = makeEmpty(root);
    }

    size_t size() const {
        return 0;
    }

    void remove(KeyType key) {
        root = remove(key, root);
    }

    void insert(KeyType const& key, DataType const& data) {
        root = insert(key, data, root);
    }

    DataType* find(KeyType const& key) {
        node *s = search(root, key);
        return &(s->data);
    }

    void deleteRoot(){
        root = makeEmpty(root);
    }

    std::string print2D()
    {
        std::stringstream treeStr;
        auto old_buf = std::cout.rdbuf(treeStr.rdbuf());
        print2D(root, 1);
        std::cout.rdbuf(old_buf);
        return treeStr.str();
    }

    std::string toString(){
        std::stringstream treeStr;
        auto old_buf = std::cout.rdbuf(treeStr.rdbuf());
        toString(root);
        std::cout.rdbuf(old_buf);
        return treeStr.str();
    }

    int size(){
        return size(root);
    }
};

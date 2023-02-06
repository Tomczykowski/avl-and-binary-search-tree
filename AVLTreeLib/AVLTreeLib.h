#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <iomanip>

static int level = 0;


template<typename KeyType, typename DataType>
class AVLTreeLib
{
private:
    struct node {
        DataType data;
        KeyType key;
        node* left;
        node* right;
        node* parent;
        int balance; //Balance Factor
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

    node* search(node* t, KeyType key) {
        if(t == nullptr)
            return nullptr;
        else if(key < t->key)
            return search(t->left, key);
        else if(key > t->key)
            return search(t->right, key);
        else
            return t;
    }

    void left_rotate(node *n)
    {
        struct node *parent = n->parent;
        struct node *right = n->right;
        if ((n->right = right->left))
            n->right->parent = n;

        n->parent = right;
        right->left = n;
        right->parent = parent;
        if (parent) {
            if (parent->left == n)
                parent->left = right;
            else
                parent->right = right;
        } else
            root = right;

        n->balance = n->balance - 1 - std::max(0, right->balance);
        right->balance = right->balance - 1 + std::min(0, n->balance);
    }

    void right_rotate(node *n)
    {
        node *parent = n->parent;
        node *left = n->left;
        if ((n->left = left->right))
            n->left->parent = n;

        n->parent = left;
        left->right = n;
        left->parent = parent;
        if (parent) {
            if (parent->left == n)
                parent->left = left;
            else
                parent->right = left;
        } else
            root = left;

        n->balance = n->balance + 1 - std::min(0, left->balance);
        left->balance = left->balance + 1 + std::max(0, n->balance);
    }

    void avl_lr_rotate(node *parent)
    {
        left_rotate(parent->left);
        right_rotate(parent);
    }
    void avl_rl_rotate(node *parent)
    {
        right_rotate(parent->right);
        left_rotate(parent);
    }

    bool insertAvl(node *newNode)
    {
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        node* parent = nullptr;
        node* cur = root;
        while (cur)
        {
            if (cur->key < newNode->key)
            {
                parent = cur;
                cur = cur->right;
            }
            else if (cur->key > newNode->key)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                parent = cur;
                cur->data = newNode->data;
                return false;
            }
        }

        cur = newNode; // ustawiamy current na nowy wierzcholek
        cur->parent = parent;
        if (parent->key > newNode->key)
            parent->left = cur;
        else
            parent->right = cur;

        while (parent)
        {
            if (cur == parent->left)
                parent->balance--;
            else if (cur == parent->right)
                parent->balance++;

            if (parent->balance == 0)
                break;
            else if (parent->balance == -1 || parent->balance == 1)
            {
                cur = parent;
                parent = cur->parent;
            }
            else
            {
                if (parent->balance == 2)
                {
                    if (cur->balance == 1)
                        left_rotate(parent);
                    else
                        avl_rl_rotate(parent);
                }
                else if (parent->balance == -2)
                {
                    if (cur->balance == -1)
                        right_rotate(parent);
                    else
                        avl_lr_rotate(parent);
                }
                break;
            }
        }
        return true;
    }

    void toString(node* t) const{
        if(t == nullptr)
            return;
        toString(t->left);
        std::cout <<"[" << t->key << "," << t->data << "],";
        toString(t->right);
    }

    void print2D(node const* t, int which) {
        if (!t)
            return;
        std::string p;
        if (which == 2)
            p = "L: ";
        else if (which == 3)
            p = "R: ";
        for (int i = 0; i < level; ++i) std::cout << "    ";
        std::cout << p << "[" << t->key << ", " << t->data << "]" << std::endl;
        ++level;
        if (t->left) {
            print2D(t->left, 2);
            --level;
        }
        if (t->right) {
            print2D(t->right, 3);
            --level;
        }
    }


    int size(node *t){
        if(t == nullptr)
            return 0;
        else
            return(size(t->left) + 1 + size(t->right));
    }

public:
    AVLTreeLib(){
        root = nullptr;
    }

    ~AVLTreeLib(){
        root = makeEmpty(root);
    }

    void insert(KeyType const& key, DataType const& value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;
        newNode->balance = 0;
        insertAvl(newNode);
    }

    DataType* find(KeyType const& key) {
        node *s = search(root, key);
        return &(s->data);
    }

    std::string toString() const {
        std::stringstream treeStr;
        auto old_buf = std::cout.rdbuf(treeStr.rdbuf());
        toString(root);
        std::cout.rdbuf(old_buf);
        return treeStr.str();
    }

    std::string print2D()
    {
        std::stringstream treeStr;
        auto old_buf = std::cout.rdbuf(treeStr.rdbuf());
        print2D(root, 1);
        std::cout.rdbuf(old_buf);
        return treeStr.str();
    }

    int size(){
        return size(root);
    }



};


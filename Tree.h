#ifndef BST_CPP_TREE_H
#define BST_CPP_TREE_H


#include <iostream>
#include <string>

template <class T>
class Tree{
public:
    struct drzewkoPojedyncze {
        T key;
        drzewkoPojedyncze* left;
        drzewkoPojedyncze* right;
    };
    drzewkoPojedyncze *korzen;

    Tree();
    ~Tree();
    drzewkoPojedyncze* insert(T addKey, drzewkoPojedyncze* drzewko);
    std::string draw(drzewkoPojedyncze* drzewko);
    std::string search(T x, drzewkoPojedyncze* drzewko);
    drzewkoPojedyncze* findMin(drzewkoPojedyncze* drzewko);
    drzewkoPojedyncze* remove(T remoweKey, drzewkoPojedyncze* drzewko);
    drzewkoPojedyncze* deleteAll(drzewkoPojedyncze* drzewko);
};


#endif //BST_CPP_TREE_H

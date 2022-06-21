#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
Tree<T>::Tree(){
    korzen = nullptr;
}

template<class T>
Tree<T>::~Tree(){
    korzen = deleteAll(korzen);
}

template<class T>
typename Tree<T>::drzewkoPojedyncze *Tree<T>::insert(T addKey, Tree::drzewkoPojedyncze *drzewko) {
    if(drzewko == nullptr){
        drzewko = new drzewkoPojedyncze;
        drzewko->key = addKey;
        drzewko->left = drzewko->right = nullptr;
    }
    else if(addKey < drzewko->key)
        drzewko->left = insert(addKey, drzewko->left);
    else if(addKey > drzewko->key)
        drzewko->right = insert(addKey, drzewko->right);
    return drzewko;
}

template<class T>
string Tree<T>::draw(Tree::drzewkoPojedyncze *drzewko) {
    if(drzewko == nullptr)
        return "()";
    return "(" + to_string(drzewko->key) + ":" + draw(drzewko->left) + ":" + draw(drzewko->right) + ")";
    // to_string nie dziala dla string
}

template<class T>
string Tree<T>::search(T x, Tree::drzewkoPojedyncze *drzewko) {
    if(drzewko == nullptr)
        return "Nie ma elementu: " + to_string(x) ;
    else if(x < drzewko->key)
        return search(x, drzewko->left);
    else if(x > drzewko->key)
        return search(x, drzewko->right);
    else
        return "Jest element: " + to_string(x);
}

template<class T>
typename Tree<T>::drzewkoPojedyncze *Tree<T>::findMin(Tree::drzewkoPojedyncze *drzewko) {
    if(drzewko == nullptr)
        return nullptr;
    else if(drzewko->left == nullptr)
        return drzewko;
    return findMin(drzewko->left);
}

//usuniecie jednego elementu o wartosci removeKey
template<class T>
typename Tree<T>::drzewkoPojedyncze *Tree<T>::remove(T remoweKey, Tree::drzewkoPojedyncze *drzewko) {
    drzewkoPojedyncze* tempDrzewko;
    if(drzewko == nullptr)
        return nullptr;

        //szukamy element do usuniecia
    else if(remoweKey < drzewko->key)
        drzewko->left = remove(remoweKey, drzewko->left);
    else if(remoweKey > drzewko->key)
        drzewko->right = remove(remoweKey, drzewko->right);

        //usuniecie
    else if(drzewko->left && drzewko->right){
        tempDrzewko = findMin(drzewko->right);
        drzewko->key = tempDrzewko->key;
        drzewko->right = remove(drzewko->key, drzewko->right);
    }
    else{
        tempDrzewko = drzewko;
        if(drzewko->left == nullptr)
            drzewko = drzewko->right;
        else if(drzewko->right == nullptr)
            drzewko = drzewko->left;
        delete tempDrzewko;
    }
    return drzewko;
}

//metoda do usuwania calego drzewka w destruktorze
template<class T>
typename Tree<T>::drzewkoPojedyncze *Tree<T>::deleteAll(Tree::drzewkoPojedyncze *drzewko) {
    if(drzewko == nullptr)
        return nullptr;
    else {
        deleteAll(drzewko->left);
        deleteAll(drzewko->right);
        delete drzewko;
    }
    return nullptr;
}

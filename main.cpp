#include "Tree.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Tree<int> root;
    root.korzen = root.remove(5, root.korzen);
    cout << root.draw(root.korzen) << endl;
    root.korzen = root.insert(10, root.korzen);
    root.korzen = root.insert(8, root.korzen);
    root.korzen = root.insert(9, root.korzen);
    root.korzen = root.insert(20, root.korzen);
    root.korzen = root.insert(15, root.korzen);
    root.korzen = root.insert(25, root.korzen);
    root.korzen = root.insert(12, root.korzen);
    cout << root.draw(root.korzen) << endl;
    root.korzen = root.remove(20, root.korzen);
    cout << root.draw(root.korzen) << endl;
    root.korzen = root.remove(10, root.korzen);
    cout << root.draw(root.korzen) << endl;
    root.korzen = root.insert(10,root.korzen);
    cout << root.search(6, root.korzen) << endl;
    cout << root.search(9, root.korzen) << endl;
    return 0;
}


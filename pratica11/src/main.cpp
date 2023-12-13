#include <iostream>
#include <string>
#include "../include/AVLTree.hpp"


int main() {
    int ope;
    std::cin >> ope;
    int num;
    ArvoreAVL meuIndice;
    for(int i = 0;i < ope;i++){
        char esc;
        std::cin >> esc;
        if(esc == 'i'){
            std::cin >> num;
            meuIndice.insert(num);
        }
        if(esc == 'r'){
            std::cin >> num;
            meuIndice.remove(num);
        }
    }
    meuIndice.printInOrder();
    meuIndice.~ArvoreAVL();
    return 0;
}
#include<bits/stdc++.h>
#include "Node.h"

int main(){

    std::vector<Node *> grafo;
    for(int i = 0; i < 10; i++)
        grafo.push_back(new Node());
    for(int i = 0; i < 10; i++){
        if(i*2+1 < 9)
            grafo[i]->addChild(grafo[i*2+1]);
        if(i*2+2 < 9)
            grafo[i]->addChild(grafo[i*2+2]);
    }
    for(int i = 0; i < 10; i++)
        printNode(grafo[i]);
    std::cout << "------------------------------------" << std::endl;
    grafo[8]->addChild(grafo[9]);
    for(int i = 0; i < 10; i++)
        printNode(grafo[i]);
    std::cout << "------------------------------------" << std::endl;
    replaceChild(grafo[0], grafo[9],0);
    for(int i = 0; i < 10; i++)
        printNode(grafo[i]);
    std::cout << "------------------------------------" << std::endl;


}

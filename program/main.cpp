#include<bits/stdc++.h>
#include "Flattening.h"
#include "Node.h"

int main(){

    std::vector<std::vector<int> > grafo;
    for(int i = 0; i < 10; i++)
        grafo.push_back(std::vector<int>());
    for(int i = 0; i < 10; i++){
        if(i*2+1 < 10)
            grafo[i].push_back(i*2+1);
        if(i*2+2 < 10)
            grafo[i].push_back(i*2+2);
    }
    Flattening Rede = Flattening(grafo);
    Rede.printNetwork();
    Rede.bottomUP(Rede.getNode(10), Rede.getNode(9), Rede.getNode(10)->getRightChild());
    Rede.printNetwork();


}

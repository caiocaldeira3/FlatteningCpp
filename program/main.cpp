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
    /*
    Flattening RedeBUP = Flattening(grafo);
    std::cout << "Testando a função Bottom Up Flattening" << std::endl;
    RedeBUP.printNetwork();
    RedeBUP.bottomUP(RedeBUP.getNode(10), RedeBUP.getNode(10), RedeBUP.getNode(9), RedeBUP.getNode(10)->getRightChild());
    RedeBUP.printNetwork();
    */
    /*
    std::cout << "Testando a função Semi Top-Down Flattening" << std::endl;
    Flattening RedeSemiTD = Flattening(grafo);
    RedeSemiTD.printNetwork();
    RedeSemiTD.topDownSemi(RedeSemiTD.getNode(1), RedeSemiTD.getNode(1), RedeSemiTD.getNode(10), RedeSemiTD.getNode(1)->getParent());
    RedeSemiTD.printNetwork();
    */
    std::cout << "Testando a função Hybrid Flattening" << std::endl;
    Flattening RedeFlatten = Flattening(grafo);
    RedeFlatten.printNetwork();
    RedeFlatten.hybridFlatten(RedeFlatten.getNode(7), RedeFlatten.getNode(10));
    RedeFlatten.printNetwork();
    RedeFlatten.hybridFlatten(RedeFlatten.getNode(9), RedeFlatten.getNode(6));
    RedeFlatten.printNetwork();
}

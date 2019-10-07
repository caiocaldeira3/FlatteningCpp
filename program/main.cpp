#include<bits/stdc++.h>
#include "Flattening.h"
#include "Node.h"

int main(){

    std::vector<std::vector<int> > grafo;
    for(int i = 0; i < 1000; i++)
        grafo.push_back(std::vector<int>());
    for(int i = 0; i < 1000; i++){
        if(i*2+1 < 1000)
            grafo[i].push_back(i*2+1);
        if(i*2+2 < 1000)
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
	const clock_t total_time = clock();
	Flattening RedeFlatten(grafo);
	 srand (time(NULL));
    std::cout << "Testando a função Hybrid Flattening" << std::endl;
	for(int i = 0; i < 1000; i++){
		int x = rand()%1000 + 1;
		int y = rand()%1000 + 1;
		if(x == y)
			continue;
		std::cout << "Requester : "<< x << " " << "Target : " << y << std::endl;
		clock_t begin_time = clock();
		RedeFlatten.hybridFlatten(RedeFlatten.getNode(x), RedeFlatten.getNode(y));
		std::cout << "End of the request in : " << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
	}
	std::cout << float(clock() - total_time) / CLOCKS_PER_SEC << std::endl;
}

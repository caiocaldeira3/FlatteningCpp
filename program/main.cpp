#include<bits/stdc++.h>
#include "Flattening.h"
#include "Node.h"

int main(){


    std::ifstream inFile;
    std::ofstream outFile;

    inFile.open("./input/tor_128.txt");
    if (!inFile) {
        std::cout << "Unable to open input file" <<  std::endl;
        exit(1); // terminate with error
    }
    outFile.open("./output/tor_128.txt");
    if (!outFile) {
        std::cout << "Unable to open output file" << std::endl;
        exit(1); // terminate with error
    }

    int size; inFile >> size;

    std::vector<std::vector<int> > grafo;
    for(int i = 0; i < size; i++)
        grafo.push_back(std::vector<int>());
    for(int i = 0; i < size; i++){
        if(i*2+1 < size)
            grafo[i].push_back(i*2+1);
        if(i*2+2 < size)
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
    int queries; inFile >> queries;
	Flattening RedeFlatten(grafo);
	 srand (time(NULL));
	double tot_time = 0;
    int tot_op = 0;
    std::cout << "Testando a função Hybrid Flattening" << std::endl;
	for(int i = 0; i < queries; i++){
        int x, y;
        inFile >> x >> y; x++; y++;
		clock_t begin_time = clock();
		tot_op += RedeFlatten.hybridFlatten(RedeFlatten.getNode(x), RedeFlatten.getNode(y), i);
		tot_time += float(clock() - begin_time) / CLOCKS_PER_SEC;
	}
	int aux = size;
	int log = 0;
	while(aux/=2) log++;

	outFile << "The average number of operations was " << tot_op/double(queries) << " to the expected " << log*2 << " on a static balanced tree" << std::endl;
	outFile << "The averate time spent on each request was " << tot_time/double(queries) << std::endl;
}	

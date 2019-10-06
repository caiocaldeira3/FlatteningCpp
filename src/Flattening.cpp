#include <bits/stdc++.h>
#include "Flattening.h"
#include "Node.h"

int dfs(int u, int p, std::vector<int> &v, std::vector<std::vector<int> > originalGraph){
    v[u] = 1;
    int flag = 1;
    for(int w : originalGraph[u])
        if(!v[w]) flag &= dfs(w, u, v, originalGraph);
        else if(p != w) return 0;
    return flag;
}

int check(std::vector<std::vector<int> > originalGraph){
    std::vector<int> v;
    int isBinary = 1;
    for(int i = 0; i < (int)originalGraph.size(); i++){
        v.push_back(0);
        isBinary &= (originalGraph[i].size() <= 3);
    }
    int hasCycles = dfs(0, -1, v, originalGraph);
    int isConnected = 1;
    for(int x : v) isConnected &= x;
    return isConnected && hasCycles && isBinary;
}

Flattening::Flattening(std::vector<std::vector<int> > originalGraph){
    if(!check(originalGraph)){
        std::cout << "This graph is not suitable to represent a tree-like network" << std::endl;
        exit(0);
    }
    this->size = (int)originalGraph.size();
    for(int i = 0; i < this->size; i++)
        this->rede.push_back(new Node());
    for(int i = 0; i < this->size; i++)
        for(int x : originalGraph[i]){
            if(this->rede[i]->getParentID() == this->rede[x]->getMyID()) continue;
            this->rede[i]->addChild(this->rede[x]);
        }
}
void Flattening::printNetwork(){
    std::cout << "--------------------------" << std::endl;
    for(Node *toPrint : this->rede){
        printNode(toPrint);
        std::cout << "--------------------------" << std::endl;
    }
}

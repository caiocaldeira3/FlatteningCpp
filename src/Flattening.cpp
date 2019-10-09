#include <bits/stdc++.h>
#include "Flattening.h"
#include "Node.h"

/* Constructors */
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
/* End of Constructors */

/* Getters */
Node *Flattening::getNode(int id){
    if(id > this->size) return new Node(-1);
    for(auto x : this->rede){
        if(x->amI(id))
            return x;
    }
    return new Node(-1);
}
Node *Flattening::getNextNode(Node *curr, Node *target){
    if(curr->isRightDesc(target->getMyID()))
        return curr->getRightChild();
    if(curr->isLeftDesc(target->getMyID()))
        return curr->getLeftChild();
    return curr->getParent();
}
/* End of Getters */

/* Algorithms */
int Flattening::bottomUP(Node *curr, Node *req, Node *target, Node *pref){
    Node *parentNode = curr->getParent();
    Node *grandParent = parentNode->getParent();
    int typ = (curr->amRightChild() << 1) + parentNode->amRightChild();
    replaceChild(curr, parentNode, typ);
    grandParent->fix(curr, parentNode);
    if(!curr->amHigh(target->getMyID()))
		return this->bottomUP(curr, req, target, parentNode) + 1;
	return 1;
}
int Flattening::topDownSemi(Node *curr, Node *req, Node *target, Node *newParent){
    if(curr->amI(target->getMyID()) or curr->isChild(target->getMyID()))
        return 0;
    Node *nextNode = getNextNode(curr, target);
    Node *otherNode = curr->getOtherChild(nextNode);
    Node *dbNextNode = getNextNode(nextNode, target);
    childSwap(nextNode, curr, dbNextNode, otherNode);
	return topDownSemi(dbNextNode, req, target, curr) + 1;
}
int Flattening::hybridFlatten(Node *req, Node *target, int qryID){
    int ret = 0;
	if(!req->amHigh(target->getMyID())){
        Node *pref;
        if(req->getLeftChildID() != -1)
            pref = req->getLeftChild();
        else
            pref = req->getRightChild();
        ret += bottomUP(req, req, target, pref);
    }
    if(!req->isChild(target->getMyID()))
        ret += topDownSemi(req, req, target, req->getParent());
	return ret;
}
/* End of Algorithms */

/* Auxiliary Functions */
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
void Flattening::printNetwork(){
    std::cout << "--------------------------" << std::endl;
    for(Node *toPrint : this->rede){
        printNode(toPrint);
        std::cout << "--------------------------" << std::endl;
    }
}
/* End of Auxiliary Functions */

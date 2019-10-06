#ifndef FLATT_H
#define FLATT_H
#include "Node.h"

int check(std::vector<std::vector<int> > graph);
int dfs(int u, int p, std::vector<int> &v, std::vector<std::vector<int> > originalGraph);

class Flattening{
private:
    int size = 0;
    std::vector<Node *> rede;
public:
    Flattening(std::vector<std::vector<int> > originalGraph);
    Node *getNode(int id);
    void bottomUP(Node *curr, Node *req, Node *pref);
    void printNetwork();

    /* Ainda falta a implementação
    void getRequest(int reqID, int targetID);
    void topDownSemi(Node *curr, Node *req, Node *target, Node *newParent);
    void hybridFlatten(Node *target, Node *req);
    */
};

#endif

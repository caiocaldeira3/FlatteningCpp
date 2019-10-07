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
    Node *getNextNode(Node *curr, Node *target);
    void bottomUP(Node *curr, Node *target, Node *req, Node *pref);
    void topDownSemi(Node *curr, Node *req, Node *target, Node *newParent);
    void printNetwork();
    void hybridFlatten(Node *target, Node *req);
};

#endif

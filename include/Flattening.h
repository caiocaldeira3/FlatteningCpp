#ifndef FLATT_H
#define FLATT_H
#include "Node.h"

/* Auxiliary Functions */
int check(std::vector<std::vector<int> > graph);
int dfs(int u, int p, std::vector<int> &v, std::vector<std::vector<int> > originalGraph);
/* End of Auxiliary Functions */

class Flattening{
private:
    /* Attributes */
    int size = 0;
    std::vector<Node *> rede;
    /* End of Attributes */
public:
    /* Constructors */
    Flattening(std::vector<std::vector<int> > originalGraph);
    /* End of Constructors */
    /* Getters */
    Node *getNode(int id);
    Node *getNextNode(Node *curr, Node *target);
    /* End of Getter */
    /* Algorithms */
    void bottomUP(Node *curr, Node *target, Node *req, Node *pref);
    void topDownSemi(Node *curr, Node *req, Node *target, Node *newParent);
    void hybridFlatten(Node *target, Node *req);
    /* End of Algorithms */
    /* Auxiliary Functions */
    void printNetwork();
    /* End of Auxiliary Functions */
};

#endif

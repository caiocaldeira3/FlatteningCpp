#ifndef NODE_H
#define NODE_H
#include<bits/stdc++.h>

const int MAX = 1e3+3;

class Node{
private:
    static int ID;

    /* Attributes */
    int myID;
    int counter;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
    std::set<int> leftChildTab, rightChildTab;
    /* End of Attributes*/

    /* Setters and Updates */
    void updateTable(int newID, int fromID);
    void updateTable(int side);
    /* End of Setters and Updates */
public:
    /* Constructors */
    Node();
    Node(int nullNode) : myID(nullNode) { };
    /* End of Constructors */

    /* Setters and Updates */
    void activate();
    void addChild(Node *newChild);
    void setChildParent(Node *newChild);
    void setMyParent(Node *parent);
    void fix(Node *newChild, Node *formerChild);
    /* End of Setters and Updates */

    /* Route Checkers */
    bool amHigh(int srchID);
    bool amI(int srchId);
    int amRightChild();
    bool isChild(int srchID);
    bool isRightDesc(int srchId);
    bool isLeftDesc(int srchId);
    /* End of Route Checkers */

    /* Getters */
    Node *getRightChild();
    Node *getLeftChild();
    Node *getOtherChild(Node *prefChild);
    Node *getParent();
    int getMyID();
    int getLeftChildID();
    int getRightChildID();
	int getParentID();
    int getCounter();
    std::set<int> getLeftChildTab();
    std::set<int> getRightChildTab();
    /* End of Getters */

    /* Friend Functions */
    friend void childSwap(Node *oldNext, Node *curr, Node *newNext, Node *other);
    friend void replaceChild(Node *target, Node *receiver, int typ);
    friend void printNode(Node *toPrint);
    /* End of Friend Functions */
};
#endif

#ifndef NODE_H
#define NODE_H
#include<bits/stdc++.h>

const int MAX = 1e3+3;

class Node{
private:
    static int ID;
    int myID;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
    std::set<int> leftChildTab, rightChildTab;
    void updateTable(int newID, int fromID);
    void updateTable(int side);
public:
    Node();
    Node(int nullNode) : myID(nullNode) { };
    void addChild(Node *newChild);
    void setChildParent(Node *newChild);
    void setMyParent(Node *parent);
    void fix(Node *newChild, Node *formerChild);
    Node *findNode(int srchId);
    int getMyID();
    int getLeftChildID();
    int getRightChildID();
	int getParentID();
    int amRightChild();
    bool amI(int srchId);
    bool isRightDesc(int srchId);
    bool isLeftDesc(int srchId);
    Node *getRightChild();
    Node *getLeftChild();
    Node *getOtherChild(Node *prefChild);
    Node *getParent();
    bool amHigh(int srchID);
    bool isChild(int srchID);
    std::set<int> getLeftChildTab();
    std::set<int> getRightChildTab();

    friend void childSwap(Node *oldNext, Node *curr, Node *newNext, Node *other);
    friend void replaceChild(Node *target, Node *receiver, int typ);
    friend void printNode(Node *toPrint);
};
#endif

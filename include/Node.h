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
    bool amI(int srchId);
    bool isRightDesc(int srchId);
    bool isLeftDesc(int srchId);
    bool isHigh(int srchID);
    void updateTable(int newID, int fromID);
    void updateTable(int side);
    void deleteSelf();
    /*friend void bottomUP(Node &curr, Node &req, Node &pref, Node &w);*/

public:
    Node();
    Node(int nullNode) : myID(nullNode) { };
    void addChild(Node *newChild);
    void setChildParent(Node *newChild);
    void setMyParent(Node *parent);
    Node *findNode(int srchId);
    int getMyID();
    int getLeftChildID();
    int getRightChildID();
	int getParentID();
    std::set<int> getLeftChildTab();
    std::set<int> getRightChildTab();

    friend void replaceChild(Node *receiver, Node *target, int typ);
    friend void printNode(Node *toPrint);
};

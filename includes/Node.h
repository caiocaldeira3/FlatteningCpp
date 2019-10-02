#include<bits/stdc++.h>

const int MAX = 1e3+3;

class Node{
private:
    static int ID;
    int myID;
    int parentID = -1;
    int leftChildID = -1;
    int rightChildID = -1;
    std::set<int> leftChild, rightChild;

    friend void replaceChild(Node target);
    bool amI(int srchId);
    bool isRightChild(int srchId);
    bool isLeftChild(int srchId);
    void updateTable(int newID, int fromID);
    void setMyParent(int parentID);

public:
    Node() : myID(ID++) { nodeList[this.myID] = this; };
    Node(int nullNode) : myID(nullNode) { };
    void addChild(int newChild);
    void setChildParent(int childID);
    int findNode(int srchId);
    int getMyID();
    int getLeftChildID();
    int getRightChildID();
    int getFatherID();
};

int Node::ID = 1;
Node nodeList[MAX];

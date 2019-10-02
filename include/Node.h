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

    friend void replaceChild(Node &target);
    bool amI(int srchId);
    bool isRightChild(int srchId);
    bool isLeftChild(int srchId);
    bool isHigh(int srchID);
    void updateTable(int newID, int fromID);
    void updateTable(int side);
    friend void bottomUP(Node &curr, Node &req, Node &pref, Node &w);

public:
    Node();
    Node(int nullNode) : myID(nullNode) { };
    void addChild(int newChild);
    void setChildParent(int childID);
    void setMyParent(int parentID);
    int findNode(int srchId);
    int getMyID();
    int getLeftChildID();
    int getRightChildID();
    std::set<int> getLeftChild();
    std::set<int> getRightChild();
    int getFatherID();
};

int Node::ID = 1;

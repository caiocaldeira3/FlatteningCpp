#include<bits/stdc++.h>
#include "Node.h"

void Node::updateTable(int newID, int fromID){
    if(fromID == this.leftChildID)
        this.leftChild.insert(newID);
    else if(fromID == this.rightChildID)
        this.rightChild.insert(newID);
    else{
        cout << "Error inserting ID : " << newID << " on vertex : " << this.myID << endl;
        return;
    }
    if(this.parentID != -1)
        nodeList[this.parentID].updateTable(newID, this.myID);
}
void Node::updateTable(int side){
    std::set<int> left, right;
    if(side == 0){
        this.leftChild.clear();
        if(this.leftChildID == -1) return;
        left = nodeList[this.leftChildID].getLeftChild();
        right = nodeList[this.leftChildID].getRightChild();
        for(int x : left) this.leftChild.insert(x);
        for(int x : right) this.leftChild.insert(x);
    }else if(side == 1){
        this.rightChild.clear();
        if(this.rightChildID == -1) return;
        left = nodeList[this.rightChildID].getLeftChild();
        right = nodeList[this.rightChildID].getRightChild();
        for(int x : left) this.rightChild.insert(x);
        for(int x : right) this.rightChild.insert(x);
    }else{
        cout << "Not clear about which child's table the vertex : " << this.myID << " should update" << endl;
        return;
    }
}

void Node::addChild(int newChild){
    if(this.leftChildID == -1){
        this.leftChild.insert(newChild);
        this.leftChildID = newChild;
    }else if(this.rightChildID == -1){
        this.rightChild.insert(newChild);
        this.rightChildID = newChild;
    }else{
        cout << "Not enough space on vertex : " << this.myID " to add new child" << endl;
        return;
    }
    if(this.parentID != -1)
        nodeList[this.parentID].updateTable(newID, this.myID);
    this.setChildParent(newID);
}

void Node::setChildParent(int newID){
    if(newID == -1) return;
    nodeList[newID].setMyParent(this.myID);
}
void Node::setMyParent(int parentID){
    this.parentID = parentID;
}

void Node::replaceChild(Node target, int typ){
    if(typ == 0){
        swap(this.leftChild, target.leftChild);
        swap(this.leftChildID, target.leftChildID);
        this.setChildParent(this.leftChildID);
        target.setChildParent(target.leftChildID);
    }else if(typ == 1){
        swap(this.leftChild, target.rightChild);
        swap(this.leftChildID, target.rightChildID);
        this.setChildParent(this.leftChildID);
        target.setChildParent(target.rightChildID);
    }else if(typ == 2){
        swap(this.rightChild, target.leftChild);
        swap(this.rightChildID, target.leftChildID);
        this.setChildParent(this.rightChildID);
        target.setChildParent(target.leftChildID);
    }else if(typ == 3){
        swap(this.rightChild, target.rightChild);
        swap(this.rightChildID, target.rightChildID);
        this.setChildParent(this.rightChildID);
        target.setChildParent(target.rightChildID);
    }else{
        cout << "Invalid type of rotation : " << typ << endl;
        return;
    }
}

friend void bottomUP(Node &curr, Node &req, Node &pref, Node &w){

}

Node Node::findNode(int srchID){
    if(this.amI(scrchID)) return this;
    if(this.isRightChild(srchID)) return nodeList[this.rightChildID].findNode(srchID);
    if(this.isLeftChild(srchID)) return nodeList[this.leftChildID].findNode(srchID);
    if(this.parentID != -1) return nodeList[this.parentID].findNode(srchID);
    return Node(-1);
}
bool Node::isHigh(int srchID){
    if(this.isRightChild(srchID) or this.isLeftChild(srchID))
        return 0;
    return 1;
}
bool Node::amI(int srchID){
    return srchID == this.myID;
}
bool Node::isRightChild(int srchID){
    auto itID = this.RightChild.find(srchID);
    if(itID != this.RightChild.end())
        return true;
    return false;
}
bool Node::isLeftChild(int srchID){
    auto itID = this.LeftChild.find(srchID);
    if(itID != this.LeftChild.end())
        return true;
    return false;
}
int Node::getMyID(){
    return this.myID;
}
int Node::getLeftChildID(){
    return this.LeftChildID;
}
int Node::getRightChildID(){
    return this.RightChildID;
}
int Node::getFatherID(){
    return this.FatherID;
}

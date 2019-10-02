#include<bits/stdc++.h>
#include"Node.h"

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

Node Node::findNode(int srchID){
    if(this.amI(scrchID)) return this;
    if(this.isRightChild(srchID)) return nodeList[this.rightChildID].findNode(srchID);
    if(this.isLeftChild(srchID)) return nodeList[this.leftChildID].findNode(srchID);
    if(this.parentID != -1) return nodeList[this.parentID].findNode(srchID);
    return Node(-1);
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

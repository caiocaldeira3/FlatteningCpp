#include<bits/stdc++.h>
#include "Node.h"

int Node::ID = 1;

Node::Node() {
   this->myID = ID++;
   this->parent = new Node(-1);
   this->leftChild = new Node(-1);
   this->rightChild = new Node(-1);
}

void Node::updateTable(int newID, int fromID){
    if(fromID == this->getLeftChildID())
        this->leftChildTab.insert(newID);
    else if(fromID == this->getRightChildID())
        this->rightChildTab.insert(newID);
    else{
        std::cout << "Error inserting ID : " << newID << " on vertex : " << this->myID << std::endl;
        return;
    }
    if(this->getParentID() != -1)
        this->parent->updateTable(newID, this->myID);
}
void Node::updateTable(int side){
    std::set<int> left, right;
    if(side == 0){
        this->leftChildTab.clear();
        if(this->getLeftChildID() == -1) return;
        left = this->leftChild->getLeftChildTab();
        right = this->leftChild->getRightChildTab();
        for(int x : left) this->leftChildTab.insert(x);
        for(int x : right) this->leftChildTab.insert(x);
    }else if(side == 1){
        this->rightChildTab.clear();
        if(this->getRightChildID() == -1) return;
        left = this->rightChild->getLeftChildTab();
        right = this->rightChild->getRightChildTab();
        for(int x : left) this->rightChildTab.insert(x);
        for(int x : right) this->rightChildTab.insert(x);
    }else{
        std::cout << "Not clear about which child's table the vertex : " << this->myID << " should update" << std::endl;
        return;
    }
}

void Node::addChild(Node *newChild){
    if(this->getLeftChildID() == -1){
        this->leftChild = newChild;
        this->leftChildTab.insert(this->getLeftChildID());
    }else if(this->getRightChildID() == -1){
        this->rightChild = newChild;
        this->rightChildTab.insert(this->getRightChildID());
    }else{
        std::cout << "Not enough space on vertex : " << this->myID << " to add new child" << std::endl;
        return;
    }
    if(this->getParentID() != -1)
       	this->parent->updateTable(newChild->getMyID(), this->myID);
    this->setChildParent(newChild);
}

void Node::setChildParent(Node *newChild){
    if(newChild->getMyID() == -1) return;
    newChild->setMyParent(this);

}
void Node::setMyParent(Node *parent){
    this->parent = parent;
}

void replaceChild(Node *receiver, Node *target, int typ){
    if(typ == 0){
        std::swap(receiver->leftChildTab, target->leftChildTab);
        std::swap(receiver->leftChild, target->leftChild);
        receiver->setChildParent(receiver->leftChild);
        target->setChildParent(target->leftChild);
    }else if(typ == 1){
        std::swap(receiver->leftChildTab, target->rightChildTab);
        std::swap(receiver->leftChild, target->rightChild);
        receiver->setChildParent(receiver->leftChild);
        target->setChildParent(target->rightChild);
    }else if(typ == 2){
        std::swap(receiver->rightChildTab, target->leftChildTab);
        std::swap(receiver->rightChild, target->leftChild);
        receiver->setChildParent(receiver->rightChild);
        target->setChildParent(target->leftChild);
    }else if(typ == 3){
        std::swap(receiver->rightChildTab, target->rightChildTab);
        std::swap(receiver->rightChild, target->rightChild);
        receiver->setChildParent(receiver->rightChild);
        target->setChildParent(target->rightChild);
    }else{
        std::cout << "Invalid type of rotation : " << typ << std::endl;
        return;
    }
    receiver->deleteSelf();
    target->deleteSelf();
}

void Node::deleteSelf(){
    auto itl = this->leftChildTab.find(this->myID);
    auto itr = this->rightChildTab.find(this->myID);
    if(itl != this->leftChildTab.end()){
        this->leftChildTab.erase(itl);
    }
    if(itr != this->rightChildTab.end()){
        this->rightChildTab.erase(itr);
    }
}
/*
void Node::bottomUP(Node &curr, Node &req, Node &pref, Node &w){

}
*/
Node *Node::findNode(int srchID){
    if(this->amI(srchID)) return this;
    if(this->isRightDesc(srchID)) return this->rightChild->findNode(srchID);
    if(this->isLeftDesc(srchID)) return this->leftChild->findNode(srchID);
    if(this->getParentID() != -1) return this->parent->findNode(srchID);
    return new Node(-1);
}
bool Node::isHigh(int srchID){
    if(this->isRightDesc(srchID) or this->isLeftDesc(srchID))
        return 0;
    return 1;
}
bool Node::amI(int srchID){
    return srchID == this->myID;
}
bool Node::isRightDesc(int srchID){
    auto itID = this->rightChildTab.find(srchID);
    if(itID != this->rightChildTab.end())
        return true;
    return false;
}
bool Node::isLeftDesc(int srchID){
    auto itID = this->leftChildTab.find(srchID);
    if(itID != this->leftChildTab.end())
        return true;
    return false;
}
int Node::getMyID(){
    return this->myID;
}
int Node::getLeftChildID(){
    return this->leftChild->getMyID();
}
int Node::getRightChildID(){
    return this->rightChild->getMyID();
}
int Node::getParentID(){
    return this->parent->getMyID();
}
std::set<int> Node::getRightChildTab(){
    return this->rightChildTab;
}
std::set<int> Node::getLeftChildTab(){
    return this->leftChildTab;
}

void printNode(Node *toPrint){
    std::cout << "Vertex's ID : " << toPrint->myID << std::endl;
    std::cout << "Vertex's Parent : " << toPrint->getParentID() << std::endl;
    std::cout << "Vertex's Left Child : " << toPrint->getLeftChildID() << " || Vertex's Right Child : " << toPrint->getRightChildID() << std::endl;

    std::cout << "Vertex Descendants : " << std::endl;
    for(int x : toPrint->getLeftChildTab()) std::cout << x << " | ";
    for(int x : toPrint->getRightChildTab()) std::cout << " | " << x;
    std::cout << std::endl;

}

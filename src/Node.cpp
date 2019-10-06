#include<bits/stdc++.h>
#include "Node.h"

int Node::ID = 1;

Node::Node() {
   this->myID = ID++;
   this->parent = new Node(-1);
   this->leftChild = new Node(-1);
   this->setChildParent(this->leftChild);
   this->rightChild = new Node(-1);
   this->setChildParent(this->rightChild);
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
        int x = this->leftChild->getMyID();
        if(x != -1)
            this->leftChildTab.insert(x);
    }else if(side == 1){
        this->rightChildTab.clear();
        if(this->getRightChildID() == -1) return;
        left = this->rightChild->getLeftChildTab();
        right = this->rightChild->getRightChildTab();
        for(int x : left) this->rightChildTab.insert(x);
        for(int x : right) this->rightChildTab.insert(x);
        int x = this->rightChild->getMyID();
        if(x != -1)
            this->rightChildTab.insert(x);
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
    newChild->setMyParent(this);
}
void Node::setMyParent(Node *parent){
    this->parent = parent;
}

void replaceChild(Node *target, Node *receiver, int typ){
    if(typ == 0){
        std::swap(receiver->leftChildTab, target->leftChildTab);
        std::swap(receiver->leftChild, target->leftChild);
        target->leftChild = receiver;
        receiver->setChildParent(receiver->leftChild);
        target->setChildParent(target->leftChild);
        target->updateTable(0);
    }else if(typ == 1){
        std::swap(receiver->leftChildTab, target->rightChildTab);
        std::swap(receiver->leftChild, target->rightChild);
        target->rightChild = receiver;
        receiver->setChildParent(receiver->leftChild);
        target->setChildParent(target->rightChild);
        target->updateTable(1);
    }else if(typ == 2){
        std::swap(receiver->rightChildTab, target->leftChildTab);
        std::swap(receiver->rightChild, target->leftChild);
        target->leftChild = receiver;
        receiver->setChildParent(receiver->rightChild);
        target->setChildParent(target->leftChild);
        target->updateTable(0);
    }else if(typ == 3){
        std::swap(receiver->rightChildTab, target->rightChildTab);
        std::swap(receiver->rightChild, target->rightChild);
        target->rightChild = receiver;
        receiver->setChildParent(receiver->rightChild);
        target->setChildParent(target->rightChild);
        target->updateTable(1);
    }else{
        std::cout << "Invalid type of rotation : " << typ << std::endl;
        return;
    }
}
void Node::fix(Node *newChild, Node *formerChild){
    if(formerChild->amRightChild()){
        this->rightChild = newChild;
        this->setChildParent(newChild);
    }else if(formerChild->amRightChild() == 0){
        this->leftChild = newChild;
        this->setChildParent(newChild);
    }else{
        std::cout << formerChild->getMyID() << " is not a son of Vertex : " << this->getMyID() << std::endl;
        return;
    }
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

Node *Node::findNode(int srchID){
    if(this->amI(srchID)) return this;
    if(this->isRightDesc(srchID)) return this->rightChild->findNode(srchID);
    if(this->isLeftDesc(srchID)) return this->leftChild->findNode(srchID);
    if(this->getParentID() != -1) return this->parent->findNode(srchID);
    return new Node(-1);
}
bool Node::amHigh(int srchID){
    if(this->isRightDesc(srchID) or this->isLeftDesc(srchID))
        return 1;
    return 0;
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
Node *Node::getOtherChild(Node *pref){
    if(this->leftChild == pref)
        return this->rightChild;
    if(this->rightChild == pref)
        return this->leftChild;
    std::cout << pref->getMyID() << " is not a child of the vertex : " << this->getMyID() << std::endl;
    return new Node(-1);
}
int Node::getParentID(){
    return this->parent->getMyID();
}
Node *Node::getParent(){
    return this->parent;
}
int Node::amRightChild(){
    return this->parent->getRightChildID() == this->getMyID();
}
Node *Node::getRightChild(){
    return this->rightChild;
}
std::set<int> Node::getRightChildTab(){
    return this->rightChildTab;
}
std::set<int> Node::getLeftChildTab(){
    return this->leftChildTab;
}

void printNode(Node *toPrint){
    if(toPrint->myID == -1){
        std::cout << "Empty vertex" << std::endl;
        return;
    }
    std::cout << "Vertex's ID : " << toPrint->myID << std::endl;
    std::cout << "Vertex's Parent : " << toPrint->getParentID() << std::endl;
    std::cout << "Vertex's Left Child : " << toPrint->getLeftChildID() << " || Vertex's Right Child : " << toPrint->getRightChildID() << std::endl;

    std::cout << "Vertex Descendants : " << std::endl;
    for(int x : toPrint->getLeftChildTab()) std::cout << x << " | ";
    for(int x : toPrint->getRightChildTab()) std::cout << " | " << x;
    std::cout << std::endl;

}

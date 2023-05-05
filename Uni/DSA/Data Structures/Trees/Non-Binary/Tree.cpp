#include "Tree.h"


Tree::~Tree()
{
    free();
}
Tree::Tree(const Tree& other){
    copyFrom(other);

}
Tree::Tree(int data){
    root = new Node(data);
}
Tree Tree::operator=(const Tree& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;

}

void Tree::free(){
    if(root == nullptr)
        return;

    (*root).free();
    root = nullptr;
}
void Tree::copyFrom(const Tree& other){
    *root = *other.root;

}
Node& Tree::getNode(size_t index){

    return _getNode(index, 0, *root);

}
Node& Tree::_getNode(size_t index, size_t nodeIter, Node& currNode){

    if(index == 0)
        return currNode;
    
    if(currNode.size() == nodeIter)


}

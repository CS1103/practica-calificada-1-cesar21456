//
// Created by ruben on 4/12/19.
//
#include <string>
#include <fstream>
#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H
using namespace std;

namespace UTEC{
struct Node {
    int value;
    Node* next;
    Node(int value1):value(value1),next(nullptr){};

};

struct TwoLinkedList {
    Node* head1;
    Node* head2;
    Node* tail1;
    Node* tail2;
    Node* tail;
    bool is_merged1;
    
    TwoLinkedList(){
        head1=nullptr;
        head2=nullptr;
        tail1=nullptr;
        tail2=nullptr;
        tail=nullptr;
        is_merged1=false;
    };
    //~TwoLinkedList(); no esta implementado
    void push_back1(int value);
    void push_back2(int value);
    string merge(int value);
    bool is_merged();
    string getlist(int value);
    Node* search(int value);
    void save(string value);

};  
}



#endif //PC1_TWOLINKEDLIST_H

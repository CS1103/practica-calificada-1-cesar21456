//
// Created by ruben on 4/12/19.
//

#include "TwoLinkedList.h"

namespace UTEC{
    //TwoLinkedList::~TwoLinkedList(){
            //Node *a=head1;
            //Node *b=a->next;
            //while (a->next!= nullptr and b->next=nullptr){
                //delete a;
                //a=b->next;
                //delete b;
                //b=a->next;
            //}
            //delete a;
            //delete b;
        
    //}
void TwoLinkedList::push_back1(int value){
    Node* temp=new Node(value);
    if (is_merged1==false){
        if (head1==nullptr){
            head1=temp;
            tail1=temp;
        }else{
            tail1->next=temp;
            tail1=temp;
        }        
    }else{
        tail->next=temp;
        tail=temp;
    }
}

void TwoLinkedList::push_back2(int value){
    Node* temp=new Node(value);
    if (is_merged1==false){
        if (head2==nullptr){
            head2=temp;
            tail2=temp;
        }else{
            tail2->next=temp;
            tail2=temp;
        }        
    }else{
        tail->next=temp;
        tail=temp;
    }
}

string TwoLinkedList::merge(int value){
    if (is_merged1==false){
        if (head1!=nullptr and head2!=nullptr){
            tail=new Node(value);
            tail1->next=tail;
            tail2->next=tail;
            is_merged1=true;
            return "Operación Exitosa";
        }
        else{
            return "Operacion Invalida";
        }
    }else{
        return "Operación duplicada";
    }

}

bool TwoLinkedList::is_merged(){
    if (is_merged1==true){
        return true;
    }
    else{
        return false;
    }
}

string TwoLinkedList::getlist(int value){
    switch (value){
        case 1:{
            string c;
            Node* a=head1;
            bool i=true;
            while (i==true){
                if (a!=tail1){
                    c+=to_string(a->value);
                    c+=" ";
                    a=a->next;
                }else{
                    i=false;
                }
                
            }
            c+=to_string(a->value);
            c+=" ";
            return c;
        }
        case 2:{
            string c;
            Node* a=head2;
            bool i=true;
            while (i==true){
                if (a!=tail2){
                    c+=to_string(a->value);
                    c+=" ";
                    a=a->next;
                }else{
                    i=false;
                }
                
            }
            c+=to_string(a->value);
            c+=" ";
            return c;
        }
        case 0:{
            if (is_merged1==false){
                string c;
                return c;
            }else{
                string c;
                Node* a=tail1;
                a=a->next;
                bool i=true;
                while (i==true){
                    if (a->next!=nullptr){
                        c+=to_string(a->value);
                        c+=" ";
                        a=a->next;
                    }else{
                        i=false;
                    } 
                }
                c+=to_string(a->value);
                c+=" ";
                return c;
            }
        }
    }
}



void TwoLinkedList::save(string value) {
    ofstream output(value);
    output<<getlist(1)<<endl;
    output<<getlist(2)<<endl;
    output<<getlist(0)<<endl;
}

Node* TwoLinkedList::search(int value){
    int contador_lista1=0;
    int contador_lista2=0;
    Node* respuesta=nullptr;
    Node* a=head1;
    Node* b=head2;
    while (a->value!=value){
        contador_lista1+=1;
        if (a!=nullptr){
        a=a->next;    
        }else{
            break;
        }
        
        
    }
    while (b->value!=value){
        contador_lista2+=1;
        if (b!=nullptr){
        b=b->next;
        }else{
            break;
        }
    }    
    if (contador_lista1>contador_lista2){
        return b;
    }else{
        return a;
    }
}

}


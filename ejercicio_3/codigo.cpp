#include <iostream>
#include "funciones.h"

using namespace std;

shared_ptr<Nodo> create_node(int valor){
    return make_shared<Nodo>(valor);
}

void push_front(shared_ptr<Nodo>& head, int valor){
    shared_ptr<Nodo> nuevo_nodo = create_node(valor);
    nuevo_nodo->siguiente = head;
    head = nuevo_nodo;
}

void push_back(shared_ptr<Nodo>& head, int valor){
    shared_ptr<Nodo> nuevo_nodo = create_node(valor);
    if (!head){
        head = nuevo_nodo;
    }else{
        shared_ptr<Nodo> temp = head;
        while(temp->siguiente){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo_nodo;
    }
}

void insert(shared_ptr<Nodo>& head, int valor, int pos){
    shared_ptr<Nodo> nuevo_nodo = create_node(valor);
    
    if(pos == 0){
        push_front(head, valor);
        return;
    }

    shared_ptr<Nodo> temp = head;
    for(int i = 0;temp && i < pos - 1; i++){
        temp = temp->siguiente;
    }

    if(temp){
        nuevo_nodo->siguiente = temp->siguiente;
        temp->siguiente = nuevo_nodo;
    }else{
        push_back(head, valor);
    }

}

void erase(shared_ptr<Nodo>& head, int pos){
    if(!head) return;

    if(pos == 0){
        head = head->siguiente;
        return;
    }

    shared_ptr<Nodo> temp = head;
    for(int i = 0; temp && i < pos -1; i++){
        temp = temp->siguiente;
    }

    if(temp && temp->siguiente){
        temp->siguiente = temp->siguiente->siguiente;
    }else{
        temp->siguiente = nullptr;
    }
}

void print_list(const shared_ptr<Nodo>& head){
    shared_ptr<Nodo> temp = head;
    while(temp){
        cout << temp->dato;
        if(temp->siguiente){
            cout << " -> ";
        }
        temp = temp->siguiente;
    }
    cout << endl;
}


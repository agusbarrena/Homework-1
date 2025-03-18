#include "funciones.h"
#include <iostream>

int main(){
    std::shared_ptr<Nodo> head = nullptr;
    push_front(head, 1);
    push_front(head, 2);
    push_front(head, 3);
    push_back(head, 4);
    push_back(head, 5);
    insert(head, 6, 2);
    erase(head, 1);
    print_list(head);
    return 0;
}
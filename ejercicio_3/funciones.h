#ifndef fUNCIONES_H
#define FUNCIONES_H
#include <memory>

struct Nodo {
    int dato;
    std::shared_ptr<Nodo> siguiente;
    Nodo(int dato) : dato(dato), siguiente(nullptr) {}
};

std::shared_ptr<Nodo> create_node(int valor);

void push_front(std::shared_ptr<Nodo>& head, int valor);

void push_back(std::shared_ptr<Nodo>& head, int valor);

void insert(std::shared_ptr<Nodo>& head, int valor, int pos);

void erase(std::shared_ptr<Nodo>& head, int pos);

void print_list(const std::shared_ptr<Nodo>& head);

#endif // FUNCIONES_H
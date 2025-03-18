#include "funciones.h"
#include <iostream>

int main() {
    int n = 2;
    std::vector<std::vector<int>> matriz = crear_matriz(n);
    imprimir_coordenadas(matriz);
    return 0;
}
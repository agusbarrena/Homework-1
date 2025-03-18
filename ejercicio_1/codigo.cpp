#include <iostream>
#include "funciones.h"

using namespace std;

vector<vector<int>> crear_matriz(int n){
    if(n < 1) return {};
    
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor_inicial = 1;
    for(int i= 0; i< n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = valor_inicial++;
        }
    }
    return matriz;
}
void imprimir_coordenadas(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int pos_totales = n * n;

    for(int i = pos_totales; i > 0; i--){
        int fila = (i - 1) / n; //i representa la pos actual de la matriz y con ella podemos calcular la fila y columna a traves de un calculo matematico sin necesidad de un ciclo
        int col = i - (fila * n) - 1;
        cout << "M[" << fila << "][" << col << "] = " << matriz[fila][col] << endl;
    }
    
}


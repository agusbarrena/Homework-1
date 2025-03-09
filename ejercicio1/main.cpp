#include <iostream>
using namespace std;
#include <vector>

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
        int fila = (i - 1) / n;
        int col = i - (fila * n) - 1;
        cout << "M[" << fila << "][" << col << "] = " << matriz[fila][col] << endl;
    }
    
}

int main() {
    int n = 2;
    vector<vector<int>> matriz = crear_matriz(n);
    imprimir_coordenadas(matriz);
    return 0;
}
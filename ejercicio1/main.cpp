int* crear_matriz(int n){
    if(n <= 1){
        int filas = n;
        int columnas = n;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                matriz[i][j] = i;
            }
        }
        return matriz;
    }
    else{
        return NULL;
    }
}

int main(){
    int n = 5;
    int* matriz = crear_matriz(n);
    if(matriz != NULL){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Error: n debe ser menor o igual a 1" << endl;
    }
    return 0;
}
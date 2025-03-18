#include <iostream>
#include "funciones.h"

bool miProcesoAMedir(const char* str1, const char* str2){
   if(*str1 != *str2){
      return false;
   }
    if(*str1 == '\0' && *str2 == '\0'){
        return true;
    }       
    return miProcesoAMedir(str1+1, str2+1);
}

/*Usé const char* en lugar de std::string porque trabajar con punteros a caracteres permite realizar la comparación de forma más eficiente. En las funciones con const char* no es necesario copiar ni crear nuevos objetos en cada llamada recursiva, como podría ocurrir con std::string. Esto reduce el tiempo de ejecución y el consumo de memoria, especialmente con textos largos. Además, const char* permite manipular directamente la dirección de memoria de los caracteres, haciendo que el paso recursivo sólo sea avanzar el puntero (str1 + 1).*/




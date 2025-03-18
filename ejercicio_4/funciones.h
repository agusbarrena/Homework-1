#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <chrono>

constexpr bool miProcesoAMedir2(const char* str1, const char* str2){
    return *str1 == *str2 ? (*str1 == '\0' && *str2 == '\0' ? true : miProcesoAMedir2(str1+1, str2+1)) : false;
}// se define toda la funcion aca ya que, la queremos ejecutar en tiempo de compilacion y no en tiempo de ejecucion

bool miProcesoAMedir(const char* str1, const char* str2);

#endif // FUNCIONES_H
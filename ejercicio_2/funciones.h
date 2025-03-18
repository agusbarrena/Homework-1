#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>

enum NivelSeveridad {DEBUG, INFO, WARNING, ERROR , CRITICAL, SECURITY};

const char* nivel_etiqueta (NivelSeveridad nivel);

void logMessage(const std::string& mensaje,NivelSeveridad nivel);

void logMessage(const std::string& mensaje_error, const std::string& archivo, int linea);

void logMessage(const std::string& mensaje_acceso, const std::string& usuario);

void simula_RuntimeError();

void menu_interactivo();

#endif // FUNCIONES_H
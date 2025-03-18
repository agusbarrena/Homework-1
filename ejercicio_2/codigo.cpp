#include <iostream>
#include <fstream>
#include "funciones.h"

using namespace std;

const char* nivel_etiqueta (NivelSeveridad nivel){
    switch(nivel){
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        case SECURITY: return "SECURITY";
    }
    return "NIVEL DESCONOCIDO";
}

void logMessage(const string& mensaje,NivelSeveridad nivel){
    ofstream archivoLog("log.txt", ios::app);

    if(!archivoLog){
        cerr<<"Error al abrir el archivo log.txt"<<endl;
        return;
    }

    archivoLog<<"["<<nivel_etiqueta(nivel)<<"]"<<mensaje<<endl;
    archivoLog.close();
}

void logMessage(const string& mensaje_error, const string& archivo, int linea){
    ofstream archivoLog("log.txt", ios::app);
    if(!archivoLog){
        cerr<<"Error al abrir el archivo log.txt"<<endl;
        return;
    }
    archivoLog << "[ERROR]" << mensaje_error << "(Archivo: " << archivo << "), Linea: " << linea << endl;
    archivoLog.close();
}

void logMessage(const string& mensaje_acceso, const string& usuario){
    ofstream archivoLog("log.txt", ios::app);
    if(!archivoLog){
        cerr<<"Error al abrir el archivo log.txt"<<endl;
        return;
    }
    archivoLog<<"[SECURITY]"<<mensaje_acceso<<"(Usuario:"<<usuario<<")"<<endl;
    archivoLog.close();
}

void simula_RuntimeError(){
    int* ptr = nullptr;

    if(ptr == nullptr){
        logMessage("Error de acceso a puntero null", __FILE__, __LINE__);
        cerr<< "Error detectado, frenando la ejecucion"<<endl;
        exit(1);
    }

    *ptr = 100;
}

void menu_interactivo(){
    int opcion;
    do{ 
        cout<<" SISTEMA DE LOGS"<<endl;
        cout<<"1. Registrar mensaje DEBUG"<<endl;
        cout<<"2. Registrar mensaje INFO"<<endl;
        cout<<"3. Registrar mensaje WARNING"<<endl;
        cout<<"4. Registrar mensaje ERROR"<<endl;
        cout<<"5. Registrar mensaje CRITICAL"<<endl;
        cout<<"6. Registrar mensaje de ERROR con su respectivo archivo y linea"<<endl;
        cout<<"7. Registrar mensaje SECURITY controlando accesos"<<endl;
        cout<<"8. Simular salida del programa con un run time error"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"Por favor, seleccione una opcion: ";
        cin>>opcion;

        cin.ignore();

        string mensaje, archivo, usuario, mensaje_acceso;
        int linea;

        switch(opcion){
            case 1:
               cout<<"Ingrese el mensaje de DEBUG: ";
                getline(cin, mensaje);
                logMessage(mensaje, DEBUG);
                break;
            case 2:
                cout<<"Ingrese el mensaje de INFO: ";
                getline(cin, mensaje);
                logMessage(mensaje, INFO);
                break;
            case 3:
                cout<<"Ingrese el mensaje de WARNING: ";
                getline(cin, mensaje);
                logMessage(mensaje, WARNING);
                break;
            case 4:
                cout<<"Ingrese el mensaje de ERROR: ";
                getline(cin, mensaje);
                logMessage(mensaje, ERROR);
                break;
            case 5:
                cout<<"Ingrese el mensaje CRITICAL: ";
                getline(cin, mensaje);
                logMessage(mensaje, CRITICAL);
                break;
            case 6:
                cout<<"Ingrese el mensaje de ERROR: ";
                getline(cin, mensaje);
                cout<<"Ingrese el nombre del archivo: ";
                getline(cin, archivo);
                cout<<"Ingrese el numero de linea: ";
                cin>>linea;
                logMessage(mensaje, archivo, linea);
                break;
            case 7:
                cout<<"Ingrese el mensaje de acceso (Access Granted, Access Denied, etc.): ";
                getline(cin, mensaje_acceso);
                cout<<"Ingrese el nombre del usuario: ";
                getline(cin, usuario);
                logMessage(mensaje_acceso, usuario);
                break;
            case 8:
                cout<<"Simulando un run time error"<<endl;
                simula_RuntimeError();
                break;
            case 9:
                cout<<"Usted esta saliendo del programa"<<endl;
                break;
            default:
                cout<<"No se encuentra dentro de las opciones, vuelva a intentar!"<<endl;
        }
    }while(opcion != 9);
}


    
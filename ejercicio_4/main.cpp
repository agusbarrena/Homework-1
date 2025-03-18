#include <iostream>
#include <chrono>

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

constexpr bool miProcesoAMedir2(const char* str1, const char* str2){
    return *str1 == *str2 ? (*str1 == '\0' && *str2 == '\0' ? true : miProcesoAMedir2(str1+1, str2+1)) : false;
}

constexpr char texto_uno[] = "Hola tengo muchos caracteres pero en total son exactamente 64!!!";
constexpr char texto_dos[] = "Hola tengo muchos caracteres pero en total son exactamente 64!!!\n";

constexpr bool resultado_compilacion = miProcesoAMedir2(texto_uno, texto_dos);
int main(){

    std::cout << "Texto uno: " << texto_uno << std::endl;
    std::cout << "Texto dos: " << texto_dos << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();
    bool resultado = miProcesoAMedir(texto_uno, texto_dos);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    auto start_compiletime = std::chrono::high_resolution_clock::now();
    bool resultado_ctime = resultado_compilacion;  
    auto end_compiletime = std::chrono::high_resolution_clock::now();
    auto elapsed_compiletime = std::chrono::duration_cast<std::chrono::nanoseconds>(end_compiletime - start_compiletime);

    std::cout << "\t---RESULTADO EN TIEMPO DE EJECUCION--- \n" << std::endl;
    std::cout << "¿Son iguales? " << (resultado ? "Sí" : "No") << std::endl;
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << " nanosegundos\n" << std::endl;

    std::cout << "\t---RESULTADO EN TIEMPO DE COMPILACION--- \n" << std::endl;
    std::cout << "¿Son iguales? " << (resultado_ctime ? "Sí" : "No") << std::endl;
    std::cout << "A miProcesoAMedir2 le tomó: " << elapsed_compiletime.count() << " nanosegundos\n" << std::endl;
    return 0;
}

/*En conclusión podemos ver que la versión constexpr es mucho más rapida que la versión normal; esto se debe a que esta última tiene que hacer una llamada recursiva para cada caracter de la cadena, mientras que la version constexpr se resuelve en tiempo de compilación. Este ejercicio nos muestra lo eficiente que puede ser el uso de funciones constexpr en comparación con funciones normales cuando hablamos de operaciones repetitivas o que no cambian, y siempre que se esten usando valores constantes como argumentos.*/
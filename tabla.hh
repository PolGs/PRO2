/** @file tabla.hh
    @brief Especificación de la clase tabla
*/

#ifndef _TABLA_HH
#define _TABLA_HH

#ifndef NO_DIAGRAM 
#include <vector>
#include <string>
#include <iostream>
#include <map>
#endif

using namespace std;


/** @class tabla
    @brief Representa la tabla de frecuencias de un idioma.
    
    Contiene el vector que funciona como tabla y operaciones que permiten leer o escribir la tabla.
*/


class tabla{
private:
    vector<pair<string,int> > t;
    map<string, int> m;
public:
    
    tabla();
    
    
    /** @brief Lee una tabla
		\pre En el canal estándard de entrada se encuentra la tabla de frecuencias a leer.
		\post Se han actualizado los datos de la tabla de frecuencias.
	*/
    void leer();
    
    /** @brief Escribe una tabla.
		\pre Cierto
		\post Se ha escrito por el canal estándard de salida una representación de la tabla.
	*/
    void modificar();
    
    
    /** @brief Consulta la tabla de frecuencias de un idioma.
		\pre cierto
		\post Se ha escrito por el canal estandard de salida la tabla de frecuencias.
	*/
    void escribir();
    
    
        
    
    /** @brief ordena la tabla de frecuencias de un idioma.
		\pre cierto
		
	*/
    void ordenar();
    
    int size();
    
    vector<pair<string,int> > consultar_tabla();
    
    pair<string,int> consultar_iessimo(int i);
    
};
#endif

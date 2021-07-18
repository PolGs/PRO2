/** @file treecode.hh
    @brief Especificación de la clase treecode
*/

#ifndef _TREECODE_HH
#define _TREECODE_HH

#ifndef NO_DIAGRAM 
#include "bintree.hh"
#include <vector>
#include "tabla.hh"
#include <string>
#include <map>
#include <set>
#include <iostream>
#endif

#include "tabla.hh"
using namespace std;

/** @class treecode
    @brief Representa el treecode de un idioma.
    
    Contiene el árbol binario de carácter/frecuencia y las operaciones sobre este como codificar, decodificar o escribir.
*/
class treecode{
    
private:
    
    BinTree<pair<string,int> > tree;
    map<string, string> codigo;
    
public:
    /**
     *  @brief Crea un nuevo objeto de la clase treecode.
     *  \pre Cierto
     *  \post Se ha creado un nuevo ojeto de la clase treecode.
     */
    treecode();

    /**
     *  @brief Crea un nuevo objeto de la clase treecode a partir de una tabla.
     *  \pre t es la tablla de frecuencias a partir de la cual se creara el arbol.
     *  \post Se ha creado un nuevo treecode correspondiente a la tabla de frecuencias.
     */
    void crear_arbol(tabla &t);
    
    /** @brief Se crean los codigos de un idioma.
		\pre t es el treecode con el que codificar, s es una string auxiliar, ts es la tabla donde se gurdan los còdigos.  
		\post Se han creado los codigos. 
	*/
    void crear_codigos(const BinTree<pair<string, int>>& t, string& s, map<string, string>& ts);
    
    /** @brief Se codifica un mensaje en el idioma correspondiente
		\pre En la string texto se encuentra el mensaje a codificar.
		\post Si el mensaje se puede codificar se imprime por el canal estándard de salida, en caso contrario se informa de la situación. 
	*/
    void codifica(const string& texto);//en la clase tabla?
    
    /** @brief Se decodifica un mensaje en el idioma correspondiente
		\pre En el arbol t se encuentra el treecode a utilizar, la string s contiene el mesaje a decodificar.
		\post Si el mensaje se puede decodificar la string out contendra el mensaje decodificado. 
	*/
    void decodifica(const BinTree<pair<string,int> >& t, const string& s, int& i, string& out);
    
    /** @brief Se escribe el menjase decodificado.
		\pre texto contiene el texto a decodificar
		\post Se escribe por el canal estándard de salida el texto decodificado o se informa de que no es posible. 
	*/
    void escribir_decodifica(const string& texto);
    
    /** @brief Se escribe el treecode.
		\pre Cierto
		\post Se escribe por el canal estándard de salida una representación del arbol binaro en preorden e inorden. 
	*/
    void escribir();
    
    /** @brief Escribir tabla de codigos.
		\pre Cierto
		\post Se escribe por el canal estándard de salida la tabla de codigos. 
	*/
    void escribir_tabla_codigos();
    
    /** @brief Se escribe un caracter codificado.
		\pre car es el caracter a codificar
		\post Se escribe por el canal estándard de salida la codificacion del caracter car. 
	*/
    void consultar_caracter(const string& car);
};
#endif



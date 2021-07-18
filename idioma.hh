/** @file idioma.hh
    @brief Especificación de la clase idioma.
*/
#ifndef IDIOMA_HH
#define IDIOMA_HH

#ifndef NO_DIAGRAM 
#include <iostream>
#endif

#include "tabla.hh"
#include "treecode.hh"

/** @class idioma
    @brief Representa un idoma.
    
    Contiene el nombre, la tabla de frecuencias y las operaciones sobre este como modificadoras o consultoras.
*/
class idioma {

private:
    //nombre del idioma
    string nombre;
    //tabla de frecuencias del idioma
    tabla frequencia;
    //funcion que genera el treecode a partir de la tabla de frecuencias.
    
    treecode tree;
    
public:
    /** @brief Crea un nuevo idioma
		\pre cierto
		\post El resultado es un objeto de la clase idoma vacio.
	*/
    idioma();

        
    /** @brief Crea un nuevo idioma
		\pre cierto
		\post Se ha creado un objeto de la clase idoma.
	*/
    void crear_idioma(); 
    
    /** @brief Modifica un idioma.
		\pre Cierto.
		\post Se ha modificado el idioma.
	*/ 
    void modificar_idioma();
    
    
    /** @brief Codifica un texto.
		\pre en la string texto se encuentra el mensaje a codificar.
		\post Se ha escrito por el canal estandard de salida el mensaje codificado.
	*/ 
    void codifica(string& text);
    
    /** @brief Decodifica un mensaje en un idioma.
		\pre texto contiene el mensaje a decodificar.
		\post Si se puede decodificar, se ha escrito por el canal estandard de salida el mensaje decodificado. En caso contrario el usuario es informado de la situación.
	*/
    void decodifica(const string& texto);
    
    /** @brief Consultar la tabla de frecuencias de un idioma.
		\pre Cierto.
		\post Se ha escrito la tabla de frecuencias del parametro implícito.
	*/ 
    void consultar_tabla();
    
    /** @brief Consultar el treecode de un idioma.
		\pre Cierto.
		\post Se ha escrito el treecode del parametro implícito.
	*/ 
    void consultar_treecode();
    
    /** @brief Consultar los codigos de un idioma.
		\pre Cierto.
		\post Se ha escrito la tabla de codigos del parametro implícito.
	*/ 
    void consultar_codigos();
    
    /** @brief Consulta el codigo de un caracter.
		\pre car contiene el caracter a consultar.
		\post Se ha escrito el codigo de car.
	*/ 
    void consultar_caracter(const string& car);
    
};
#endif

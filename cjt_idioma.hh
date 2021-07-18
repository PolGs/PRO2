/** @file cjt_idioma.hh
    @brief Especificación de la clase cjt_dioma.
*/

#ifndef CJT_IDIOMA_HH
#define CJT_IDIOMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
#include "idioma.hh"



/** @class cjt_idioma
    @brief Representa un conjunto de idomas.
    
    Contiene los idiomas y operaciones de gestión del conjunto.
*/

class cjt_idioma {

private:
    map<string, idioma> c;
    map<string, idioma>::iterator it;
public:
     /** @brief Crea un conjunto de idiomas.
		\pre Cierto
		\post Se ha creado un conjunto de idiomas vacio.
	*/
   cjt_idioma();
    
      /** @brief Consulta si existe un idioma en el conjunto con el nombre del parámetro.
		\pre  i contiene el nombre del idioma a consultar.
		\post Se retorna cierto si el idoma existe, falso en caso contario.
	*/
    bool existe_idioma(const string& i);
    
   /** @brief Se añade al conjunto un nuevo idioma.
		\pre  s contiene el nombre del idioma a añadir.
		\post se ha añadido el idioma de nombre s al conjunto c.
	*/
    void anadir_idioma(const string& s);

    /** @brief Modifica un idioma.
		\pre  i contiene el nombre del idioma a modificar, i existe en c.
		\post se ha modificado el idioma.
	*/
    void modificar_idioma(const string& i);
   
    /** @brief Codifica un mensaje en un idioma.
		\pre nombre contiene el idioma en el que codificar y texto el mensaje a codificar.
		\post Si se puede codificar, se ha escrito por el canal estandard de salida el mensaje codificado. En caso contrario el usuario es informado de la situación.
	*/
    void codifica(const string& nombre, string& texto);

    
    /** @brief Decodifica un mensaje en un idioma.
		\pre nombre contiene el idioma en el que decodificar y texto el mensaje a decodificar.
		\post Si se puede decodificar, se ha escrito por el canal estandard de salida el mensaje decodificado. En caso contrario el usuario es informado de la situación.
	*/
    void decodifica(const string& nombre, const string& texto);

    
    /** @brief Consulta la tabla de frecuencias de un idioma.
		\pre i contiene el nombre del idioma del que queremos ver la tabla de frecuencias, i existe en c.
		\post se ha escrito por el canal estandard de salida la tabla de frecuencias.
	*/
    void consultar_tabla_de_frequencias(const string& i);

    /** @brief Consulta el treecodede un idioma.
		\pre i contiene el nombre del idioma del que queremos ver el treecode, i existe en c.
		\post se ha escrito por el canal estandard de salida el treecode en prorden e inorden.
	*/
    void consultar_treecode(const string& i);
    
    /** @brief Consulta uno o todos los codigios de un idioma.
		\pre s contiene el nombre del idioma del que queremos ver los codigos. En el canal estandard de entrada espera el caracter a consultaro  la string "todos".
		\post se ha escrito por el canal estandard de salida el codigo o codigos correspondientes.
	*/    
    void consultar_codigos(const string& s);
   
};
#endif

/** @mainpage

	Este documento html documenta la especificación de un codificador/decodificador de mensajes.
	El programa principal se encuentra en el archivo main.cc.
	A parte de este archivo también són necesarias la siguientes 4 clases:<br>
        -<b>cjt_idioma.hh</b> que se encarga de gestionar conjuntos de idiomas<br>
        -<b>idioma.hh</b> con el que podemos definir un nuevo idioma a partir de un nombre y una tabla de frecuencias.<br>
        -<b>treecode.hh</b> que se encarga de traducir las tablas de frecuencias a arbol binario y después codificar/decodificar mensajes recorriendo los árboles.<br>
        -<b>tabla.hh</b> se encarga de leer,almacenar y escribir las tablas de frecuencias.<br>
*/

/** @file program.cc
    @brief Programa principal
*/

#ifndef NO_DIAGRAM 
#include <iostream>
#endif

#include "cjt_idioma.hh"
using namespace std;

int main(){
    int n;
    cin >>n;
    cjt_idioma c;
    string i;
    for(int j=0; j<n; j++){
        cin >> i;
        c.anadir_idioma(i);
    }
    string s;
    while(cin>>s and s != "fin"){
        
        if(s == "anadir/modificar"){
            cin >> i;
            if(c.existe_idioma(i)) c.modificar_idioma(i);
            else {
                c.anadir_idioma(i);
                cout << "Anadido " << i << endl<<endl;
            }
        }
        
        else if(s == "codifica"){
            cin >> i;
            string texto;
            cin >> texto;
            cout<< "Codifica en " << i << " el texto:" << endl;
            cout << texto << endl;
            c.codifica(i, texto);
        }
        
        else if(s == "decodifica"){
            string texto;
            cin >> i >> texto;
            cout<< "Decodifica en " << i << " el texto:" << endl;
            cout << texto << endl;
            c.decodifica(i, texto);
        }
        
        
        else if(s == "tabla_frec"){
            cin >> i;
            if(c.existe_idioma(i)){
                cout << "Tabla de frecuencias de " << i << ":" << endl;
                c.consultar_tabla_de_frequencias(i);
            }
            else{
                cout << "Tabla de frecuencias de " << i << ":" << endl;
                cout << "El idioma no existe"<< endl << endl;
            }
        }
        
        else if(s == "treecode"){
            cin >> i;
            if(c.existe_idioma(i)){
                cout << "Treecode de " << i <<":"<< endl;
                c.consultar_treecode(i);
            }
            else{
                cout << "Treecode de " << i <<":"<< endl;
                cout << "El idioma no existe"<< endl << endl;
            }
        }
    
        else if(s == "codigos"){
                cin >>i;
                c.consultar_codigos(i);
                cout << endl;
        }      
    }
}

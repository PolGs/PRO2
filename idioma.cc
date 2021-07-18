#include "idioma.hh"
using namespace std;

idioma::idioma(){}

void idioma::crear_idioma(){    
    frequencia.leer();
    tree.crear_arbol(frequencia);
}

void idioma::modificar_idioma(){    
    frequencia.modificar();
    tree.crear_arbol(frequencia);
}

void idioma::codifica(string& texto){
	tree.codifica(texto);
	}
	
void idioma::decodifica(const string& texto){
	tree.escribir_decodifica(texto);
}

void idioma::consultar_tabla(){
    frequencia.escribir();
}

void idioma::consultar_treecode(){
    tree.escribir();
}

void idioma::consultar_codigos(){
    tree.escribir_tabla_codigos();
}

void idioma::consultar_caracter(const string& car){
    tree.consultar_caracter(car);
}

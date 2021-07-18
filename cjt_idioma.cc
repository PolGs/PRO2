#include "cjt_idioma.hh"

cjt_idioma::cjt_idioma(){}


void cjt_idioma::anadir_idioma(const string& s){
    idioma i;
    i.crear_idioma();
    c.insert(make_pair(s, i));
}
/*Pre: */
/*Post: */
void cjt_idioma::consultar_treecode(const string& i){
    c.find(i)->second.consultar_treecode();
}
/*Pre: i contiene el nombre del idioma del que queremos ver la tabla de frecuencias, i existe en c*/
/*Post:*/
void cjt_idioma::consultar_tabla_de_frequencias(const string& i){
    c.find(i)->second.consultar_tabla();
}
/*Pre: */
/*Post:*/
bool cjt_idioma::existe_idioma(const string& i){
    map<string, idioma>::iterator it = c.find(i);
	if(it==c.end()) return false;
	else return true;
}
/*Pre: */
/*Post:*/
void cjt_idioma::codifica(const string& nombre, string& texto){
	map<string, idioma>::iterator it = c.find(nombre);
	if(it==c.end()) cout << "El idioma no existe" << endl << endl;
	else it->second.codifica(texto);
}

void cjt_idioma::decodifica(const string& nombre, const string& texto){
	map<string, idioma>::iterator it = c.find(nombre);
	if(it==c.end()) cout << "El idioma no existe" << endl << endl;
	else it->second.decodifica(texto);
}

void cjt_idioma::consultar_codigos(const string& s){
	map<string, idioma>::iterator it = c.find(s);
    string in;
    cin >> in;
    if(in == "todos" ){
        if(it==c.end()){
            cout << "Codigos de " << s << ":"<<endl;
            cout << "El idioma no existe" << endl;
        }
        else{
            cout << "Codigos de " << s<< ":" << endl;
            c.find(s)->second.consultar_codigos();
        }
    }
    else{
        if(it==c.end()){
            cout << "Codigo de " << in << " en " << s << ":"<<endl;
            cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
        }
        else{
            cout << "Codigo de " << in << " en " << s << ":" << endl;
            c.find(s)->second.consultar_caracter(in);
        }
    }
}
          


void cjt_idioma::modificar_idioma(const string& i){
    map<string, idioma>::iterator it = c.find(i);
    it->second.modificar_idioma();
    cout << "Modificado " << i << endl << endl;
}


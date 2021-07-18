#include "treecode.hh"
#include "bintree.hh"
#include <set>
using namespace std;

treecode::treecode(){}


bool operator<(const BinTree<pair<string, int>>& a,const BinTree<pair<string, int>>& b){
    if(a.value().second == b.value().second) return (a.value().first < b.value().first);
    return a.value().second < b.value().second;
}


void treecode::crear_arbol(tabla &t){
    int n = t.size();
    set<BinTree<pair<string, int> > >element_arb;
    for(int i=0; i<n; ++i){
        pair<string, int> a = t.consultar_iessimo(i);
        BinTree<pair<string, int> > c(a);
        element_arb.insert(c);
    }
    set<BinTree<pair<string, int> > >::const_iterator it;
    set<BinTree<pair<string, int> > >::const_iterator it2;
    
    while(element_arb.size() > 1){
        it = element_arb.begin();
        it2 = ++element_arb.begin();
        pair<string, int> raiz;
        if(it->value().first < it2->value().first) raiz.first = it->value().first + it2->value().first;
        else raiz.first = it2->value().first + it->value().first;
        raiz.second = it->value().second + it2->value().second;
        BinTree<pair<string, int> > nuevo(raiz, *it, *it2); 
        element_arb.insert(nuevo);
        element_arb.erase(it);
        element_arb.erase(it2);
    }
    tree = *element_arb.begin();
    string s;
    crear_codigos(tree, s, codigo);
    
}

void treecode::crear_codigos(const BinTree<pair<string, int>>& t, string& s, map<string, string>& ts){
    if(t.right().empty()){
        ts[t.value().first]=s;
    }
    else{
        s.push_back('0');
        crear_codigos(t.left(), s, ts);
        s.pop_back();
        s.push_back('1');
        crear_codigos(t.right(), s, ts);
        s.pop_back();
    }
}

void treecode::escribir_decodifica(const string& texto){
    string out;
    int i=0;
    int n = texto.size();
    int ult_pos=0;
    bool error=false;
    while(i<n and not error){
        decodifica(tree, texto, i, out);
        if(i==-1){
            error = true;
            cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << ult_pos << endl <<endl;
        }
        else ult_pos = i;
    }
    if(not error) cout << out << endl << endl;
}
    
    
void treecode::decodifica(const BinTree<pair<string,int> >& t, const string& s, int& i, string& out){
    if(t.left().empty()){
        
        out += t.value().first;
    }
    
    else if(s[i] == '0'){
        ++i;
        decodifica(t.left(), s, i, out);
    }
    else if(s[i] == '1'){
        ++i;
        decodifica(t.right(), s, i, out);
    }
    else i = -1;
}

bool next_symbol(const string& s, int& i, string& out){
    /* Pre: i=I<s.length() es la primera posicion de un caracter de s */
    /* Post: out es el caracter que comienza en s[I]; si out es normalretorna true y i=I+1, si es especial retorna false y i=I+2 */
    if (s[i]>=0) {out = string(1, s[i]); ++i; return true;}
    else {out = string(s, i, 2); i+=2;; return false;}
}

void treecode::codifica(const string& texto){
    int i = 0;
    bool miss = false;
    string out1 = "";
    while( i< texto.length() and not miss){
        string aux;
        next_symbol(texto, i, aux);
        map<string, string>::const_iterator it = codigo.find(aux);
        if(it == codigo.end()){
            cout << "El texto no pertenece al idioma; primer caracter que falla: "<< aux << endl << endl;;
            miss = true;
        }
        else out1 += it->second;
    }
    if(not miss) cout << out1 << endl << endl;
}
        
void preorden(const BinTree<pair<string, int> >& tre){
    if(not tre.empty()){
        cout << tre.value().first << " " << tre.value().second << endl;
        preorden(tre.left());
        preorden(tre.right());
    }
}

void inorden(const BinTree<pair<string, int> >& tre){
    if(not tre.empty()){
        inorden(tre.left());
        cout << tre.value().first << " " << tre.value().second << endl;
        inorden(tre.right());
    }
}
void treecode::escribir(){
    cout << "recorrido en preorden:" << endl;
    preorden(tree);
    cout << "recorrido en inorden:" << endl;
    inorden(tree);
    cout << endl;
}

void treecode::consultar_caracter(const string& car){
    map<string, string>::const_iterator it = codigo.find(car);
    if(it == codigo.end()) cout << "El idioma no existe o el caracter no esta en el idioma"<< endl;
    else{
        cout << car << " ";
        string a = it->second;
        cout << a << endl;
    }
}



void treecode::escribir_tabla_codigos(){
    for (map<string, string> ::const_iterator it = codigo.begin(); it != codigo.end(); ++it){
        cout << it->first  << " " <<  it->second <<  endl;
    }
}
    

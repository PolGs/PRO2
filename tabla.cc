/** @file tabla.cc
    @brief Codigo de la classe tabla
*/


#include "tabla.hh"
#include <algorithm>

tabla::tabla(){}


bool comp(pair<string, int> a, pair<string, int> b){
    if(a.first > b.first) return true;
    else return false;
}


void tabla::leer(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        pair<string,int> p;
        string ts;
        cin>>p.first>>p.second;
        t.push_back(p);
    }
    sort(t.begin(), t.end(), comp);
}

void tabla::modificar(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        bool found = false;
        for(int j=0; j< t.size(); j++){
            if(a == t[j].first){
                found = true;
                int m;
                cin >> m;
                t[j].second = t[j].second + m;
            }
        }
        if(not found){
            int m;
            cin >> m;
            t.push_back(make_pair(a,m));
        }
    }
    sort(t.begin(), t.end(), comp);
}

void tabla::ordenar(){
    sort(t.begin(), t.end(), comp);    
}

void tabla::escribir(){
    int n = t.size();
    for(int i=n-1; i>=0; i--){
        cout << t[i].first <<" " <<t[i].second << endl;
    }
    cout << endl;
}


int tabla::size(){
    return t.size();
}

vector<pair<string,int> > tabla::consultar_tabla(){
    return t;
}

pair<string,int> tabla::consultar_iessimo(int i){
    return t[i];
}


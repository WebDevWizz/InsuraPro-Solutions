#include "Interazioni.h"
#include <sstream>

Interazioni::Interazioni(const string& _tipo, const string& _descrizione, const string& _data, const string& _agente) : tipo(_tipo), descrizione(_descrizione), data(_data), agente(_agente) {}

string Interazioni::getTipo() const {
    return tipo; 
}

string Interazioni::getDescrizione() const {
    return descrizione; 
}

string Interazioni::getData() const {
    return data; 
}

string Interazioni::getAgente() const {
    return agente; 
}

void Interazioni::setTipo(const string& t) {
    tipo = t; 
}

void Interazioni::setDescrizione(const string& d) {
    descrizione = d; 
}

void Interazioni::setData(const string& d) {
    data = d; 
}

void Interazioni::setAgente(const string& a) {
    agente = a; 
}

//Conversione stringa in CSV
string Interazioni::toCSV() const {
    return tipo + ",  " + descrizione + ", " + data + ", " + agente; 
}

//Conversione CSV in stringa -> parsing 
Interazioni Interazioni::fromCSV(const string& csvLine) {
    stringstream ss(csvLine); //Leggo dal file
    string _tipo, _descrizione, _data, _agente; 

    //Leggo i singoli pezzi dalla linea, usando la virgola come separatore, e memorizzare ogni pezzo nell'apposita variabile
    getline(ss, _tipo, ',');
    getline(ss, _descrizione, ','); 
    getline(ss, _data, ','); 
    getline(ss, _agente, ','); 

    //Ritorno a questo punto l'Interazione
    return Interazioni(_tipo, _descrizione, _data, _agente); 
}


void Interazioni::stampaInterazione() const {
    cout << " - Tipo: " << tipo << endl; 
    cout << " - Descrizione: " << descrizione << endl;
    cout << " - Data: " << data << endl;
    cout << " - Agente incaricato: " << agente << endl;
}
//CLASSE PER RAPPRESENTARE UN'INTERAZIONE (APPUNTAMENTO O CONTRATTO) DI UN CLIENTE
#include <iostream>
using namespace std; 

#ifndef INTERAZIONI_H
#define INTERAZIONI_H

class Interazioni{
    private:
        string tipo; //App. o contratto
        string descrizione; 
        string data; 
        string agente; 

    public:
        //Definizione prototipi che andranno poi definiti in Interazioni.cpp
        Interazioni(const string&, const string&, const string&, const string&); 

        string getTipo() const; 
        string getDescrizione() const; 
        string getData() const; 
        string getAgente() const; 

        void setTipo(const string&); 
        void setDescrizione(const string&); 
        void setData(const string&); 
        void setAgente(const string&); 

        //Metodo per salvare la stringa in un file CSV: 
        string toCSV() const; 

        //Metodo per caricare da CSV in stringa
        static Interazioni fromCSV(const string&); 

        //Visualizzare l'interazione: 
        void stampaInterazione() const; 
};

#endif
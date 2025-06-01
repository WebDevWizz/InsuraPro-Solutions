#include <iostream>
#include <vector>

#include "Interazioni.h"

using namespace std; 

#ifndef CLIENT_H
#define CLIENT_H

class Client{
    private: 
        static int proxClient; //Variabile che serve per generare automaticamente un nuovo id quando viene aggiunto un cliente nel file CSV
        int id;
        string nome; 
        string cognome; 
        string data_nascita; 
        string email;
        string telefono; 
        string indirizzo; 
        vector<Interazioni> interazioni; 
    
    public: 
        //Costruttore 
        Client(const string&, const string&, const string&, const string&, const string&, const string&);

        //Costruttore con id specificato (per caricamento da file)
        Client(int, const string&, const string&, const string&, const string&, const string&, const string&); 

        //Getter
        int getID() const; 
        string getNome() const; 
        string getCognome() const;
        string getData() const; 
        string getEmail() const; 
        string getTelefono() const; 
        string getIndirizzo() const; 
        const vector<Interazioni>& getInterazioni() const; 

        //Setter
        void setNome(const string&); 
        void setCognome(const string&); 
        void setData(const string&); 
        void setEmail(const string&); 
        void setIndirizzo(const string&); 

        //Per un cliente, voglio poter aggiungere, eliminare e cercare interazioni: 
        void aggiungiInterazione(const Interazioni&); 
        void rimuoviInterazione(int); //Rimuovo l'indice
        vector<int> cercaInterazioni(const string&) const; 

        //Anche i clienti devono essere caricati da file CSV -> 2 metodi quindi per convertire stringa Client in CSV e viceversa
        string ClientToCsv() const; 
        static Client ClientFromCsv(const string&); 

        //Stampa Client: 
        void mostraClient() const; 

        //Stampa Client con interazioni: 
        void mostraCompleto() const; 

};

#endif
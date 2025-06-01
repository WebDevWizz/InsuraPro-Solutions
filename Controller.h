/* 
    Fulcro del programma, rappresenta tutto quello che deve fare il software, ovvero: 
    1. Aggiungere un cliente
    2. Eliminare un cliente
    3. Modificare un cliente
    4. Visualizzare tutti i clienti
    5. Ricercare un cliente per nome o cognome
    6. Gestione delle interazioni dei clienti
        6.1 Aggiunta interazione (app. o contratto) per un cliente
        6.2 Visualizzare interazioni di un cliente
        6.3 Cercare un interazione
    7. Salvare i dati ad ogni operazione effettuata in un file CSV
    8. Caricare i dati da un file CSV ad ogni avvio dell'interfaccia
*/

#include <iostream>
#include <vector>
#include "Client.h"
#include "Interazioni.h"


class Controller {
    private: 
        vector<Client> clienti; 
        const string FILE_CLIENTI = "client.csv"; 
        const string FILE_INTERAZIONI = "interazioni.csv"; 

    public: 
        Controller() { //Quando il Controller viene creato, carica i dati dal file
            caricaDati(); 
        }

        //All'invocazione del Distruttore, i dati vengono salvati
        ~Controller() {
            salvaDati();
        }

        //DEFINIZIONE METODI: 
        void aggiungiCliente(); 
        void modificaCliente(); 
        void eliminaCliente(); 
        void visualizzaClienti() const; 
        void cercaClienti() const; //Ricerca tramite nome e cognome
        Client* cercaCliente(int); 
        void aggiungiInterazione(); 
        void visualizzaInterazioni() const; 
        void cercaInterazioni() const; 
        
        void caricaDati(); 
        void salvaDati() const; 

        void mostraMenu() const; 
        void esegui(); 
};
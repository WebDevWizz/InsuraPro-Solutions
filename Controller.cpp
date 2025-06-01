#include "Controller.h"
#include <iomanip> //setw
#include <sstream>
#include <fstream>
#include <string>



void Controller::aggiungiCliente() {
    string nome, cognome, data, email, telefono, indirizzo; 

    cout << "\n *** AGGIUNTA NUOVO CLIENTE ***" << endl; 
    cout << "Nome: "; 
    cin.ignore(); 
    getline(cin, nome);
    cout << "\nCognome: "; 
    getline(cin, cognome); 
    cout << "\nData: "; 
    getline(cin, data); 
    cout << "\nEmail: "; 
    getline(cin, email); 
    cout << "\nTelefono: "; 
    getline(cin, telefono); 
    cout << "\nIndirizzo: "; 
    getline(cin, indirizzo);

    Client newClient(nome, cognome, data, email, telefono, indirizzo); 
    clienti.push_back(newClient); 

    cout << "\nCliente aggiunto con successo! ID: " << newClient.getID() << endl;  
}

void Controller::visualizzaClienti() const {
    if(clienti.empty()){
        cout << "\nNessun cliente presente" << endl; 
        return; 
    }

    cout << "\n *** LISTA CLIENTI ***" << endl; 
    cout << left << setw(5) << "ID" << setw(20) << "Nome" << setw(20) << "Cognome" 
         << setw(25) << "Email" << setw(15) << "Telefono" << "Interazioni" << endl;
    cout << string(90, '-') << endl;

    for(const auto& cliente: clienti) {
        //Stampo i dati
        cout << left << setw(5) << cliente.getID() << setw(20) << cliente.getNome() << setw(20) << cliente.getCognome()
             << setw(25) << cliente.getEmail() << setw(15) << cliente.getTelefono() << cliente.getInterazioni().size() << endl;
    }
}

Client* Controller::cercaCliente(int id) {
    //Funzione che sarà utile per la modifica del cliente e per aggiungere l'interazione.
    //Cerca l'id del cliente, e restituisce un oggetto Client
    for(auto& cliente: clienti) {
        if(cliente.getID() == id)
            return &cliente;
    }

    return nullptr; 
}


void Controller::cercaClienti() const {
    //1. Check che il vector sia pieno
    //2. Inserisci nome o cognome 
    //2.1 Definisco un vettore con i risultati
    //3. Scorro tutto il vettori dei client
    //3.1 Salvo nome e cognome di un cliente in una variabile
    //3.2 Uso la funzione find(termine) sulla variabile 
    //4. Stampo 

    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return;
    }

    string scelta; 
    cout << "\nInserisci nome o cognome del cliente: "; 
    cin.ignore(); 
    getline(cin, scelta); 

    vector<const Client*> risultati; 

    for(const auto& cliente: clienti){
        string nomeCompleto = cliente.getNome() + " " + cliente.getCognome(); 

        if(nomeCompleto.find(scelta) != string::npos)
            risultati.push_back(&cliente); 
    }

    //Stampo: 
    if(risultati.empty())
        cout << "\nNessun cliente trovato." << endl; 
    else {
        cout << "\n*** RISULTATI RICERCA ***" << endl; 
        for(const auto* ris: risultati)
            ris->mostraClient(); 
    }
}


void Controller::modificaCliente(){
    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return;
    }

    visualizzaClienti(); 

    int id; 
    cout << "\nInserisci l'id del cliente che vuoi modificare: "; 
    cin >> id; 

    Client* cliente = cercaCliente(id); 
    if(!cliente) {
        cout << "\nNessun cliente trovato." << endl; 
        return; 
    }

    cout << "\n *** MODIFICA CLIENTE ***" << endl; 
    cout << "1. Nome" << endl;
    cout << "2. Cognome" << endl;
    cout << "3. Email" << endl;
    cout << "4. Telefono" << endl;
    cout << "5. Indirizzo" << endl;
    cout << "Inserisci il campo da modificare (1-5): "; 
    int scelta; 
    cin >> scelta; 
    cin.ignore(); 

    string newValue; 
    cout << "Inserisci il nuovo valore: "; 
    getline(cin, newValue); 

    //Logica di scelta del campo: 
    switch(scelta) {
        case 1: cliente -> setNome(newValue); 
            break; 
        case 2: cliente -> setCognome(newValue); 
            break; 
        case 3: cliente -> setData(newValue); 
            break; 
        case 4: cliente -> setEmail(newValue); 
            break; 
        case 5: cliente -> setIndirizzo(newValue); 
            break; 
        default: cout << "Scelta non valida." << endl; 
            return; 
    }

    cout << "\nCliente modificato con successo!" << endl; 
}


void Controller::eliminaCliente() {
    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return; 
    }

    visualizzaClienti(); 
    int id; 
    cout << "\nInserisci l'ID del cliente da eliminare: "; 
    cin >> id; 

    bool trovato = false; //Flag per tracciare se l'id è stato trovato

    for(int i=0; i<clienti.size(); i++) {
        if(clienti[i].getID() == id) {
            cout << "\nCliente " << clienti[i].getNome() << " " << clienti[i].getCognome() << " eliminato con successo.\n"; 
            clienti.erase(clienti.begin() + i); 
            trovato = true; 
            break; //Uscita dal ciclo se cliente trovato
        }
    }

    if(!trovato)
        cout << "Cliente non trovato." << endl; 
}


void Controller::aggiungiInterazione() {
    //  1. Check che il vector sia pieno
    //  2. Aggiunta in input di una nuova interazione per un determinato cliente
    // 2.1 Solito meccanismo di ricerca del cliente tramite id (visualizzaClienti + inserisci id in input + Client* cliente = cercaCliente(id))
    // 2.2 Chiedi prima che tipo di interazione vuoi che venga inserita (contratto o appuntamento)
    // 2.3. Chiedi poi di inserire tutti i parametri 
    // 3. Crea un oggetto Interazioni con i parametri immessi
    // 4. cliente->aggiungi_interazione(oggetto)
    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return; 
    }

    visualizzaClienti(); 
    int id; 
    cout << "\nInserisci l'ID del cliente: " << endl; 
    cin >> id; 

    Client* cliente = cercaCliente(id);
    if(!cliente) {
        cout << "\nNessun cliente trovato con questo id!" << endl; 
        return; 
    } 

    cout << "\n*** AGGIUNTA INTERAZIONE ***" << endl; 
    string tipo; 
    cout << "Inserisci il tipo: "; 
    cin.ignore(); 
    getline(cin, tipo); 

    if(tipo == "appuntamento" || tipo == "contratto") {
        string descrizione, data, agente;

        cout << "\nInserisci descrizione: "; 
        getline(cin, descrizione); 
        cout << "\nInserisci data (es. 31-05-2025): "; 
        getline(cin, data); 
        cout << "\nInserisci agente: "; 
        getline(cin, agente); 

        Interazioni interazione(tipo, descrizione, data, agente); 

        cliente -> aggiungiInterazione(interazione); 

        cout << "\nInterazione aggiunta con successo!" << endl; 
        
    } else {
        cout << "\nIl tipo inserito non è valido. " << endl; 
    }
}


void Controller::visualizzaInterazioni() const {
    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return; 
    }

    visualizzaClienti(); 
    int id; 
    cout << "\nInserisci l'ID del cliente: " << endl; 
    cin >> id; 

    bool trovato = false; 
    for(int i=0; i<clienti.size(); i++) {
        if(clienti[i].getID() == id) {
            clienti[i].mostraCompleto(); 

            trovato = true; 

            break; 
        }
    }

    if(!trovato)
        cout << "Cliente non trovato." << endl; 
}


void Controller::cercaInterazioni() const {  //Cerco per tipo, se appuntamento o contratto
    if(clienti.empty()) {
        cout << "\nNessun cliente presente." << endl; 
        return; 
    }


    string scelta; 
    cout << "\nInserisci il tipo di interazione (appuntamento-contratto): "; 
    cin.ignore(); 
    getline(cin, scelta); 

    bool trovato = false; 

    if(scelta == "appuntamento" || scelta == "contratto") {
        for(const auto& cliente: clienti) {
            vector<int> risultati = cliente.cercaInterazioni(scelta); 

            if(!risultati.empty()) {
                cout << "\nCLIENTE: " << cliente.getNome() << " " << cliente.getCognome() << endl;
                for(int i: risultati) {
                    cout << "\nInterazione " << (i+1) << ": "; 
                    cliente.getInterazioni()[i].stampaInterazione(); 
                    cout << endl; 
                }
                trovato = true;
            }

        }
        if (!trovato)
            cout << "\nNessuna interazione trovata per il tipo \"" << scelta << "\"." << endl;
    } else {
        cout << "\nTipo non valido." << endl; 
    }
}


void Controller::salvaDati() const { //Salva i dati (clienti + interazioni) su file
    //Apro in scrittura: 
    ofstream fileClienti(FILE_CLIENTI); 
    if(fileClienti.is_open()) {
        for(const auto& cliente: clienti) 
            fileClienti << cliente.ClientToCsv() << endl; 
        
        fileClienti.close(); 
    }


    //Interazioni: 
    ofstream fileInterazioni(FILE_INTERAZIONI); 
    if(fileInterazioni.is_open()) {
        for(const auto& cliente: clienti) {
            for(const auto& interazione: cliente.getInterazioni())
                fileInterazioni << cliente.getID() << ", " << interazione.toCSV() << endl; 
        }
        fileInterazioni.close(); 
    }
}

void Controller::caricaDati() { //Duale del salvataggio
    //Caricamento clienti: 
    ifstream fileClienti(FILE_CLIENTI); 
    if(fileClienti.is_open()) {
        string linea; 

        while(getline(fileClienti, linea)){
            if(!linea.empty()) {
                Client cliente = Client::ClientFromCsv(linea); 
                clienti.push_back(cliente); 
            }
        }

        fileClienti.close(); 
    }


    //Caricamento interazioni cliente: 
    ifstream fileInterazioni(FILE_INTERAZIONI); 
    if(fileInterazioni.is_open()) {
        string linea; 

        while(getline(fileInterazioni, linea)) {
            if(!linea.empty()) {
                stringstream ss(linea); 
                string idClientStringa; 
                getline(ss, idClientStringa, ','); 

                int idCliente = stoi(idClientStringa); 
                Client* cliente = cercaCliente(idCliente); 

                if(cliente) {
                    string lineaRimanente; 
                    getline(ss, lineaRimanente); 
                    Interazioni interazione = Interazioni::fromCSV(lineaRimanente); 
                    cliente->aggiungiInterazione(interazione);
                }
            }
        }
        fileInterazioni.close(); 
    }
}

void Controller::mostraMenu() const {
    cout << "\n" << string(50, '=') << endl;
    cout << "    INSURA PRO SOLUTIONS - CRM SYSTEM" << endl;
    cout << string(50, '=') << endl;
    cout << "1.  Aggiungi Cliente" << endl;
    cout << "2.  Visualizza Clienti" << endl;
    cout << "3.  Modifica Cliente" << endl;
    cout << "4.  Elimina Cliente" << endl;
    cout << "5.  Cerca Cliente" << endl;
    cout << "6.  Aggiungi Interazione" << endl;
    cout << "7.  Visualizza Interazioni Cliente" << endl;
    cout << "8.  Cerca Interazioni" << endl;
    cout << "9.  Salva Dati" << endl;
    cout << "0.  Esci" << endl;
    cout << string(50, '-') << endl;
    cout << "Scegli un'opzione: ";
}

void Controller::esegui() { //PUNTO D'INGRESSO DEL PROGRAMMA: 
    cout << "Benvenuto nel sistema CRM di InsuraPro Solutions!" << endl; 
    cout << "Dati caricati: " << clienti.size() << "clienti trovati." << endl; 

    int scelta; 

    do{
        mostraMenu(); 
        cout << "Inserisci numero operazione: "; 
        cin >> scelta; 

        switch(scelta) {
            case 1: aggiungiCliente(); break; 
            case 2: visualizzaClienti(); break; 
            case 3: modificaCliente(); break; 
            case 4: eliminaCliente(); break; 
            case 5: cercaClienti(); break; 
            case 6: aggiungiInterazione(); break; 
            case 7: visualizzaInterazioni(); break; 
            case 8: cercaInterazioni(); break; 
            case 9: 
                salvaDati(); 
                cout << "Dati salvati con successo!" << endl; 
                break; 

            case 0: 
                cout << "Salvataggio dati in corso..." << endl; 
                salvaDati(); 
                cout << "Grazie per aver utilizzato InsuraPro!" << endl; 
                break; 

            default:  
                cout << "Scelta non valida. Riprova." << endl; 
        }

        if(scelta!=0) {
            cout << "\nPremi Invio per continuare..."; 
            cin.ignore(); 
            cin.get(); 
        }
    }while(scelta != 0); 
}
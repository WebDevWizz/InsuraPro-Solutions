#include "Client.h"
#include <sstream>

Client::Client(const string& n, const string& c, const string& d, const string& e, const string& t, const string& i) : id(proxClient++), nome(n), cognome(c), data_nascita(d), email(e), telefono(t), indirizzo(i) {}

Client::Client(int _id, const string& n, const string& c, const string& d, const string& e, const string& t, const string& i) : id(_id), nome(n), cognome(c), data_nascita(d), email(e), telefono(t), indirizzo(i) {
    if(_id >= proxClient) 
        proxClient = id + 1; 
}

int Client::getID() const {
    return id; 
}

string Client::getNome() const {
    return nome; 
}

string Client::getCognome() const {
    return cognome; 
}

string Client::getData() const {
    return data_nascita; 
}

string Client::getEmail() const {
    return email; 
}

string Client::getTelefono() const {
    return telefono; 
}

string Client::getIndirizzo() const {
    return indirizzo; 
}

const vector<Interazioni>& Client::getInterazioni() const {
    return interazioni; 
}

void Client::setNome(const string& _nome) {
    nome = _nome; 
}

void Client::setCognome(const string& _cognome) {
    cognome = _cognome; 
}

void Client::setData(const string& _data) {
    data_nascita = _data; 
}

void Client::setEmail(const string& _email) {
    email = _email; 
}

void Client::setIndirizzo(const string& _indirizzo) {
    indirizzo = _indirizzo; 
}

void Client::aggiungiInterazione(const Interazioni& i) {
    interazioni.push_back(i); 
}

void Client::rimuoviInterazione(int index) {
    if(index >=0 && index < interazioni.size())
        interazioni.erase(interazioni.begin() + index); 
}

vector<int> Client::cercaInterazioni(const string& key) const {
    vector<int> risultati; 

    for(int i=0; i<interazioni.size(); i++) {
        //Estraggo descrizione e tipo di ogni interazione
        string descr = interazioni[i].getDescrizione(); 
        string tipo = interazioni[i].getTipo(); 

        //TODO: eventuale check case-sensitives

        //Check che la key (tipo o descrizione) venga trovata nel tipo o nella descrizione estratta per ogni i
        if(descr.find(key) != string::npos || tipo.find(key) != string::npos)
            risultati.push_back(i); 

            //OSS: string::npos è una costante speciale che vuol dire "nessuna posizione trovata"
    }

    return risultati; 
}


string Client::ClientToCsv() const {
    return to_string(id) + ", " + nome + ", " + cognome + ", " + data_nascita + ", " + email + ", " + indirizzo; 
}

Client Client::ClientFromCsv(const string& csvLine) {
    stringstream ss(csvLine);
    string idStringa, _nome, _cognome, _data, _email, _telefono, _indirizzo;  

    getline(ss, idStringa, ','); 
    getline(ss, _nome, ','); 
    getline(ss, _cognome, ','); 
    getline(ss, _data, ','); 
    getline(ss, _email, ','); 
    getline(ss, _telefono, ','); 
    getline(ss, _indirizzo, ','); 

    return Client(stoi(idStringa), _nome, _cognome, _data, _email, _telefono, _indirizzo); 
}

void Client::mostraClient() const {
    cout << "\n*** ID CLIENTE: " << id << " ***" << endl;
    cout << "Cliente: " << nome << " " << cognome << endl;
    cout << "Email: " << email << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Indirizzo: " << indirizzo << endl;
    cout << "Numero interazioni: " << interazioni.size() << endl;
}

void Client::mostraCompleto() const{
    mostraClient(); 
    if(!interazioni.empty()) {
        cout << "\n*** INTERAZIONI CLIENTE ***" << endl; 
        for(int i=0; i<interazioni.size(); i++) {
            cout << "Interzione " << (i+1) << ":" << endl; 
            interazioni[i].stampaInterazione(); 
            cout << endl; 
        }
    }
}

int Client::proxClient = 1; //Quando inserisco il primo cliente, l'id del successivo passa in questo modo a 2
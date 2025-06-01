#include <iostream>
#include "Client.h"
#include "Interazioni.h"
#include "Controller.h"

using namespace std; 

int main()
{
    try {
        Controller c;
        c.esegui();
    } catch (const exception& e) {
        cout << "Errore: " << e.what() << endl;
        return 1;
    }

    return 0; 
}
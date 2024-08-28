#include "Persona.h"
#include <cstdlib>

void clear();

int main()
{
    Persona *p1 = new Persona("Juan", 25);

    int opcion;
    do
    {
        cout << "1. Saludar\n2. Comer\n3. HacerReir\n0. Salir\n: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            p1->Saludar();
            break;
        case 2:
            p1->Comer();
            break;

        case 3:
        {
            int motivo;
            cout << "Motivo (int): ";
            cin >> motivo;
            p1->HacerReir(motivo);
        }
        break;

        case 0:
            break;

        default:
            cout << "Opcion no valida\n";
            break;
        }
    } while (opcion != 0);
    delete p1;
    return 0;
}

void clear() { system("clear"); }
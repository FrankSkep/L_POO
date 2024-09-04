#include "Persona.h"
#include <cstdlib>
using namespace std;

void clear();
void pausa();
void usarPersona(const Persona &persona);

int main()
{
    srand(time(0));

    Persona *p1 = new Persona("Juan", 25);

    int opcion;
    do
    {
        clear();

        cout << "+- Acciones -+\n1. Saludar\n2. Comer\n3. HacerReir\n4. Todo\n0. Salir\n: ";
        cin >> opcion;
        cout << endl;

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

        case 4:
            usarPersona(*p1);
            break;

        case 0:
            break;

        default:
            cout << "Opcion no valida\n";
            break;
        }
        pausa();
        clear();
    } while (opcion != 0);

    delete p1; // Liberar la memoria
}

void clear() { system("clear"); }
void pausa()
{
    system("read -p 'Press Enter to continue...' var");
}

void usarPersona(const Persona &persona)
{
    cout << "+-- Utilizando persona " << persona.getNombre() << " --+" << endl;
    persona.Saludar();
    persona.Comer();
    persona.HacerReir(rand());
    cout << "* Persona utilizada *\n";
}
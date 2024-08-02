#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
int fichas = 100; 
void girar(int apuesta, int cantidad);

int main() {
    srand(time(0)); 

    cout << "Bienvenido al juego de la ruleta!" << endl;
    string opcion = "";
    while (fichas > 0) {
	    cout << "Tienes " << fichas << " fichas." << endl;
        cout << "Selecciona una opcion:" << endl;
        cout << "1. Jugar por numero" << endl;
        cout << "2. Jugar por paridad" << endl;
        cout << "3. Retirarse" << endl;
        cout << endl;
        cin >> opcion;
system("cls");
        if (opcion == "1") {
            int numero_apuesta, cantidad_apuesta;
            cout << "Ingresa el numero al que deseas apostar (del 0 al 36): ";
            cin >> numero_apuesta;
            if (numero_apuesta < 0 || numero_apuesta > 36) {
                cout << "Numero invalido. Por favor, intenta de nuevo." << endl;
                continue;
            }
            cout << "Cuantas fichas deseas apostar? ";
            cin >> cantidad_apuesta;
            if (cantidad_apuesta > fichas) {
                cout << "No tienes suficientes fichas para realizar esa apuesta. Intenta de nuevo." << endl;
                continue;
            }
            girar(numero_apuesta, cantidad_apuesta);
        } else if (opcion == "2") {
            int paridad_apuesta, cantidad_apuesta;
            cout << "Selecciona la paridad a la que deseas apostar (0 para PAR o 1 para IMPAR): ";
            cin >> paridad_apuesta;
            if (paridad_apuesta != 0 && paridad_apuesta != 1) {
                cout << "Por favor ingrese 0 o 1. Intenta de nuevo." << endl;
                continue;
            }
            cout << "Cuantas fichas deseas apostar? ";
            cin >> cantidad_apuesta;
            if (cantidad_apuesta > fichas) {
                cout << "No tienes suficientes fichas para realizar esa apuesta. Intenta de nuevo." << endl;
                continue;
            }
            girar(paridad_apuesta, cantidad_apuesta);
        } else if (opcion == "3") {
            cout << "Gracias por jugar. Te quedaron " << fichas << " fichas. Hasta la proxima!" << endl;
            break;
        } else {
            cout << "Opcion no valida. Por favor selecciona una opcion valida." << endl;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
    }

    if (fichas <= 0) {
        cout << "Te has quedado sin fichas. Gracias por jugar!" << endl;
    }

	system ("pause");
    return 0;
}



void girar(int apuesta, int cantidad) 
{
    int numero_ruleta = rand() % 37; 
    cout << "El numero que ha salido en la ruleta es: " << numero_ruleta << endl;

    if (apuesta == numero_ruleta) {
        fichas += cantidad * 36; 
        cout << "Has acertado al numero. Has ganado " << cantidad * 36 << " fichas." << endl;
    } else if (apuesta == 0 && numero_ruleta % 2 == 0) {
        fichas += cantidad * 2; 
        cout << "Has acertado a la paridad! El numero es par. Has ganado " << cantidad * 2 << " fichas." << endl;
    } else if (apuesta == 1 && numero_ruleta % 2 != 0) {
        fichas += cantidad * 2; 
        cout << "Has acertado a la paridad! El numero es impar. Has ganado " << cantidad * 2 << " fichas." << endl;
    } else {
        fichas -= cantidad;
        cout << "Lo siento, has perdido la apuesta." << endl;
 }

	system ("pause");
    
}

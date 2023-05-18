// ExamenP2Progra.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include <vector>
#include <cctype>

using namespace std;
int maxinventory=5;
string newobject;
vector<string> Inventory;
vector<string>::const_iterator iter;
int exit2=1;
int Gems = 20;
int inventoryspace = 0;
int inventoryfull=1;
int vectorreplace;
void vectorprint(vector<string> a, vector<string>::const_iterator iter);
void gemtransaction(int &gem, int &max);
int main()
{
	while (exit2 == 1)
	{


		cout << "Bienvenido a Inventory Manager!\n";
		while (inventoryspace!=maxinventory)
		{
			cout << "Agrega un objeto a tu inventario"<<endl;

			cin >> newobject;
			Inventory.push_back(newobject);
			
			cout << "\nEl tamaño de tu inventario es " << maxinventory << endl<<"Tienes "<<Gems<< " Gemas y tu inventario es :"<<endl;
			vectorprint(Inventory, iter);
			system("pause");
				system("cls");
				inventoryspace++;

		}
		while (inventoryspace == maxinventory && exit2 !=2)
		{
			cout << "No te queda espacio, quieres Continuar sin el objeto(1),Reemplazar un objeto (2),Añadir 1 espacio por 5 Gemas(3) "<<endl;
			cin >> inventoryfull;
			

			switch (inventoryfull)
			{
			case 1:
				cout << "Bien,Ignoras los posibles objetos en el lugar y continúas con tu camino";
				exit2 = 2;
				break;
			case 2:
				cout << "Elige el objeto que vas a reemplazar con el numero de su espacio"<<endl;
				vectorprint(Inventory, iter);
				cin >> vectorreplace;
				cout << "\nEscribe el objeto que quieres" << endl;
				cin >> newobject;
				Inventory[vectorreplace-1] = newobject;
				vectorprint(Inventory, iter);
				break;
			case 3:
				if (Gems>=5)
				{
					cout << "Pagaste 5 Gemas por un espacio";
					gemtransaction(Gems, maxinventory);
					cout << "Tienes " << Gems << " gemas y " << maxinventory << " espacios"<<endl;
				}
				else
				{
					cout << "Mueres por el peso de ambas tus decisiones economicas y el peso de tu mochila";
					exit2 = 2;
				}
				break;
			default:
				cout << "no es una opcion valida"<<endl;
				break;
			}
		}
	}
}
void vectorprint(vector<string> a,vector<string>::const_iterator iter)
{
	for (iter=a.begin(); iter != a.end(); iter++)
	{
		cout << *iter<<endl;
	}
}
void gemtransaction(int &gem, int &max)
{
	gem = gem - 5;
	max = max + 1;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

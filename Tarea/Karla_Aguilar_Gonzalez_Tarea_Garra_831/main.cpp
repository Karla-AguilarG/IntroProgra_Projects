/*      UNIVERSIDAD ESTATAL A DISTANCIA
	Curso: Introducción a la Programación
	Código: 0831
	Tarea 1: (Máquina Virtual Garra)
	Tutor: Johan Manuel Acosta Ibañez
    Grupo: 03
	Estudiante: Karla Bricelda Aguilar González
	Cédula: 155825898214
	III Cuatrimestre 2020
	Fecha de Inicio: 05 de octubre 2020
	Fecha de finalización: 24 de octubre 2020
*/

#include <iostream>
#include <stdlib.h> //Librería para generar datos aleatorios.
#include <time.h> //Librería para que los datos aleatorios vayan cambiando según la hora del día.
#include <cctype>

using namespace std;

void Llenar(char MatrizGarra[5][5], char VectorPremios[10]);
void Movimientos(int tecla_movimiento,int &fila_inicio, int &cant_movimientos, int &columna_inicio);
void MostrarPremio(char MatrizGarra[5][5],int fila_inicio, int columna_inicio);
void MostrarAmbasMatrices(int fila_inicio, int columna_inicio,char MatrizGarra[5][5]);
void Mostrar_Encabezado_La_Garra();
void MostrarMatrizOculta(int fila_inicio, int columna_inicio);
bool SoloNumeros(string Texto);

int main() //Se inicia la función principal del programa.
{
    setlocale(LC_ALL,"Spanish");//Para permitir el uso de tildes, a letra ñ, etc....
    srand(time(NULL));//Para ir generando los datos aleatorios a partir de la semilla.
    char MatrizGarra[5][5];
    char VectorPremios[]= {'A','A','C','C','F','F','P','P','R','R'};

    char seguir=' ';
    string Opcion="";

    do
    {
        int tecla_movimiento=0;
        int cant_movimientos=0;
        int fila_inicio=4;
        int columna_inicio=0;

        Llenar(MatrizGarra,VectorPremios);

        do
        {
            Mostrar_Encabezado_La_Garra(); //Se imprime el encabezado de "La Garra".

            //Mostrar matriz con Premios ocultos.
            MostrarMatrizOculta(fila_inicio,columna_inicio);

            cout<<"Ingrese el movimiento  "<<cant_movimientos+1<<":  ";
            cin>>Opcion;

            if(SoloNumeros(Opcion))
            {
                tecla_movimiento = stoi(Opcion);
                Movimientos(tecla_movimiento,fila_inicio,cant_movimientos,columna_inicio);
            }
            else
            {
                cout<<"Digite un valor numérico de las teclas disponibles."<<endl;
                system("PAUSE");
            }
        }
        while(cant_movimientos !=12  && tecla_movimiento !=5);
        Mostrar_Encabezado_La_Garra();
        MostrarAmbasMatrices(fila_inicio,columna_inicio,MatrizGarra);
        MostrarPremio(MatrizGarra,fila_inicio,columna_inicio);
        cout <<endl;
        cout<<"                                             ¿Desea jugar otra vez? (S/N)  >>  ";

        cin>>seguir;
        system("CLS");
    }
    while(seguir!='n' && seguir!='N');
    //Mensaje de Despedida.
    cout<<"\n\n";
    cout<< "                         *******************************************************"<<endl;
    cout<< "                         *              Máquina Virtual Garra                  *"<<endl;
    cout<< "                         *       Elaborado por: Karla Aguilar González         *"<<endl;
    cout<< "                         *         ¡Muchas Gracias por preferirnos!            *"<<endl;
    cout<< "                         *           ¡Qué tenga un lindo día!                  *"<<endl;
    cout<< "                         *******************************************************"<<endl;
    return 0;

}

/*Función para validar que el dato que ingrese el usuario sea correcto,ya que si él ingresa una o varias letras, o un número no válido
se le mostrará un mensaje de error y se le pedirá nuevamente el dato, hasta que sea correcto...*/
bool SoloNumeros(string Texto)
{

    for(int i=0; i<Texto.length(); i++)
    {

        if(!isdigit(Texto.at(i)))
        {
            return false;
        }
    }
    return true;
}

/*Función para realizar el llenado de la matriz con los premios correspondientes de forma aleatoria */
void Llenar(char MatrizGarra[5][5], char VectorPremios[10])
{

    //Inicializar la matriz con "X"
    for(int i =0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            MatrizGarra[i][j]='X';
        }
    }

    //Llenar una matriz con premios (letras: A, C, F, P, R) de forma aleatoria durante cada ejecución de la Garra..
    for(int cont_premios=0; cont_premios<10; cont_premios++)
    {
        int fila= rand () % (4+1);
        int columna= rand () % (4+1);

        while (MatrizGarra[fila][columna] != 'X' )
        {
            fila= rand () % (4+1);
            columna = rand() % (4+1);
        }
        MatrizGarra[fila][columna] = VectorPremios[cont_premios];
    }

}

/*Función para los movimientos que haga el usuario en la matriz. De igual forma se va haciendo el debido procemiento para
cada movimiento, con su debida validación para que el movimiento sea el correcto, de acuerdo con las teclas disponibles.*/
void Movimientos(int tecla_movimiento,int &fila_inicio, int &cant_movimientos, int &columna_inicio)
{
    switch (tecla_movimiento)
    {
    case 8:
        if(fila_inicio!=0)
        {
            fila_inicio--;
            cant_movimientos++;
            cout<<"Arriba"<<endl;
            break;

        }
        else
        {
            cout<<"Movimiento Inválido"<<endl;
            cant_movimientos++;
            break;
        }
    case 2:
        if (fila_inicio!=4)
        {
            fila_inicio++;
            cant_movimientos++;

            cout<<"Abajo"<<endl;
            break;
        }
        else
        {
            cout<<"Movimiento Inválido"<<endl;
            cant_movimientos++;
            break;
        }
    case 4:
        if (columna_inicio!=0)
        {
            columna_inicio--;
            cant_movimientos++;

            cout<<"Izquierda"<<endl;
            break;
        }
        else
        {
            cout<<"Movimiento Inválido"<<endl;
            cant_movimientos++;
            break;
        }
    case 6:
        if (columna_inicio!=4)
        {
            columna_inicio++;
            cant_movimientos++;

            cout<<"Derecha"<<endl;
            break;
        }
        else
        {
            cout<<"Movimiento Inválido"<<endl;
            cant_movimientos++;
            break;
        case 5:
            cout<<"Terminar"<<endl;
            break;
        }
    default:
        cout<<"Tecla de movimiento inválida. Intente otra vez"<<endl;
    }
}

//Función para mostrarle al usuario el premio que ganó durante el juego "La Garra".
void MostrarPremio(char MatrizGarra[5][5],int fila_inicio, int columna_inicio)
{
    cout<<endl;
    cout<<"                                         ";
    switch(MatrizGarra[fila_inicio][columna_inicio])
    {

    case 'A':
        cout<<"----------------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"|¡Felicidades usted ha ganado unos Audífonos! |"<<endl;
        cout<<"                                         ";
        cout<<"----------------------------------------------"<<endl;
        break;
    case 'C':
        cout<<"---------------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"|¡Felicidades usted ha ganado un Celular!   |"<<endl;
        cout<<"                                         ";
        cout<<"---------------------------------------------"<<endl;
        break;
    case 'F':
        cout<<"------------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"|¡Felicidades usted ha ganado un Perfume! |"<<endl;
        cout<<"                                         ";
        cout<<"-------------------------------------------"<<endl;
        break;
    case 'P':
        cout<<"------------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"|¡Felicidades usted ha ganado un Peluche! |"<<endl;
        cout<<"                                         ";
        cout<<"-------------------------------------------"<<endl;
        break;
    case 'R':
        cout<<"-----------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"|¡Felicidades usted ha ganado un Reloj!  |"<<endl;
        cout<<"                                         ";
        cout<<"-----------------------------------------"<<endl;
        break;
    default:
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"                                         ";
        cout<<"| Desafortunadamente usted no ha ganado nada. ¡Vuelva a intentarlo! |"<<endl;
        cout<<"                                         ";
        cout<<"--------------------------------------------------------------------"<<endl;
        break;
    }
}
void Mostrar_Encabezado_La_Garra()
{
    system("CLS");
    //Se empieza a ejecutar "La Máquina Virtual Garra".
    cout <<"         **************************************************"<<endl;
    cout <<"               Máquina Virtual Garra - Karla Aguilar"<<endl;
    cout <<"         **************************************************\n"<<endl;
    cout <<" Premios disponibles: [A] Audífonos - [C] Celular - [F] Perfume - [P] Peluche - [R] Reloj"<<endl;
    cout <<" Instrucciones: para realizar un movimiento utilice las teclas:\n"<<endl;
    cout <<"                                       Arriba [8]\n"<<endl;
    cout <<"                    Izquierda [4]    Terminar [5]     Derecha [6]\n"<<endl;
    cout <<"                                        Abajo [2]\n\n"<<endl;

}

//Función para mostrar la matriz ocultando los premios
void MostrarMatrizOculta(int fila_inicio, int columna_inicio)
{

    for(int i=0; i<5; i++)
    {
        cout<<"                      **********************************************"<<endl;
        cout<<"                      ";
        for(int j=0; j<5; j++)
        {
            if(i==fila_inicio && j==columna_inicio)
            {
                cout<<"|   "<<"@"<<"    ";
            }
            else
            {
                cout<<"|   "<<"X"<<"    ";
            }
        }
        cout<<"|";
        cout<<" "<<endl;
    }
    cout<<"                      **********************************************"<<endl;
}

/*Función para mostrar la matriz en la que el usuario hace los movimientos y la matriz con los premios
con la última posición del usuario en La Garra, y también si la persona gana en esa posición, se le muestra el premio y un "[@]",
que indica la posición y a la par la letra del premio.*/
void MostrarAmbasMatrices(int fila_inicio, int columna_inicio,char MatrizGarra[5][5])
{
    cout<<endl;
    cout<<"**********************************************                       **********************************************"<<endl;
    cout<<"            Movimientos del usuario                                                Premios en La Garra"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"**********************************************                       **********************************************"<<endl;
        for(int j=0; j<5; j++)
        {
            if(i==fila_inicio && j==columna_inicio)
            {
                cout<<"|   "<<"@"<<"    ";
            }
            else
            {
                cout<<"|   "<<"X"<<"    ";
            }


        }
        cout<<"|                       ";
        for(int j=0; j<5; j++)
        {
            if(i==fila_inicio && j== columna_inicio)
            {
                cout<<"|   "<<MatrizGarra[i][j]<<" [@]";
            }
            else
            {
                cout<<"|   "<<MatrizGarra[i][j]<<"    ";
            }
        }
        cout<<"|";
        cout<<" "<<endl;
    }
    cout<<"**********************************************                       **********************************************"<<endl;
}

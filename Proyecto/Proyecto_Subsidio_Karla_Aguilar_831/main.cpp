/*      UNIVERSIDAD ESTATAL A DISTANCIA
Curso: Introducción a la Programación
Código: 0831
   Proyecto Final: (Software  Transporte  Público)
Tutor: Johan Manuel Acosta Ibañez
   Grupo: 03
Estudiante: Karla Bricelda Aguilar González
Cédula: 155825898214
III Cuatrimestre 2020
Fecha de Inicio:  02 de noviembre 2020
Fecha de finalización: 05 de diciembre 2020
*/

//Declaración de las  librerías a usar
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

//Prototipos de las funciones
bool SoloNumeros(string Texto);
void Mostrar_NombreCompania();
void Menu_Perfil_Operativo();
void Logo_Perfil_Software_Transporte_Publico();
void Menu_Perfil_Administrativo();
void Mostrar_Listado_Operativo();
void Modificar_Arch_Operativo();
void Mostrar_Reporte_Admi();
void Mensaje_Despedida();

int main() //Se inicia la función principal del programa.
{

    setlocale(LC_ALL,"Spanish"); //Para permitir el uso de tildes, a letra ñ, etc....

    //Variables
    int Opcion=-1;
    string Opc_Val="";
    do
    {
        try
        {
            system("CLS");
            system("Color 70");

            //Se muestra el menú principal del programa
            Mostrar_NombreCompania();
            cout <<setw(100)<<"----------     P e r f i l    d e    T r a b a j o     ----------\n\n\n";
            Logo_Perfil_Software_Transporte_Publico();
            cout <<"\t\t[1] -> Operativo   \t\t\t\t\t\t[2] -> Menú administrativo\n\n\n";
            cout <<"\t\t\t\t\t\t[0] -> Salir\n\n";
            cout <<"\t\t\t\t\t\tElije una opción : ";

            //Se captura el valor ingresado por el usuario y se verifica que esté entre los valores disponibles (1-2-0).
            cin>>Opc_Val;
            if(SoloNumeros(Opc_Val))
            {
                Opcion = stoi(Opc_Val);
                switch(Opcion)
                {
                case 1:
                    //Abrimos y ejecutamos el Perfil Operativo.
                    Menu_Perfil_Operativo();
                    break;
                case 2:
                    //Abrimos y ejecutamos el Perfil Administrativo.
                    Menu_Perfil_Administrativo();
                    break;

                case 0:
                    //Saliendo del programa...

                    cout<<"Saliendo..."<<endl;
                    system("Pause");
                    system("CLS");
                    Mensaje_Despedida();
                    break;

                default:
                    cout<<"\t\t\t\t\t\tOpción Inválida"<<endl;
                    system("Pause");
                }
            }
        }
        catch (string Error)
        {

            cout<<Error<<endl;
            system("Pause");

        }

    }
    while(Opcion!=0);

    return 0;
} //Fin de la función principal

void Mostrar_NombreCompania()
{

    cout <<"\t\t\t\t-----------------------------------------------------------------"<<endl;
    cout <<"\t\t\t\t*    S o f t w a r e    T r a n s p o r t e   P ú b l i c o     *"<<endl;
    cout <<"\t\t\t\t-----------------------------------------------------------------\n"<<endl;

}

/*Función para validar que el dato que ingrese el usuario sea correcto,ya que si él ingresa una o varias letras, o un número no válido
se le mostrará un mensaje de error y se le pedirá nuevamente el dato, hasta que sea correcto...*/
bool SoloNumeros(string Texto)
{

    for(char& Letra : Texto)
    {
        if(!isdigit(Letra))
        {
            throw (string) "Digite un valor numérico de las opciones disponibles.";
        }
    }
    return true;
}


void Menu_Perfil_Operativo()
{
    int MonthActual, DayActual, YearActual;//Variables para asignarles la fecha actual

    time_t t = time( NULL ); //se obtiene fecha del sistema y la guarda en 3 variables. / time() devuelve un tipo time_t a un apuntador*
    struct tm fechaInicio = *localtime( &t ); /// struct descompone la fecha y hora en sus componentes

    DayActual= fechaInicio.tm_mday; /// días del 1-31
    MonthActual = fechaInicio.tm_mon + 1; /// meses del (0-11)+1
    YearActual = ( fechaInicio.tm_year+1900 );

    //Declaración de variables
    string people="";
    string persona="";
    string tipo_sexo="";
    string sexo="";
    string Opc_VD="";
    int opc_oprtvo=0;
    int tipo_persona,genero;
    string seguir="";
    bool salir=true;
    do
    {
        try
        {

            system("CLS");
            Mostrar_NombreCompania();
            system("Color 74");
            cout <<"\t\t\t\t----------   M e n ú   P e r f i l   O p e r a t i v o    ----------\n\n";
            Logo_Perfil_Software_Transporte_Publico();
            //Menú de opciones disponibles.
            cout <<"\t\t[1] -> Registro de pasajeros"<<endl;
            cout <<"\t\t[2] -> Reporte parcial de dispositivos"<<endl;
            cout <<"\t\t[0] -> Salir\n"<<endl;
            cout <<"\t\tElije una opción : ";
            cin>>Opc_VD;//Se captura el valor ingresado por el usuario y se verifica que esté entre los valores disponibles (1-2-0).
            if(SoloNumeros(Opc_VD))
            {
                opc_oprtvo = stoi(Opc_VD);

                switch(opc_oprtvo)
                {
                case 1:

                    do
                    {
                        cout<<endl;
                        cout<<"\t\t\t¿Desea registrar un pasajero? (S/N)  >> "; //Se le pregunta al usuario si desea registrar un pasajero.
                        cin>>seguir;

                        if(seguir=="N" || seguir=="n")
                        {

                            salir=false;
                        }
                        if(seguir=="S" || seguir=="s") //Se valida que para que el usuario pueda realizar un registro debe ingresar la letra "s" ó "S".
                        {
                            //si el usuario no ingresa "S","s" ó "N","n" el ciclo se va  a repetir hasta
                            //que ingrese la letra correspondiente, bien para ingresar o para salir

                            do
                            {
                                try
                                {
                                    system("CLS");
                                    Mostrar_NombreCompania();
                                    cout <<"\t\t\t\t----------   REGISTRO DE PASAJEROS   ----------\n\n\n";
                                    cout <<"[TIPO DE PERSONA]"<<endl;
                                    cout <<" [1]-> Adulto \t\t[2]->Niño \t\t[3]->Adulto Mayor \t\t[4]->Discapacitado"<<endl;
                                    cin>>people;//Se captura el valor ingresado por el usuario y se verifica que esté entre los valores disponibles (1-2-0).
                                    if(SoloNumeros(people))
                                    {
                                        tipo_persona = stoi(people);
                                        switch(tipo_persona)
                                        {
                                        case 1: //Si el usuario digita "1" persona va a ser igual a "adl" (forma reducida para mostrar si es "Adulto" en el perfil operativo).
                                            persona="adl";
                                            break;
                                        case 2://Si el usuario digita "2" persona va a ser igual a "nin" (forma reducida para mostrar si es "Niño" en el perfil operativo).
                                            persona="nin";
                                            break;
                                        case 3://Si el usuario digita "3" persona va a ser igual a "adm" (forma reducida para mostrar si es "Adulto Mayor" en el perfil operativo).
                                            persona="adm";
                                            break;
                                        case 4://Si el usuario digita "4" persona va a ser igual a "dis" (forma reducida para mostrar si es "Discapacitado" en el perfil operativo).
                                            persona="dis";
                                            break;
                                        default://Si el usuario no ingresa "1", "2", "3" ó "4",se le indica que es una opción invalida.
                                            cout<<"\t\t\t\t\t\tOpción Inválida"<<endl;
                                            system("Pause");
                                            break;
                                        }
                                    }
                                }
                                catch (string Error)
                                {

                                    cout<<Error<<endl;
                                    system("Pause");

                                }




                            }
                            while(tipo_persona>=5 || tipo_persona<=0);

                            do
                            {
                                try
                                {
                                    system("CLS");
                                    Mostrar_NombreCompania();
                                    cout <<"\t\t\t\t----------   REGISTRO DE PASAJEROS   ----------\n\n\n";
                                    cout <<"\n[GÉNERO]"<<endl;
                                    cout<<" [1]-> Masculino         [2]-> Femenino "<<endl;
                                    cin>>tipo_sexo;//Se captura el valor ingresado por el usuario y se verifica que esté entre los valores disponibles (1-2-0).
                                    if(SoloNumeros(tipo_sexo))
                                    {
                                        genero = stoi(tipo_sexo);
                                        switch(genero)
                                        {
                                        case 1://Si el usuario digita "1" persona va a ser igual a "ma" (forma reducida para mostrar si el genero es "Masculino" en el perfil operativo).
                                            sexo="ma";
                                            break;
                                        case 2://Si el usuario digita "2" persona va a ser igual a "fe" (forma reducida para mostrar si el genero es "Femenino" en el perfil operativo).
                                            sexo="fe";
                                            break;
                                        default: //Si el usuario no ingresa "1" ó "2",se le indica que es una opción invalida.
                                            cout<<"\t\t\t\t\t\tOpción Inválida"<<endl;
                                            system("Pause");
                                            break;

                                        }
                                    }
                                }
                                catch (string Error)
                                {

                                    cout<<Error<<endl;
                                    system("Pause");

                                }


                            }
                            while(genero>=3 || genero<=0);

                            ofstream archivo; ///Creamos el archivo
                            archivo.open("Operativo.txt",ios::out | ios::app); ///Abrimos el archivo operativo.txt, y si ya tiene texto se escribe al final del archivo.

                            //Se guardan todos los registros realizados
                            archivo<<persona<< "  " << sexo << " " <<hex<<DayActual<<" "<<hex<<MonthActual<<" "<<hex<<YearActual << endl;
                            archivo.close(); //Cerramos el archivo
                            salir=true;
                        }
                    }
                    while(salir==true);

                    break;
                case 2:

                    system("CLS");
                    system("Color 75");


                    Mostrar_NombreCompania();
                    cout <<"\t\t\t\t              -----------------------------"<<endl;
                    cout <<"\t\t\t\t       <<---- | Listado Dispositivo Móvil | ---->>"<<endl;
                    cout <<"\t\t\t\t              -----------------------------"<<endl;
                    Mostrar_Listado_Operativo();
                    system("Pause");

                    break;
                case 0:
                    cout<<"Saliendo...."<<endl;
                    system("Pause");
                    break;
                default:
                    cout<<"\t\t\t\t\t\tOpción Inválida"<<endl;
                    system("Pause");

                }
            }
        }
        catch (string Error)
        {

            cout<<Error<<endl;
            system("Pause");

        }

    }
    while(Opc_VD!="0");

}

void Mostrar_Listado_Operativo()
{
    ifstream Lectura;
    string direccion="";
    string sexo="";
    int MonthActual, DayActual, YearActual;
    Lectura.open("Operativo.txt", ios::in); //Abrimos el Archivo para Lectura.
    int contador=1;

    if(!Lectura.fail())
    {
        //Lee todos los registros recorriendo el archivo.
        Lectura>>direccion; //Lectura del archivo.
        cout<<"\t\t\t\t               --------------------"<<endl;
        while (!Lectura.eof()) //Si existe el archivo se procede a mostrar los datos que están guardados...
        {

            if(contador==5)
            {
                cout<<direccion<<"  | "<<endl;//Si ya el contador  identifica los  5 datos o variables, entonces se agigna un "endl" para el fin de la línea.

                contador=1;

            }
            else if(contador==1)
            {
                //Cuando el contador va identificando la segunda variable alineamos los datos y le asignamos un split de separación.
                cout<<setw(50)<<"  |  "<<direccion<<"@";
                contador++;
            }
            else
            {
                //Cuando el contador identifica a las siguientes variables, se les asigna un split de separación.
                cout<<direccion<<"@";
                contador++;
            }


            Lectura>>direccion;

        }

        cout<<"\t\t\t\t               --------------------"<<endl;
        Lectura.close(); //Cerramos el archivo.
    }
    else
    {
        throw (string) "\n\n\t\tArchivo no encontrado!. Debe registrar los pasajeros(as) para ver el Listado de Dispositivo Móvil.\n";
    }
}


void Modificar_Arch_Operativo()
{
    int MonthActual, DayActual, YearActual;
    string person_ad=" ";
    string sexo_ad=" ";
    string persona="";
    string sexo="";

    ofstream modificar;
    ifstream lectura;

    lectura.open("Operativo.txt",ios::in); //Abrimos el Archivo para Lectura.

    if(!lectura.fail())
    {
        cout <<"\t\t\t\t Conversión y generación de reporte satisfactorio...\n"<<endl;
        modificar.open("Administrativo.txt",ios::out | ios::app );  //Abrimos el archivo Administrativo.txt, y si ya tiene texto se escribe al final del archivo.
        lectura>>persona>>sexo>>hex>>DayActual>>MonthActual>>YearActual;

        while (!lectura.eof())  //Recorremos todos los valores que están en el txt Operativo y los vamos actualizando, para agregarlos al txt Administrativo.

        {
            //Se actualizan los datos referentes al tipo de persona.
            if(persona=="adl")
            {
                //Si la variable persona es igual a "adl", se le asigna "Adulto".
                person_ad="Adulto";


            }
            if(persona=="adm")
            {
                //Si la variable persona es igual a "adm", se le asigna "Adulto-Mayor".
                person_ad="Adulto-Mayor";

            }
            else if(persona=="nin")
            {
                //Si la variable persona es igual a "nin", se le asigna "Niño".
                person_ad="Niño";

            }
            else if(persona=="dis")
            {
                //Si la variable persona es igual a "dis", se le asigna "Discapacitado".
                person_ad="Discapacitado" ;

            }

            //Se actualizan los datos del sexo según corresponda  de manera legible para la parte administrativa.
            if(sexo=="fe")
            {
                //Si la variable persona es igual a "fe", se le asigna "Femenino".
                sexo_ad="Femenino";

            }
            else if(sexo=="ma")
            {
                //Si la variable persona es igual a "ma", se le asigna "Masculino".
                sexo_ad="Masculino";

            }


            //Guardamos los datos actualizados con una alineación (setw()), para que todos los datos estén ordenados y sea más fácil identificarlos.
            modificar<<setw(15)<<person_ad<<setw(12)<<sexo_ad<<setw(6)<<dec<<DayActual<<"/"<<dec<<MonthActual<<"/"<<dec<<YearActual << endl;

            lectura>>persona>>sexo>>hex>>DayActual>>MonthActual>>YearActual;


        }


        lectura.close(); //Cerramos el archivo Operativo.
        modificar.close(); //Cerramos el archivo Administrativo.
        remove ("Operativo.txt");//Eliminamos el archivo Operativo y solamente queda el archivo Administrativo con todos los registros actaulizados.
    }
    else
    {
        throw (string) "\n\t\t\tArchivo no encontrado, debe registrar los pasajeros(as) para continuar con el proceso..\n";
    }


}
void Mostrar_Reporte_Admi()
{

    string direccion="";
    string sexo="";
    int MonthActual, DayActual, YearActual;

    ifstream Leer_archivo;

    Leer_archivo.open("Administrativo.txt", ios::in);//Abrimos el Archivo para Lectura
    int contador=1;

    if(!Leer_archivo.fail())
    {
        //Lee todos los registros recorriendo el archivo
        Leer_archivo>>direccion;
        cout<<"\t\t\t\t------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t|    Tipo persona   |    Género       |    Fecha     |"<<endl;
        cout<<"\t\t\t\t------------------------------------------------------"<<endl;
        while (!Leer_archivo.eof())  //Si existe el archivo se procede a mostrar los datos que están guardados...
        {
            if(contador==3)
            {

                cout<<direccion<<"  | "<<endl;//Si ya el contador  identifica los 3 datos(persona,sexo y fecha), entonces se agigna un "endl" para el fin de la línea.
                contador=1;

            }
            else if(contador==1)
            {
                //Cuando el contador va identificando la segunda variable alineamos los datos y le asignamos un split de separación.
                cout<<setw(33)<<"|"<<setw(15)<<direccion<<"    |   ";
                contador++;
            }
            else
            {
                //Cuando el contador identifica a las siguientes variables, se les asigna un split de separación.
                cout<<setw(10)<<direccion<<"    |   ";

                contador++;
            }


            Leer_archivo>>direccion;

        }
        cout<<"\t\t\t\t------------------------------------------------------"<<endl;
        Leer_archivo.close();//Cerramos el archivo.
    }
    else
    {
        throw (string) "\n\t\t\tArchivo no encontrado!, Debe registrar los pasajeros(as) y generar el Reporte Administrativo para continuar con el proceso...\n\n";
    }

}

void Logo_Perfil_Software_Transporte_Publico()
{

    cout<<"\t\t\t\t\t\t      __________________"<<endl;
    cout<<"\t\t\t\t\t\t ____//_]|[__] [__] [__]|"<<endl;
    cout<<"\t\t\t\t\t\t(o _   |-|      |-|_   o|"<<endl;
    cout<<"\t\t\t\t\t\t `(_)-------------(_)---'"<<endl;
}

void Menu_Perfil_Administrativo()
{

//Declaración de variables
    int opcion_admi=0;
    string Opc_VaD="";
    do
    {
        try
        {
            system("CLS");
            system("Color 71");
            Mostrar_NombreCompania();

            //Menú de opciones disponibles.
            cout <<"\t\t\t\t-------------   M e n ú   A d m i n i s t r a t i v o    --------------\n\n\n";
            Logo_Perfil_Software_Transporte_Publico();
            cout <<"\t\t[1] -> Generar Reporte"<<endl;
            cout <<"\t\t[2] -> Reporte Administrativo"<<endl;
            cout <<"\t\t[0] -> Salir\n"<<endl;
            cout <<"\t\tElije una opción : ";

            cin>>Opc_VaD;//Se captura el valor ingresado por el usuario y se verifica que esté entre los valores disponibles (1-2-0).
            if(SoloNumeros(Opc_VaD))
            {
                opcion_admi = stoi(Opc_VaD);
                switch(opcion_admi)
                {
                case 1:
                    system("CLS");
                    Mostrar_NombreCompania();
                    cout<<"\n\n";
                    cout <<"\t\t\t\t--------------   Generar Reporte  -----------\n\n";
                    /*se modifican los regitros que están en el txt Operativo en información entendible
                    y luego se alamacenan los datos en el archivo administrativo.*/
                    Modificar_Arch_Operativo();
                    system("Pause");
                    break;
                case 2:
                    system("CLS");
                    Mostrar_NombreCompania();
                    cout<<"\t\t\t\t                 -------------------------------"<<endl;
                    cout<<"\t\t\t\t<<---------------|    Reporte Administrativo   |---------------->>"<<endl;
                    cout<<"\t\t\t\t                 -------------------------------\n"<<endl;
                    Mostrar_Reporte_Admi(); //Se muestran los datos que están en el txt Administrativo.
                    system("Pause");
                    break;
                case 0:
                    cout<<"Saliendo...."<<endl;;
                    system("Pause");
                    break;
                default:
                    cout<<"\t\t\t\t\t\tOpción Inválida"<<endl;
                    system("Pause");
                }
            }

        }
        catch (string Error)
        {

            cout<<Error<<endl;
            system("Pause");

        }
    }
    while(Opc_VaD!="0");
}

void Mensaje_Despedida()
{

    //Mensaje de Despedida.
    cout<<"\n\n";
    cout<< setw(100)<<"  _________________________________________________________"<<endl;
    cout<< setw(100)<<"  |           Software  Transporte Público                |"<<endl;
    cout<< setw(100)<<"  |         Elaborado por: Karla Aguilar González         |"<<endl;
    cout<< setw(100)<<"  |          ¡Muchas Gracias por preferirnos!             |"<<endl;
    cout<< setw(100)<<"  |_______________________________________________________|"<<endl;
}

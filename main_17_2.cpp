#include <iostream> //libreria estandar de c++
#include <windows.h> //contiene las declaraciones de todas las funciones del abiblioteca windows
//#include <stdio.h>
//#include <stdlib.h>
#include <conio.h> //consola de entradda y salida
//#include <time.h>
#include <ctime> //libreria de tiempo
#include <iomanip> //capturar tiempo
#include <fstream> //libreria para archivos
#include <string> //librerias para strings
#include <thread> //libreria para hilos
#define LAR 2 //medidas de los rectangulos (estetico)
#define ANCH 24 //
#define ENTER 13 //valor ascii de la tecla ENTER
#define BACKSPACE 8 //valor ascii de la tecla BACKSPACE
#define ESC 27 //valor ascii de la tecla ESCAPE

/**
* @Mainpage proyecto de programacion
* @author Uriel Gonzalez 320736
* @author Victor Gutierrez 320635
* @author Roberto Nava 320832
* @author Abraham Ibarra 320861
* @date 29 mayo 2018
*/

using namespace std;


void gotoxy(int x,int y);
void SetColorAndBackground(int ForgC, int BackC);
void ShowConsoleCursor(bool showFlag);


/** @brief Creacion de una variable estructura donde se almacenaran los datos que necesitamos para la creacion y de la cuenta
*/

struct Info{
    char nombre[20], apellido1[20], apellido2[20], ciudad[20], entidad[20];
    int dia, mes, anio;
    string carrera, telefono, correo1, correo2;
};

/**
*@brief Esta es una excepcion personalizada de acuerdo al programa que se arrojara en cierto punto,si es que se llega a presentar el error
*/

struct Archivos : public exception{
    const char* what() const throw() {
        return "ERROR: Matricula no registrada";
    }
};

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void fecha(){
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d / %m / %Y") <<endl;
}
/**
* @fn void titulo()
* @brief Esta funcion es para la interfaz estetica y la impresion de "FICHAS" en el menu,utiliza funciones como setcolorandbackground
  y la funcion gotoxy para ir a una coordenada (1,1) y comenzar a imprimir caracteres. Se mueve a la coordenada (92,3),llama a la funcion fecha y imprime
  en una coordenada.
  */

void titulo(){
    SetColorAndBackground(7,5);
    for(int i=0;i<=119;i++){
        for(int y=0;y<=8;y++){
            gotoxy(i,y);
            cout << " ";
        }
    }
    gotoxy(1,1);
    cout << "\n\t\t\t          ___ _      _                ";
    cout << "\n\t\t\t         / __(_) ___| |__   __ _ ___        \\     _ \\  |   |\\ \\     /";
    cout << "\n\t\t\t        / _\\ | |/ __| '_ \\ / _` / __|      _ \\   |   | |   | \\ \\   / ";
    cout << "\n\t\t\t       / /   | | (__| | | | (_| \\__ \\     ___ \\  __ <  |   |  \\ \\ / ";
    cout << "\n\t\t\t       \\/    |_|\\___|_| |_|\\__,_|___/   _/    _\\_| \\_\\\\___/    \\_/";

    gotoxy(98,3);
    fecha();

    SetColorAndBackground(16,7);
    gotoxy(5,28);
    cout << "**Usa Enter y las Flechas para desplazarte por el menu**";

}
/**
* @fn void titulobienvenido()
* @brief Esta funcion es para la interfaz estetica y la impresion de "BIENVENIDO" una vez que el usuario inicia sesion con exito, utiliza la funcion
  gotoxy para ir a una coordenada distintas coordenadas y comenzar a imprimir caracteres.
  */
void titulobienvenido(){
    gotoxy(6,24);
    cout<<"___  _ ____ _  _ _  _ ____ _  _ _ ___  ____"<<endl;
    gotoxy(6,25);
    cout<<"|__] | |___ |\\ | |  | |___ |\\ | | |  \\ |  |"<<endl;
    gotoxy(6,26);
    cout<<"|__] | |___ | \\|  \\/  |___ | \\| | |__/ |__|"<<endl;
    gotoxy(5,1);
    cout<< "< ESC" << endl;
}
/** @fn void rectangulo(int x,int z)
* @brief Esta funcion crea los 3 rectangulos que observamos en el menu donde dicen:CREAR CUENTA,INICIAR SESION,SALIR,la medias de ANCH Y LAR estan definidas
* en el principio del programa e imprime los caracteres ASCII para hacer el diseño.
* los @param de la funcion son enteros x,y,los cuales indican la posicion donde se imprimira el caracter
Esta funcion no tiene @return de ningun valor,solamente ejecuta las
instrucciones
*/

void rectangulo(int x, int z){
    for(int i=0;i<=ANCH;i++){
        for(int y=0;y<=LAR;y++){
            if(y==0){
                gotoxy(i+x,y+z);
                cout << "\315";
            }
            if(y==LAR){
                gotoxy(i+x,y+z);
                cout << (char)205;
            }
            if(i==ANCH){
                gotoxy(i+x,y+z);
                cout << (char)186;
            }
            if(i==0){
                gotoxy(i+x,y+z);
                cout << (char)186;
            }
            if(i==0 && y==0){
                gotoxy(i+x,y+z);
                cout << (char)201;
            }
            if(i==0 && y==LAR){
                gotoxy(i+x,y+z);
                cout << (char)200;
            }
            if(i==ANCH && y==0){
                gotoxy(i+x,y+z);
                cout << (char)187;
            }
            if(i==ANCH && y==LAR){
                gotoxy(i+x,y+z);
                cout << (char)188;
            }
        }
    }
}

void dibujartabla(int x, int y, int x2, int y2){
	int xa=0, ya=0, xb=0, yb=0;
	xa=x;
	ya=y;
	yb=y2;
	xb=x2;

	gotoxy(xb,ya);

	if(x2>x)
	{
	    gotoxy(x,y);
        cout<<"\311";
		for(;x+1<x2;x++)
		{
			gotoxy(x+1,y);
			cout<<"\315"<<endl;
		}

        gotoxy(x2,y2);
        cout<<"\274";
		while(x2-1 != xa)
		{
			gotoxy(x2-1,y2);
			cout<<"\315"<<endl;
			x2--;
		}
	}
	if(y2>y)
	{
	    gotoxy(x+1,y);
        cout<<"\273";
		for(;y<y2-1;y++)
		{
			gotoxy(x+1,y+1);
			cout<<"\272"<<endl;
		}

	}
        gotoxy(x2-1,y2);
        cout<<"\310";
		while(y2-1!=ya)
		{
			gotoxy(x2-1,y2-1);
			cout<<"\272"<<endl;
			y2--;
		}

}
/**
@fn void crear( info datos, string contra, string &nmatricula)
@brief esta funcion crea el archivo, pero primero se asegura de que el archivo se abra, por medio de una comprobacion,
en caso de que no abra el archivo entonces crea uno nuevo con nombre +1.
Si el archivo funciona se imprimen los datos de la estructura Info en el archivo base
@param Info datos- es la estructura del arreglo, string contra- es la contraseña aleatoria que se genero, string &nmatricula-
esta mandando a llamar por referencia a la variable nmatricula para asi ponerle nombre al archivo
@return no regresa un valor pero si se crea un arhivo o se lanza una excepcion.
 */
void crear(Info datos, string contra, string &nmatricula){
    ofstream base;
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1;
    int anio = now->tm_year + 1900;

    base.open(nmatricula, ios::in);
    while (base.is_open()){
    base.close();
    int convint = atoi(nmatricula.c_str());
    convint=convint+1;
    nmatricula=to_string(convint);
    base.open(nmatricula, ios::in);
}
    try{
        base.open(nmatricula, ios::out);

    if(base.fail())
    {
        throw Archivos();
    }else{
        base << contra << endl;
        base<<datos.nombre <<endl;
        base<<datos.apellido1<<endl;
        base<<datos.apellido2<<endl;
        base<<datos.ciudad<<endl;
        base<<datos.entidad<<endl;
        base<<datos.telefono<<endl;
        base<<datos.correo1<<endl;
        base<<datos.correo2<<endl;
        base<<dia<<"/"<<mes<<"/"<<anio<<endl;
        base<<datos.dia<<endl;
        base<<datos.mes<<endl;
        base<<datos.anio<<endl;
        base<<datos.carrera<<endl;
    }
        base.close();

    }catch(Archivos& msg){
        cout<<msg.what()<<endl;
    }
}
/** @fn void leer(string *lineas,string matricula)
* @brief  Esta funcion  se encarga de leer los datos del archivo ingresados en la funcion anterior,usa tambien excepciones por si el archivo no puede
ser abierto,lee el archivo linea por linea.
*@param los parametros de la funcion son string *lineas que es una apuntador a donde se encuentra las lineas que leera,y @param matricula para identificar de
de que archivo va a leer los datos.
*/

void leer(string *lineas, string matricula){
    ifstream archivo;

    archivo.open(matricula, ios::in);
    if(archivo.fail())
    {
        throw Archivos();
    }else{
        for (int i=0;i<14;i++)
            getline(archivo, lineas[i]);
    }
    archivo.close();

}

void leertodos(string archnum){
    ifstream archivo;
    string lineas [14];


    try{
        archivo.open(archnum, ios::in);
        if(archivo.fail()){
            throw Archivos();
        }else{
            for (int i=0;i<14;i++){
                getline(archivo, lineas[i]);
                }
        }archivo.close();
        SetColorAndBackground(16,7);
        cout << lineas[1]<< "\n" << lineas[2] << "\n" << lineas[13] << "\n" <<"____________________________________________________"<< "\n" << endl;

        }catch(Archivos &msg){
            cout << msg.what();
        }



}

void cargando (){
    int x=1, y=47;

    SetColorAndBackground(7,5);
    for(int i=40;i<=63;i++){
        for(int y=3;y<=5;y++){
            gotoxy(i,y);
            cout << " ";
        }
    }
    gotoxy(50,4);
    cout << "Cargando";
    for (int i=45;i<49;i++){
        gotoxy(i,4);
        cout << "-";
        Sleep(500);
    }
}

void editarbase(Info datos, string matriculau, string contra, string ciudad, string entidad){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1;
    int anio = now->tm_year + 1900;
    ofstream archivocambio;
    string lineas[14];

    //leer
    ifstream archivo;

    archivo.open(matriculau, ios::in);
    if(archivo.fail())
    {
        throw Archivos();
    }else{
        for (int i=0;i<14;i++)
            getline(archivo, lineas[i]);
    }
    archivo.close();

    //editar
    archivocambio.open(matriculau, ios::out);
    if(archivocambio.fail()){
        throw Archivos();
    }else{
        if(contra==""){
            archivocambio << lineas[0] << endl;
        }else{
            archivocambio << contra << endl;
        }
        archivocambio<<lineas[1] <<endl;
        archivocambio<<lineas[2]<<endl;
        archivocambio<<lineas[3]<<endl;
        if(ciudad==""){
            archivocambio<<lineas[4]<<endl;
        }else{
            archivocambio<<ciudad<<endl;
        }
        if(entidad==""){
            archivocambio<<lineas[5]<<endl;
        }else{
            archivocambio<<entidad<<endl;
        }
        if(datos.telefono==""){
            archivocambio<<lineas[6]<<endl;
        }else{
            archivocambio<<datos.telefono<<endl;
        }
        if(datos.correo1==""){
            archivocambio<<lineas[7]<<endl;
        }else{
            archivocambio<<datos.correo1<<endl;
        }
        if(datos.correo2==""){
            archivocambio<<lineas[8]<<endl;
        }else{
            archivocambio<<datos.correo2<<endl;
        }
        archivocambio<<dia<<"/"<<mes<<"/"<<anio<<endl;
        archivocambio<<lineas[10]<<endl;
        archivocambio<<lineas[11]<<endl;
        archivocambio<<lineas[12]<<endl;
        archivocambio<<lineas[13]<<endl;
        }
    archivocambio.close();
}
/**
@fn void menu()
@brief Esta funcion realiza la mayor parte de las ejectuciones del progrma ya que manda a llamar a funiones externas
de esta misma, se encarga de la interfaz visual del programa por medio de las funciones predeterminadas gotoxy,
setcolorandbackground, aqui mismo se uso del manejo de excepciones.
@param la funcion es vacia ya que no esta recibiendo nada
@return no regresa un valor pero se ejecutan todas las funciones del programa, dentro de el y esta se llama en el main
*/
void menu(){
    int a=50, b=4, c=12, posicion=0, e=0, color1=4, color2=7, color3=7, color4=7, colorletras1=12, colorletras2=9,colorfondo=7,tecla;
    SetConsoleTitle("---------------------------------------------------------------FICHAS---------------------------------------");
    SetColorAndBackground(colorfondo,colorfondo);
    for(int i=0;i<=120;i++){
        for(int y=8;y<=29;y++){
            gotoxy(i,y);
            cout << " ";
        }
    }
    titulo();
    //MENU PRINCIPAL
    do{
        if(posicion==0){
            color1=colorletras1;
            color2=colorletras2;
            color3=colorletras2;
            color4=colorletras2;
        }
        if(posicion==1){
            color1=colorletras2;
            color2=colorletras1;
            color3=colorletras2;
            color4=colorletras2;
        }
        if(posicion==2){
            color1=colorletras2;
            color2=colorletras2;
            color3=colorletras1;
            color4=colorletras2;
        }
         if(posicion==3){
            color3=colorletras2;
            color4=colorletras1;
        }
        SetColorAndBackground(color1,colorfondo);
        rectangulo(a,c);
        gotoxy(a+3,c+1);
        cout << "Crear Nueva Cuenta";
        SetColorAndBackground(color2,colorfondo);
        rectangulo(a,c+b);
        gotoxy(a+5,c+b+1);
        cout << "Iniciar Sesion";
        SetColorAndBackground(color3,colorfondo);
        rectangulo(a,c+(2*b));
        gotoxy(a+8,c+(2*b)+1);
        cout << "Acerca De";
        SetColorAndBackground(color4,colorfondo);
        rectangulo(a,c+(3*b));
        gotoxy(a+10,c+(3*b)+1);
        cout << "Salir";
        if(posicion==0){
            SetColorAndBackground(colorletras1,colorfondo);
            gotoxy(a-3,c+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+b+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+(2*b)+1);
            cout << "-->";
        }
        if(posicion==1){
            SetColorAndBackground(colorletras1,colorfondo);
            gotoxy(a-3,c+b+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+(2*b)+1);
            cout << "-->";
        }
        if(posicion==2){
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+b+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+1);
            cout << "-->";
            SetColorAndBackground(colorletras1,colorfondo);
            gotoxy(a-3,c+(2*b)+1);
            cout << "-->";
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+(3*b)+1);
            cout << "-->";
        }
        if(posicion==3){
            SetColorAndBackground(colorfondo,colorfondo);
            gotoxy(a-3,c+(2*b)+1);
            cout << "-->";
            SetColorAndBackground(colorletras1,colorfondo);
            gotoxy(a-3,c+(3*b)+1);
            cout << "-->";
        }


        tecla=getch();
        if (tecla==115 || tecla==80){
            if(posicion<3)
                posicion++;
        }
        if (tecla==119 || tecla==72){
            if(posicion>0)
                posicion--;
        }
        if (posicion==0 && tecla==ENTER){
            //MENU CREAR CUENTA
            string carrera, nmatricula="3201";
            int posicion2=0,colorm1=colorletras1,colorm2=colorletras2,colorm3=colorletras2,colorm4=colorletras2,colorm5=colorletras2,colorm6=colorletras2;
            int colorm7=colorletras2, salir=0;
            string contra;
            Info datos={};
            system("cls");
            SetColorAndBackground(7,5);
                for(int i=0;i<=119;i++){
                    for(int y=22;y<=29;y++){
                        gotoxy(i,y);
                        cout << " ";
                    }
                }
            gotoxy(6,24);
            cout<<"____ ____ ____ ____ ____    ____ _  _ ____ _  _ ___ ____"<<endl;
            gotoxy(6,25);
            cout<<"|    |__/ |___ |__| |__/    |    |  | |___ |\\ |  |  |__|"<<endl;
            gotoxy(6,26);
            cout<<"|___ |  \\ |___ |  | |  \\    |___ |__| |___ | \\|  |  |  | "<<endl;
            gotoxy(5,1);
            cout<< "< ESC" << endl;

            do{
                ShowConsoleCursor(false);
                SetColorAndBackground(colorm1,colorfondo);
                dibujartabla(5,3,89,5);
                SetColorAndBackground(colorletras2,colorfondo);
                dibujartabla(90,3,115,5);
                SetColorAndBackground(colorm2,colorfondo);
                dibujartabla(5,7,115,9);
                SetColorAndBackground(colorm3,colorfondo);
                dibujartabla(5,11,30,13);
                SetColorAndBackground(colorm4,colorfondo);
                dibujartabla(34,11,59,13);
                SetColorAndBackground(colorm5,colorfondo);
                dibujartabla(5,14,59,16);
                SetColorAndBackground(colorm6,colorfondo);
                dibujartabla(90,12,115,14);
                SetColorAndBackground(colorm7,colorfondo);
                dibujartabla(90,18,100,20);
                gotoxy(91,19);
                cout<<"> Crear <"<<endl;

                SetColorAndBackground(colorletras2,colorfondo);
                gotoxy(10,6);
                cout<<"Nombre(s)  \t\t  Apellido Paterno  \t\t  Apellido Materno \t\t    Fecha " << endl;
                gotoxy(12,10);
                cout<<"    Ciudad\t\t\t\t  Entidad federativa\t\t\t\tTelefono"<<endl;
                gotoxy(61,12);
                cout<<"Correo Electronico"<<endl;
                gotoxy(32,12);
                cout<<"@"<<endl;
                gotoxy(100,13);
                cout << "/";
                gotoxy(105,13);
                cout << "/";
                gotoxy(61,15);
                cout<<"Carrera seleccionada      \t      Fecha de Nacimiento"<<endl;
                gotoxy(97,16);
                cout<<"(DD/MM/AAAA)"<<endl;
                gotoxy(96,4);
                fecha();
                SetColorAndBackground(16,colorfondo);
                gotoxy(10,18);
                cout<<"**Ingresa todos los datos correspondientes**"<<endl;

                if(posicion2==0){
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(2,4);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,15);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                }
                if(posicion2==1){
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(2,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,4);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,15);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                }
                if(posicion2==2 || posicion2==4){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,4);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(2,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,15);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                }
                if(posicion2==3){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,4);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,12);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(2,15);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                }
                if(posicion2==5){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,4);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(2,15);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,19);
                    cout << "-->";
                }
                 if(posicion2==6){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(87,13);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(87,19);
                    cout << "-->";
                 }

                tecla=getch();
                if (tecla==115 || tecla==80){
                    if(posicion2<3)
                        posicion2++;
                    if(posicion2==4)
                        posicion2=3;
                    if(posicion2==5)
                        posicion2=6;
                }
                if (tecla==119 || tecla==72){
                    if(posicion2==4)
                        posicion2=2;
                    if(posicion2>0)
                        posicion2--;
                     if(posicion2==6)
                        posicion2=5;
                }
                if (tecla==100 || tecla==77){
                    if(posicion2==4)
                        posicion2=5;
                    if(posicion2==2)
                        posicion2=4;
                    if(posicion2==3)
                        posicion2=5;
                }
                if (tecla==97 || tecla==75){
                    if(posicion2==4)
                        posicion2=2;
                    if(posicion2==5)
                        posicion2=4;
                }

                if (posicion2==0){
                    colorm1=colorletras1;
                    colorm2=colorletras2;
                    colorm3=colorletras2;
                    colorm4=colorletras2;
                    colorm5=colorletras2;
                    colorm6=colorletras2;
                    if(tecla==ENTER){
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(7,4);
                        cin.getline(datos.nombre, 20, '\n');
                        gotoxy(36,4);
                        cin.getline(datos.apellido1, 20, '\n');
                        gotoxy(68,4);
                        cin.getline(datos.apellido2, 20, '\n');

                    }
                }
                if (posicion2==1){
                    colorm1=colorletras2;
                    colorm2=colorletras1;
                    colorm3=colorletras2;
                    colorm4=colorletras2;
                    colorm5=colorletras2;
                    colorm6=colorletras2;
                    if(tecla==ENTER){
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(14,8);
                        cin.getline(datos.ciudad, 20, '\n');
                        gotoxy(50,8);
                        cin.getline(datos.entidad, 20, '\n');
                        gotoxy(95,8);
                        cin>>datos.telefono;
                        cin.ignore();
                    }
                }
                if (posicion2==2){
                    colorm1=colorletras2;
                    colorm2=colorletras2;
                    colorm3=colorletras1;
                    colorm4=colorletras2;
                    colorm5=colorletras2;
                    colorm6=colorletras2;
                    if(tecla==ENTER){
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(9,12);
                        cin >> datos.correo1;
                        cin.ignore();
                    }
                }
                if (posicion2==3){
                    int colorcarrera1=12, colorcarrera2=7, colorcarrera3=7, colorcarrera4=7, posicioncarrera=0;
                    colorm1=colorletras2;
                    colorm2=colorletras2;
                    colorm3=colorletras2;
                    colorm4=colorletras2;
                    colorm5=colorletras1;
                    colorm6=colorletras2;
                    if(tecla==ENTER){
                        SetColorAndBackground(7,5);
                        for(int i=5;i<=59;i++){
                            for(int y=1;y<=16;y++){
                                gotoxy(i,y);
                                cout << " ";
                            }
                        }
                        gotoxy(10,2);
                        cout << " Seleccione una de las carreras disponibles";
                        gotoxy(10,4);
                        cout << " Ingenieria en Ciencias de la Computacion";
                        gotoxy(10,7);
                        cout << " Ingenieria Civil";
                        gotoxy(10,10);
                        cout << " Ingenieria Aeroespacial";
                        gotoxy(10,13);
                        cout << " Ingenieria en Minas";
                    do{
                        SetColorAndBackground(colorcarrera4,5);
                        dibujartabla(7,12,57,14);
                        SetColorAndBackground(colorcarrera3,5);
                        dibujartabla(7,9,57,11);
                        SetColorAndBackground(colorcarrera2,5);
                        dibujartabla(7,6,57,8);
                        SetColorAndBackground(colorcarrera1,5);
                        dibujartabla(7,3,57,5);

                        tecla=getch();
                        if (tecla==115 || tecla==80){
                            if(posicioncarrera<4)
                                posicioncarrera++;
                        }
                        if (tecla==119 || tecla==72){
                            if(posicioncarrera>0)
                                posicioncarrera--;
                        }
                        if (posicioncarrera==0){
                            colorcarrera1=colorletras1;
                            colorcarrera2=7;
                            colorcarrera3=7;
                            colorcarrera4=7;
                            if (tecla==ENTER)
                                carrera = "Ingeneria en Ciencias de la Computacion";
                        }
                        if (posicioncarrera==1){
                            colorcarrera1=7;
                            colorcarrera2=colorletras1;
                            colorcarrera3=7;
                            colorcarrera4=7;
                            if (tecla==ENTER)
                                carrera = "Ingeneria Civil";
                        }
                        if (posicioncarrera==2){
                            colorcarrera1=7;
                            colorcarrera2=7;
                            colorcarrera3=colorletras1;
                            colorcarrera4=7;
                            if (tecla==ENTER)
                                carrera = "Ingeneria Aeroespacial";
                        }
                        if (posicioncarrera==3){
                            colorcarrera1=7;
                            colorcarrera2=7;
                            colorcarrera3=7;
                            colorcarrera4=colorletras1;
                            if (tecla==ENTER)
                                carrera = "Ingeneria en Minas";
                        }
                        datos.carrera=carrera;
                    }while(tecla!=ENTER);
                        SetColorAndBackground(colorletras2,colorfondo);
                        for(int i=5;i<=59;i++){
                            for(int y=1;y<=16;y++){
                                gotoxy(i,y);
                                cout << " ";
                            }
                        }
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(7,4);
                        cout << datos.nombre;
                        gotoxy(36,4);
                        cout << datos.apellido1;
                        gotoxy(14,8);
                        cout << datos.ciudad;
                        gotoxy(50,8);
                        cout << datos.entidad;
                        gotoxy(9,12);
                        cout << datos.correo1;
                        gotoxy(38,12);
                        cout << datos.correo2;
                    }
                    SetColorAndBackground(7,5);
                    gotoxy(5,1);
                    cout<< "< ESC" << endl;
                    SetColorAndBackground(16,colorfondo);
                    gotoxy(9,15);
                    cout << carrera;
                }
                if (posicion2==4){
                    colorm1=colorletras2;
                    colorm2=colorletras2;
                    colorm3=colorletras2;
                    colorm4=colorletras1;
                    colorm5=colorletras2;
                    colorm6=colorletras2;
                    colorm7=colorletras2;
                    if (tecla==ENTER){
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(38,12);
                        cin >> datos.correo2;
                        cin.ignore();
                    }
                }
                if (posicion2==5){
                    colorm1=colorletras2;
                    colorm2=colorletras2;
                    colorm3=colorletras2;
                    colorm4=colorletras2;
                    colorm5=colorletras2;
                    colorm6=colorletras1;
                    colorm7=colorletras2;
                     if (tecla==ENTER){
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        gotoxy(97,13);
                        cin >> datos.dia;
                        gotoxy(102,13);
                        cin >> datos.mes;
                        gotoxy(107,13);
                        cin >> datos.anio;
                        cin.ignore();
                    }
                }
                 if (posicion2==6){
                    colorm1=colorletras2;
                    colorm2=colorletras2;
                    colorm3=colorletras2;
                    colorm4=colorletras2;
                    colorm5=colorletras2;
                    colorm6=colorletras2;
                    colorm7=colorletras1;
                    if (tecla==ENTER){
                        try{
                        int j=0, i=0;
                        j=strlen(datos.nombre);
                        if(j==0){
                            throw invalid_argument("! Datos incorrectos");
                        }else{
                            while(i<j){
                                if(isdigit(datos.nombre[i])!=0){
                                    throw invalid_argument("! Datos incorrectos");
                                }
                                i++;
                            }
                        }
                        i=0;
                        j=0;
                        j=strlen(datos.apellido1);
                        if(j==0){
                            throw invalid_argument("! Datos incorrectos");
                        }else{
                            while(i<j){
                                if(isdigit(datos.apellido1[i])!=0){
                                    throw invalid_argument("! Datos incorrectos");
                                }
                                i++;
                            }
                        }
                        i=0;
                        j=0;
                        j=strlen(datos.apellido2);
                        if(j==0){
                            throw invalid_argument("! Datos incorrectos");
                        }else{
                            while(i<j){
                                if(isdigit(datos.apellido2[i])!=0){
                                    throw invalid_argument("! Datos incorrectos");
                                }
                                i++;
                            }
                        }
                        i=0;
                        j=0;
                        j=strlen(datos.ciudad);
                        if(j==0){
                            throw invalid_argument("! Datos incorrectos");
                        }else{
                            while(i<j){
                                if(isdigit(datos.ciudad[i])!=0){
                                    throw invalid_argument("! Datos incorrectos");
                                }
                                i++;
                            }
                        }
                        i=0;
                        j=0;
                        j=strlen(datos.entidad);
                        if(j==0){
                            throw invalid_argument("! Datos incorrectos");
                        }else{
                            while(i<j){
                                if(isdigit(datos.entidad[i])!=0){
                                    throw invalid_argument("! Datos incorrectos");
                                }
                                i++;
                            }
                        }
                        i=0;
                        j=0;
                        for(i=0;i<datos.telefono.size();i++){
                            if(isdigit(datos.telefono[i])==0){
                                throw invalid_argument("! Datos incorrectos");
                            }
                            i++;
                        }
                        if(datos.dia<0 || datos.dia>31 || datos.mes<0||datos.mes>12 || datos.anio<1940 || datos.anio>2002)
                            throw out_of_range("! Fecha incorrecta");
                        if(datos.dia == 29 && datos.mes == 02 && (datos.anio % 4 != 0 && (datos.anio % 100 == 0 || datos.anio % 400 != 0)))
                            throw out_of_range("! A\244o no bisiesto");

                        int coloraceptar1=12, coloraceptar2=7, posicionaceptar=0;
                        SetColorAndBackground(7,5);
                        for(int i=28;i<=93;i++){
                            for(int y=8;y<=15;y++){
                                gotoxy(i,y);
                                cout << " ";
                            }
                        }
                        gotoxy(32,9);
                        cout << "Estas seguro que todos los datos ingresados son correctos?";
                        do{
                            SetColorAndBackground(coloraceptar1,5);
                            dibujartabla(46,12,56,14);
                            gotoxy(50,13);
                            cout << "Si";
                            SetColorAndBackground(coloraceptar2,5);
                            dibujartabla(65,12,75,14);
                            gotoxy(69,13);
                            cout << "No";

                            tecla=getch();

                            if (tecla==100 || tecla==77){
                                if(posicionaceptar==0)
                                    posicionaceptar++;
                            }
                            if (tecla==97 || tecla==75){
                                if(posicionaceptar==1)
                                    posicionaceptar--;
                            }
                            if (posicionaceptar==0){
                                coloraceptar1=colorletras1;
                                coloraceptar2=7;
                                if(tecla==ENTER){
                                    SetColorAndBackground(colorletras2,colorfondo);
                                    for(int i=28;i<=93;i++){
                                        for(int y=8;y<=15;y++){
                                            gotoxy(i,y);
                                            cout << " ";
                                        }
                                    }
                                    SetColorAndBackground(7,5);
                                    for(int i=28;i<=93;i++){
                                        for(int y=8;y<=15;y++){
                                            gotoxy(i,y);
                                            cout << " ";
                                        }
                                    }
                                    gotoxy(33,9);
                                    cout << "Cuenta y Ficha creadas... Pulsa una tecla para continuar";
                                    gotoxy(40,13);
                                    cout << "Matricula: ";
                                    gotoxy(65,13);
                                    cout << "Contrase" << (char)-92 << "a: ";
                                    srand(time(NULL));
                                    string caracteresPosibles = "abcdefghijklmnopqrstuvwxyz123456789";
                                    for(int i=0;i<6;i++)
                                        contra+= caracteresPosibles[rand() % caracteresPosibles.size()];
                                    cout << contra;
                                    crear(datos, contra, nmatricula);
                                    gotoxy(51,13);
                                    cout << nmatricula;
                                    tecla=getch();
                                    salir=1;
                                }
                            }
                            if (posicionaceptar==1){
                            coloraceptar1=7;
                            coloraceptar2=colorletras1;
                            }
                            if(salir==1)
                            tecla=ENTER;
                        }while(tecla!=ENTER);
                         SetColorAndBackground(colorletras2,colorfondo);
                            for(int i=28;i<=93;i++){
                                for(int y=8;y<=15;y++){
                                    gotoxy(i,y);
                                    cout << " ";
                                }
                            }
                            SetColorAndBackground(16,colorfondo);
                            gotoxy(50,8);
                            cout << datos.entidad;
                            gotoxy(38,12);
                            cout << datos.correo2;
                            gotoxy(9,15);
                            cout << carrera;
                            }catch(invalid_argument &msg3){
                                gotoxy(86,21);
                                cout << msg3.what() << endl;
                            }catch(out_of_range& msg4){
                                gotoxy(86,21);
                                cout << msg4.what() << endl;
                            }
                        }
                    }

                 if(salir==1)
                    tecla=ESC;
            }while(tecla!=ESC);
            SetColorAndBackground(colorfondo,colorfondo);
            for(int i=0;i<=120;i++){
                for(int y=8;y<=29;y++){
                    gotoxy(i,y);
                    cout << " ";
                }
            }
            titulo();
        }
        if (posicion==1 && tecla==ENTER){
            //MENU INICIAR SESION
            int coloric1 = 12, coloric2 = 9, coloric3 = 9, posicionic = 0;
            string contra2, nmatriculau;
            Info datos={};
            system("cls");
            SetColorAndBackground(7,5);
                for(int i=0;i<=119;i++){
                    for(int y=22;y<=29;y++){
                        gotoxy(i,y);
                        cout << " ";
                    }
                }
            gotoxy(6,24);
            cout<<"_ _  _ _ ____ _ ____ ____    ____ ____ ____ _ ____ _  _"<<endl;
            gotoxy(6,25);
            cout<<"| |\\ | | |    | |__| |__/    [__  |___ [__  | |  | |\\ |"<<endl;
            gotoxy(6,26);
            cout<<"| | \\| | |___ | |  | |  \\    ___] |___ ___] | |__| | \\|"<<endl;
            gotoxy(5,1);
            cout<< "< ESC" << endl;

            do{
                SetColorAndBackground(coloric1,colorfondo);
                rectangulo(a,7);
                gotoxy(a+5,7+3);
                cout << "   Matricula";
                SetColorAndBackground(coloric2,colorfondo);
                rectangulo(a,7+b);
                gotoxy(a+5,7+b+3);
                cout << "  Contrase" << (char)-92 << "a";
                SetColorAndBackground(coloric3,colorfondo);
                dibujartabla(55,17,68,19);
                gotoxy (56,18);
                cout << "> Ingresar <";
                if (posicionic==0){
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(47,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(47,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(52,18);
                    cout << "-->";
                }
                if (posicionic==1){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(47,8);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(47,12);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(52,18);
                    cout << "-->";
                }
                if (posicionic==2){
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(47,8);
                    cout << "-->";
                    SetColorAndBackground(colorfondo,colorfondo);
                    gotoxy(47,12);
                    cout << "-->";
                    SetColorAndBackground(colorletras1,colorfondo);
                    gotoxy(52,18);
                    cout << "-->";
                }

                tecla=getch();

                if (tecla==115 || tecla==80){
                    if(posicionic<2)
                        posicionic++;
                }
                if (tecla==119 || tecla==72){
                    if(posicionic>0)
                        posicionic--;
                }
                if (posicionic==0){
                    coloric1=colorletras1;
                    coloric2=colorletras2;
                    coloric3=colorletras2;
                    if(tecla==ENTER){
                        gotoxy(60,8);
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);
                        cin >> nmatriculau;
                        cin.ignore();
                        ShowConsoleCursor(false);
                    }
                }
                if (posicionic==1){
                    coloric1=colorletras2;
                    coloric2=colorletras1;
                    coloric3=colorletras2;
                    if(tecla==ENTER){
                        gotoxy(59,12);
                        ShowConsoleCursor(true);
                        SetColorAndBackground(16,colorfondo);

                        char caracter;
                        caracter = getch();

                        while (caracter != ENTER) {

                        if (caracter != BACKSPACE) {
                            contra2.push_back(caracter);
                            cout << "*";

                        } else {
                            if (contra2.length() > 0) {
                                cout << "\b \b";
                                contra2 = contra2.substr(0, contra2.length() - 1);
                            }
                        }
                        caracter = getch();
                        }
                        ShowConsoleCursor(false);

                    }
                }
                if (posicionic==2){
                    coloric1=colorletras2;
                    coloric2=colorletras2;
                    coloric3=colorletras1;
                    if (tecla==ENTER){
                        try{
                        string *lineas = new string[14];
                        leer(lineas, nmatriculau);
                        if(contra2.compare(lineas[0])==0){
                            int colorsi1=12, colorsil2=9, colorsil3=9, posicionil=0, salir=0;
                            string ciudad, entidad;
                            system("cls");
                            SetColorAndBackground(7,5);
                            for(int i=0;i<=119;i++){
                                for(int y=22;y<=29;y++){
                                    gotoxy(i,y);
                                    cout << " ";
                                }
                            }
                            titulobienvenido();

                            SetColorAndBackground(7,5);
                            gotoxy(6,27);
                            cout << lineas[1]; //nombre
                            gotoxy(70,25);
                            cout << "Matricula No.";
                            gotoxy(70,26);
                            cout << nmatriculau; //matricula
                            gotoxy(90,25);
                            cout << "Fecha de Creacion";
                            gotoxy(90,26);
                            cout << lineas[9];
                            SetColorAndBackground(16,colorfondo);
                            gotoxy(6,3);
                            cout << "INFORMACION PERSONAL";
                            for (int i=6;i<70;i++){
                                gotoxy(i,4);
                                cout << (char)196;
                            }
                            gotoxy(83,3);
                            cout << "OPCIONES";
                            for (int i=83;i<111;i++){
                                gotoxy(i,4);
                                cout << (char)196;
                            }
                            SetColorAndBackground(16,colorfondo);
                            gotoxy(6,6);
                            cout << "Nombre ";
                            gotoxy(6,9);
                            cout << "Ciudad ";
                            gotoxy(40,9);
                            cout << "Entidad ";
                            gotoxy(6,12);
                            cout << "Telefono ";
                            gotoxy(6,15);
                            cout << "Correo                    @ ";
                            gotoxy(6,18);
                            cout << "Carrera ";

                            do{
                                    SetColorAndBackground(colorletras2,colorfondo);
                                    dibujartabla(15,5,69,7);
                                    dibujartabla(15,8,34,10);
                                    dibujartabla(48,8,69,10);
                                    dibujartabla(15,14,50,16);
                                    dibujartabla(15,17,69,19);
                                    dibujartabla(15,11,29,13);
                                    dibujartabla(55,11,69,13);

                                    SetColorAndBackground(16,colorfondo);
                                    gotoxy(17,9);
                                    cout << lineas[4]; //ciudad
                                    gotoxy(50,9);
                                    cout << lineas[5]; //entidad
                                    gotoxy(17,15);
                                    cout << lineas[7]; //correo 1
                                    gotoxy(37,15);
                                    cout << lineas[8]; //correo 2
                                    gotoxy(17,12);
                                    cout << lineas[6];//telefono
                                    gotoxy(17,18);
                                    cout << lineas[13]; //carrera
                                    gotoxy(17,6);
                                    cout << lineas[1]; //nombre
                                    gotoxy(35,6);
                                    cout << lineas[2]; //apellido 1
                                    gotoxy(55,6);
                                    cout << lineas[3]; //apellido 2
                                    gotoxy(40,9);
                                    cout << "Entidad ";
                                    gotoxy(35,12);
                                    cout << "Fecha de Nacimiento";
                                    gotoxy(59,12);
                                    cout << "/  /";
                                    gotoxy(57,12);
                                    cout << lineas[10];
                                    gotoxy(60,12);
                                    cout << lineas[11];
                                    gotoxy(63,12);
                                    cout << lineas[12];
                                    if(posicionil==0){
                                    colorsi1=colorletras1;
                                    colorsil2=colorletras2;
                                    colorsil3=colorletras2;
                                    }
                                    if(posicionil==1){
                                        colorsi1=colorletras2;
                                        colorsil2=colorletras1;
                                        colorsil3=colorletras2;
                                    }
                                    if(posicionil==2){
                                        colorsi1=colorletras2;
                                        colorsil2=colorletras2;
                                        colorsil3=colorletras1;
                                    }
                                    SetColorAndBackground(colorsi1,colorfondo);
                                    rectangulo(86,5);
                                    gotoxy(89,6);
                                    cout << "Editar Datos";
                                    SetColorAndBackground(colorsil2,colorfondo);
                                    rectangulo(86,8);
                                    gotoxy(88,9);
                                    cout << "Ver Todos los Perfiles";
                                    SetColorAndBackground(colorsil3,colorfondo);
                                    rectangulo(86,11);
                                    gotoxy(89,12);
                                    cout << "Cerrar Sesion";
                                    if(posicionil==0){
                                        SetColorAndBackground(colorletras1,colorfondo);
                                        gotoxy(83,6);
                                        cout << "-->";
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,9);
                                        cout << "-->";
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,12);
                                        cout << "-->";
                                    }
                                    if(posicionil==1){
                                        SetColorAndBackground(colorletras1,colorfondo);
                                        gotoxy(83,9);
                                        cout << "-->";
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,6);
                                        cout << "-->";
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,12);
                                        cout << "-->";
                                    }
                                    if(posicionil==2){
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,9);
                                        cout << "-->";
                                        SetColorAndBackground(colorfondo,colorfondo);
                                        gotoxy(83,6);
                                        cout << "-->";
                                        SetColorAndBackground(colorletras1,colorfondo);
                                        gotoxy(83,12);
                                        cout << "-->";
                                    }

                                    tecla=getch();

                                    if (tecla==115 || tecla==80){
                                        if(posicionil<2)
                                            posicionil++;
                                    }
                                    if (tecla==119 || tecla==72){
                                        if(posicionil>0)
                                            posicionil--;
                                    }

                                    if(posicionil==0 && tecla==ENTER){
                                    int posicionn=0, colorr=12, colorr2=7, colorr3=7, colorr4=7, colorr5=7;
                                    string contranueva;
                                    SetColorAndBackground(7,5);
                                    for(int i=27;i<=92;i++){
                                        for(int y=3;y<=20;y++){
                                            gotoxy(i,y);
                                            cout << " ";
                                        }
                                    }
                                    gotoxy(45,4);
                                    cout << "Editando/Actualizando Datos... ";
                                    try{
                                        do{
                                            SetColorAndBackground(colorr,5);
                                            dibujartabla(54,6,69,8);
                                            dibujartabla(70,6,86,8);
                                            gotoxy(29,7);
                                            cout << "Editar Ciudad y Entidad";
                                            SetColorAndBackground(colorr2,5);
                                            dibujartabla(54,9,86,11);
                                            gotoxy(29,10);
                                            cout << "Editar Telefono";
                                            SetColorAndBackground(colorr3,5);
                                            dibujartabla(54,12,68,14);
                                            dibujartabla(72,12,86,14);
                                            gotoxy(29,13);
                                            cout << "Editar Correo";
                                            gotoxy(70,13);
                                            cout << "@";
                                            SetColorAndBackground(colorr4,5);
                                            dibujartabla(54,15,86,17);
                                            gotoxy(29,16);
                                            cout << "Editar Contrase\244a";
                                            gotoxy(28,17);
                                            cout << "*6 Caracteres o Numeros*";
                                            SetColorAndBackground(colorr5,5);
                                            dibujartabla(51,18,71,20);
                                            gotoxy(53,19);
                                            cout << ">Salir de Editar<";

                                            tecla=getch();

                                            if (tecla==115 || tecla==80){
                                                if(posicionn<4)
                                                    posicionn++;
                                            }
                                            if (tecla==119 || tecla==72){
                                                if(posicionn>0)
                                                    posicionn--;
                                            }
                                            if (posicionn==0){
                                                colorr=colorletras1;
                                                colorr2=7;
                                                if(tecla==ENTER){
                                                    gotoxy(56,7);
                                                    ShowConsoleCursor(true);
                                                    SetColorAndBackground(16,5);
                                                    getline(cin,ciudad);
                                                    gotoxy(72,7);
                                                    getline(cin,entidad);
                                                    cin.ignore();
                                                    ShowConsoleCursor(false);
                                                }
                                            }
                                            if (posicionn==1){
                                                colorr=7;
                                                colorr2=colorletras1;
                                                colorr3=7;
                                                if(tecla==ENTER){
                                                    gotoxy(56,10);
                                                    ShowConsoleCursor(true);
                                                    SetColorAndBackground(16,5);
                                                    cin >> datos.telefono;
                                                    cin.ignore();
                                                    ShowConsoleCursor(false);
                                                }
                                            }
                                            if (posicionn==2){
                                                colorr2=7;
                                                colorr3=colorletras1;
                                                colorr4=7;
                                                if(tecla==ENTER){
                                                    gotoxy(56,13);
                                                    ShowConsoleCursor(true);
                                                    SetColorAndBackground(16,5);
                                                    cin >> datos.correo1;
                                                    gotoxy(74,13);
                                                    cin >> datos.correo2;
                                                    cin.ignore();
                                                    ShowConsoleCursor(false);
                                                }
                                            }
                                            if (posicionn==3){
                                                colorr3=7;
                                                colorr4=colorletras1;
                                                colorr5=7;
                                                if(tecla==ENTER){
                                                    gotoxy(56,16);
                                                    ShowConsoleCursor(true);
                                                    SetColorAndBackground(16,5);
                                                    cin >>setw(6)>> contranueva;
                                                    ShowConsoleCursor(false);
                                                }
                                            }
                                            if (posicionn==4){
                                                colorr4=7;
                                                colorr5=colorletras1;
                                            }
                                        }while(posicionn != 4 || tecla != ENTER);

                                                    for(int i=0;i<ciudad.size();i++){
                                                            if(isdigit(ciudad[i])!=0){
                                                                throw invalid_argument("! Datos incorrectos");
                                                            }
                                                            i++;
                                                    }
                                                    for(int i=0;i<entidad.size();i++){
                                                            if(isdigit(entidad[i])!=0){
                                                                throw invalid_argument("! Datos incorrectos");
                                                            }
                                                            i++;
                                                    }
                                                    for(int i=0;i<datos.telefono.size();i++){
                                                            if(isdigit(datos.telefono[i])==0){
                                                            throw invalid_argument("! Datos incorrectos");
                                                            }
                                                        i++;
                                                    }

                                                    editarbase(datos, nmatriculau, contranueva, ciudad, entidad);
                                                    leer(lineas, nmatriculau);
                                                    }catch(invalid_argument &msg5){
                                                    gotoxy(85,24);
                                                    cout<<msg5.what()<<endl;
                                                    }
                                        SetColorAndBackground(colorletras2,colorfondo);
                                        for(int i=27;i<=92;i++){
                                            for(int y=3;y<=20;y++){
                                                gotoxy(i,y);
                                                cout << " ";
                                            }
                                        }
                                        SetColorAndBackground(16,colorfondo);
                                        gotoxy(6,3);
                                        cout << "INFORMACION PERSONAL";
                                        for (int i=6;i<70;i++){
                                            gotoxy(i,4);
                                            cout << (char)196;
                                        }
                                        gotoxy(83,3);
                                        cout << "OPCIONES";
                                        for (int i=83;i<111;i++){
                                            gotoxy(i,4);
                                            cout << (char)196;
                                        }
                                    }

                                    if(posicionil==1 && tecla==ENTER){
                                        string archnum,nmatricula="3201";
                                        int numarch,numerodearchivos=0;
                                        ifstream base;
                                        base.open(nmatricula, ios::in);
                                        while (base.is_open()){
                                            base.close();
                                            int convint = atoi(nmatricula.c_str());
                                            convint=convint+1;
                                            numerodearchivos=numerodearchivos+1;
                                            nmatricula=to_string(convint);
                                            base.open(nmatricula, ios::in);
                                        }
                                        thread car(&cargando);
                                        car.join();

                                        SetColorAndBackground(16,colorfondo);
                                        thread th[numerodearchivos];

                                        system("cls");
                                        for(int i=0;i<numerodearchivos;i++){
                                            numarch=3201+i;
                                            archnum= to_string(numarch);
                                            th[i] = thread(&leertodos, archnum);
                                            Sleep(750);
                                            th[i].join();
                                        }
                                        system("pause");
                                        system("cls");
                                        SetColorAndBackground(7,5);
                                        for(int i=0;i<=119;i++){
                                            for(int y=22;y<=29;y++){
                                                gotoxy(i,y);
                                                cout << " ";
                                            }
                                        }
                                        titulobienvenido();
                                        SetColorAndBackground(7,5);
                                        gotoxy(6,27);
                                        cout << lineas[1]; //nombre
                                        gotoxy(70,25);
                                        cout << "Matricula No.";
                                        gotoxy(70,26);
                                        cout << nmatriculau; //matricula
                                        gotoxy(90,25);
                                        cout << "Fecha de Creacion";
                                        gotoxy(90,26);
                                        cout << lineas[9];
                                        SetColorAndBackground(16,colorfondo);
                                        gotoxy(6,3);
                                        cout << "INFORMACION PERSONAL";
                                        for (int i=6;i<70;i++){
                                            gotoxy(i,4);
                                            cout << (char)196;
                                        }
                                        gotoxy(83,3);
                                        cout << "OPCIONES";
                                        for (int i=83;i<111;i++){
                                            gotoxy(i,4);
                                            cout << (char)196;
                                        }
                                        SetColorAndBackground(16,colorfondo);
                                        gotoxy(6,6);
                                        cout << "Nombre ";
                                        gotoxy(6,9);
                                        cout << "Ciudad ";
                                        gotoxy(40,9);
                                        cout << "Entidad ";
                                        gotoxy(6,12);
                                        cout << "Telefono ";
                                        gotoxy(6,15);
                                        cout << "Correo                    @ ";
                                        gotoxy(6,18);
                                        cout << "Carrera ";
                                    }

                                    if(tecla==ESC || (posicionil==2 && tecla==ENTER)){
                                    int posicionn=0, colorr=12, colorr2=7;
                                    SetColorAndBackground(7,5);
                                    for(int i=27;i<=92;i++){
                                        for(int y=8;y<=15;y++){
                                            gotoxy(i,y);
                                            cout << " ";
                                        }
                                    }

                                    gotoxy(50,9);
                                    cout << "Deseas Cerrar tu Sesion?";
                                         do{
                                            SetColorAndBackground(colorr,5);
                                            dibujartabla(46,12,56,14);
                                            gotoxy(50,13);
                                            cout << "Si";
                                            SetColorAndBackground(colorr2,5);
                                            dibujartabla(65,12,75,14);
                                            gotoxy(69,13);
                                            cout << "No";

                                            tecla=getch();

                                            if (tecla==100 || tecla==77){
                                                if(posicionn==0)
                                                    posicionn++;
                                            }
                                            if (tecla==97 || tecla==75){
                                                if(posicionn==1)
                                                    posicionn--;
                                            }
                                            if (posicionn==0){
                                                colorr=colorletras1;
                                                colorr2=7;
                                                if (tecla==ENTER)
                                                    salir=1;
                                            }
                                            if (posicionn==1){
                                            colorr=7;
                                            colorr2=colorletras1;
                                            }
                                        }while(tecla!=ENTER);
                                        SetColorAndBackground(colorletras2,colorfondo);
                                        for(int i=27;i<=93;i++){
                                            for(int y=8;y<=15;y++){
                                                gotoxy(i,y);
                                                cout << " ";
                                            }
                                        }
                                    }
                            }while(salir!=1);
                            delete[] lineas;
                            contra2={};
                            system("cls");
                            SetColorAndBackground(7,5);
                                for(int i=0;i<=119;i++){
                                    for(int y=22;y<=29;y++){
                                        gotoxy(i,y);
                                        cout << " ";
                                    }
                                }
                            gotoxy(6,24);
                            cout<<"_ _  _ _ ____ _ ____ ____    ____ ____ ____ _ ____ _  _"<<endl;
                            gotoxy(6,25);
                            cout<<"| |\\ | | |    | |__| |__/    [__  |___ [__  | |  | |\\ |"<<endl;
                            gotoxy(6,26);
                            cout<<"| | \\| | |___ | |  | |  \\    ___] |___ ___] | |__| | \\|"<<endl;
                            gotoxy(5,1);
                            cout<< "< ESC" << endl;
                        }else{
                            contra2={};
                            gotoxy(59,12);
                            cout << "        ";
                            throw "Datos incorrectos";
                        }
                        }catch(Archivos& msg){
                            gotoxy(48,20);
                            cout<<msg.what()<<endl;
                        }catch(const char *msg2){
                            gotoxy(53,16);
                            cout<<msg2<<endl;
                        }
                    }
                }
            }while(tecla!=ESC);
            SetColorAndBackground(colorfondo,colorfondo);
            for(int i=0;i<=120;i++){
                for(int y=8;y<=29;y++){
                    gotoxy(i,y);
                    cout << " ";
                }
            }
            titulo();
        }
        if (posicion==2 && tecla==ENTER){
            system("cls");
             SetColorAndBackground(7,5);
                for(int i=0;i<=119;i++){
                    for(int y=22;y<=29;y++){
                        gotoxy(i,y);
                        cout << " ";
                    }
                }
                SetColorAndBackground(16,colorfondo);
                gotoxy(38,2);
                cout<<" __  __  ______  ____     __  __"<<endl;
                gotoxy(38,3);
                cout<<"/\\ \\/\\ \\/\\  _  \\/\\  _`\\  /\\ \\/\\ \\ "<<endl;
                gotoxy(38,4);
                cout<<"\\ \\ \\ \\ \\ \\ \\L\\ \\ \\ \\/\\_\\\\ \\ \\_\\ \\" <<endl;
                gotoxy(38,5);
                cout<<" \\ \\ \\ \\ \\ \\  __ \\ \\ \\/_/_\\ \\  _  \\ "<< endl;
                gotoxy(38,6);
                cout<<"  \\ \\ \\_\\ \\ \\ \\/\\ \\ \\ \\L\\ \\\\ \\ \\ \\ \\ "<<endl;
                gotoxy(38,7);
                cout<<"   \\ \\_____\\ \\_\\ \\_\\ \\____/ \\ \\_\\ \\_\\"<<endl;
                gotoxy(38,8);
                cout<<"    \\/_____/\\/_/\\/_/\\/___/   \\/_/\\/_/"<<endl;
                gotoxy(46,10);
                cout << "Facultad de Ingenieria" << endl;

                gotoxy(46,12);
                cout << "Victor Gutierrez 320635" << endl;
                gotoxy(46,13);
                cout << "Roberto Nava     320832" << endl;
                gotoxy(46,14);
                cout << "Abraham Ibarra   320861" << endl;
                gotoxy(46,15);
                cout << "Uriel Gonzalez   320736" << endl;

                SetColorAndBackground(7,5);
                gotoxy(6,24);
                cout<<"____ ____ ____ ____ ____ ____    ___  ____ "<<endl;
                gotoxy(6,25);
                cout<<"|__| |    |___ |__/ |    |__|    |  \\ |___ "<<endl;
                gotoxy(6,26);
                cout<<"|  | |___ |___ |  \\ |___ |  |    |__/ |___ "<<endl;
                gotoxy(5,1);
                cout<< "< ESC" << endl;
            do{
                tecla=getch();
            }while(tecla!=ESC);
            SetColorAndBackground(colorfondo,colorfondo);
            for(int i=0;i<=120;i++){
                for(int y=8;y<=29;y++){
                    gotoxy(i,y);
                    cout << " ";
                }
            }
            titulo();
        }
        if (posicion==3 && tecla==ENTER){
            e=1;
            system("cls");
            titulo();
            gotoxy(35,17);
            cout<<"C I E N C I A S   D E   L A   C O M P U T A C I O N"<<endl;
            gotoxy(6,26);
            system("pause");
            gotoxy(0,28);
            cout<<"_____________________________________________________________"<<endl;
            SetColorAndBackground(colorfondo,colorfondo);
        }
    }while(e!=1);
}

int main()
{
    SetWindow(120,30);
    ShowConsoleCursor(false);
    menu();
    return 0;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void SetColorAndBackground(int ForgC, int BackC){

     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

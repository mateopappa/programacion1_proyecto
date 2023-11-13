#include <iostream>
#include <string.h>
using namespace std;

struct fecha
{
    int anio;
    int mes;
    int dia;
};
struct datosCandidatos
{
    char nombre[20];
    char apellido[20];
    fecha fecha_1;
    char partidoPol[20];
    int dni;
    int votos_recibidos;
    int edad;
    char sexo;
};

struct datosElectores
{
    char nombre[20];
    char apellido[20];
    fecha fecha_2;
    int dni;
    int edad;
    char sexo;
};
void menu1()
{
    cout << '\n';
    cout << "------BIENVENIDO AL SISTEMA ELECTORAL 2023------" << endl;
    cout << '\n'
         << endl;
    cout << "------Por favor, seleccione una opción: " << endl;
    cout << "-------1 Ingresar nuevo/s candidato/s       " << endl;
    cout << "-------2 Listar candidatos ya ingresados    " << endl;
    cout << "-------3 Eliminar Candidato                 " << endl;
    cout<<  "-------4 Continuar proceso con carga del electorado y votos "<<endl;
}
bool existe (int dni, datosCandidatos x[],int n){
    for (int i = 0; i < n; i++)
    {
        if(dni== x[i].dni){
            return 1;
        }
    }
    return 0;
    
}
void calculo_de_edad_candidatos (datosCandidatos A[], int n_cand, int diaAct, int mesAct, int anioAct){
	int i;

    for (i=0;i<n_cand;i++){
        if (A[i].fecha_1.mes < mesAct){	//aca ya cumplio
	        A[i].edad = anioAct - A[i].fecha_1.anio;
        }
        else if (A[i].fecha_1.mes == mesAct){	    //aca estamos en el mes de cumple
            if (A[i].fecha_1.dia <= diaAct)   
            {		
	        A[i].edad = anioAct - A[i].fecha_1.anio; //ya cumplio
	        }
	        else {		
	        A[i].edad= (anioAct- A[i].fecha_1.anio) - 1; //no cumplio pero esta en el mes del cumple 
            }
        }
        else if (A[i].fecha_1.mes > mesAct){	//aca todavia no cumplio anios
            A[i].edad= ( anioAct - A[i].fecha_1.anio) - 1;
        }
        
    }
}
void calculo_de_edad_votantes (datosElectores X[], int n_vot, int diaAct, int mesAct, int anioAct){
	int i;

    for (i=0;i<n_vot;i++){
        if (X[i].fecha_2.mes < mesAct){	//aca ya cumplio
	        X[i].edad = anioAct - X[i].fecha_2.anio;
        }
        else if (X[i].fecha_2.mes == mesAct){	    //aca estamos en el mes de cumple
            if (X[i].fecha_2.dia <= diaAct)   
            {		
	        X[i].edad = anioAct - X[i].fecha_2.anio; //ya cumplio
	        }
	        else {		
	        X[i].edad= (anioAct- X[i].fecha_2.anio) - 1; //no cumplio pero esta en el mes del cumple 
            }
        }
        else if (X[i].fecha_2.mes > mesAct){	//aca todavia no cumplio anios
            X[i].edad= ( anioAct - X[i].fecha_2.anio) - 1;
        }
        
    }
    
}
    
int main()
{
    int dni_busqueda_cand, n_cand;

    datosCandidatos cand[100];
    datosElectores elec[100];
    int opcion1;

    do{
    menu1();
    cin >> opcion1;
    switch (opcion1)
    {
    case 1:
        cout << "Agregando nuevo candidato..." << endl;
       
        break;

    case 2:
        
        break;

    case 3:
        cout << "Ingrese el dni del candidato a eliminar " << endl;
        cin>> dni_busqueda_cand;
        busqueda(cand, n_cand, dni_busqueda_cand);
        break;

    default:
        if (opcion1 != 4)
        {
            cout << "Elija una opcion valida" << endl;
        }

        break;
    }
}
while (opcion1 != 4) s
    ;
}
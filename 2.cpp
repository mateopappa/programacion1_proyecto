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
    char sexo [1];
};

struct datosElectores
{
    char nombre[20];
    char apellido[20];
    char voto_realizado [20];
    fecha fecha_2;
    int dni;
    int edad;
    char sexo [1];
};
void menu1()
{
    cout << '\n';
    cout << "------BIENVENIDO AL SISTEMA ELECTORAL 2023------" << endl;
    cout << '\n';
    cout << "------Por favor, seleccione una opción: " << endl;
    cout << "-------1 Ingresar nuevo/s candidato/s: " << endl;
    cout << "-------2 Ingresar nuevo/s candidato/s: " << endl;
    cout << "-------3 Listar candidatos ya ingresados:" << endl;
    cout<<  "-------4 Buscar votante con DNI: "<<endl;
    cout<<  "-------5 Buscar candidato con DNI: "<<endl;
    cout<<  "-------6 Candidatos menores a 50 años: "<<endl;
    cout<<  "-------7 Lista de candidatos en orden: "<<endl;
    cout<<  "-------8 Cerrar programa. "<<endl;
}

bool existe1 (int dni, datosCandidatos x[],int n){
    for (int i = 0; i < n; i++)
    {
        if(dni== x[i].dni){
            return 1;
        }
    }
    return 0;
    
}

void buscar_candidatos (datosCandidatos cand[], int n_cand, int buscar_dni){
    int i, band=0;

    for (i=0;i<n_cand;i++){
        if (cand[i].dni == buscar_dni){
            cout<<"El numero de votantes que tiene es: "<<cand[i].votos_recibidos<<endl;   // cargar numero de votos;
            band=1;
            break;
        }else if (band==0){
            cout<<"No hay candidatos con ese dni."<<endl;
        }
    }
    

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

void agregar_cand (datosCandidatos cand[], int n_cand){     //candidatos
    int i;

    cout<<"---CANDIDATOS---"<<endl;

    for (i=0;i<n_cand;i++){
        do
        {
            cout<<"Ingrese el nombre: "<<endl;
            cin.getline(cand[i].nombre,20,'\n');
            
            cout<<"Ingrese el apellido: "<<endl;
            cin.getline(cand[i].apellido,20,'\n');

            cout<<"Ingrese el sexo (m,f): "<<endl;
            cin.ignore();
            cin.getline(cand[i].sexo,1,'\n');
            
            cout<<"Ingrese el dni: "<<endl;
            cin>>cand[i].dni;
            
            cout<<"Ingrese el partido politico: "<<endl;
            cin.getline(cand[i].partidoPol,20,'\n');

            cout<<"Ingrese la fecha de nacimiento: (d/m/a)"<<endl;
            cin>>cand[i].fecha_1.dia;
            cin>>cand[i].fecha_1.mes;
            cin>>cand[i].fecha_1.anio;

        } while (existe1 (cand[i].dni, cand, n_cand)== 1);
        
        
    }
}

void mostrar_candidatos (datosCandidatos cand[], int n_cand){
    int i;
    for (i=0; i<n_cand; i++){
        cout<<"Nombre: "<<cand[i].nombre<<"Apellido: "<<cand[i].apellido<<" Partido P: "<<cand[i].partidoPol<<endl;
        cout<<"\n";
    }
}

void cand_menores50 (datosCandidatos cand[], int n_cand){
    int i;
    for (i=0; i<n_cand; i++){
        if ( cand[i].edad < 50) {
            cout<<"Los candidatos menores de 50 son: " <<endl;
            cout<<cand[i].nombre<<endl;
            cout<<cand[i].apellido<<endl;
            cout<<cand[i].dni<<endl;
            cout<<cand[i].edad<<endl;
            cout<<cand[i].fecha_1.dia<<"/"<< cand[i].fecha_1.mes<<"/" << cand[i].fecha_1.anio<<endl;
            cout<<cand[i].partidoPol<<endl;
            cout<<cand[i].votos_recibidos<<endl;
        }
    }
}

//votantes//

bool existe2 (int dni, datosElectores elec[],int n_elec){
    for (int i = 0; i < n_elec; i++)
    {
        if(dni== elec[i].dni){
            return 1;
        }
    }
    return 0;
    
}

void buscar_electores (datosElectores elec[], int n_elec, int buscar_dni){
    int i, band=0;

    for (i=0;i<n_elec;i++){
        if (elec[i].dni == buscar_dni){
            cout<<"La edad del votante es: "<<elec[i].edad<<endl;
            cout<<"Y voto por: "<<elec[i].nombre<<endl;
            band=1;
            break;
        }else if (band==0){
            cout<<"No hay votantes con ese dni."<<endl;
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

void agregar_elec (datosElectores elec[], int n_elec){     //electores
    int i;

    cout<<"---VOTANTES---"<<endl;

    for (i=0;i<n_elec;i++){
        do{        
            cout<<"Ingrese el nombre: "<<endl;
            cin.getline(elec[i].nombre,20,'\n');
            
            cout<<"Ingrese el apellido: "<<endl;
            cin.getline(elec[i].apellido,20,'\n');

            cout<<"Ingrese el sexo (m,f): "<<endl;
            cin.getline(elec[i].sexo,1,'\n');
            
            cout<<"Ingrese el dni: "<<endl;
            cin>>elec[i].dni;
            
            cout<<"Ingrese el nombre del candidato a votar: "<<endl;
            cin.getline(elec[i].voto_realizado,20,'\n');

            cout<<"Ingrese la fecha de nacimiento: (d/m/a)"<<endl;
            cin>>elec[i].fecha_2.dia;
            cin>>elec[i].fecha_2.mes;
            cin>>elec[i].fecha_2.anio;
        }while (existe2 (elec[i].dni, elec, n_elec)== 1);
        
    }
}

int main()
{
    int buscar_dni, n_cand, n_elec;

    datosCandidatos cand[100];
    datosElectores elec[100];
    int opcion1;

    do{
    menu1();
    cin >> opcion1;
    cin.ignore();
    switch (opcion1)
    {
    case 1:
        cout << "Agregando nuevo candidato..." << endl;
        agregar_cand (cand, n_cand);
        break;

    case 2:
        cout << "Agregar nuevo votante... " << endl;
        agregar_elec ( elec, n_elec);
        break;

    case 3:
        cout<<"Lista de candidatos ya inscriptos:"<<endl;
        mostrar_candidatos(cand, n_cand);
        break;

    case 4:
        cout<< "Ingrese el dni del votante: " << endl;
        cin>> buscar_dni;
        buscar_electores (elec, n_elec, buscar_dni);
        break;

    case 5:
        cout<< "Ingrese el dni del candidato: " << endl;
        cin>> buscar_dni;
        buscar_candidatos (cand, n_cand, buscar_dni);
        break;
    
    case 6:
        cout<<"Candidatos menores de 50: "<<endl;
        cand_menores50 (cand, n_cand);
        break;
    
    case 7:
        cout<<"Puestos de los candidatos: "<<endl;

        break;
    default:
        if (opcion1 != 8)
        {
            cout << "Elija una opcion valida" << endl;
        }

        break;
    }
}
while (opcion1 != 8);
}

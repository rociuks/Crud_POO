#include "Estudiante.cpp"
#include <iostream>

using namespace  std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_aux.dat";
int opc = 0;

	void menu();
	void crear();
	void leer();
	void actualizar();
	void delete_line();

int main(){
menu();
}

	string codigo, nombres, apellidos, direccion;
	int telefono;
	
	
	void menu(){
	system("cls");
	
		cout<<"1. Insertar estudiante"<<endl;
		cout<<"2. Ver estudiantes"<<endl;
		cout<<"3. Actualizar estudiante"<<endl;
		cout<<"4. Eliminar estudiante"<<endl;
		cout<<"5. Salir"<<endl<<endl;
		cout<<"Digite su opcion: ";
		cin>>opc; 
		
		system("cls");
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: delete_line();	 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
}

	void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");
		}
		
		Estudiante estudiante;
		int id=0;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<codigo<<"|"<<nombres<<"|"<<apellidos<<"|"<<direccion<<"|"<<telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
		system("pause");
		
		menu();	
}

	void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	
	int id;
	Estudiante estudiante;
	
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
	cout<<"Ingrese el Codigo: ";
		cin>>codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombres);
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellidos);
		cout<<"Ingrese los Direccion: ";
		getline(cin,direccion);
		cout<<"Ingrese el Telefono: ";
		cin>>telefono;
		cin.ignore();
		
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}

	void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo: ";
		cin>>codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombres);
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellidos);
		cout<<"Ingrese los Direccion: ";
		getline(cin,direccion);
		cout<<"Ingrese el Telefono: ";
		cin>>telefono;
		cin.ignore();
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n): ";
		cin>>continuar;
		
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}

void delete_line(){
 	
	FILE *archivo, *archivo_temp; 
	int codigo; 
	Estudiante estudiante; 
	
	archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	                      				                
	cout<<"codigo del estudiante a eliminar:"<<endl; 
	cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			if (codigo != codigo) 
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	
	leer(); 

}

	Estudiante c = Estudiante(nombres, apellidos, direccion, telefono, codigo);




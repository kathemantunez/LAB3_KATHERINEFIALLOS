#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;

void e1();
void e3();
void e2();
int* crearArray(int);
int* leerElementos(int*,int);
void printArray(int*,int);
int juego(int*,string);
void metodo1(int*, int,int,int);
void metodo2(int*,int,int);
void imprimir(int*,int);
int main()
{
    bool bandera=true;
    char tecla;
 
    do
    {
      
       
        cout << "\tLAB 3" << endl;
        cout << "\t-----------" << endl << endl;
        cout << "\t1 .- EJERCICIO 1" << endl;
        cout << "\t2 .- EJERCICIO 2" << endl;
        cout << "\t3 .- EJERCICIO 3" << endl;
        cout << "\t4 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
		{
			case '1':
					
				e1();
				
				break;
 
			case '2':
				cout<<"op 2"<<endl;	
				e2();
	
				break;
 
			case '3':
			
				cout<<"op 3"<<endl;
				e3();
				break;
 
			case '4':
				bandera=false;
				//exit(1);
				break;
 
			default:
				
				cout << "Opcion no valida.\a\n";
				
				break;
		}
    }while(bandera!=false);
 
    return 0;

}

void e2(){
	string polinomio;
	cout<<"ingrese el polinomio a factorizar: "<<endl;

	cin>>polinomio;




}

void e3(){

	int size;
	int* array;
	cout<<"ingrese el tamaño:"<<endl;
	cin>>size;	

	array=crearArray(size);
	array=leerElementos(array,size);
	
	int array_size=sizeof(array)/sizeof(array[0]);
	cout<<"arreglo"<<endl;
	imprimir(array,array_size);
	metodo2(array,0,array_size-1);
	cout<<"sorteo"<<endl;
	imprimir(array,array_size);
	
	

}	
void metodo1(int* array, int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 int L[n1], R[n2];   
    for (i = 0; i < n1; i++){
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = array[m + 1+ j];
    }
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1)
    {
       array[k] = L[i];
        i++;
        k++;
    }
 
    
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}




void metodo2(int* array, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
  
        metodo2(array, l, m);
        metodo2(array, m+1, r);
 
        metodo1(array, l, m, r);
    }
}


void imprimir(int* Arreglo, int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d ", Arreglo[i]);
    }

    printf("\n");
}
 


void e1(){
	
int* array_p;
int size=5;


array_p=crearArray(size);

array_p=leerElementos(array_p,size);

printArray(array_p,size);
int cont=0;
string cadena;
while(cont<=5){
	cout<<"ESTE SU TURNO "<<cont<<endl;
	cout<<"ingrese la cadena de numeros:"<<endl;
	cin>>cadena;
	int size_cadena=cadena.length();
	
	while(size_cadena!=5){
	cout<<"tamaño incorrecto, ingrese de nuevo"<<endl;
	cin>>cadena;
	size_cadena=cadena.length();
	}




	cont++;
	int opcion=juego(array_p,cadena);

}



}

int juego(int* array, string cadena){
	int temp2,temp1;
	char x,z;
	string tempo;
	int cont=0;
	

	//pasar arreglo a string 
	string r = "";
	/*
  	for (int temp = 0; temp <=5 ; temp++){
    	r += itoa(array[temp]);
	}
	if(r.compare(cadena)==0){
		cout<<"adivino todos los numeros"<<endl;
	}

	   */
	for(int i=0;i<=5;i++){
		temp1=array[i];
		
		for(int y=0;y<=cadena.length();y++){
			tempo=cadena[y];
			temp2=atoi(tempo.c_str());
			

			if(temp2==temp1){
				cont++;
			}
			
		}
	}
	cout<<"coinciden  "<< cont-1<<" digitos"<<endl;


return 0;
}


int* crearArray(int size){
	int* retvalue=new int [size];
	return retvalue;
}
int* leerElementos(int* array,int size){
	int num, c;
    srand(time(NULL));
    
    for(c = 1; c <= size; c++)
    {
        num = 1 + rand() % (10 - 1);
        array[c]=num;
    }
    return array;
}


void printArray(int* array, int size){
	for (int i=0;i<size;i++){

	cout<<" "<<array[i];
	}
	cout<<endl;
}


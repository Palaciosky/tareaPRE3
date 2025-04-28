/*

Programa que permite el registro de las N notas de los M alumnos, permite tambien la busqueda de un registro en especifico.

Programa que mediante el uso de arreglos, matrices, ciclos repetitivos, realiza las funciones desarrolladas arriba.

*/


/*
C. “Determinar el promedio Global de la clase”: se deberá de sumar las notas de cada uno 
de los alumnos calcular los promedios individuales y posteriormente calcular el promedio 
global de la clase, el cual deberá ser mostrado como salida de esta opción. 
● D. “Determinar los 3 primeros lugares de la clase”: tomando como referencia el 
procedimiento para calcular el promedio individual del literal c, determinar aquellos 3 
estudiantes que han obtenido el mayor promedio individual. Para los cuales deberá 
mostrarse el nombre, y el promedio obtenido por el alumno. 
● Tiene la libertad completa para lograr realizar las funcionalidades solicitadas de la forma 
que usted considere conveniente; sin embargo, debe de respetar las siguientes limitantes:
 
1. No puede modificar de ninguna forma los bloques de código de los literales “a”, “b”, y “e”. 
2. 3. 
No puede modificar los tipos de datos de los arreglos y matrices que ya se han establecido 
dentro del código. 
Puede añadir nuevas variables, arreglos y matrices, si lo considera necesario. 
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

try{
	    int n=0;  //Variable que para almacenar el numero de alumnos que se almacenaran.
    int m=0;  //Variable que almacenara la cantidad de notas a almacenar para cada uno de los N alumnos.
    char menu;
    int row; //Variables que almacenaran el indice de la fila, y por lo tanto del alumno.
    int col; //Variable que almaenara la posicion de la columna y por tanto de la nota,
    char resp; //Variable de respuesta para repeticion de bucle.
    bool existe; //Bandera para verificacion si el alumno existe.
    char continuar;
    int idx = 0;
    float suma, suma2, suma3,varprue, varprue2, sumar, suma4, ax, suma5;
    vector<float> elementos;
    string nombre; //Variable que servira para la busqueda de los nombres de los alumnos
    
	
			    cout<<"=========================================================="<<endl;
    cout<<"| Programa de Registro de Notas - Escuela Manguito Tierno |"<<endl;
    cout<<"=========================================================="<<endl;

    cout<<" Se procedera a registrar a los alumnos junto con sus notas"<<endl<<endl;
    cout<<"     !!DISSCLAIMER!! "<<endl;
    cout<<" Por favor ingrese la cantidad de Alumnos a registrar: "<<endl;
            cin>>n; //Se captura la variable N que determinara la cantidad de alumnos a procesar.
            cout<<"Ingrese Cuantas notas va a registrar por alumno: "<<endl;
            cin>>m; //Se captura la varibale M que determinara la cantidad de notas que se van a procesar para cada uno de los alumnos.
            
            string nombres[n]; //Arreglo de N posiciones que estara destinado para que se almecenen los nombres de cada uno de los alumnos
            float promedios[n]; //Arreglo de N posiciones que podra almacenar los promedios de cada uno de los alumnos
            float mi_arreglo[n][m];//Matriz de N filas (Una para cada alumno) y de M columnas (Una para cada una de las notas)
            system("cls");
            
 	  /*
            Se inicia el llenado de los datos, cada vez que se ejecute el ciclo externo, se registrara el nombre del alumno
            dentro del arreglo nombres[n] y tambien se van a llenar los datos de cada fila.

            Note que para emular el funcionamiento de los datos lo que se hace es recorrer el arreglo en cada una de sus posiciones, y al
            mismo tiempo para cada una de las posiciones del arreglo, se recorre cada fila de la matriz similar a lo que se muestra a continuacion

            Tome en cuenta que se ha ingresado los valores de 5 alumnos, y 5  notas 

            por lo tanto el proceso de llenado se realizara asi, para la iteracion #1 del ciclo externo


                +--------------+--------------+--------------+--------------+-------------+
                |Alumno1       |NULL          |NULL          |NULL          |NULL         |
                +--------------+--------------+--------------+--------------+-------------+

                Y para cada una de las iteraciones del ciclo interno se tendra

                |Iteracion 1   |Iteracion 2   |Iteracion 3   |Iteracion 4   |Iteracion 5
                    |               |               |               |               |
                    v               V               V               V               V
                +--------------+--------------+--------------+--------------+-------------+
                |5             |5             |5             |             5|           10|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                +--------------+--------------+--------------+--------------+-------------+

            para la iteracion #2 del ciclo externo

                +--------------+--------------+--------------+--------------+-------------+
                |Alumno1       |Alumno2          |NULL          |NULL          |NULL         |
                +--------------+--------------+--------------+--------------+-------------+

                Y para cada una de las iteraciones del ciclo interno se tendra

                |Iteracion 1   |Iteracion 2   |Iteracion 3   |Iteracion 4   |Iteracion 5
                    |               |               |               |               |
                    v               V               V               V               V
                +--------------+--------------+--------------+--------------+-------------+
                |5             |5             |5             |             5|           10|
                |10            |8             |7             |             9|            8|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                |NULL          |NULL          |NULL          |          NULL|         NULL|
                +--------------+--------------+--------------+--------------+-------------+

                Y asi sucesivamente hasta que los datos esten llenos por completo:

                para la iteracion #5 del ciclo externo

                +--------------+--------------+--------------+--------------+-------------+
                |Alumno1       |Alumno2       |Alumno3       |Alumno4       |Alumno5      |
                +--------------+--------------+--------------+--------------+-------------+

                Y para cada una de las iteraciones del ciclo interno se tendra

                |Iteracion 1   |Iteracion 2   |Iteracion 3   |Iteracion 4   |Iteracion 5
                    |               |               |               |               |
                    v               V               V               V               V
                +--------------+--------------+--------------+--------------+-------------+
                |5             |5             |5             |             5|           10|
                |10            |8             |7             |             9|            8|
                |10            |8             |7             |             9|            8|
                |10            |8             |7             |             9|            8|
                |10            |8             |7             |             9|            8|
                +--------------+--------------+--------------+--------------+-------------+


            */
            for(int i=0;i<n;i++) //<--- Note que en la definicion de este ciclo el limite de iteraciones es N, el numero de alumnos
            {
                cout<<"Ingrese el nombre del alumno ["<<i+1<<"]: ";
                cin>>nombres[i]; //Captura de los datos de los nombres de los alumnos para las N veces
                /*
                Cada vez que se ejecute el ciclo interno, se iran llenando las posiciones N,M de la columna de la iteracion
                por lo tanto se realizara el llenado de los datos de las notas cada fila de la matriz, equivale a las notas de un alumno
                por ejemplo la fila 1, equivale a las notas del alumno 1, etc...
                */
                for(int j=0;j<m;j++) //<--- Note que en la definicion de este ciclo el limite de iteraciones es M, el numero de notas
                {
                    cout<<"Ingrese la nota ["<<j+1<<"] del alumno ["<<i+1<<"] ("<<nombres[i]<<") : ";
                    cin>>mi_arreglo[i][j]; //Para cada una de las filas, se inicia la captura de datos de manera que, solamente se ingresen las notas
                }
                system("cls");
            }
            cout<<"Se ha terminado el ingreso de los alumnos y sus notas."<<endl<<endl;
            //Se finaliza el ciclo para el llenado de datos
do{		
		cout<<"================================================================"<<endl;
        cout<<"| Seleccione Una opcion Del menu que se presenta a continuacion:|"<<endl;
        cout<<"|a|. Buscar registro de Notas de alumnos"<<endl;
        cout<<"|b|. Ver Reporte de notas de TODOS los alumnos"<<endl;
        cout<<"|c|. Determinar Promedio Global de la Clase"<<endl;
        cout<<"|d|. Determinar los 3 primeros Lugares de la Clase"<<endl;
        cout<<"|e|. Salir del Sistema. \n"<<endl;
        cout<<"================================================================|"<<endl;
        cout<<"Ingrese la opcion seleccionada: ";
        
        cin>>menu;
        //	Condicion case que permite elegir las iteraciones que el shistema dispone
        switch(menu)
        {
            case 'a': 
                system("cls");
                //Ciclo necesario para la busqueda de las notas
                do{
                      //Proceso para la busqueda de notas de un alumno en especifico
                        cout<<"Ingrese nombre para buscar datos: ";
                        cin>>nombre; //Se captura el nombre del alumno que se va a buscar.
                        /*
                            Hay que tener en cuenta que para buscar un valor en el arreglo, hay que recorrer todo el mismo, por lo tanto,
                            se debe iterar con un ciclo FOR
                        */
                    for(int i=0;i<n;i++)
                    {
                        //Se comienza a buscar los nombres dentro del arreglo iterando
                        if(nombre==nombres[i]) //Si hay coincidencia entre lo que el usuario ingreso, y el nombre de un alumno
                        {
                            existe=true; //Se activa la bandera a TRUE
                            cout<<"Alumno detectado en posicion: ["<<i<<"] \n"; //Se obtiene el indice en donde esta la coinciden
                            cout<<"|\t";
                            for(int j=0;j<m;j++)
                                cout<<mi_arreglo[i][j]<<"\t | \t"; //Esto solo se va a ejecutar para el ciclo especifico en donde ocurra la coincidencia
                            cout<<endl<<endl;
                            break;//Rompe el ciclo for, para no seguir iterando
                        }
                        else //Si no hay coincidencia entonces la bandera se mantiene en falso
                        {
                            existe = false;
                        }
                    }
                    if(existe==false) //Si la bandera se ha mantenido en falso, se muestra el mensaje al usuario
                    {
                      cout<<"No existe el alumno"<<endl<<endl;
                    }
                    cout<<"Si desea consultar otro registro presione cualquier tecla, de lo contrario, la tecla N o n...";
                    cin>>resp;//Captura de variable para verificar la continuacion
                    system("cls");
                }while(resp !='n' && resp!='N');
            break;

            case 'b':
                    system("cls");
                    /*
                    Proceso para mostrar las notas de los alumnos registrados, note que para emular el funcionamiento, lo que se hace es
                    recorrer el arreglo de la misma forma que en el llenado, con la diferencia, que, ahora, lo que se hace es mostrar el valor
                    que se ha almacenado en cada uno de los registros anteriores
                    */
                    for(int i=0;i<n;i++)
                    {
                        cout<<"Notas de "<<nombres[i]<<": "<<endl<<endl;
                        cout<<"|\t";
                        for(int j=0;j<m;j++)
                        {
                            cout<<mi_arreglo[i][j]<<"\t |\t ";
                        }
                        cout<<endl<<endl;
                    }
            break;

            case 'c':
                //Para Calcular el promedio global de la clase, es necesario calcular el promedio individual de cada uno de los alumnos, y finalmente calcular el promedio global
                //Para el promedio individual, recuerde que se deben sumar las M notas coontenidas en cada una de las filas de la matriz y dividirlas entre M.
                //Escriba el codigo necesario para realizarlo.
                system("cls");
                for(int i=0;i<n;i++)
                    {
                       cout<<"|================================================================|"<<endl;
                       cout<<"Nota promedio de "<<nombres[i]<<": "<<endl<<endl;
                        for(int j=0;j<m;j++)
                        {
                        		suma2 = j+1;
                        	
                        	//cout<<mi_arreglo[i][j]<<"|\|"<<endl;
                        cout<<"| NOTA "<<suma2 <<":"<<mi_arreglo[i][j]<<endl;
						cout<<"|	"<<endl;
                        varprue2 = mi_arreglo[i][j];
						varprue += mi_arreglo[i][j];
                       
                           // cout<<"|sumatoria es "<<suma<<"|valor es i|"<<i<<"|valor j es |"<<suma2;
                        	
                        }
                        suma3 += varprue2;
                        	
                        cout<<endl<<endl;
                        
                        cout<<"| cantidad de calificaciones es "<<suma2<<endl;
                        cout<<"| total notas obtenidas 1 "<<varprue<<endl;
                        cout<<"| suma calif obtenidas |1| "<<varprue2<<endl;
						cout<<"| suma calif obtenidas |2| "<<suma3<<endl;
						cout<<"|================================================================|"<<endl;
						}
							suma2 += suma2;
							
						 cout<<endl<<endl;
						cout<<"prueba avr si sirve "<<suma3<<endl;	
						cout<<"================================================================"<<endl;
						cout<<"| Cantidad de calificaciones es "<<suma2<<endl;
                        cout<<"| Total notas obtenidas :"<<varprue<<endl;
                        cout<<"================================================================"<<endl;
						
            break;

            case 'd':
                // //Para Calcular el promedio global de la clase, es necesario calcular el promedio individual de cada uno de los alumnos, y finalmente en base al promedio de cada uno de estos
                // Se deberan ordenar de acuerdo a las notas para determinar cual de ellos son los 3 primeros lugares.
                 system("cls");// limpiar sys
				 for(int i=0;i<n;i++)
				 // ciclica anidada para recorrer la matriz, eso si para que sume solo                 
				 // la fila la variable debe estar siempre == 0, para que no se acumule y no de falsos positivco
                    {
                    	float varpruex = 0;
                    	float ax2 = 0;
                       
                       cout<<"Nota promedio de "<<nombres[i]<<": "<<endl<<endl;
                       
                        for(int j=0;j<m;j++)
                        {
                        	varpruex += mi_arreglo[i][j];
                        	ax2 = j+1;
								
                        }
                        	suma4 = varpruex/ax2;
                        	cout<<"TOTAL PROM: "<<"  "<<ax2<<"  "<<suma4<<endl;
                        	
                        	
                        	
						}
						
						
						
						 cout<<"|==========   3 MEJORES LUGARES     ============|"<<endl;
						  // ciclica anidada para recorrer la matriz, eso si para que sume solo                 
				 // la fila la variable debe estar siempre == 0, para que no se acumule y no de falsos positivco
				 
						 for (int i = 0; i < n; ++i) {
      						  for (int j = 0; j < m; ++j) {
         						   elementos.push_back(mi_arreglo[i][j]);
       							 }
   							 }						
				 		//Ordena el nuevo vector de mayor a menor
				 		sort(elementos.begin(), elementos.end(), [](float a, float b) {
        				return a > b;
   								 });
   								 
   					   	 
    						for (int i = 0; i < n; ++i) {
        						for (int j = 0; j < m; ++j) {
           						 mi_arreglo[i][j] = elementos[idx++];
        						}
    						}
				 	
						
						//osdjlkasndfklj
						
				 
						for(int i=0;i<3;i++)
                  		  {
                    	float varpruex2 = 0;
                    	float ax3 = 0;
                      
                       
                       //sort(varpruex2.begin(), varpruex2.end(), [](float a, float b) {
      					  //return a > b;
   						 //});
                        for(int j=0;j<m;j++)
                        {
                        	varpruex2 += mi_arreglo[i][j];
                        		ax3 = j+1;
								
                        }
                        	suma5 = varpruex2/ax3;
                        	cout<<"PROMEDIO ES DE: "<<" "<<suma5<<endl;
                        	
                        	
                        	
						}
						
						
                
						
            break;

            case 'e':
                    system("exit");
            break;

            default:
                cout<<"No se ha seleccionado una opcion Valida..."<<endl;
            break;

        }
        cout<<"Desea realizar otra operacion? Presione Cualquier Tecla, Salir presione n o N."<<endl;
        cin>>continuar;
        system("cls");
    }while(continuar!='n' && continuar!='N');
    cout<<"Gracias por utilizar el sistema..."<<endl<<endl;
}catch (const std::runtime_error& e) {
  // Code to handle the exception
  std::cerr << "Error: " << e.what() << std::endl;
}
    return 0;
}

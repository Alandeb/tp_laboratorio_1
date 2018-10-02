#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utn_abm.h"
/**
 * \brief escanea un entero y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
int getInt(int* pBuffer)
{
    fflush(stdin);
    return scanf("%d",pBuffer);
}
/**
 * \brief escanea un flotante y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
int getFloat(float* pBuffer)
{
    fflush(stdin);
    return scanf("%f",pBuffer);
}
/**
 * \brief escanea un caracter y lo guarda en un puntero
 * \param msg Mensaje a ser mostrado
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
    //gets(pBuffer);//lo intente con fgets pero no podia tomar el dato lo siento
}
/**
 * \brief escanea un caracter y lo guarda en un puntero
 * \param pBuffer puntero donde se va a guardar el dato
 * \return Retorna true o false dependiendo si scan consigue un dato
 *
 */
int getCaracter(char* pBuffer)
{
    fflush(stdin);
    return scanf("%c",pBuffer);
}
/** \brief indica que todas las posiciones del array estan
 *  habilitadas poniendo todas las banderas(isEmpty) en 1 o true
 * \param Employee empleado Lista,estructura del sistema de empleado
 * \param cantidad de veces que debe interar
 * \return no retorna nada es vacio
 */

void init(Employee* empleado,int cantidad){
    int i;
    for (i=0;i<cantidad;i++){
        empleado[i].isEmpty=1;
    }
}
/**
 * \brief Solicita un número al usuario para lograr alguna opcion
 * \return Retorna opcion numero que pide el menu
 *
 */
int menu(){
    int opcion;
    system("cls");
    printf("\tMENU");
    printf("\n\n1. Alta de personal ");
    printf("\n2. Modificacion");
    printf("\n3. Baja de personal ");
    printf("\n4. Informacion del personal ");
    printf("\n5. Salir");
    utn_getEntero(&opcion,"\n\n Seleccione opcion: ","\nOpcion incorrecta es entre 1 y 5: ",1,5);
    while(opcion==0)
        utn_getEntero(&opcion,"\nOpcion incorrecta es entre 1 y 5: ","\nOpcion incorrecta es entre 1 y 5: ",1,5);
    return opcion;
}
/**\brief agrega a la lista de empleados employee los datos coloca la bandera IsEmpty en 0
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addEmployee(Employee empleado[],int cantidad)
{
    int index,valSal,retorno=-1,valSec,valNom,valApe,i;
    char nombreAux[51],apellidoAux[51];
    char salida;
    index=obtenerEspacioLibre(empleado,cantidad);
    srand(time(NULL));
    if(index!=-1)
    {
        do{
            system("cls");
            printf("\tALTA\n\n");
            empleado[index].id=validRamdonNumber(empleado,cantidad);
            printf("ID aleatoria: %d\n",empleado[index].id);
            valApe=getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            valNom=getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            valSec=utn_getEntero(&empleado[index].sector,"Ingrese sector (1 a 25): ","ERROR!!, Reingrese el sector(1 a 25): ",1,25);
            while(empleado[index].sector==0){
                valSec=utn_getEntero(&empleado[index].sector,"ERROR!!, Reingrese el sector (1 a 25): ","ERROR!!, Reingrese el sector(1 a 25): ",1,25);
            }
            valSal=utn_getFloat(&empleado[index].salary,"Ingrese salario: ","ERROR!!, Reingrese el salario: ",1);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            strcpy(empleado[index].name,nombreAux);
            strcpy(empleado[index].lastName,apellidoAux);
            if(valApe==0&&valSec==0&&valSal==0&&valNom==0){
                system("cls");
                printEmployee(empleado,index);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }
        }while(salida!='s');
        empleado[index].isEmpty=0;
        retorno=0;
    }

    return retorno;

}
/** \brief imprime todos los datos de los empleados cada vez que se solicita
* \param Employee empleado Lista , estructra del sistema de empleados
* \param i Numero de posicion del empleado que se desea imprimir
* \return np retorno ningun valor
*
*/
void printEmployee(Employee* empleado,int i)
{
    printf("\nID: %d",empleado[i].id);
    printf("\tSector: S0%d",empleado[i].sector);
    printf("\tNombre:%s, %s",empleado[i].lastName,empleado[i].name);
    printf("\t\tSalario: $%.2f\n",empleado[i].salary);
}
/** \brief busca al empleado por el id en la estructura Employee
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \param id Numero del empleado buscado
* \return Retorna -1 si no encontro al empleado su no retorna la posicion del empleado buscado
*
*/
int findEmployeeById(Employee* empleado, int cantidad,int id)
{
    int i;
    for(i=0;i<cantidad;i++){
        if(id==empleado[i].id && empleado[i].isEmpty==0)
        {
            printf("\nEmpleado encontrado... \n\n");
            system("pause");
            return i;

        }
    }
    printf("Empleado no encontrado...\n\n");
    system("pause");
    return -1;
}
/** \brief modifica al empleado buscado primero preguntando que datos quiere cambiar o si desea salir
* \param Employee empleado Lista , estructra del sistema de empleados
* \param posID Numero del empleado que se desea modificar
* \return np retorno ningun valor
*
*/
void modificationEmployee(Employee* empleado,int posID)
{
    char apellidoAux[51],nombreAux[51];
    char salida;
    float salaryAux;
    int i,opcion,sectorAux;
    do{
    system("cls");
    printf("DATOS DEL EMPLEADO \n");
    printEmployee(empleado, posID);
    printf("\nQUE DESEA MODIFICAR");
    printf("\n\n1. Apellido \n");
    printf("2. Nombre\n");
    printf("3. Sector\n");
    printf("4. Salario\n");
    printf("5. Todas las opciones\n");
    printf("6. Salir");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\nERROR Seleccione una opcion valida: ",1,6);
    while(opcion==0)
        utn_getEntero(&opcion,"\nERROR Seleccione una opcion valida: ","\nERROR Seleccione una opcion valida: ",1,6);
    switch(opcion){
        case 1:
            getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            for(i=0;i<51;i++){
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(empleado[posID].lastName,apellidoAux);
                break;
            }
            break;
        case 2:
            getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(empleado[posID].name,nombreAux);
                break;
            }
            break;
        case 3:
            utn_getEntero(&sectorAux,"Ingrese sector (1 a 25): ","ERROR!!, Reingrese el sector(1 a 25): ",1,25);
            while(sectorAux==0){
                utn_getEntero(&sectorAux,"ERROR!!, Reingrese el sector(1 a 25): ","ERROR!!, Reingrese el sector(1 a 25): ",1,25);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                empleado[posID].sector=sectorAux;
                break;
            }
            break;
        case 4:
            utn_getFloat(&salaryAux,"Ingrese salario: ","ERROR!!, Reingrese el salario: ",1);
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                empleado[posID].salary=salaryAux;
                break;
            }
        case 5:
            getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            utn_getEntero(&sectorAux,"Ingrese sector (1 a 25): ","ERROR!!, Reingrese el sector: ",1,25);
            while(sectorAux==0){
                utn_getEntero(&sectorAux,"ERROR!!, Reingrese el sector(1 a 25): ","ERROR!!, Reingrese el sector(1 a 25): ",1,25);
            }
            utn_getFloat(&salaryAux,"Ingrese salario: ","ERROR!!, Reingrese el salario: ",1);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                empleado[posID].sector=sectorAux;
                empleado[posID].salary=salaryAux;
                strcpy(empleado[posID].name,nombreAux);
                strcpy(empleado[posID].lastName,apellidoAux);
                break;
            }
            break;
        case 6:
            system("cls");
            printf("Volviendo al menu principal...\n");
            system("pause");
            break;
        default:
            break;
    }
    }while(opcion !=6 );
}
/** \brief Remueve al empleado buscado por el id pone la bandera isEmpty en 1
*
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \param posID numero exacto donde se encuantra el dato buscado
* \return no retorna ningun valor
*
*/
void removeEmployee(Employee* empleado,int posID)
{
    char salida;
    printEmployee(empleado, posID);
    utn_getCaracter(&salida,"\n\nDesea eliminar el archivo del empleado S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
    if(salida=='s'){
        system("cls");
        printf("El empleado ha sido eliminado...\n\n");
        system("pause");
        empleado[posID].id=0;
        empleado[posID].isEmpty=1;
      }else{
        printf("Volviendo al menu...\n\n");
        system("pause");
    }
}
/** \brief Obtiene el espacio libre en la que la bandera isEmplty esta
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*
*/
int obtenerEspacioLibre(Employee empleado[] , int cantidad){
    int i, retorno;
    for (i=0;i<cantidad;i++){
        if(empleado[i].isEmpty==1){
            retorno=i;
            break;
        }
        if(i==cantidad){
            system("cls");
            retorno=-1;
            printf("Limite de registro alcanzado ");
            getch();
            break;
        }
    }
    return retorno;
}
/**
 * \brief Solicita un flotante  al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pFlotante Puntero donde se guardara el dato ingresado
 * \param min Minimo del numero entero que necesito como condicion
 * \return 0 si el enterp que ingresaron esta entre los numeros de condicion
 */
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min)
{
    int retorno=-1;
    float bufferFloat;
    char bufferFloatString[256];
    if(pFlotante != NULL && msg != NULL && msgErr != NULL&& min >= 1)
    {
        do
        {
            getString(msg,bufferFloatString);
            if( esNumerico(bufferFloatString))
            {
                bufferFloat = atof (bufferFloatString);
                if(bufferFloat >= min){
                    *pFlotante = bufferFloat;
                    retorno = 0;
                    break;
                }
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);
    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=','))
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Solicita un entero al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pEntero Puntero donde se guardara el dato ingresado
 * \param min Minimo del numero entero que necesito como condicion
 * \param max Maximo del numero entero que necesito como segunda condicion
 * \return 0 si el entero que ingresaron esta entre los numeros de condicion
 */
int utn_getEntero(  int* pEntero, char* msg,char* msgErr,int min, int max)
{
    int retorno=-1;
    int bufferInt;
    char bufferIntString[256];
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            getString(msg,bufferIntString);
            if( esNumerico(bufferIntString))
            {
                bufferInt = atoi(bufferIntString);
                if((bufferInt >= min && bufferInt <= max)){
                    *pEntero = bufferInt;
                    retorno = 0;
                    break;
                }
            }
            if(bufferInt==0)
                break;
            else
            {
                fflush(stdin);//limpia en linux como fflush
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pBuffer Array donde se cargará el texto ingresado
 * \return 0 si el texto contiene solo letras
 */
int getStringLetras(char* msg,char* msgErr,char* pBuffer)
{
    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esSoloLetras(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
/**
 * \brief Solicita un caracter al usuario ,lo valida  y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgErr Es el mensaje a ser mostrado si falla el primer ingreso
 * \param pCaracter char donde se cargará el texto ingresado
 * \param letraUno caracter que necesito como condicion
 * \param letraDos caracter que necesito como segunda condicion
 * \return 0 si el caracter que ingresaron en igual al que se colo como condicion
 */
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr,char letraUno,char letraDos)

{
    int retorno=-1,devuelve;
    char bufferChar;
    if( msg != NULL && msgErr != NULL&& (letraUno>=0||letraUno<=255)&& (letraDos>=0||letraDos<=255) )
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            devuelve=getCaracter(&bufferChar);
            bufferChar=tolower(bufferChar);
            if( ( devuelve == 1)&&(bufferChar == letraUno || bufferChar == letraDos))
            {
                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
/** \brief valida el numero ramdon y lo pide
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \return Retorna idAux numero id si no esta repetido
*/
int validRamdonNumber(Employee empleado[],int cantidad)
{
    int i,idAux;
     do{
            idAux=getNumeroAleatorio(1000,10000);
            for (i=0;i<cantidad;i++){
                if(empleado[i].id==idAux)
                  break;
                }
        }while(i!=cantidad);
    return idAux;
}
/**
 * \brief Solicita un número al usuario para lograr alguna opcion
 * \return Retorna opcion numero que pide el menu
 *
 */
int menuDos(){
    int opcion=0;
    system("cls");
    printf("\tLISTADO\n\n");
    printf("1. Listado de empleados.\n");
    printf("2. Total y promedio de los salarios\n");
    printf("3. Volver a atras");
    utn_getEntero(&opcion,"\n\n Seleccione opcion: ","\nOpcion incorrecta es entre 1 y 3: ",1,3);
    return opcion;
}
/** \brief Acomoda el array de empleados el order indica si de mayor a menor
*           o de menor a mayor
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \param order [1] indica de mayor a menor  - [0] indica de menor a mayor
* \return ino retorna ningun valor
*
*/
void sortEmployees(Employee empleado[], int cantidad ,int order){
    Employee empAux;
    int i,j;
    if(order==0){
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if(empleado[i].sector>empleado[j].sector){
                    empAux=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=empAux;
                }else
                    if(empleado[i].sector==empleado[j].sector){
                        if((stricmp(empleado[i].lastName,empleado[j].lastName))>0){
                            empAux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=empAux;
                        }
                }else
                    if((stricmp(empleado[i].lastName,empleado[j].lastName))==0){
                        if((stricmp(empleado[i].name,empleado[j].name))>0){
                            empAux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=empAux;
                        }
                    }


            }
        }
    }else{
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if(empleado[i].sector<empleado[j].sector){
                    empAux=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=empAux;
                }else
                    if(empleado[i].sector==empleado[j].sector){
                        if((stricmp(empleado[i].lastName,empleado[j].lastName))<0){
                            empAux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=empAux;
                        }
                }else
                    if((stricmp(empleado[i].lastName,empleado[j].lastName))==0){
                        if((stricmp(empleado[i].name,empleado[j].name))<0){
                            empAux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=empAux;
                        }
                    }

            }
        }
    }
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \return retorna el número aleatorio generado
 *
 */
int getNumeroAleatorio(int desde , int hasta)
{
    //srand(time(NULL));
    return desde + (rand() % (hasta +1-desde));
}


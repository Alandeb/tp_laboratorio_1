#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "utn_abm.h"
#define personal 1000

int main()
{
    Employee empleado[personal];
    int opcion,alta,flag=0,auxId,valID=-1,posicionID=-1,opcionDos,order,i,accountantAverage=0,accountantMedia=0;
    float promedio,salaryTotal=0;
    init(empleado,personal);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                alta=addEmployee(empleado,personal);
                if(alta==0&&flag==0)
                    flag=1;
                break;
            case 2:
                if(flag==1){
                    do{
                        system("cls");
                        printf("\tMODIFICACIONES\n\n");
                        valID=utn_getEntero(&auxId,"Ingrese ID del empleado que desea modificar,o ingrese 0 para volver al menu principal: ","ID incorrecto. Ingrese un id del 1000 al 10000 o 0 para salir: ",1000,10000);
                        if(valID==0)
                        {
                            posicionID=findEmployeeById(empleado,personal,auxId);
                            if(posicionID!=-1){
                                modificationEmployee(empleado,posicionID);
                                break;
                            }
                        }else
                            break;
                    }while(posicionID==-1);
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado\n");
                    system("pause");
                }
                break;
            case 3:
                if(flag==1)
                {
                    do{
                        system("cls");
                        printf("\tBAJA\n\n");
                        valID=utn_getEntero(&auxId,"Ingrese ID del empleado que desea remover,o ingrese 0 para volver al menu principal: ","ID incorrecto. Ingrese un id del 1000 al 10000 o 0 para salir",1000,10000);
                        if(valID==0)
                        {
                            posicionID=findEmployeeById(empleado,personal,auxId);
                                if(posicionID!=-1){
                                    removeEmployee(empleado,posicionID);
                                    break;
                                }
                        }else
                            break;
                    }while(posicionID==-1);
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado\n");
                    system("pause");
                }
                break;
            case 4:
                if(flag==1){
                    opcionDos=menuDos();
                    switch(opcionDos){
                        case 1:
                            system("cls");
                            utn_getEntero(&order,"INGRESE EL CRITERIO DE ORDENAMIENTO:  0(de menor a mayor) o 1 (de mayor a menor)  \n",
                                          "ERROR INGRESE EL CRITERIO DE ORDENAMIENTO: 0(de menor a mayor) o 1 (de mayor a menor)  \n",0,1);
                            sortEmployees(empleado,personal,order);
                            for(i=0;i<personal;i++){
                                if(empleado[i].isEmpty==0){
                                    printEmployee(empleado,i);
                                }
                            }
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            for(i=0;i<personal;i++){
                                if(empleado[i].isEmpty==0){
                                    salaryTotal=salaryTotal+empleado[i].salary;
                                    accountantAverage++;
                                }
                            }
                            promedio=salaryTotal/accountantAverage;
                            for(i=0;i<personal;i++){
                                if(empleado[i].salary>promedio&&empleado[i].isEmpty==0){
                                    accountantMedia++;
                                }
                            }
                            printf("Salario total: %.2f\tMedio de salarios: %.2f\tEmpleados que superan la media: %d\n",salaryTotal,promedio,accountantMedia);
                            system("pause");
                            break;
                        default:
                            break;
                    }
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado \n");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                printf("HASTA LUEGO");
                break;
            default:
                break;
        }
    }while(opcion!=5);
    return 0;
}

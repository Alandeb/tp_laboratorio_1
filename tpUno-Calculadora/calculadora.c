/**
 * \brief Solicita un número al usuario
 * \param operando Se carga el numero ingresado
 * \return Retorna el valor cargado
 *
 */
float ingreseNumero(float operando){
          system("cls");
          printf("Coloque un numero: ");
          scanf("%f",&operando);
          return operando;
}

/**
 * \brief Solicita un número al usuario del menu
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna opcion numero que pide el menu
 *
 */

int menu(float numeroUno,float numeroDos){
        int opcion;
        printf("MENU");
        printf("\n\n1. Ingresar 1er operando(A=%.2f)",numeroUno);
        printf("\n2. Ingresar 2do operando(B=%.2f)",numeroDos);
        printf("\n3. Calcular las operaciones");
        printf("\n4. Informar resultados");
        printf("\n5. Salir");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opcion);
        return opcion;

}
/**
 * \brief Solicita un caracter al usuario del menu
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna opcion caracter que pide el menu
 *
 */
char menuDos(float numeroUno,float numeroDos){
        char opcion;
        system("cls");
        printf("Calculos");
        printf("\n\nA) Suma de %.2f+%.2f",numeroUno,numeroDos);
        printf("\nB) Resta de %.2f-%.2f",numeroUno,numeroDos);
        printf("\nC) Producto de %.2f*%.2f",numeroUno,numeroDos);
        printf("\nD) division de %.2f/%.2f",numeroUno,numeroDos);
        printf("\nE) Factorial de %.0f!",numeroUno);
        printf("\nF) Factorial de %.0f!",numeroDos);
        printf("\nG) Hacer todos los calculos");
        printf("\n\n Seleccione opcion: ");
        //fflush(stdin);
        //scanf("%c",&opcion);
        opcion = getche();
        return opcion;
}
/**
 * \brief Solicita un número al usuario
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna resultado de la suma de los numeros
 *
 */
float suma(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno+numeroDos;
    return resultado;
}
/**
 * \brief Solicita un número al usuario
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna resultado de la resta de los numeros
 *
 */
float resta(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno-numeroDos;
    return resultado;
}
/**
 * \brief Solicita un número al usuario
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna resultado del producto de los numeros
 *
 */
float producto(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno*numeroDos;
    return resultado;
}
/**
 * \brief Solicita un número al usuario
 * \param numeroUno primer numero para mostrar en el sistema
 * \param numeroDos segundo numero para mostrar en el sistema
 * \return Retorna resultado la division  de los numeros
 *
 */
float dividir(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno/numeroDos;
    return resultado;
}
/**
 * \brief Solicita un número al usuario
 * \param numero  para poder igualarlo a otra variable
 * \return Retorna fact resultado del factorial
 *
 */
int factorial(int numero){
      int numeFact ,fact = 1;
      for (numeFact = numero; numeFact > 1; numeFact--){
            fact *=  numeFact;
       }
       return fact;
}

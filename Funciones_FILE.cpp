#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <time.h>
#include "Declaraciones_2.0.cpp"
#include "Struct_FinalProyecto.h"

struct temporalRecibo {//ESTRUCTURA PARA VENTAS

    char a[30];//NOMBRE DEL PRODUCTO
    int cantz;//CANTIDAD
    float unit;//PRECIO UNITARIO
    float priceT;//PRECIO TOTAL
    float inversion;//INVERSION

}na[10];//VARIABLE DE ESTRUCTURA

using namespace std;

void NuevoCliente() {// AGREGAR CLIENTE

    FILE *R, *V;//CREA LA VARIABLE DE ARCHIVO
    int retorno=0, enc;//VARIABLE DE RETORNO POR SI DESEA AGREGAR OTRO REGISTRO
    char code[30];

    do {//REGISTRAR OTRO CLIENTE

        system("cls");//LIMPIAR PANTALLA
        R=fopen("Clientes.txt", "ab");//ABRE EL ARCHIVO DE CLIENTES

        // SOLICITAS LOS DATOS QUE VAN A SER ALMACENADOS

        system("color 0B");

        do{//VERIFICA SI EL CODIGO YA EXISTE

            V=fopen("Clientes.txt", "r");//ABRE EL ARCHIVO EN MODO LECTURA PARA VERIFICAR SI EL CODIGO EXISTE

        gotoxy(31, 6);
        printf("\t============================================================\n");
        gotoxy(31, 7);
        printf("\t||                    COMPUTECNO S.A                      ||\n");
        gotoxy(31, 8);
        printf("\t============================================================\n");
        gotoxy(31, 9);
        printf("\t||     R E G I S T R A N D O  N U E V O  C L I E N T E    ||\n");
        gotoxy(31, 10);
        printf("\t============================================================\n");
        gotoxy(31, 11);
        printf("\t|| NOMBRE DEL CLIENTE |                                   ||\n");
        gotoxy(31, 12);
        printf("\t============================================================\n");
        gotoxy(31, 13);
        printf("\t|| NUMERO DE CEDULA   |                                   ||\n");
        gotoxy(31, 14);
        printf("\t============================================================\n");
        gotoxy(31, 15);
        printf("\t|| DIRECCION          |                                   ||\n");
        gotoxy(31, 16);
        printf("\t============================================================\n");
        gotoxy(31, 17);
        printf("\t|| TELEFONO           |                                   ||\n");
        gotoxy(31, 18);
        printf("\t============================================================\n");
        gotoxy(31, 19);
        printf("\t|| CORREO ELECTRONICO |                                   ||\n");
        gotoxy(31, 20);
        printf("\t============================================================\n");

        gotoxy(56, 13);
        fflush(stdout);
        fflush(stdin);
        gets(code);

        enc=0;

        while ( fread(&C, sizeof(C), 1, V) )// LEE LOS REGISTROS DE VENTAS
        {
            if (enc==0)
            {
                if (strcmp(code, C.id)==0)//COMPARA EL CODIGO
                {
                    enc=1;//EXISTE

                }//FIN DE IF

                else
                {
                    enc=0;//NO EXISTE

                }//FIN DE ELSE

            }//FIN DE IF ENC==0

        }//FIN DE WHILE

        if (enc==1)// SI EXISTE
        {
            codeexist();

        }//FIN DE IF
        else// SI NO EXISTE GUARDA EL CODIGO EN LA VARIABLE DE ESTRUCTURA
        {
            strcpy(C.id, code); //strcpy( <variable_destino>, <cadena_fuente> )
        }

        fclose(V);//CIERRA EL ARCHIVO

    }while(enc==1);//FIN DE DO WHILE

        gotoxy(56, 11);
        fflush(stdout);
        fflush(stdin);
        gets(C.nombre_cliente);

        gotoxy(56, 15);
        fflush(stdout);
        fflush(stdin);
        gets(C.direccion);

        gotoxy(56, 17);
        fflush(stdout);
        fflush(stdin);
        gets(C.telf);

        gotoxy(56, 19);
        fflush(stdout);
        fflush(stdin);
        gets(C.e_mail);

        fwrite(&C,sizeof(C),1,R);//LOS ESCRIBE EN EL ARCHIVO

        fclose(R);//CIERRA EL ARCHIVO

        save();//MENSAJE DE INTERFAZ
        scanf("%d", &retorno);//SI DESEA REGISTRAR OTRO REGISTRO

        system("color 0F");

    }while(retorno==1);//FIN DE DO

}//FIN DE VOID

void ModificarCliente() {// ACTUALIZAR CLIENTE

           FILE *origen, *temp;// CREA DOS VARIABLES DE ARCHIVOS PARA MODIFICAR
           char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
           int enc=0;//VALIDACION DE ENCONTRADO

           remove("TempC.txt");//ELIMINA EL TEMPORAL

           origen=fopen("Clientes.txt","r");//ABRE EL REGISTRO DE CLIENTES EN MODO LECTURA
           temp=fopen("TempC.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA

           codemodify();//INTERFAZ DE SOLICITUD DE CODIGO
           fflush(stdout);//BUFFER
           fflush(stdin);//BUFFER
           gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA GUARDAR

           while(fread(&C,sizeof(C),1,origen))// LEE LOS REGISTROS DE CLIENTES
           {
               if(enc==0)
               {
                   if((strcmp(codigo,C.id))==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                   {
                       int sc=0;
                       enc=1;//EL REGISTRO FUE ENCONTRADO

                       do
                       {
                            system("cls");

                            printf("\n\n\n\n\n");
                            printf("\t============================================================\n");
                            printf("\t||                    COMPUTECNO S.A                      ||\n");
                            printf("\t============================================================\n");
                            printf("\t||       M O D I F I C A C I O N  D E  C L I E N T E      ||\n");
                            printf("\t============================================================\n");
                            printf("\t|| NOMBRE DEL CLIENTE | %s", C.nombre_cliente);
                            gotoxy(66, 10);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| NUMERO DE CEDULA   | %s", C.id);
                            gotoxy(66, 12);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| DIRECCION          | %s", C.direccion);
                            gotoxy(66, 14);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| TELEFONO           | %s", C.telf);
                            gotoxy(66, 16);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| CORREO ELECTRONICO | %s", C.e_mail);
                            gotoxy(66, 18);
                            printf("||\n");
                            printf("\t============================================================\n");

                            int opcmod=0;

                            fflush(stdout);
                            fflush(stdin);
                            gotoxy(74, 6);
                            printf("INGRESE UNA OPCION SEGUN LO QUE DESEE MODIFICAR:");
                            gotoxy(74, 8);
                            printf("      [1] MODIFICAR NOMBRE DEL CLIENTE");
                            gotoxy(74, 10);
                            printf("      [2] MODIFICAR DIRECCION");
                            gotoxy(74, 12);
                            printf("      [3] MODIFICAR TELEFONO");
                            gotoxy(74, 14);
                            printf("      [4] MODIFICAR CORREO ELECTRONICO");
                            gotoxy(74, 16);
                            printf("      [5] SALIR");
                            gotoxy(74, 18);
                            printf(" --> ");
                            gotoxy(80, 18);
                            scanf("%i",&opcmod);

                            //MODIFICA LOS DATOS QUE EL USUARIO DESEE

                            switch(opcmod)
                            {
                                case 1:
                                {
                                    gotoxy(32,10);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(C.nombre_cliente);

                                    break;
                                }

                                case 2:
                                {
                                    gotoxy(32,14);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(C.direccion);

                                    break;
                                }

                                case 3:
                                {
                                    gotoxy(32,16);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(C.telf);

                                    break;
                                }

                                case 4:
                                {
                                    gotoxy(32,18);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(C.e_mail);

                                    break;
                                }

                                case 5:
                                {
                                    sc=1;
                                    break;
                                }

                                default:
                                {
                                    tryagain();
                                }

                            }//FIN DE SWITCH

                     }while(!sc);//FIN DE DO

                     fwrite(&C,sizeof(C),1,temp);//ESCRIBE LOS NUEVOS DATOS REGISTRADOS POR EL USUARIO

                   }//FIN DE IF COMPARACION

                   else
                   {
                       fwrite(&C,sizeof(C),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                       enc=0;//NO ENCONTRADO

                   }//FIN DE ELSE

               }//FIN DE IF ENC

               else
               {
                   system("cls");
                   fwrite(&C,sizeof(C),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

               }//FIN DE ELSE

           }//FIN DE WHILE

          if(enc==0)//NO ENCONTRADO
          {
              searching();//INTERFAZ DE NO ENCONTRADO

          }//FIN DE IF

          fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
          fclose(temp);// CIERRA EL ARCHIVO TEMPORAL
          remove("Clientes.txt");//ELIMINA EL REGISTRO DE CLIENTES
          rename("TempC.txt","Clientes.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR CLIENTES


}//FIN DE VOID

void EliminarCliente() {// ELIMINAR CLIENTE

           FILE *origen, *temp;// CREA DOS VARIABLES DE ARCHIVOS PARA MODIFICAR
           char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
           int enc=0;//VALIDACION DE ENCONTRADO

           remove("TempC.txt");//ELIMINA EL TEMPORAL

           origen=fopen("Clientes.txt","r");//ABRE EL REGISTRO DE CLIENTES EN MODO LECTURA
           temp=fopen("TempC.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA

           codedelete();//INTERFAZ DE SOLICITUD DE CODIGO
           fflush(stdout);
           fflush(stdin);
           gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA GUARDAR
           system("cls");

           while(fread(&C,sizeof(C),1,origen))// LEE LOS REGISTROS DE CLIENTES
           {
               if(enc==0)
               {
                   if(strcmp(codigo,C.id)==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                   {
                       enc=1;//EL REGISTRO FUE ENCONTRADO

                            system("cls");

                            printf("\n\n\n\n\n");
                            printf("\t============================================================\n");
                            printf("\t||                    COMPUTECNO S.A                      ||\n");
                            printf("\t============================================================\n");
                            printf("\t||       M O D I F I C A C I O N  D E  C L I E N T E      ||\n");
                            printf("\t============================================================\n");
                            printf("\t|| NOMBRE DEL CLIENTE | %s", C.nombre_cliente);
                            gotoxy(66, 10);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| NUMERO DE CEDULA   | %s", C.id);
                            gotoxy(66, 12);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| DIRECCION          | %s", C.direccion);
                            gotoxy(66, 14);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| TELEFONO           | %s", C.telf);
                            gotoxy(66, 16);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| CORREO ELECTRONICO | %s", C.e_mail);
                            gotoxy(66, 18);
                            printf("||\n");
                            printf("\t============================================================\n");

                            advertencia();//MENSAJE DE AVISO DE ELIMINACION

                   }//FIN DE IF COMPARACION

                   else
                   {
                       fwrite(&C,sizeof(C),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                       enc=0;//NO ENCONTRADO

                   }//FIN DE ELSE

               }//FIN DE IF ENC

               else
               {
                   system("cls");
                   fwrite(&C,sizeof(C),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

               }//FIN DE ELSE

           }//FIN DE WHILE

          if(enc==0)//NO ENCONTRADO
          {
              searching();//INTERFAZ DE NO ENCONTRADO

          }//FIN DE IF

          fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
          fclose(temp);// CIERRA EL ARCHIVO TEMPORAL

          if(enc==1)//ENCONTRADO
          {
             deletesucces();//ELIMINACION EXITOSA

          }//FIN DE IF

          remove("Clientes.txt");//ELIMINA EL REGISTRO DE CLIENTES
          rename("TempC.txt","Clientes.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR CLIENTES

}//FIN DE VOID

void R_ClienteN1() { //REGISTRO DE UN CLIENTE

    char codigo[30];//CODIGO DE BUSQUEDAD
    int enc=0;//VERIFICACION DE ENCONTRADO

    FILE *C1;//CREA UNA VARIABLE DE ARCHIVO
    C1=fopen("Clientes.txt","r");//ABRE EL ARCHIVO EN MODO DE LECTURA

    codesearch();//INTERFAZ DE BUSQUEDA
    fflush(stdout);
    fflush(stdin);
    gets(codigo);// LEE EL CODIGO
    system("cls");

    while(fread(&C,sizeof(C),1,C1))// LEE LOS REGISTROS
    {
        if(enc==0)
        {
            if((strcmp(codigo,C.id))==0)// COMPARA LOS CODIGOS
            {
                enc=1;//ENCONTRADO

                gotoxy(31,5);
                printf("\t============================================================");
                gotoxy(31,6);
                printf("\t||                    COMPUTECNO S.A                      ||");
                gotoxy(31,7);
                printf("\t============================================================");
                gotoxy(31,8);
                printf("\t||             R E G I S T R O  C L I E N T E             ||");
                gotoxy(31,9);
                printf("\t============================================================");
                gotoxy(31,10);
                printf("\t|| NOMBRE DEL CLIENTE | %s", C.nombre_cliente);
                gotoxy(90,10);
                printf("||");
                gotoxy(31,11);
                printf("\t============================================================");
                gotoxy(31,12);
                printf("\t|| NUMERO DE CEDULA   | %s", C.id);
                gotoxy(90, 12);
                printf("||");
                gotoxy(31,13);
                printf("\t============================================================");
                gotoxy(31,14);
                printf("\t|| DIRECCION          | %s", C.direccion);
                gotoxy(90, 14);
                printf("||");
                gotoxy(31,15);
                printf("\t============================================================");
                gotoxy(31,16);
                printf("\t|| TELEFONO           | %s", C.telf);
                gotoxy(90,16);
                printf("||");
                gotoxy(31,17);
                printf("\t============================================================");
                gotoxy(31,18);
                printf("\t|| CORREO ELECTRONICO | %s", C.e_mail);
                gotoxy(90,18);
                printf("||");
                gotoxy(31,19);
                printf("\t============================================================");
                gotoxy(31,21);
                system("pause");

            }//FIN DE IF COMPARACION

        }//FIN DE ENC

    }//FIN DE WHILE

    if(enc==0)// NO ENCONTRADO
    {
        searching();// INTERFAZ DE NO ENCONTRADO

    }//FIN DE IF

    fclose(C1);// CIEERA EL ARCHIVO
}

void R_ClienteT() {// TODO LOS REGISTROS

    FILE *R;
    R=fopen("Clientes.txt","r");// ABRE EL ARCHIVO EN MODO DE LECTURA

    gotoxy(2,1);
    printf("===============================================================================================================================");
    gotoxy(2,2);
    printf("||                                                      COMPUTECNO S.A                                                       ||");
    gotoxy(2,3);
    printf("===============================================================================================================================");
    gotoxy(2,4);
    printf("||                                    R  E  G  I  S  T  R  O     D  E     C L I E N T E S                                    ||");
    gotoxy(2,5);
    printf("===============================================================================================================================");
    gotoxy(2,6);
    printf("||  IDENTIFICACION  |             NOMBRE             |    TELEFONO    |         DIRECCION         |          E-MAIL          ||");
    gotoxy(2,7);
    printf("===============================================================================================================================");

    int c=7;

    while (fread(&C, sizeof(C), 1, R))// LEE LOS REGISTROS
    {
        //IMPRIME TODO LOS REGISTROS

        gotoxy(2,++c);
        printf("||                  |                                |                |                           |                          ||");
        gotoxy(4,c);
        printf(" %s", C.id);
        gotoxy(23,c);
        printf(" %s", C.nombre_cliente);
        gotoxy(56,c);
        printf(" %s", C.telf);
        gotoxy(73,c);
        printf(" %s", C.direccion);
        gotoxy(101,c);
        printf(" %s", C.e_mail);
    }

    gotoxy(2,c+1);
    printf("===============================================================================================================================");
    gotoxy(2,c+2);
    system("pause");

    fclose(R);// CIERRA EL ARCHIVO
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void NuevaVenta() { //AGREGAR NUEVA VENTA

    char timesave;
    time_t tiempo = time(0);
    char output[128];
    char nombre[90];
    char idS[30];
    struct tm *tlocal = localtime(&tiempo);
    (strftime(output,128,"%d/%m/%y",tlocal)); //TOMA LA FECHA DEL SISTEMA

    int opc=0, i=0, exit=0;
    char code[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
    char code2[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
    int enc=0;

    FILE *O, *temp, *F, *P2, *infoR;//VARIABLES DE ARCHIVO

    infoR= fopen("Ventas.txt","a");//ABRE EL ARCHIVO DE VENTAS

    for (int a=0; a<10; a++)//INICIALIZA LAS VARIABLES EN 0
    {
        na[a].cantz=0;
        na[a].priceT=0;
        na[a].unit=0;
        na[a].inversion=0;
    }

    do {//Verificacion de cliente

        system("cls");

        F=fopen("Clientes.txt", "r");//ABRE EL REGISTRO DE LOS CLIENTES EN MODO LECTURA

        codeID();//VERIFICACION DE IDENTIFICACION
        fflush(stdout);
        fflush(stdin);
        scanf("%s",code);//GUARDA EL CODIGO

        enc=0;

        while ( fread(&C, sizeof(C), 1, F) )//LEE LOS REGISTROS
        {
            if (enc==0)
            {
                if (strcmp(code, C.id)==0)//COMPARA LOS CODIGOS
                {
                    enc=1;//ENCONTRADO

                    system("cls");
                    gotoxy(26, 12);
                    printf("==============================================================================\n");
                    gotoxy(26, 13);
                    printf("||        Nombre del cliente: %s                          \n", C.nombre_cliente);
                    gotoxy(102, 13);
                    printf("||");
                    gotoxy(26, 14);
                    printf("==============================================================================\n");
                    Sleep(3000);//ESPERAR 3 SEGUNDOS

                }//FIN DE IF

                else
                {
                    enc=0;//NO ENCONTRADO

                }//FIN DE ELSE

            }//FIN DE IF ENC==0

        }//FIN DE WHILE

        if (enc==0)// NO ENCONTRADO
        {
            searching();//INTERFAZ DE NO ENCONTRADO
            RegisterC();// INTERFAZ DE CREAR CLIENTE
            scanf("%d", &opc);// LEE LA OPCION

            if (opc==1)// SI OPCION ES 1
            {
                exit=1;//REGRESA AL MENU PRINCIPAL
                enc=1;

            }//fin de if

        }//FIN DE IF

        fclose(F);// CIERRA EL ARCHIVO

    } while(enc!=1);//FIN DE DO WHILE;

    if (exit==0) {

        do { //Creacion de numero de factura

        P2= fopen("Ventas.txt","r");// ABRE EL REGISTRO DE VENTAS EN MODO DE LECTURA

        system("cls");
        gotoxy(26, 12);
        printf("==============================================================================\n");
        gotoxy(26, 13);
        printf("||                    FACTURA #                                             ||\n");
        gotoxy(26, 14);
        printf("==============================================================================\n");

        gotoxy(58, 13);
        fflush(stdout);
        fflush(stdin);
        scanf("%s",code2);//LEE EL CODIGO

        enc=0;

        while ( fread(&fact, sizeof(fact), 1, P2) )// LEE LOS REGISTROS DE VENTAS
        {
            if (enc==0)
            {
                if (strcmp(code2, fact.factN)==0)//COMPARA EL CODIGO
                {
                    enc=1;//EXISTE

                }//FIN DE IF

                else
                {
                    enc=0;//NO EXISTE

                }//FIN DE ELSE

            }//FIN DE IF ENC==0

        }//FIN DE WHILE

        if (enc==1)// SI EXISTE
        {

            system("cls");
            gotoxy(26, 12);
            printf("==============================================================================\n");
            gotoxy(26, 13);
            printf("||                    Este numero de factura ya existe!                     ||\n");
            gotoxy(26, 14);
            printf("==============================================================================\n");
            Sleep(3000);

        }//FIN DE IF
        else// SI NO EXISTE GUARDA EL CODIGO EN LA VARIABLE DE ESTRUCTURA
        {
            strcpy(fact.factN, code2); //strcpy( <variable_destino>, <cadena_fuente> )
        }

        fclose(P2);//CIERRA EL ARCHIVO

    }while(enc==1);//FIN DE DO WHILE

        do {//Buscando producto

            system("cls");

            char codigo[30];
            enc=0;

            remove("Temp.txt");// ELIMINA EL TEMPORAL

            O=fopen("Inv_productos.txt","r");//ABRE EL REGISTRO DE PRODUCTOS EN MODO LECTURA
            temp=fopen("Temp.txt", "a");// ABRE E TEMPORAL EN MODO DE ESCRITURA

            codebuy();// INTERFAZ DE SOLICITUD DE CODIGO DE PRODUCTO DE COMPRA
            fflush(stdout);
            fflush(stdin);
            gets(codigo);//LEE EL CODIGO
            system("cls");

            i++;//ITERACION PARA LOS ARREGLOS DENTRO DEL WHILE

        while(fread(&P,sizeof(P),1,O))//LEE LOS REGISTROS DE PRODUCTOS
        {
            if(enc==0)
            {
                if((strcmp(codigo,P.codeB))==0)//COMPARA EL CODIGO CON LOS REGISTROS
                {
                    enc=1;//ENCONTRADO

                    if (P.cant>0)//SI CANTIDAD EN INVENTARIO ES MAYOR A 0
                    {
                        gotoxy(31,4);
                        printf("\t============================================================");
                        gotoxy(31,5);
                        printf("\t||                    COMPUTECNO S.A                      ||");
                        gotoxy(31,6);
                        printf("\t============================================================");
                        gotoxy(31,7);
                        printf("\t||            R E G I S T R O  P R O D U C T O            ||");
                        gotoxy(31,8);
                        printf("\t============================================================");
                        gotoxy(31,9);
                        printf("\t|| CODIGO DE BARRA     | %s", P.codeB);
                        gotoxy(90,9);
                        printf("||");
                        gotoxy(31,10);
                        printf("\t============================================================");
                        gotoxy(31,11);
                        printf("\t|| NOMBRE DEL PRODUCTO | %s", P.nombre);
                        gotoxy(90, 11);
                        printf("||");
                        gotoxy(31,12);
                        printf("\t============================================================");
                        gotoxy(31,13);
                        printf("\t|| MARCA               | %s", P.marca);
                        gotoxy(90, 13);
                        printf("||");
                        gotoxy(31,14);
                        printf("\t============================================================");
                        gotoxy(31,15);
                        printf("\t|| MODELO              | %s", P.modelo);
                        gotoxy(90, 15);
                        printf("||");
                        gotoxy(31,16);
                        printf("\t============================================================");
                        gotoxy(31,17);
                        printf("\t|| DESCRIPCION         | %s", P.descrip);
                        gotoxy(90, 17);
                        printf("||");
                        gotoxy(31,18);
                        printf("\t============================================================");
                        gotoxy(31,19);
                        printf("\t|| CANTIDAD            | %d", P.cant);
                        gotoxy(90, 19);
                        printf("||");
                        gotoxy(31,20);
                        printf("\t============================================================");
                        gotoxy(31,21);
                        printf("\t|| PRECIO DE VENTA     | C$ %.2f", P.precio);
                        gotoxy(90, 21);
                        printf("||");
                        gotoxy(31,22);
                        printf("\t============================================================");
                        gotoxy(31,24);
                        system("pause");

                        cant();//SOLICITUD DE CANTIDADES
                        fflush(stdin);
                        fflush(stdout);
                        scanf("%d", &na[i].cantz);//LEE LA CANTIDAD DE PRODUCTOS SOLICITADOS

                        int cnt=0;

                        cnt=(P.cant-na[i].cantz);//CANTIDAD RESTANTE EN EL INVENTARIO

                        if (cnt>=0)//SI CANTIDAD ES MAYOR O IGUAL A 0
                        {
                            strcpy( na[i].a, P.nombre);//GUARDA EL NOMBRE DEL PRODUCTO
                            na[i].unit = P.precio;// GUARDA EL PRECIO
                            na[i].priceT = (P.precio*na[i].cantz);//GUARDA EL PRECIO TOTAL POR LAS CANTIDADES
                            na[i].inversion = (P.precioC*na[i].cantz);// GUARDA LA INVERSION

                            P.cant=cnt;//LA CANTIDAD EN INVENTARIO SERA IGUAL A EL RESTANTE
                            fwrite(&P, sizeof(P), 1, temp);//ESCRIBE EN EL REGISTRO

                        }//fin de else

                        else
                        {
                            P.cant;//LA CANTIDAD EN INVENTARIO QUEDARA IGUAL
                            fwrite(&P, sizeof(P), 1, temp);// ESCRIBE EN EL REGISTRO

                            stock();//MENSAJE DE PRODUCTOS EN INVENTARIO

                        }//fin de else

                    }//FIN DE IF CANTIDAD MAYOR A 0

                else
                {
                    P.cant=0;//CANTIDAD EN INVENTARIO ES IGUAL A 0
                    fwrite(&P, sizeof(P), 1, temp);//ESCRIBE EN EL REGISTRO

                    stock();//MENSAJE DE PRODUCTOS EN INVENTARIO

                }//FIN DE ELSE

            }//FIN DE IF COMPARACION

            else
            {
                fwrite(&P, sizeof(P), 1, temp);//ESCRIBE EN EL REGISTRO
                enc=0;//NO ENCONTRADO

            }//FIN DE ELSE

        }//FIN DE ENC

        else
        {
            system("cls");
            fwrite(&P, sizeof(P), 1, temp);//ESCRIBE EN EL REGISTRO

        }//FIN DE ELSE

    }//FIN DE WHILE

    if(enc==0)//NO ENCONTRADO
    {
        searching();//MENSAJE DE TEXTO NO ENCONTRADO

    }//FIN DE IF

    Add();//MENU DE AGREGAR
    scanf("%d",&opc);//LEER OPCION

    fclose(O);//CIERRA EL ARCHIVO O
    fclose(temp);//CIERRA EL ARCHIVO TEMP

    remove("Inv_productos.txt");//ELIMINA EL REGISTRO
    rename("Temp.txt","Inv_productos.txt");//CAMBIA EL NOMBRE DEL TEMPORAL CON LA DE PRODUCTOS

    }while (opc==1);

    system("cls");

    strcpy(fact.idC, code);//GUARDA EL CODIGO DEL CLIENTE
    strcpy(fact.fecha, output);//GUARDA LA FECHA

    //SE INICIALIZAN LOS ACUMULADORES EN 0

    fact.cant_prod=0;
    fact.totalPago=0;
    fact.pagoFinal=0;
    fact.imp=0;
    fact.inversionT=0;
    fact.moneyG=0;

    for (int j=1; j<=i; j++)//CALCULA EL TOTAL PAGO
    {
        fact.totalPago+=na[j].priceT;

    }//FIN DE FOR

    for (int c=1; c<=i; c++)// CALCULA LA CANTIDAD DE PRODUCTOS COMPRADOS
    {
        fact.cant_prod+=na[c].cantz;
    }

    fact.imp=(fact.totalPago*0.15);//CALCULA EL IMPUESTO
    fact.pagoFinal=(fact.totalPago+fact.imp);//CALCULA EL PAGO FINAL CON IVA

     for (int s=1; s<=i; s++)//CALCULA LA INVERSION
    {
        fact.inversionT+= na[s].inversion;
    }

    fact.moneyG = (fact.pagoFinal-fact.inversionT);//CALCULA LAS GANANCIAS

    fwrite(&fact, sizeof(fact), 1, infoR);//ESCRIBE EN EL REGISTRO
    fclose(infoR);//CIERRA EL ARCHIVO

    FILE *K;//CREA UNA VARIABLE DE ARCHIVO

    K = fopen("Clientes.txt", "r");// ABRE EL ARCHIVO DE CLIENTES EN MODO LECTURA

    system("color 0B");

    gotoxy(30, 1);
    printf("\t=================================================================");
    gotoxy(30, 2);
    printf("\t||                       COMPUTECNO S.A                        ||");
    gotoxy(30, 3);
    printf("\t=================================================================");
    gotoxy(30, 4);
    printf("\t||           D E T A L L E S  D E  L A  C O M P R A            ||");
    gotoxy(30, 5);
    printf("\t=================================================================");
    gotoxy(30, 6);
    printf("\t|| FACTURA # |                       | FECHA |                 ||");
    gotoxy(30, 7);
    printf("\t-----------------------------------------------------------------");
    gotoxy(30, 8);
    printf("\t|| CLIENTE |                                 | ID |            ||");
    gotoxy(30, 9);
    printf("\t=================================================================");
    gotoxy(30, 10);
    printf("\t|| # | NOMBRE DEL PRODUCTO    | CANT | P. UNITARIO |   TOTAL   ||");
    gotoxy(30, 11);
    printf("\t=================================================================");

    gotoxy(47,6);
    puts(fact.factN);//PONE EL NUMERO DE FACTURA

    gotoxy(79,6);
    puts(fact.fecha);//PONE LA FECHA

    while (fread(&C, sizeof(C), 1, K))//LEE LOS REGISTROS
    {
        if (strcmp(code, C.id)==0)//COMPARA EL CODIGO
        {
            gotoxy(45, 8);
            puts(C.nombre_cliente);//PONE EL NOMBRE DEL CLIENTE

            gotoxy(84,8);
            puts(C.id);//PONE EL ID DEL CLIENTE

        }//Fin de if

    }//Fin de WHILE

    int j;

    for (j=1; j<=i; j++)//IMPRIME TODOS LOS ARTICULOS ADQUIRIDOS
    {
        if (na[j].cantz>0)
        {
            gotoxy(30,11+j);
            printf("\t||   |                        |      | C$          | C$        ||");

            gotoxy(35,11+j);
            printf("%d",j);

            gotoxy(39,11+j);
            puts(na[j].a);

            gotoxy(64,11+j);
            printf("%d", na[j].cantz);//IMPRIME LA CANTIDAD

            gotoxy(73,11+j);
            printf("%.2f", na[j].unit);//IMPRIME EL PRECIO UNITARIO

            gotoxy(87,11+j);
            printf("%.2f",na[j].priceT);//IMPRIME EL PRECIO TOTAL

        }//FIN DE IF
        if (j==i)//SI J ES IGUAL A I PROCEDE A LOS DATOS FINALES DE CALCULOS
        {
            system("color 0B");

            gotoxy(30,12+j);
            printf("\t=================================================================");
            gotoxy(30,13+j);
            printf("\t=================================================================");
            gotoxy(30,14+j);
            printf("\t||                                 SUBTOTAL| C$                ||");
            gotoxy(30,15+j);
            printf("\t||                                 IMPUESTO| C$                ||");
            gotoxy(30,16+j);
            printf("\t||                                    TOTAL| C$                ||");
            gotoxy(30,17+j);
            printf("\t=================================================================");

            gotoxy(80,14+j);
            printf("%.2f", fact.totalPago);//IMPRIME EL SUBTOTAL

            gotoxy(80,15+j);
            printf("%.2f", fact.imp);//IMPRIME EL IMPUESTO

            gotoxy(80,16+j);
            printf("%.2f", fact.pagoFinal);//IMPRIME EL PAGO FINAL

        }

    }//FIN DE FOR

    fclose(K);//CIERRA EL ARCHIVO

    printf("\n\n\n\t\t\t\t");

    system("color 0F");

    system("pause");

    }//FIN DE IF EXIT

}

void ModificarVenta() { //ACTUALIZAR UNA VENTA

           FILE *origen, *temp, *F;// CREA DOS VARIABLES DE ARCHIVOS PARA MODIFICAR
           char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
           int enc=0, found=0;//VALIDACION DE ENCONTRADO

           remove("TempC.txt");//ELIMINA EL TEMPORAL

           origen=fopen("Ventas.txt","r");//ABRE EL REGISTRO DE VENTAS EN MODO LECTURA
           temp=fopen("TempV.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA
           F=fopen("Clientes.txt","r");//ABRE EL REGISTRO DE CLIENTES EN MODO LECTURA

           codemodify();//INTERFAZ DE SOLICITUD DE CODIGO
           fflush(stdout);
           fflush(stdin);
           gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA GUARDAR

           while(fread(&fact,sizeof(fact),1,origen))// LEE LOS REGISTROS
           {
               if(enc==0)
               {
                   if((strcmp(codigo,fact.factN))==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                   {
                       int sc=0;
                       enc=1;//EL REGISTRO FUE ENCONTRADO

                       do
                       {
                            F=fopen("Clientes.txt", "r");
                            system("cls");

                            gotoxy(6, 6);
                            printf("\t=================================================================");
                            gotoxy(6, 7);
                            printf("\t||                       COMPUTECNO S.A                        ||");
                            gotoxy(6, 8);
                            printf("\t=================================================================");
                            gotoxy(6, 9);
                            printf("\t||           D E T A L L E S  D E  L A  C O M P R A            ||");
                            gotoxy(6, 10);
                            printf("\t=================================================================");
                            gotoxy(6, 11);
                            printf("\t|| FACTURA # |                       | FECHA |                 ||");
                            gotoxy(6, 12);
                            printf("\t-----------------------------------------------------------------");
                            gotoxy(6, 13);
                            printf("\t|| CLIENTE |                                 | ID |            ||");
                            gotoxy(6, 14);
                            printf("\t=================================================================");
                            gotoxy(6, 15);
                            printf("\t||     SUBTOTAL| C$               CANT.PRODUCTOS|              ||");
                            gotoxy(6, 16);
                            printf("\t||     IMPUESTO| C$                    INVERSION| C$           ||");
                            gotoxy(6, 17);
                            printf("\t||        TOTAL| C$                    GANANCIAS| C$           ||");
                            gotoxy(6, 18);
                            printf("\t=================================================================");

                            gotoxy(23,11);
                            puts(fact.factN);

                            gotoxy(55,11);
                            puts(fact.fecha);

                            while (fread(&C, sizeof(C), 1, F))// LEE LOS REGISTROS
                            {
                                if (strcmp(fact.idC, C.id)==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                                {
                                    gotoxy(21, 13);
                                    puts(C.nombre_cliente);//IMPRIME EL NOMBRE

                                    gotoxy(60,13);
                                    puts(C.id);//IMPRIME EL ID

                                }//Fin de if

                            }//Fin de WHILE

                            gotoxy(28,15);
                            printf("%.2f", fact.totalPago);

                            gotoxy(28,16);
                            printf("%.2f", fact.imp);

                            gotoxy(28,17);
                            printf("%.2f", fact.pagoFinal);

                            gotoxy(61,15);
                            printf("%d", fact.cant_prod);

                            gotoxy(61,16);
                            printf("%.2f", fact.inversionT);

                            gotoxy(61,17);
                            printf("%.2f", fact.moneyG);

                            int opcmod=0;

                            fflush(stdout);
                            fflush(stdin);
                            gotoxy(79, 8);
                            printf("INGRESE UNA OPCION SEGUN LO QUE DESEE MODIFICAR:");
                            gotoxy(79, 10);
                            printf("      [1] MODIFICAR NUMERO DE IDENTIFICACION");
                            gotoxy(79, 12);
                            printf("      [2] SALIR");
                            gotoxy(79, 14);
                            printf(" --> ");
                            gotoxy(84, 14);
                            scanf("%i",&opcmod);

                            //MODIFICA LOS DATOS QUE EL USUARIO DESEE

                            switch(opcmod)
                            {
                                case 1:
                                {
                                    found=0;

                                    gotoxy(60,13);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(fact.idC);

                                    while ( fread(&C, sizeof(C), 1, F) )// LEE LOS REGISTROS
                                    {
                                        if (found==0)
                                        {
                                            if (strcmp(fact.idC, C.id)==0)
                                            {
                                                found=0;//EL REGISTRO FUE ENCONTRADO

                                                gotoxy(60,13);
                                                puts(C.id);

                                                gotoxy(21, 13);
                                                puts(C.nombre_cliente);

                                            }//FIN DE IF

                                            else
                                            {
                                                found=1;//NO ENCONTRADO

                                            }//FIN DE ELSE

                                        }//FIN DE IF ENC==0

                                    }//FIN DE WHILE

                                    if (found==1)//NO ENCONTRADO
                                    {
                                        searching();//INTERFAZ DE NO ENCONTRADO

                                    }//FIN DE IF

                                    break;

                                }//FIN DE CASE 1

                                case 2:
                                {
                                    sc=1;//SALIR DEL MENU
                                    break;

                                }//FIN DE CASE 2

                                default:
                                {
                                    tryagain();//INTERFAZ DE INTENTAR DE NUEVO

                                }//DEFAULT

                            }//FIN DE SWITCH

                     }while(!sc);//FIN DE DO

                     fwrite(&fact,sizeof(fact),1,temp);//ESCRIBE LOS NUEVOS DATOS REGISTRADOS POR EL USUARIO

                   }//FIN DE IF COMPARACION

                   else
                   {
                       fwrite(&fact,sizeof(fact),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                       enc=0;

                   }//FIN DE ELSE

               }//FIN DE IF ENC

               else
               {
                   system("cls");
                   fwrite(&fact,sizeof(fact),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

               }//FIN DE ELSE

           }//FIN DE WHILE

          if(enc==0)
          {
              searching();//INTERFAZ DE NO ENCONTRADO

          }//FIN DE IF

          fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
          fclose(temp);// CIERRA EL ARCHIVO TEMPORAL
          fclose(F);// CIERRA EL ARCHIVO F
          remove("Ventas.txt");//ELIMINA EL REGISTRO DE VENTAS
          rename("TempV.txt","Ventas.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR VENTAS
}

void EliminarVenta() { //ELIMINAR UNA VENTA


           FILE *origen, *temp, *F;// CREA VARIABLES DE ARCHIVOS
           char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
           int enc=0, found=0;//VALIDACION DE ENCONTRADO

           remove("TempC.txt");//ELIMINA EL TEMPORAL

           origen=fopen("Ventas.txt","r");//ABRE EL REGISTRO DE VENTAS EN MODO LECTURA
           temp=fopen("TempV.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA
           F=fopen("Clientes.txt","r");//ABRE EL REGISTRO DE CLIENTES EN MODO LECTURA

           codedelete();//INTERFAZ DE SOLICITUD DE CODIGO
           fflush(stdout);
           fflush(stdin);
           gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA ELIMINAR

           while(fread(&fact,sizeof(fact),1,origen))// LEE LOS REGISTROS
           {
               if(enc==0)
               {
                   if((strcmp(codigo,fact.factN))==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                   {

                       enc=1;//EL REGISTRO FUE ENCONTRADO

                        F=fopen("Clientes.txt", "r");//ABRE EL ARCHIVO DE CLIENTES
                        system("cls");

                        gotoxy(6, 6);
                        printf("\t=================================================================");
                        gotoxy(6, 7);
                        printf("\t||                       COMPUTECNO S.A                        ||");
                        gotoxy(6, 8);
                        printf("\t=================================================================");
                        gotoxy(6, 9);
                        printf("\t||           D E T A L L E S  D E  L A  C O M P R A            ||");
                        gotoxy(6, 10);
                        printf("\t=================================================================");
                        gotoxy(6, 11);
                        printf("\t|| FACTURA # |                       | FECHA |                 ||");
                        gotoxy(6, 12);
                        printf("\t-----------------------------------------------------------------");
                        gotoxy(6, 13);
                        printf("\t|| CLIENTE |                                 | ID |            ||");
                        gotoxy(6, 14);
                        printf("\t=================================================================");
                        gotoxy(6, 15);
                        printf("\t||     SUBTOTAL| C$               CANT.PRODUCTOS|              ||");
                        gotoxy(6, 16);
                        printf("\t||     IMPUESTO| C$                    INVERSION| C$           ||");
                        gotoxy(6, 17);
                        printf("\t||        TOTAL| C$                    GANANCIAS| C$           ||");
                        gotoxy(6, 18);
                        printf("\t=================================================================");

                        gotoxy(23,11);
                        puts(fact.factN);

                        gotoxy(55,11);
                        puts(fact.fecha);

                        while (fread(&C, sizeof(C), 1, F))
                        {
                            if (strcmp(fact.idC, C.id)==0)// LEE LOS REGISTROS
                            {
                                gotoxy(21, 13);
                                puts(C.nombre_cliente);//IMPRIME EL NOMBRE

                                gotoxy(60,13);
                                puts(C.id);//IMPRIME EL ID

                            }//Fin de if

                        }//Fin de WHILE

                        gotoxy(28,15);
                        printf("%.2f", fact.totalPago);

                        gotoxy(28,16);
                        printf("%.2f", fact.imp);

                        gotoxy(28,17);
                        printf("%.2f", fact.pagoFinal);

                        gotoxy(61,15);
                        printf("%d", fact.cant_prod);

                        gotoxy(61,16);
                        printf("%.2f", fact.inversionT);

                        gotoxy(61,17);
                        printf("%.2f", fact.moneyG);

                        advertencia();//MENSAJE DE AVISO DE ELIMINACION

                   }//FIN DE IF COMPARACION

                   else
                   {
                       fwrite(&fact,sizeof(fact),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                       enc=0;

                   }//FIN DE ELSE

               }//FIN DE IF ENC

               else
               {
                   system("cls");
                   fwrite(&fact,sizeof(fact),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

               }//FIN DE ELSE

           }//FIN DE WHILE

          if(enc==0)//NO ENCONTRADO
          {
              searching();//INTERFAZ DE NO ENCONTRADO

          }//FIN DE IF

          fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
          fclose(temp);// CIERRA EL ARCHIVO TEMPORAL
          fclose(F);// CIERRA EL ARCHIVO F

          if(enc==1)
          {
             deletesucces();//MENSAJE DE AVISO DE ELIMINACION

          }//FIN DE IF

          remove("Ventas.txt");//ELIMINA EL REGISTRO DE VENTAS
          rename("TempV.txt","Ventas.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR VENTAS



}

void R_VentasN1() { //REGISTRO DE UNA VENTA

           FILE *V, *F;// CREA DOS VARIBALES DE ARCHIVO
           char codigo[30];// CODIGO DE BUSQUEDAD
           int enc=0, found=0;// VALIDACION DE ENCONTRADO

           V=fopen("Ventas.txt","r");// ABRE EL ARCHIVO DE VENTAS EN MODO LECTURA
           F=fopen("Clientes.txt", "r");// ABRE EL ARCHIVO DE CLIENTES EN MODO LECTURA

           codesearch();//INTERFAZ DE BUSQUEDA
           fflush(stdout);
           fflush(stdin);
           gets(codigo);// LEE EL CODIGO

           while(fread(&fact,sizeof(fact),1,V))// LEE LOS REGISTROS DE VENTAS
           {
               if(enc==0)
               {
                   if((strcmp(codigo,fact.factN))==0)// COMPARA LOS CODIGOS
                   {
                       enc=1;// ENCONTRADO
                        system("cls");

                        gotoxy(26, 6);
                        printf("\t=================================================================");
                        gotoxy(26, 7);
                        printf("\t||                       COMPUTECNO S.A                        ||");
                        gotoxy(26, 8);
                        printf("\t=================================================================");
                        gotoxy(26, 9);
                        printf("\t||           D E T A L L E S  D E  L A  C O M P R A            ||");
                        gotoxy(26, 10);
                        printf("\t=================================================================");
                        gotoxy(26, 11);
                        printf("\t|| FACTURA # |                       | FECHA |                 ||");
                        gotoxy(26, 12);
                        printf("\t-----------------------------------------------------------------");
                        gotoxy(26, 13);
                        printf("\t|| CLIENTE |                                 | ID |            ||");
                        gotoxy(26, 14);
                        printf("\t=================================================================");
                        gotoxy(26, 15);
                        printf("\t||     SUBTOTAL| C$               CANT.PRODUCTOS|              ||");
                        gotoxy(26, 16);
                        printf("\t||     IMPUESTO| C$                    INVERSION| C$           ||");
                        gotoxy(26, 17);
                        printf("\t||        TOTAL| C$                    GANANCIAS| C$           ||");
                        gotoxy(26, 18);
                        printf("\t=================================================================");

                        // IMPRIME EL REGISTRO

                        gotoxy(47,11);
                        puts(fact.factN);

                        gotoxy(79,11);
                        puts(fact.fecha);

                        while (fread(&C, sizeof(C), 1, F))// LEE LOS REGISTROS DE CLIENTES
                        {
                            if (strcmp(fact.idC, C.id)==0)
                            {
                                gotoxy(45, 13);
                                puts(C.nombre_cliente);

                                gotoxy(84,13);
                                puts(C.id);

                            }//Fin de if

                        }//Fin de WHILE

                        gotoxy(52,15);
                        printf("%.2f", fact.totalPago);

                        gotoxy(52,16);
                        printf("%.2f", fact.imp);

                        gotoxy(52,17);
                        printf("%.2f", fact.pagoFinal);

                        gotoxy(85,15);
                        printf("%d", fact.cant_prod);

                        gotoxy(85,16);
                        printf("%.2f", fact.inversionT);

                        gotoxy(85,17);
                        printf("%.2f", fact.moneyG);

                        gotoxy(30,20);
                        system("pause");

                   }//FIN DE IF STRCMP

               }// FIN DE IF ENC==0

           }//FIN DE WHILE

        if(enc==0)// NO ENCONTRADO
        {
            searching();// INTERFAZ DE NO ENCONTRADO

        }//FIN DE IF

        fclose(F);// CIERRA EL ARCHIVO F
        fclose(V);// CIERRA EL ARCHIVO V

}

void R_VentasT() { // TODOS LOS REGISTROS

    FILE *R;//DECLARACION DE VARIBALE DE ARCHIVO
    R=fopen("Ventas.txt","r");// ABRE EL ARCHIVO EN MODO LECTURA

    gotoxy(2,1);
    printf("===============================================================================================================================");
    gotoxy(2,2);
    printf("||                                                      COMPUTECNO S.A                                                       ||");
    gotoxy(2,3);
    printf("===============================================================================================================================");
    gotoxy(2,4);
    printf("||                                      R  E  G  I  S  T  R  O     D  E     V E N T A S                                      ||");
    gotoxy(2,5);
    printf("===============================================================================================================================");
    gotoxy(2,6);
    printf("||      FECHA      |    FACT #    |        COMPRA/INVERSION        |        VENTA/VENDIDO        |          GANANCIAS        ||");
    gotoxy(2,7);
    printf("===============================================================================================================================");

    int c=7;

    float a=0,b=0,d=0;//INICIALIZACION DE LAS VARIABLES EN 0

    while (fread(&fact, sizeof(fact), 1, R))// LEE TODO LOS REGISTROS
    {
        gotoxy(2, ++c);
        printf("||                 |              |     C$                         |     C$                      |     C$                    ||");

        gotoxy(25, c);
        printf("%s", fact.factN);

        gotoxy(8, c);
        printf("%s", fact.fecha);

        // SUMA LOS PAGOS FINALES, INVERSIONES Y GANANCIAS

        a+=fact.pagoFinal;
        b+=fact.inversionT;
        d+=fact.moneyG;

        gotoxy(45, c);
        printf("%.2f", fact.inversionT);//IMPRIME LA INVERSION DE LA VENTA
        gotoxy(78, c);
        printf("%.2f", fact.pagoFinal);// IMPRIME EL PAGO FINAL
        gotoxy(108, c);
        printf("%.2f", fact.moneyG);// IMPRIME LAS GANANCIAS

    }//FIN DE WHILE

    gotoxy(2,c+1);
    printf("===============================================================================================================================");
    gotoxy(2,c+2);
    printf("||             TOTAL              |     C$                         |     C$                      |     C$                    ||");
    gotoxy(2,c+3);
    printf("===============================================================================================================================");

    // IMPRIME EL TOTAL DE TODAS LAS VENTAS

    gotoxy(45, c+2);
    printf("%.2f", b);//INVERSION
    gotoxy(78, c+2);
    printf("%.2f", a);//PAGO
    gotoxy(108, c+2);
    printf("%.2f", d);//GANANCIAS

    gotoxy(2,c+4);
    system("pause");

    fclose(R);//CIERRA EL ARCHIVO

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void NuevoProducto() { //AGREGAR NUEVO PRODUCTO

    FILE *R, *V;//CREA LA VARIABLE DE ARCHIVO
    int retorno=0, enc;//VARIABLE DE RETORNO POR SI DESEA AGREGAR OTRO REGISTRO
    char code[30];

    do
    {//AGREGA OTRO REGISTRO
        system("cls");
        R=fopen("Inv_productos.txt", "ab");//ABRE EL ARCHIVO DE INVENTARIOS

        system("color 0B");

        do{//VERIFICA SI EL CODIGO YA EXISTE

            V=fopen("Inv_productos.txt", "r");

        gotoxy(31, 2);
        printf("\t============================================================\n");
        gotoxy(31, 3);
        printf("\t||                    COMPUTECNO S.A                      ||\n");
        gotoxy(31, 4);
        printf("\t============================================================\n");
        gotoxy(31, 5);
        printf("\t||    R E G I S T R A N D O  N U E V O  P R O D U C T O   ||\n");
        gotoxy(31, 6);
        printf("\t============================================================\n");
        gotoxy(31, 7);
        printf("\t|| PROVEEDOR           |                                  ||\n");
        gotoxy(31, 8);
        printf("\t============================================================\n");
        gotoxy(31, 9);
        printf("\t|| CODIGO DE BARRA     |                                  ||\n");
        gotoxy(31, 10);
        printf("\t============================================================\n");
        gotoxy(31, 11);
        printf("\t|| NOMBRE DEL PRODUCTO |                                  ||\n");
        gotoxy(31, 12);
        printf("\t============================================================\n");
        gotoxy(31, 13);
        printf("\t|| TIPO                |                                  ||\n");
        gotoxy(31, 14);
        printf("\t============================================================\n");
        gotoxy(31, 15);
        printf("\t|| MARCA               |                                  ||\n");
        gotoxy(31, 16);
        printf("\t============================================================\n");
        gotoxy(31, 17);
        printf("\t|| MODELO              |                                  ||\n");
        gotoxy(31, 18);
        printf("\t============================================================\n");
        gotoxy(31, 19);
        printf("\t|| DESCRIPCION         |                                  ||\n");
        gotoxy(31, 20);
        printf("\t============================================================\n");
        gotoxy(31, 21);
        printf("\t|| CANTIDAD            |                                  ||\n");
        gotoxy(31, 22);
        printf("\t============================================================\n");
        gotoxy(31, 23);
        printf("\t|| PRECIO DE COMPRA    |     C$                           ||\n");
        gotoxy(31, 24);
        printf("\t============================================================\n");
        gotoxy(31, 25);
        printf("\t|| PRECIO DE VENTA     |     C$                           ||\n");
        gotoxy(31, 26);
        printf("\t============================================================\n");

        // SOLICITAS LOS DATOS QUE VAN A SER ALMACENADOS

        gotoxy(58, 9);
        fflush(stdout);
        fflush(stdin);
        gets(code);

        enc=0;

        while ( fread(&P, sizeof(P), 1, V) )// LEE LOS REGISTROS
        {
            if (enc==0)
            {
                if (strcmp(code, P.codeB)==0)//COMPARA EL CODIGO
                {
                    enc=1;//EXISTE

                }//FIN DE IF

                else
                {
                    enc=0;//NO EXISTE

                }//FIN DE ELSE

            }//FIN DE IF ENC==0

        }//FIN DE WHILE

        if (enc==1)// SI EXISTE
        {
            codeexist();//INTERFAZ DE QUE SI EXISTE

        }//FIN DE IF
        else// SI NO EXISTE GUARDA EL CODIGO EN LA VARIABLE DE ESTRUCTURA
        {
            strcpy(P.codeB, code); //strcpy( <variable_destino>, <cadena_fuente> )
        }

        fclose(V);//CIERRA EL ARCHIVO

    }while(enc==1);//FIN DE DO WHILE

        gotoxy(58, 7);
        fflush(stdout);
        fflush(stdin);
        gets(P.proveedor);

        gotoxy(58, 11);
        fflush(stdout);
        fflush(stdin);
        gets(P.nombre);

        gotoxy(58, 13);
        fflush(stdout);
        fflush(stdin);
        gets(P.Tipo);

        gotoxy(58, 15);
        fflush(stdout);
        fflush(stdin);
        gets(P.marca);

        gotoxy(58, 17);
        fflush(stdout);
        fflush(stdin);
        gets(P.modelo);

        gotoxy(58, 19);
        fflush(stdout);
        fflush(stdin);
        gets(P.descrip);

        gotoxy(58, 21);
        fflush(stdout);
        fflush(stdin);
        scanf("%i",&P.cant);

        gotoxy(64, 23);
        fflush(stdout);
        fflush(stdin);
        scanf("%f",&P.precioC);

        gotoxy(64, 25);
        fflush(stdout);
        fflush(stdin);
        scanf("%f",&P.precio);

        fwrite(&P,sizeof(P),1,R);//LOS ESCRIBE EN EL ARCHIVO
        fclose(R);//CIERRA EL ARCHIVO

        save();//MENSAJE DE INTERFAZ
        scanf("%d", &retorno);//SI DESEA REGISTRAR OTRO REGISTRO

        system("color 0F");

    }while(retorno==1);//FIN DE DO

}//FIN DE VOID

void ModificarProducto() { //ACTUALIZAR PRODUCTO

           FILE *origen, *temp;// CREA DOS VARIABLES DE ARCHIVOS PARA MODIFICAR
           char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
           int enc=0;//VALIDACION DE ENCONTRADO

           remove("Temp.txt");//ELIMINA EL TEMPORAL

           origen=fopen("Inv_productos.txt","r");//ABRE EL REGISTRO EN MODO LECTURA
           temp=fopen("Temp.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA

           codemodify();//INTERFAZ DE SOLICITUD DE CODIGO
           fflush(stdout);
           fflush(stdin);
           gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA GUARDAR

           while(fread(&P,sizeof(P),1,origen))// LEE LOS REGISTROS
           {
               if(enc==0)
               {
                   if((strcmp(codigo,P.codeB))==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
                   {
                       int sc=0;
                       enc=1;//EL REGISTRO FUE ENCONTRADO

                       do
                       {//MODIFICAR OTRA INFORMACION
                            system("cls");

                            printf("\n\n");
                            printf("\t============================================================\n");
                            printf("\t||                    COMPUTECNO S.A                      ||\n");
                            printf("\t============================================================\n");
                            printf("\t||      M O D I F I C A C I O N  D E  P R O D U C T O     ||\n");
                            printf("\t============================================================\n");
                            printf("\t|| PROVEEDOR           | %s", P.proveedor);
                            gotoxy(66, 7);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| CODIGO DE BARRA     | %s", P.codeB);
                            gotoxy(66, 9);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| NOMBRE DEL PRODUCTO | %s", P.nombre);
                            gotoxy(66, 11);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| TIPO                | %s", P.Tipo);
                            gotoxy(66, 13);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| MARCA               | %s", P.marca);
                            gotoxy(66, 15);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| MODELO              | %s", P.modelo);
                            gotoxy(66, 17);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| DESCRIPCION         | %s", P.descrip);
                            gotoxy(66, 19);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| CANTIDAD            | %d", P.cant);
                            gotoxy(66, 21);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| PRECIO DE COMPRA    | C$ %.2f", P.precioC);
                            gotoxy(66, 23);
                            printf("||\n");
                            printf("\t============================================================\n");
                            printf("\t|| PRECIO DE VENTA     | C$ %.2f", P.precio);
                            gotoxy(66, 25);
                            printf("||\n");
                            printf("\t============================================================\n");

                            int opcmod=0;

                            fflush(stdout);
                            fflush(stdin);
                            gotoxy(74, 2);
                            printf("INGRESE UNA OPCION SEGUN LO QUE DESEE MODIFICAR:");
                            gotoxy(74, 4);
                            printf("      [1] MODIFICAR PROVEEDOR");
                            gotoxy(74, 6);
                            printf("      [2] MODIFICAR NOMBRE DEL PRODUCTO");
                            gotoxy(74, 8);
                            printf("      [3] MODIFICAR TIPO");
                            gotoxy(74, 10);
                            printf("      [4] MODIFICAR MARCA");
                            gotoxy(74, 12);
                            printf("      [5] MODIFICAR MODELO");
                            gotoxy(74, 14);
                            printf("      [6] MODIFICAR DESCRIPCION");
                            gotoxy(74, 16);
                            printf("      [7] MODIFICAR CANTIDAD");
                            gotoxy(74, 18);
                            printf("      [8] MODIFICAR PRECIO DE COMPRA");
                            gotoxy(74, 20);
                            printf("      [9] MODIFICAR PRECIO DE VENTA");
                            gotoxy(74, 22);
                            printf("     [10] SALIR");
                            gotoxy(74, 24);
                            printf(" --> ");
                            gotoxy(80, 24);
                            scanf("%i",&opcmod);

                            //MODIFICA LOS DATOS QUE EL USUARIO DESEE

                            switch(opcmod)
                            {
                                case 1:
                                {
                                    gotoxy(33,7);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.proveedor);

                                    break;
                                }

                                case 2:
                                {
                                    gotoxy(33,11);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.nombre);

                                    break;
                                }

                                case 3:
                                {
                                    gotoxy(33,13);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.Tipo);

                                    break;
                                }

                                case 4:
                                {
                                    gotoxy(33,15);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.marca);

                                    break;
                                }

                                case 5:
                                {
                                    gotoxy(33,17);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.modelo);

                                    break;
                                }

                                case 6:
                                {
                                    gotoxy(33,19);
                                    fflush(stdout);
                                    fflush(stdin);
                                    gets(P.descrip);

                                    break;
                                }

                                case 7:
                                {
                                    gotoxy(33,21);
                                    fflush(stdout);
                                    fflush(stdin);
                                    scanf("%d", &P.cant);

                                    break;
                                }

                                case 8:
                                {
                                    gotoxy(36,23);
                                    fflush(stdout);
                                    fflush(stdin);
                                    scanf("%f", &P.precioC);

                                    break;
                                }

                                case 9:
                                {
                                    gotoxy(36,25);
                                    fflush(stdout);
                                    fflush(stdin);
                                    scanf("%f", &P.precio);

                                    break;
                                }

                                case 10:
                                {
                                    sc=1;
                                    break;
                                }

                                default:
                                {
                                    tryagain();
                                }

                            }//FIN DE SWITCH

                     }while(!sc);//FIN DE DO

                     fwrite(&P,sizeof(P),1,temp);//ESCRIBE LOS NUEVOS DATOS REGISTRADOS POR EL USUARIO

                   }//FIN DE IF COMPARACION

                   else
                   {
                       fwrite(&P,sizeof(P),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                       enc=0;

                   }//FIN DE ELSE

               }//FIN DE IF ENC

               else
               {
                   system("cls");
                   fwrite(&P,sizeof(P),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

               }//FIN DE ELSE

           }//FIN DE WHILE

          if(enc==0)//NO ENCONTRADO
          {
              searching();//INTERFAZ DE NO ENCONTRADO

          }//FIN DE IF

          fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
          fclose(temp);// CIERRA EL ARCHIVO TEMPORAL
          remove("Inv_productos.txt");//ELIMINA EL REGISTRO DE PRODUCTOS
          rename("Temp.txt","Inv_productos.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR PRODUCTOS

}//FIN DE VOID

void EliminarProducto() { //ELIMINAR PRODUCTO


    FILE *origen, *temp;// CREA DOS VARIABLES DE ARCHIVOS PARA ELIMINAR
    char codigo[30];// VARIABLE PARA BUSCAR EL CODIGO DEL REGISTRO
    int enc=0;//VALIDACION DE ENCONTRADO

    remove("Temp.txt");//ELIMINA EL TEMPORAL

    origen=fopen("Inv_productos.txt","r");//ABRE EL REGISTRO DE CLIENTES EN MODO LECTURA
    temp=fopen("Temp.txt", "a");//ABRE EL TEMPORAL EN MODO DE ESCRITURA

    codedelete();//INTERFAZ DE SOLICITUD DE CODIGO
    fflush(stdout);
    fflush(stdin);
    gets(codigo);//GUARDA EL CODIGO DEL REGISTRO QUE DESEA BUSCAR
    system("cls");

    while(fread(&P,sizeof(P),1,origen))// LEE LOS REGISTROS
    {
        if(enc==0)
        {
            if((strcmp(codigo,P.codeB))==0)//HACE COMPARACIONES DE CODIGOS, SI SON LOS MISMOS
            {
                enc=1;//EL REGISTRO FUE ENCONTRADO

                printf("\n\n");
                printf("\t============================================================\n");
                printf("\t||                    COMPUTECNO S.A                      ||\n");
                printf("\t============================================================\n");
                printf("\t||            E L I M I N A R  P R O D U C T O            ||\n");
                printf("\t============================================================\n");
                printf("\t|| PROVEEDOR           | %s", P.proveedor);
                gotoxy(66, 7);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| CODIGO DE BARRA     | %s", P.codeB);
                gotoxy(66, 9);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| NOMBRE DEL PRODUCTO | %s", P.nombre);
                gotoxy(66, 11);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| TIPO                | %s", P.Tipo);
                gotoxy(66, 13);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| MARCA               | %s", P.marca);
                gotoxy(66, 15);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| MODELO              | %s", P.modelo);
                gotoxy(66, 17);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| DESCRIPCION         | %s", P.descrip);
                gotoxy(66, 19);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| CANTIDAD            | %d", P.cant);
                gotoxy(66, 21);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| PRECIO DE COMPRA    | C$ %.2f", P.precioC);
                gotoxy(66, 23);
                printf("||\n");
                printf("\t============================================================\n");
                printf("\t|| PRECIO DE VENTA     | C$ %.2f", P.precio);
                gotoxy(66, 25);
                printf("||\n");
                printf("\t============================================================\n");

                advertencia();//MENSAJE DE AVISO DE ELIMINACION

            }//FIN DE IF COMPARACION

            else
            {
                fwrite(&P,sizeof(P),1,temp);// ESCRIBE LOS REGISTROS QUE NO ENTRARON AL IF DE COMPARACION EN EL TEMPORAL
                enc=0;

            }//FIN DE ELSE

        }//FIN DE ENC

        else
        {
            fwrite(&P,sizeof(P),1,temp);//ESCRIBE LOS REGISTROS QUE NO HAYAN ENTRADO EN EL IF ENC==0 EN EL TEMPORAL

        }//FIN DE ELSE

    }//FIN DE WHILE

    if(enc==0)//NO ENCONTRADO
    {
        searching();//INTERFAZ DE NO ENCONTRADO

    }//FIN DE IF

    fclose(origen);//CIERRA EL ARCHIVO DE ORIGEN
    fclose(temp);// CIERRA EL ARCHIVO TEMPORAL

    if(enc==1)//ENCONTRADO
    {
        deletesucces();//MENSAJE DE AVISO DE ELIMINACION

    }//FIN DE IF

    remove("Inv_productos.txt");//ELIMINA EL REGISTRO DE PRODUCTOS
    rename("Temp.txt", "Inv_productos.txt");//EL REGISTRO TEMPORAL SE LE CAMBIA EL NOMBRE POR PRODUCTOS

}//FIN DE VOID

void R_InventarioN1() { // REGISTRO DE UN PRODUCTO

    char codigo[30];// VARIABLE DE BUSQUEDA
    int enc=0;// VALIDACION DE ENCONTRADO

    FILE *C;// DECLARACION DE VARIABLE DE ARCHIVO
    C=fopen("Inv_productos.txt","r");// ABRE EL ARCHIVO EN MODO LECTURA

    codesearch();// INTERFAZ DE BUSQUEDA
    fflush(stdout);
    fflush(stdin);
    gets(codigo);// LEE EL CODIGO
    system("cls");

    while(fread(&P,sizeof(P),1,C))//LEE LOS REGISTROS DE PRODUCTOS
    {
        if(enc==0)
        {
            if((strcmp(codigo,P.codeB))==0)// COMPARA LOS CODIGOS
            {
                enc=1;//ENCONTRADO

                gotoxy(31,2);
                printf("\t============================================================");
                gotoxy(31,3);
                printf("\t||                    COMPUTECNO S.A                      ||");
                gotoxy(31,4);
                printf("\t============================================================");
                gotoxy(31,5);
                printf("\t||            R E G I S T R O  P R O D U C T O            ||");
                gotoxy(31,6);
                printf("\t============================================================");
                gotoxy(31,7);
                printf("\t|| PROVEEDOR           | %s", P.proveedor);
                gotoxy(90,7);
                printf("||");
                gotoxy(31,8);
                printf("\t============================================================");
                gotoxy(31,9);
                printf("\t|| CODIGO DE BARRA     | %s", P.codeB);
                gotoxy(90,9);
                printf("||");
                gotoxy(31,10);
                printf("\t============================================================");
                gotoxy(31,11);
                printf("\t|| NOMBRE DEL PRODUCTO | %s", P.nombre);
                gotoxy(90, 11);
                printf("||");
                gotoxy(31,12);
                printf("\t============================================================");
                gotoxy(31,13);
                printf("\t|| TIPO                | %s", P.Tipo);
                gotoxy(90, 13);
                printf("||");
                gotoxy(31,14);
                printf("\t============================================================");
                gotoxy(31,15);
                printf("\t|| MARCA               | %s", P.marca);
                gotoxy(90, 15);
                printf("||");
                gotoxy(31,16);
                printf("\t============================================================");
                gotoxy(31,17);
                printf("\t|| MODELO              | %s", P.modelo);
                gotoxy(90, 17);
                printf("||");
                gotoxy(31,18);
                printf("\t============================================================");
                gotoxy(31,19);
                printf("\t|| DESCRIPCION         | %s", P.descrip);
                gotoxy(90, 19);
                printf("||");
                gotoxy(31,20);
                printf("\t============================================================");
                gotoxy(31,21);
                printf("\t|| CANTIDAD            | %d", P.cant);
                gotoxy(90, 21);
                printf("||");
                gotoxy(31,22);
                printf("\t============================================================");
                gotoxy(31,23);
                printf("\t|| PRECIO DE COMPRA    | C$ %.2f", P.precioC);
                gotoxy(90, 23);
                printf("||");
                gotoxy(31,24);
                printf("\t============================================================");
                gotoxy(31,25);
                printf("\t|| PRECIO DE VENTA     | C$ %.2f", P.precio);
                gotoxy(90, 25);
                printf("||");
                gotoxy(31,26);
                printf("\t============================================================");
                gotoxy(31,28);
                system("pause");

            }//FIN DE IF COMPARACION

        }//FIN DE ENC

    }//FIN DE WHILE

    if(enc==0)// NO ENCONTRADO
    {
        searching();// INTERFAZ DE NO ENCONTRADO

    }//FIN DE IF

    fclose(C);// CIERRA EL ARCHIVO
}

void R_InventarioT() { // TODOS LOS REGISTROS

    FILE *R;// DECLARACION DE ARCHIVO
    R=fopen("Inv_productos.txt","r");// ABRE EL ARCHIVO EN MODO LECTURA

    gotoxy(2,1);
    printf("===============================================================================================================================");
    gotoxy(2,2);
    printf("||                                                      COMPUTECNO S.A                                                       ||");
    gotoxy(2,3);
    printf("===============================================================================================================================");
    gotoxy(2,4);
    printf("||                              R  E  G  I  S  T  R  O     D  E     I  N  V  E  N  T  A  R  I  O                             ||");
    gotoxy(2,5);
    printf("===============================================================================================================================");
    gotoxy(2,6);
    printf("|| CODIGO |  PROVEEDOR  |     NOMBRE     |    MARCA    |         DESCRIPCION         |   CANT   |    COMPRA    |    VENTA    ||");
    gotoxy(2,7);
    printf("===============================================================================================================================");

    int c=7;

    while (fread(&P, sizeof(P), 1, R))// LEE LOS REGISTRES
    {
        // IMPRIME TODOS LOS REGISTROS DE PRODUCTOS

        gotoxy(2,++c);
        printf("||        |             |                |             |                             |          |              |             ||");
        gotoxy(4,c);
        printf(" %s", P.codeB);
        gotoxy(13,c);
        printf(" %s", P.proveedor);
        gotoxy(27,c);
        printf(" %s", P.nombre);
        gotoxy(44,c);
        printf(" %s", P.marca);
        gotoxy(58,c);
        printf(" %s", P.descrip);
        gotoxy(88,c);
        printf(" %d", P.cant);
        gotoxy(99,c);
        printf(" C$ %.2f", P.precioC);
        gotoxy(114,c);
        printf(" C$ %.2f", P.precio);

    }

    gotoxy(2,c+1);
    printf("===============================================================================================================================");
    gotoxy(2,c+2);
    system("pause");

    fclose(R);// CIERRA EL ARCHIVO
}








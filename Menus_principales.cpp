#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Declaraciones_2.0.cpp"

using namespace std;

void Welcome() { //Bienvenida y verificacion

    system("mode con: cols=131 lines=30");// TAMAÑO DE LA PANTALLA DE LA CONSOLA
    system("pause");
    system("cls");

    logo();//FUNCION
    bienvenida();
    Verificacion();

}//FIN DE VOID WELCOME

void MenuPrincipal() {

    int opcM1, opcS, exit=0;// VARIABLES DE OPCIONES EN MENU

    do
    {
        opcM1=0; opcS=0;
        char timesave;
        time_t tiempo = time(0);
        char output[128],output2[128];
        struct tm *tlocal = localtime(&tiempo);
        (strftime(output2,128,"%H:%M:%S",tlocal)); // OBTIENE LA HORA DEL SISTEMA
        (strftime(output,128,"%d/%m/%y",tlocal)); // OBTIENE LA FECHA DEL SISTEMA

        system("cls");

        system("color 0B");

        gotoxy(31, 4);
        printf("\t============================================================\n");
        gotoxy(31, 5);
        printf("\t||                    COMPUTECNO S.A                      ||\n");
        gotoxy(31, 6);
        printf("\t============================================================\n");
        gotoxy(31, 7);
        printf("\t|| FECHA |                          || HORA |             ||\n");
        gotoxy(31, 8);
        printf("\t============================================================\n");
        gotoxy(44,7);
        printf("%s\n", output);//FECHA
        gotoxy(79,7);
        printf("%s\n", output2);//HORA
        gotoxy(31, 9);
        printf("\t||                                                        ||\n");
        gotoxy(31, 10);
        printf("\t||                [1] CLIENTES                            ||\n");
        gotoxy(31, 11);
        printf("\t||                                                        ||\n");
        gotoxy(31, 12);
        printf("\t||                [2] VENTAS                              ||\n");
        gotoxy(31, 13);
        printf("\t||                                                        ||\n");
        gotoxy(31, 14);
        printf("\t||                [3] INVENTARIOS                         ||\n");
        gotoxy(31, 15);
        printf("\t||                                                        ||\n");
        gotoxy(31, 16);
        printf("\t||                [4] REPORTES                            ||\n");
        gotoxy(31, 17);
        printf("\t||                                                        ||\n");
        gotoxy(31, 18);
        printf("\t||                [5] SALIR DEL PROGRAMA                  ||\n");
        gotoxy(31, 19);
        printf("\t||                                                        ||\n");
        gotoxy(31, 20);
        printf("\t============================================================\n");
        gotoxy(31, 21);
        printf("\t||  OPCION | -->                                          ||\n");
        gotoxy(31, 22);
        printf("\t============================================================\n");
        gotoxy(50, 21);
        scanf("%d",&opcM1);

        system("color 0F");

        system("cls");
        fflush(stdin);
        fflush(stdout);

        switch (opcM1)
        {
            case 1: {//CLIENTES

                gotoxy(31, 4);
                printf("\t============================================================\n");
                gotoxy(31, 5);
                printf("\t||                    COMPUTECNO S.A                      ||\n");
                gotoxy(31, 6);
                printf("\t============================================================\n");
                gotoxy(31, 7);
                printf("\t||               M E N U   C L I E N T E S                ||\n");
                gotoxy(31, 8);
                printf("\t============================================================\n");
                gotoxy(31, 9);
                printf("\t||                                                        ||\n");
                gotoxy(31, 10);
                printf("\t||             [1] NUEVO CLIENTE                          ||\n");
                gotoxy(31, 11);
                printf("\t||                                                        ||\n");
                gotoxy(31, 12);
                printf("\t||             [2] MODIFICAR UN CLIENTE                   ||\n");
                gotoxy(31, 13);
                printf("\t||                                                        ||\n");
                gotoxy(31, 14);
                printf("\t||             [3] ELIMINAR UN CLIENTE                    ||\n");
                gotoxy(31, 15);
                printf("\t||                                                        ||\n");
                gotoxy(31, 16);
                printf("\t||             [4] REGRESAR AL MENU PRINCIPAL             ||\n");
                gotoxy(31, 17);
                printf("\t||                                                        ||\n");
                gotoxy(31, 18);
                printf("\t============================================================\n");
                gotoxy(31, 19);
                printf("\t||  OPCION | -->                                          ||\n");
                gotoxy(31, 20);
                printf("\t============================================================\n");
                gotoxy(50, 19);
                scanf("%d",&opcS);

                system("cls");

                switch (opcS) {

                    case 1: {

                        NuevoCliente();

                        break;
                    }//FIN DE CASE 1

                    case 2: {

                        ModificarCliente();

                        break;
                    }//FIN DE CASE 2

                    case 3: {

                        EliminarCliente();

                        break;
                    }//FIN DE CASE 3

                    case 4: {

                        exit=0;

                        break;
                    }//FIN DE CASE 4

                    default: {

                        tryagain();

                        break;
                    }//FIN DE DEFAULT

                }//FIN DE SWITCH

                break;
            }//FIN DE CASE 1

            case 2: {//VENTAS

                gotoxy(31, 4);
                printf("\t============================================================\n");
                gotoxy(31, 5);
                printf("\t||                    COMPUTECNO S.A                      ||\n");
                gotoxy(31, 6);
                printf("\t============================================================\n");
                gotoxy(31, 7);
                printf("\t||                 M E N U   V E N T A S                  ||\n");
                gotoxy(31, 8);
                printf("\t============================================================\n");
                gotoxy(31, 9);
                printf("\t||                                                        ||\n");
                gotoxy(31, 10);
                printf("\t||             [1] NUEVA VENTA                            ||\n");
                gotoxy(31, 11);
                printf("\t||                                                        ||\n");
                gotoxy(31, 12);
                printf("\t||             [2] MODIFICAR UNA VENTA                    ||\n");
                gotoxy(31, 13);
                printf("\t||                                                        ||\n");
                gotoxy(31, 14);
                printf("\t||             [3] ELIMINAR UNA VENTA                     ||\n");
                gotoxy(31, 15);
                printf("\t||                                                        ||\n");
                gotoxy(31, 16);
                printf("\t||             [4] REGRESAR AL MENU PRINCIPAL             ||\n");
                gotoxy(31, 17);
                printf("\t||                                                        ||\n");
                gotoxy(31, 18);
                printf("\t============================================================\n");
                gotoxy(31, 19);
                printf("\t||  OPCION | -->                                          ||\n");
                gotoxy(31, 20);
                printf("\t============================================================\n");
                gotoxy(50, 19);
                scanf("%d",&opcS);

                system("cls");
                fflush(stdin);
                fflush(stdout);

                switch (opcS) {

                    case 1: {

                        NuevaVenta();

                        break;
                    }//FIN DE CASE 1

                    case 2: {

                        ModificarVenta();

                        break;
                    }//FIN DE CASE 2

                    case 3: {

                        EliminarVenta();

                        break;
                    }//FIN DE CASE 3

                    case 4: {

                        exit=0;

                        break;
                    }//FIN DE CASE 4

                    default: {

                        tryagain();

                        break;
                    }//FIN DE DEFAULT

                }//FIN DE SWITCH

                break;
            }//FIN DE CASE 2

            case 3: {//INVENTARIOS

                gotoxy(31, 4);
                printf("\t============================================================\n");
                gotoxy(31, 5);
                printf("\t||                    COMPUTECNO S.A                      ||\n");
                gotoxy(31, 6);
                printf("\t============================================================\n");
                gotoxy(31, 7);
                printf("\t||              M E N U   I N V E N T A R I O             ||\n");
                gotoxy(31, 8);
                printf("\t============================================================\n");
                gotoxy(31, 9);
                printf("\t||                                                        ||\n");
                gotoxy(31, 10);
                printf("\t||             [1] NUEVO PRODUCTO                         ||\n");
                gotoxy(31, 11);
                printf("\t||                                                        ||\n");
                gotoxy(31, 12);
                printf("\t||             [2] MODIFICAR UN PRODUCTO                  ||\n");
                gotoxy(31, 13);
                printf("\t||                                                        ||\n");
                gotoxy(31, 14);
                printf("\t||             [3] ELIMINAR UN PRODUCTO                   ||\n");
                gotoxy(31, 15);
                printf("\t||                                                        ||\n");
                gotoxy(31, 16);
                printf("\t||             [4] REGRESAR AL MENU PRINCIPAL             ||\n");
                gotoxy(31, 17);
                printf("\t||                                                        ||\n");
                gotoxy(31, 18);
                printf("\t============================================================\n");
                gotoxy(31, 19);
                printf("\t||  OPCION | -->                                          ||\n");
                gotoxy(31, 20);
                printf("\t============================================================\n");
                gotoxy(50, 19);
                scanf("%d",&opcS);

                system("cls");
                fflush(stdin);
                fflush(stdout);

                switch (opcS) {

                    case 1: {

                        NuevoProducto();

                        break;
                    }//FIN DE CASE 1

                    case 2: {

                        ModificarProducto();

                        break;
                    }//FIN DE CASE 2

                    case 3: {

                        EliminarProducto();

                        break;
                    }//FIN DE CASE 3

                    case 4: {

                        exit=0;

                        break;
                    }//FIN DE CASE 4

                    default: {

                        tryagain();

                        break;
                    }//FIN DE DEFAULT

                }//FIN DE SWITCH

                break;
            }//FIN DE CASE 3

            case 4: {//REPORTES

                gotoxy(31, 4);
                printf("\t============================================================\n");
                gotoxy(31, 5);
                printf("\t||                    COMPUTECNO S.A                      ||\n");
                gotoxy(31, 6);
                printf("\t============================================================\n");
                gotoxy(31, 7);
                printf("\t||                M E N U   R E P O R T E S               ||\n");
                gotoxy(31, 8);
                printf("\t============================================================\n");
                gotoxy(31, 9);
                printf("\t||                                                        ||\n");
                gotoxy(31, 10);
                printf("\t||             [1] REPORTES CLIENTES                      ||\n");
                gotoxy(31, 11);
                printf("\t||                                                        ||\n");
                gotoxy(31, 12);
                printf("\t||             [2] REPORTES VENTAS                        ||\n");
                gotoxy(31, 13);
                printf("\t||                                                        ||\n");
                gotoxy(31, 14);
                printf("\t||             [3] REPORTES DE INVENTARIO                 ||\n");
                gotoxy(31, 15);
                printf("\t||                                                        ||\n");
                gotoxy(31, 16);
                printf("\t||             [4] REGRESAR AL MENU PRINCIPAL             ||\n");
                gotoxy(31, 17);
                printf("\t||                                                        ||\n");
                gotoxy(31, 18);
                printf("\t============================================================\n");
                gotoxy(31, 19);
                printf("\t||  OPCION | -->                                          ||\n");
                gotoxy(31, 20);
                printf("\t============================================================\n");
                gotoxy(50, 19);
                scanf("%d",&opcS);

                system("cls");
                fflush(stdin);
                fflush(stdout);

                switch (opcS) {

                    case 1: {

                        MenuR();
                        scanf("%d",&opcS);

                        system("cls");
                        fflush(stdin);
                        fflush(stdout);

                        switch (opcS) {

                            case 1: {

                                R_ClienteN1();

                                break;
                            }//Fin de case 1

                            case 2: {

                                R_ClienteT();

                                break;
                            }//Fin de case 2

                            case 3: {

                                exit=0;

                                break;
                            }//Fin de case 3

                            default: {

                                tryagain();

                            }//Fin de default

                        }//Fin de switch

                        break;
                    }//FIN DE CASE 1

                    case 2: {

                        MenuR();
                        scanf("%d",&opcS);

                        system("cls");
                        fflush(stdin);
                        fflush(stdout);

                        switch (opcS) {

                            case 1: {

                                R_VentasN1();

                                break;
                            }//Fin de case 1

                            case 2: {

                                R_VentasT();

                                break;
                            }//Fin de case 2

                            case 3: {

                                exit=0;

                                break;
                            }//Fin de case 3

                            default: {

                                tryagain();

                            }//Fin de default

                        }//Fin de switch

                        break;
                    }//FIN DE CASE 2

                    case 3: {

                        MenuR();
                        scanf("%d",&opcS);

                        system("cls");
                        fflush(stdin);
                        fflush(stdout);

                        switch (opcS) {

                            case 1: {

                                R_InventarioN1();

                                break;
                            }//Fin de case 1

                            case 2: {

                                R_InventarioT();

                                break;
                            }//Fin de case 2

                            case 3: {

                                exit=0;

                                break;
                            }//Fin de case 3

                            default: {

                                tryagain();

                            }//Fin de default

                        }//Fin de switch

                        break;
                    }//FIN DE CASE 3

                }//FIN DE SWITCH


                break;
            }//FIN DE CASE 4

            case 5: {//SALIDA

                fflush(stdin);
                fflush(stdout);

                Salida();
                exit=1;

                break;
            }//FIN DE CASE 5

            default: {

                tryagain();// INTERFAZ DE OPCION INVALIDA

            }//FIN DE DEFAULT

        }//FIN DE SWITCH

    }while (!exit);//FIN DE DO

}


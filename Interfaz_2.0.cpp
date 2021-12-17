#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Declaraciones_2.0.cpp"

using namespace std;

//INTERFAZES

void gotoxy (int x , int y) { //Tabulación de los registros e inventarios

    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition (hCon, dwPos);
}

void logo() { // LOGO DE LA EMPRESA

    system("color 0F");

    gotoxy(12,10);
    printf("   ____                                       _                                     ____           _     \n");
    gotoxy(12,11);
    printf("  / ___|   ___    _ __ ___    _ __    _   _  | |_    ___    ___   _ __     ___     / ___|         / \\    \n");
    gotoxy(12,12);
    printf(" | |      / _ \\  | '_ ` _ \\  | '_ \\  | | | | | __|  / _ \\  / __| | '_ \\   / _ \\    \\___ \\        / _ \\   \n");
    gotoxy(12,13);
    printf(" | |___  | (_) | | | | | | | | |_) | | |_| | | |_  |  __/ | (__  | | | | | (_) |    ___) |  _   / ___ \\  \n");
    gotoxy(12,14);
    printf("  \\____|  \\___/  |_| |_| |_| | .__/   \\__,_|  \\__|  \\___|  \\___| |_| |_|  \\___/    |____/  (_) /_/   \\_\\ \n");
    gotoxy(12,15);
    printf("                             |_|                                                                         \n\n\n");

    Sleep(2500);
    system("cls");

}

void bienvenida() { //INTERFAZ DE BIENVENIDA

    gotoxy(28,9);
    printf(" ____    _                                         _       _           _\n");
    gotoxy(28,10);
    printf("|  _ \\  (_)                                       (_)     | |         | |\n");
    gotoxy(28,11);
    printf("| |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___   | |\n");
    gotoxy(28,12);
    printf("|  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\  | |\n");
    gotoxy(28,13);
    printf("| |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) | |_|\n");
    gotoxy(28,14);
    printf("|____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/  (_)\n\n\n");
    gotoxy(28,16);
    system("pause");
    system("cls");
}

void tryagain() { // MENSAJE DE OPCION INCORRECTA

    system("cls");
    gotoxy(26, 12);
    system("color 4F");
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("|| Al parecer haz digitado una opcion invalida! Por favor intenta de nuevo! ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

    system("color 0F");

}

void codeexist() {// MENSAJE DE QUE EL CODIGO EXISTE

    system("color 4F");

    system("cls");
    gotoxy(26, 12);
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("||       Al parecer este codigo ya existe! Por favor intenta de nuevo!      ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

    system("color 0F");

    system("cls");

}

void save() { // MENSAJE DE REGISTRO GUARDADO CON EXITO

    system("cls");
    gotoxy(26, 12);
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("||                       Registro guardado con exito!                       ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

    system("cls");
    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||              Desea agregar otro registro?   [1] SI   [2] NO              ||\n");
    gotoxy(26, 13);
    printf("||                         -->                                              ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(58,13);

}

void RegisterC() { // MENSAJE REGISTRAR UN CLIENTE QUE NO EXISTE EN VENTAS

    system("cls");
    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("|| Desea regresar al menu principal para registrar al cliente? [1]SI  [2]NO ||\n");
    gotoxy(26, 13);
    printf("||              -->                                                         ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(46,13);
}

void Add() { //MENSAJE AGREGAR OTRO PRODUCTO

    system("cls");
    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||         Desea ordenar otro producto?   [1]SI  [2]NO                      ||\n");
    gotoxy(26, 13);
    printf("||              -->                                                         ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(46,13);
}

void deletesucces() { //MENSAJE DE ELIMINACION EXITOSA

    system("cls");
    gotoxy(26, 12);
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("||                       Registro eliminado con exito!                      ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

}//FIN DE VOID

void searching() { //MENSAJE DE REGISTRO NO ENCONTRADO

    system("cls");
    gotoxy(26, 12);
    system("color 4F");
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("||                         Registro no encontrado!                          ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

     system("color 0F");

}//FIN DE VOID

void stock() { // MENSAJE DE PRODUCTOS EN INVENTARIO

    system("cls");
    gotoxy(26, 12);
    printf("==============================================================================\n");
    gotoxy(26, 13);
    printf("||              NO HAY SUFICIENTE PRODUCTO SEGUN EL INVENTARIO!             ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    Sleep(3000);

}//FIN DE VOID

void codemodify() { // MENSAJE DE SOLICITUD DE CODIGO PARA MODIFICAR

    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||    Estimado usuario digite el codigo del registro que desea modificar    ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);

}//FIN DE VOID

void codesearch() { // MENSAJE DE SOLICITUD DE CODIGO PARA BUSCAR

    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||    Estimado usuario digite el codigo del registro que desea consultar    ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);
}

void codebuy() { // MENSAJE DE SOLICITUD DE CODIGO PARA COMPRAR

    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||     Estimado usuario digite el codigo del producto que desea comprar     ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);
}

void codedelete() { // MENSAJE DE SOLICITUD DE CODIGO PARA ELIMINAR

    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||     Estimado usuario digite el codigo del registro que desea eliminar    ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);

}//FIN DE VOID

void codeID() { // MENSAJE DE SOLICITUD DE CODIGO PARA BUSCAR CLIENTE

    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||     Estimado usuario digite el numero de identificacion del cliente      ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);

}//FIN DE VOID

void cant() { // MENSAJE DE CANTIDADES DE PRODUCTOS

    system("cls");
    gotoxy(26, 11);
    printf("==============================================================================\n");
    gotoxy(26, 12);
    printf("||         Digite la cantidad que desea el cliente de este producto         ||\n");
    gotoxy(26, 13);
    printf("||               -->                                                        ||\n");
    gotoxy(26, 14);
    printf("==============================================================================\n");
    gotoxy(48,13);

}//FIN DE VOID

void advertencia() { // MENSAJE DE AVISO DE ELIMINACION

    gotoxy(74,6);
    printf("          d8888          d8b  \n");
    gotoxy(74,7);
    printf("         d88888          Y8P   \n");
    gotoxy(74,8);
    printf("        d88P888                     \n");
    gotoxy(74,9);
    printf("       d88P 888 888  888 888 .d8888b   .d88b.\n");
    gotoxy(74,10);
    printf("      d88P  888 888  888 888 88K      d88\"\"88b \n");
    gotoxy(74,11);
    printf("     d88P   888 Y88  88P 888 \"Y8888b. 888  888 \n");
    gotoxy(74,12);
    printf("    d8888888888  Y8bd8P  888      X88 Y88..88P \n");
    gotoxy(74,13);
    printf("   d88P     888   Y88P   888  88888P'  \"Y88P\"  \n");

    gotoxy(74,15);
    printf("=====================================================\n");
    gotoxy(74,16);
    printf("||          Este registro sera eliminado!          ||\n");
    gotoxy(74,17);
    printf("=====================================================\n");
    gotoxy(74,19);
    system("pause");

}

void Verificacion() { // LOGIN- INICIO DE SESION

    int exit = 0;

    do
    {

     char username[10],password[10];//VARIABLES QUE SE VAN A USAR PARA COMPARAR
     const char user[10] = "admin";//EL USUARIO
     const char contra[10] = "12345";//CONTRASENA

     system("cls");

     system("color 0D");

        gotoxy(44, 9);
        printf("================================\n");
        gotoxy(44, 10);
        printf("|        INICIAR SESION        |\n");
        gotoxy(44, 11);
        printf("================================\n");
        gotoxy(44, 12);
        printf("|Usuario :                     |\n");
        gotoxy(44, 13);
        printf("--------------------------------\n");
        gotoxy(44, 14);
        printf("|Contrasenia :                 |\n");
        gotoxy(44, 15);
        printf("================================\n\n\n");

        gotoxy(56, 12);
        gets(username);
        gotoxy(59, 14);
        gets(password);
        Sleep(1500);

        system("color 0F");

        system("cls");

        if ( (strcmp(username,user) == 0 ) && (strcmp(password,contra) == 0 ) )
        {
            gotoxy(17, 11);
            system("color 0A");
            printf("==============================================================================================\n");
            gotoxy(17, 12);
            printf("|                  Bienvenido! Sera redirigido al menu de Computecno S.A...                  |\n");
            gotoxy(17, 13);
            printf("==============================================================================================\n\n");
            Sleep(3000);
            exit=1;
        }

        system("color 0F");

        if ( (strcmp(username,user) != 0 ) || (strcmp(password,contra) != 0 ) )
        {
            gotoxy(17, 11);
            system("color 4F");
            printf("==============================================================================================\n");
            gotoxy(17, 12);
            printf("|             Los datos ingresados son erroneos! Verifique e intente de nuevo...             |\n");
            gotoxy(17, 13);
            printf("==============================================================================================\n\n");
            Sleep(3000);
        }

    }while(exit==0); //FIN DE DO WHILE

    MenuPrincipal();

}//FIN DE VOID

void MenuR() { // MENU DE REGISTROS

    system("color 0F");

    gotoxy(31, 7);
    printf("\t============================================================\n");
    gotoxy(31, 8);
    printf("\t||                    COMPUTECNO S.A                      ||\n");
    gotoxy(31, 9);
    printf("\t============================================================\n");
    gotoxy(31, 10);
    printf("\t||               M E N U   R E G I S T R O S              ||\n");
    gotoxy(31, 11);
    printf("\t============================================================\n");
    gotoxy(31, 12);
    printf("\t||                                                        ||\n");
    gotoxy(31, 13);
    printf("\t||             [1] BUSCAR POR CODIGO                      ||\n");
    gotoxy(31, 14);
    printf("\t||                                                        ||\n");
    gotoxy(31, 15);
    printf("\t||             [2] MOSTRAR TODOS LOS REGISTROS            ||\n");
    gotoxy(31, 16);
    printf("\t||                                                        ||\n");
    gotoxy(31, 17);
    printf("\t||             [3] REGRESAR AL MENU PRINCIPAL             ||\n");
    gotoxy(31, 18);
    printf("\t||                                                        ||\n");
    gotoxy(31, 19);
    printf("\t============================================================\n");
    gotoxy(31, 20);
    printf("\t||  OPCION | -->                                          ||\n");
    gotoxy(31, 21);
    printf("\t============================================================\n");
    gotoxy(50, 20);

}// FIN DE VOID

void Salida() { // INTERFAZ DE SALIDA

    logo();

    gotoxy(20,10);
    system("color 0E");
    printf("  _   _                 _                                              _             _ ");
    gotoxy(20,11);
    printf(" | | | |   __ _   ___  | |_    __ _     _ __    _ __    ___    _ __   | |_    ___   | |");
    gotoxy(20,12);
    printf(" | |_| |  / _` | / __| | __|  / _` |   | '_ \\  | '__|  / _ \\  | '_ \\  | __|  / _ \\  | |");
    gotoxy(20,13);
    printf(" |  _  | | (_| | \\__ \\ | |_  | (_| |   | |_) | | |    | (_) | | | | | | |_  | (_) | |_|");
    gotoxy(20,14);
    printf(" |_| |_|  \\__,_| |___/  \\__|  \\__,_|   | .__/  |_|     \\___/  |_| |_|  \\__|  \\___/  (_)");
    gotoxy(20,15);
    printf("                                       |_|                                             ");
    Sleep(3000);
    system("cls");

    gotoxy(40,8);
    printf("==========================================");
    gotoxy(40,9);
    printf("||         CREADORES DEL SOFTWARE       ||");
    gotoxy(40,10);
    printf("==========================================");
    gotoxy(40,11);
    printf("||                                      ||");
    gotoxy(40,12);
    printf("|| - Armando Ernesto Cordero Montoya    ||");
    gotoxy(40,13);
    printf("||                                      ||");
    gotoxy(40,14);
    printf("|| - Josue Daniel Lumbi Gonzalez        ||");
    gotoxy(40,15);
    printf("||                                      ||");
    gotoxy(40,16);
    printf("|| - Renchi Frabelle Melendez Simplina  ||");
    gotoxy(40,17);
    printf("||                                      ||");
    gotoxy(40,18);
    printf("==========================================");
    Sleep(2000);

}

void clienteregister() {

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


}






















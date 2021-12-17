#ifndef STRUCT_FINALPROYECTO_H_INCLUDED
#define STRUCT_FINALPROYECTO_H_INCLUDED

struct informacion_producto
{
    char proveedor[50];
    char codeB[30];
    char nombre[40];//nombre del producto
    char Tipo[30];//tipo del producto
    char marca[20];//marca del producto
    char modelo[25];//modelo del producto
    char descrip[100];//descripcion del producto
    int cant;//cantidad de este producto
    float precio;//precio del producto
    float precioC;//precio de la compra del producto

}P;

struct ventas
{
    char fecha[128];
    char factN[30];//codigo de factura
    char idC[30];
    int cant_prod;//cantidad de productos
    float totalPago;// total a pagar
    float imp;
    float pagoFinal;
    float moneyG;//ganancias
    float inversionT;//inversion total del dia o periodo

}fact;

struct cliente_data
{
    char nombre_cliente[90];//nombre del cliente
    char id[30];//identificacion cliente
    char direccion[100];
    char telf[30];
    char e_mail[80];

}C;




#endif // STRUCT_FINALPROYECTO_H_INCLUDED

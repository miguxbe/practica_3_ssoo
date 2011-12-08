#ifndef _CONCURRENTE_H_
#define _CONCURRENTE_H_

/*
 * Incluir el resto de "includes" necesarios
 */
#include "bd_banco.h"

/*
 *  Descripci�n: funci�n que inicializa los recursos utilizados en 
 *  la biblioteca, as� como la base de datos utilizada. Usar solo una 
 *  vez al inicio.
 *  Valor de retorno: 0 -> ok, -1 -> error
 */
int concurrente_init();

/*
 *  Descripci�n: funci�n que elimina los recursos utilizados en la 
 *  biblioteca, as� como los utilizados en la base de datos. Usar solo 
 *  una vez al final del programa.
 *  Valor de retorno: 0 -> ok, -1 -> error
 */
int concurrente_destroy();

/*
 *  Descripci�n: funci�n que crea una cuenta en la base de 
 *  datos utilizando gesti�n de la concurrencia. En caso de encontrar
 *  otra cuenta con el mismo nombre, se considera que la creaci�n se
 *  ha realizado con �xito.
 *  Debe mantener la coherencia de la BD. No permite realizar otras 
 *  operaciones al mismo tiempo. 
 *  Entrada: nombre de la cuenta
 *  Valor de retorno: 0 -> ok, -1 -> error
 */
int concurrente_crear_cuenta(char *cuenta);


 /*
 *  Descripci�n: funci�n que consulta en la base de datos el n�mero 
 *  de cuentas existente utilizando gesti�n de la concurrencia. 
 *  Debe mantener la coherencia de la BD. Permite realizar otras
 *  operaciones de consulta al mismo tiempo.
 *  Salida: devuelve el n�mero de cuentas existentes en el banco.
 *  Valor de retorno: 0 -> ok, -1 -> error
 */
int concurrente_obtener_num_cuentas(int *num_cuentas);


/*
 *  Descripci�n: funci�n que borra una cuenta en la base de 
 *  datos utilizando gesti�n de la concurrencia. En caso de no encontrarse
 *  una cuenta con el mismo nombre, se considera que el borrado se
 *  ha realizado con �xito.
 *  Debe mantener la coherencia de la BD. No permite realizar otras 
 *  operaciones al mismo tiempo.
 *  Entrada: nombre de la cuenta
 *  Valor de retorno: 0 -> ok, -1 -> error
 */
int concurrente_borrar_cuenta(char *cuenta);

/*
 * Descripci�n: funci�n que incrementa el saldo de una cuenta y devuelve 
 * el saldo actualizado. 
 * Debe permitir actualizar o leer otras cuentas en paralelo.
 * Entrada: nombre de la cuenta y el saldo a actualizar
 * Salida: devuelve el saldo actualizado
 * Valor de retorno: 0 -> ok, -1 -> error (cuenta no encontrada, etc.)
 */
int concurrente_incrementar_saldo(char *cuenta, int saldo, int *saldo_actualizado);


/*
 * Descripci�n: funci�n que decrementa el saldo de una cuenta y devuelve 
 * el saldo actualizado
 * Debe permitir actualizar o leer otras cuentas en paralelo.
 * Entrada: nombre de la cuenta y el saldo a actualizar
 * Salida: devuelve el saldo actualizado
 * Valor de retorno: 0 -> ok, -1 -> error (cuenta no encontrada, etc.)
 */
int concurrente_decrementar_saldo(char *cuenta, int saldo, int *saldo_actualizado);


/*
 * Descripci�n: funci�n que devuelve el saldo de una cuenta
 * Debe permitir actualizar o leer otras cuentas en paralelo.
 * Entrada: nombre de la cuenta
 * Salida: devuelve el saldo actualizado
 * Valor de retorno: 0 -> ok, -1 -> error (cuenta no encontrada, etc.)
 */
int concurrente_obtener_saldo(char *cuenta, int *saldo);

#endif// _CONCURRENTE_H_

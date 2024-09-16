#ifndef KIWISCAN_H
#define KIWISCAN_H

#include <stdint.h>

/**
 * @brief Inicializa el sistema de escaneo de kiwis.
 * 
 * Esta función configura e inicializa todos los parámetros necesarios
 * para el correcto funcionamiento del sistema de escaneo de kiwis.
 */
void Kiwiscan_Init(void);

/**
 * @brief Añade el peso de un kiwi al total.
 * 
 * Suma el peso proporcionado al total acumulado de kiwis escaneados.
 * 
 * @param weight Peso del kiwi a añadir (en gramos).
 */
void Kiwiscan_AddWeight(uint16_t weight);

/**
 * @brief Elimina el peso de un kiwi.
 * 
 * Resta el peso proporcionado del total acumulado de kiwis escaneados.
 * 
 * @param weight Peso del kiwi a eliminar (en gramos).
 */
void Kiwiscan_RemoveWeight(uint16_t weight);

/**
 * @brief Devuelve el peso total de los kiwis escaneados.
 * 
 * Esta función devuelve el total acumulado del peso de los kiwis escaneados.
 * 
 * @return Peso total de los kiwis escaneados (en gramos).
 */
uint16_t Kiwiscan_GetTotalWeight(void);

/**
 * @brief Devuelve la cantidad de kiwis escaneados.
 * 
 * Esta función devuelve la cantidad total de kiwis escaneados hasta el momento.
 * 
 * @return Cantidad total de kiwis escaneados.
 */
uint16_t Kiwiscan_GetCount(void);

/**
 * @brief Calcula el peso promedio de los kiwis escaneados.
 * 
 * Calcula el peso promedio de los kiwis escaneados, dividiendo el peso total
 * acumulado entre la cantidad de kiwis.
 * 
 * @return Peso promedio de los kiwis escaneados (en gramos).
 */
uint16_t Kiwiscan_GetAverageWeight(void);

/**
 * @brief Resetea el sistema de escaneo.
 * 
 * Reinicia todos los valores del sistema de escaneo, incluyendo el peso total
 * y la cantidad de kiwis escaneados.
 */
void Kiwiscan_Reset(void);

#endif // KIWISCAN_H

#include "kiwiscan.h"

//! \brief Almacena el peso total de los kiwis escaneados.
static uint16_t total_weight = 0;

//! \brief Almacena la cantidad de kiwis escaneados.
static uint16_t kiwi_count = 0;

//! \brief Inicializa el sistema de escaneo de kiwis, reiniciando el peso total y la cantidad de kiwis.
void Kiwiscan_Init(void)
{
    total_weight = 0;
    kiwi_count = 0;
}

//! \brief Añade el peso de un kiwi al total y aumenta la cantidad de kiwis.
//! \param weight Peso del kiwi a añadir.
void Kiwiscan_AddWeight(uint16_t weight)
{
    total_weight += weight;
    kiwi_count++;
}

//! \brief Elimina el peso de un kiwi del total y disminuye la cantidad de kiwis, si es posible.
//! \param weight Peso del kiwi a eliminar.
//! \note Esta función no hace nada si no hay kiwis escaneados o si el peso a eliminar es mayor que el peso total.
void Kiwiscan_RemoveWeight(uint16_t weight)
{
    if (kiwi_count > 0 && total_weight >= weight)
    {
        total_weight -= weight;
        kiwi_count--;
    }
}

//! \brief Devuelve el peso total de los kiwis escaneados.
//! \return Peso total de los kiwis escaneados.
uint16_t Kiwiscan_GetTotalWeight(void)
{
    return total_weight;
}

//! \brief Devuelve la cantidad de kiwis escaneados.
//! \return Cantidad de kiwis escaneados.
uint16_t Kiwiscan_GetCount(void)
{
    return kiwi_count;
}

//! \brief Calcula y devuelve el peso promedio de los kiwis escaneados.
//! \return Peso promedio de los kiwis escaneados. Si no hay kiwis, devuelve 0.
uint16_t Kiwiscan_GetAverageWeight(void)
{
    if (kiwi_count == 0)
    {
        return 0;
    }
    return total_weight / kiwi_count;
}

//! \brief Resetea el sistema de escaneo, eliminando el peso total y la cantidad de kiwis.
void Kiwiscan_Reset(void)
{
    total_weight = 0;
    kiwi_count = 0;
}

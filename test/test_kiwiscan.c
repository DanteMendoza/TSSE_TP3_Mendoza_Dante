#include "unity.h"
#include "kiwiscan.h"

/**
 * @brief Configuración previa a cada prueba. 
 * Inicializa el sistema de escaneo de kiwis.
 */
void setUp(void)
{
    Kiwiscan_Init();
}

/**
 * @brief Función de limpieza posterior a cada prueba.
 * No requiere limpieza en este caso.
 */
void tearDown(void)
{
    // Nada que limpiar después de cada prueba
}

/**
 * @test Verifica que la inicialización del sistema funcione correctamente.
 * Se espera que el peso total y la cantidad de kiwis escaneados sean cero.
 */
void test_Kiwiscan_Init(void)
{
    TEST_ASSERT_EQUAL_UINT16(0, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(0, Kiwiscan_GetCount());
}

/**
 * @test Verifica la adición de un único kiwi.
 * Se espera que el peso total y la cantidad de kiwis reflejen la adición.
 */
void test_Kiwiscan_Add_One_Kiwi(void)
{
    Kiwiscan_AddWeight(150);

    TEST_ASSERT_EQUAL_UINT16(150, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(1, Kiwiscan_GetCount());
}

/**
 * @test Verifica la adición de múltiples kiwis.
 * Se espera que el sistema acumule correctamente los pesos y la cantidad de kiwis.
 */
void test_Kiwiscan_Add_Multiple_Kiwis(void)
{
    Kiwiscan_AddWeight(150);
    Kiwiscan_AddWeight(200);
    Kiwiscan_AddWeight(100);

    TEST_ASSERT_EQUAL_UINT16(450, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(3, Kiwiscan_GetCount());
}

/**
 * @test Verifica que la función para remover el peso de un kiwi funcione correctamente.
 * Se espera que el peso y la cantidad de kiwis se ajusten al eliminar uno.
 */
void test_Kiwiscan_Remove_Kiwi(void)
{
    Kiwiscan_AddWeight(150);
    Kiwiscan_AddWeight(200);
    
    Kiwiscan_RemoveWeight(150);

    TEST_ASSERT_EQUAL_UINT16(200, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(1, Kiwiscan_GetCount());
}

/**
 * @test Verifica el comportamiento al intentar remover más peso del permitido.
 * Se espera que ni el peso ni la cantidad de kiwis cambien si el peso a remover es mayor al total.
 */
void test_Kiwiscan_Remove_TooMuchWeight(void)
{
    Kiwiscan_AddWeight(100);

    // Intentar eliminar más peso del que se ha añadido
    Kiwiscan_RemoveWeight(200);

    // El peso y la cantidad no deberían cambiar
    TEST_ASSERT_EQUAL_UINT16(100, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(1, Kiwiscan_GetCount());
}

/**
 * @test Verifica el cálculo correcto del peso promedio de los kiwis.
 */
void test_Kiwiscan_GetAverageWeight(void)
{
    Kiwiscan_AddWeight(150);
    Kiwiscan_AddWeight(50);
    Kiwiscan_AddWeight(100);

    TEST_ASSERT_EQUAL_UINT16(100, Kiwiscan_GetAverageWeight());
}

/**
 * @test Verifica el cálculo del peso promedio cuando no hay kiwis escaneados.
 * Se espera que el resultado sea 0.
 */
void test_Kiwiscan_GetAverageWeight_NoKiwis(void)
{
    TEST_ASSERT_EQUAL_UINT16(0, Kiwiscan_GetAverageWeight());
}

/**
 * @test Verifica que la función de reseteo funcione correctamente.
 * Se espera que tanto el peso total como la cantidad de kiwis sean 0 tras el reinicio.
 */
void test_Kiwiscan_Reset(void)
{
    Kiwiscan_AddWeight(200);
    Kiwiscan_Reset();

    TEST_ASSERT_EQUAL_UINT16(0, Kiwiscan_GetTotalWeight());
    TEST_ASSERT_EQUAL_UINT16(0, Kiwiscan_GetCount());
}

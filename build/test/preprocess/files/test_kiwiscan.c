#include "src/kiwiscan.h"
#include "C:/Users/dmendoza/.local/share/gem/ruby/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










void setUp(void)

{

    Kiwiscan_Init();

}











void tearDown(void)

{



}











void test_Kiwiscan_Init(void)

{

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_Add_One_Kiwi(void)

{

    Kiwiscan_AddWeight(150);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((150)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_Add_Multiple_Kiwis(void)

{

    Kiwiscan_AddWeight(150);

    Kiwiscan_AddWeight(200);

    Kiwiscan_AddWeight(100);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((450)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((3)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_Remove_Kiwi(void)

{

    Kiwiscan_AddWeight(150);

    Kiwiscan_AddWeight(200);



    Kiwiscan_RemoveWeight(150);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((200)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_Remove_TooMuchWeight(void)

{

    Kiwiscan_AddWeight(100);





    Kiwiscan_RemoveWeight(200);





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_UINT16);

}









void test_Kiwiscan_GetAverageWeight(void)

{

    Kiwiscan_AddWeight(150);

    Kiwiscan_AddWeight(50);

    Kiwiscan_AddWeight(100);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((100)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetAverageWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_GetAverageWeight_NoKiwis(void)

{

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetAverageWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_UINT16);

}











void test_Kiwiscan_Reset(void)

{

    Kiwiscan_AddWeight(200);

    Kiwiscan_Reset();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetTotalWeight())), (

   ((void *)0)

   ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((Kiwiscan_GetCount())), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_UINT16);

}

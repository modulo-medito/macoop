/***************************************************************************************************
 * @file        animal_demo.c
 * @author      Modulo Medito (chcchc1995@outlook.com)
 * @brief
 *
 * @version     0.1.0
 * @date        2025-01-15
 * @copyright   Copyright (C) 2025 Modulo Medito
 **************************************************************************************************/
//==================================================================================================
// INCLUDE
//==================================================================================================
#include "animal.h"
#include "animal_demo.h"
#include <stdio.h>

//==================================================================================================
// DEFINE
//==================================================================================================

//==================================================================================================
// TYPEDEF
//==================================================================================================

//==================================================================================================
// ENUM
//==================================================================================================

//==================================================================================================
// STRUCTURE
//==================================================================================================

//==================================================================================================
// UNION
//==================================================================================================

//==================================================================================================
// LOCAL INLINE FUNCTION DECLARATION
//==================================================================================================

//==================================================================================================
// LOCAL FUNCTION DECLARATION
//==================================================================================================

//==================================================================================================
// GLOBAL FUNCTION DECLARATION
//==================================================================================================

//==================================================================================================
// LOCAL VARIABLE DEFINITION
//==================================================================================================

//==================================================================================================
// GLOBAL VARIABLE DEFINITION
//==================================================================================================

//==================================================================================================
// GLOBAL FUNCTION DEFINITION
//==================================================================================================
void animal_demo() {
    u16 num;

    // TODO: Can I combine VCALL and CALL?
    trait_new(animal1, Animal, Dog, .num = 5);
    call(animal1, say);
    num = call(animal1, getnum);
    printf("Animal1 is dog, num is %d\n", num);

    struct_new(bigdog, Dog, .num = 1);
    call(bigdog, say);

    trait_new(animal2, Animal, Cat, .num = 1000);
    call(animal2, say);
    num = call(animal2, getnum);
    printf("Animal2 is cat, num is %d\n", num);

    struct_new(ducky, Duck, .num = 1);
    call(ducky, say);
    num = call(ducky, getnum);
    printf("ducky num is %d\n", num);
}

//==================================================================================================
// LOCAL FUNCTION DEFINITION
//==================================================================================================

//==================================================================================================
// LOCAL INLINE FUNCTION DEFINITION
//==================================================================================================

//==================================================================================================
// TEST
//==================================================================================================

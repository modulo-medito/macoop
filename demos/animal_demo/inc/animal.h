/***************************************************************************************************
 * @file        animal.h
 * @author      Modulo Medito (chcchc1995@outlook.com)
 * @brief
 *
 * @version     0.1.0
 * @date        2025-01-15
 * @copyright   Copyright (C) 2025 Modulo Medito
 **************************************************************************************************/
#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus
//==================================================================================================
// INCLUDE
//==================================================================================================
#include "macoop.h"
#include "typedefs.h"

//==================================================================================================
// TYPEDEF
//==================================================================================================

//==================================================================================================
// DEFINE
//==================================================================================================

//==================================================================================================

//==================================================================================================
// ENUM
//==================================================================================================

//==================================================================================================
// STRUCTURE
//==================================================================================================
#define Animal_trait                                                                               \
    implfn(void, say)                                                                              \
    implfn(u16, getnum)

#define Beagle_implfn implfn(u8, getcolor)
#define Beagle_child
mstruct(Beagle)
    u8 color;
end

#define Dog_implfn                                                                                 \
    trait(Animal)                                                                                  \
    implfn(void, specical_move)
#define Dog_child child(Beagle, beagle_dog)
mstruct(Dog)
    u16 num;
end

#define Cat_implfn trait(Animal)
#define Cat_child
mstruct(Cat)
    u16 num;
end

#define Duck_implfn                                                                                \
    implfn(void, say)                                                                              \
    implfn(u16, getnum)
#define Duck_child
mstruct(Duck)
    u16 num;
end

//==================================================================================================
// UNION
//==================================================================================================

//==================================================================================================
// GLOBAL VARIABLE DECLARATION
//==================================================================================================

//==================================================================================================
// GLOBAL FUNCTION DECLARATION
//==================================================================================================

//==================================================================================================
// GLOBAL INLINE FUNCTION DEFINITION
//==================================================================================================

//==================================================================================================
// EOF
//==================================================================================================
#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif // #ifndef __ANIMAL_H__

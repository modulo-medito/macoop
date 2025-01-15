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
#define Animal_IMPLFN IMPLFN(void, say, mself), IMPLFN(u16, getnum, mself),
trait(Animal);

#define Dog_IMPLFN impl_trait(Animal), IMPLFN(void, specical_move, mself),
mstruct(Dog)
    u16 num;
    impl(Dog);
end

#define Cat_IMPLFN impl_trait(Animal),
mstruct(Cat)
    u16 num;
    impl(Cat);
end

#define Duck_IMPLFN IMPLFN(void, say, mself), IMPLFN(u16, getnum, mself),
mstruct(Duck)
    u16 num;
    impl(Duck);
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

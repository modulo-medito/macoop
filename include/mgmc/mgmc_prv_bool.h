/***************************************************************************************************
 * @file        mgmc_prv_bool.h
 * @author      Modulo Medito (chcchc1995@outlook.com)
 * @brief       Magic Macro primitives of boolean logic.
 *
 * @version     0.1.0
 * @date        2025-01-16
 * @copyright   Copyright (C) 2025 Modulo Medito
 **************************************************************************************************/
#ifndef __MGMC_PRV_BOOL_H__
#define __MGMC_PRV_BOOL_H__
#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus
//==================================================================================================
// INCLUDE
//==================================================================================================

//==================================================================================================
// DEFINE
//==================================================================================================
#define MGMC_PRV_BOOL_TRUE(...)  1
#define MGMC_PRV_BOOL_FALSE(...) 0

/// @brief      Not logic
/// @param[in]  b: boolean, 0 or 1
/// @par        Expansion:
/// @li         <MGMC_PRV_BOOL_NOT(0)> == _MGMC_PRV_BOOL_NOT_OVERLOAD(0)
/// @li         <_MGMC_PRV_BOOL_NOT_OVERLOAD(0)> == _MGMC_PRV_BOOL_NOT_##0
/// @li         <_MGMC_PRV_BOOL_NOT_0> == 1
#define _MGMC_PRV_BOOL_NOT_0           1
#define _MGMC_PRV_BOOL_NOT_1           0
#define _MGMC_PRV_BOOL_NOT_OVERLOAD(b) _MGMC_PRV_BOOL_NOT_##b
#define MGMC_PRV_BOOL_NOT(b)           _MGMC_PRV_BOOL_NOT_OVERLOAD(b)

/// @brief      Like (cond ? x : y), if condition is 1, expanded as x, else y
/// @param[in]  cond: condition, 0 or 1
/// @param[in]  x: true statement
/// @param[in]  y: false statement
/// @par        Expansion:
/// @li         <MGMC_PRV_BOOL_IF(0, x, y)> == _MGMC_PRV_BOOL_IF_OVERLOAD(0)(x, y)
/// @li         <_MGMC_PRV_BOOL_IF_OVERLOAD(0)>(x, y) == _MGMC_PRV_BOOL_IF_##0(x, y)
/// @li         <_MGMC_PRV_BOOL_IF_0(x, y)> == y
#define _MGMC_PRV_BOOL_IF_0(_x, y)       y
#define _MGMC_PRV_BOOL_IF_1(x, _y)       x
#define _MGMC_PRV_BOOL_IF_OVERLOAD(cond) _MGMC_PRV_BOOL_IF_##cond
#define MGMC_PRV_BOOL_IF(cond, x, y)     _MGMC_PRV_BOOL_IF_OVERLOAD(cond)(x, y)

//==================================================================================================
// EOF
//==================================================================================================
#ifdef __cplusplus
}
#endif // #ifdef __cplusplus
#endif // #ifndef __MGMC_PRV_BOOL_H__

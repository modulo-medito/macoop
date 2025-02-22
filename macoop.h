/***************************************************************************************************
 * @file        macoop.h
 * @author      Modulo Medito (chcchc1995@outlook.com)
 * @brief       Macro OOP.
 *              A zero-dependency header with rust-like macros that
 *              empowers object-oriented programming features for C.
 *              It is with leverage of C preprocessor tricks and without "malloc",
 *              which is suitable for embedded C projects developement.
 *              Inspired by:
 *              -   https://github.com/pfultz2/Cloak
 *              -   https://github.com/Hirrolot/interface99
 *              -   https://github.com/hirrolot/metalang99
 *              -   https://github.com/Akagi201/lw_oopc
 * @version     0.1.0
 * @date        2025-02-22
 * @copyright   Copyright (C) 2025 Modulo Medito
 **************************************************************************************************/
#ifndef __MACOOP_H__
#define __MACOOP_H__
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
#error Please specify /Zc:preprocessor to enable a standard-compliant C99/C++11 preprocessor, or   \
       add this into the CMakeLists.txt: `if(MSVC) add_compile_options(/Zc:preprocessor) endif()`
#endif
// clang-format off
//==================================================================================================
// Main Macros
//==================================================================================================
/// @brief  User in class header
#define implfn(...)                                                 implfn(__VA_ARGS__),
#define child(...)                                                  child(__VA_ARGS__),
#define childst                                                     MACOOP_CHILDST_API
#define mstruct                                                     MACOOP_STRUCT_API
/// @brief  Used in class source
#define fn                                                          MACOOP_FN_API
#define end                                                         MACOOP_END_API
#define impl                                                        MACOOP_IMPL_API
#define impl_trait                                                  MACOOP_IMPL_TRAIT_API
// #define trait                                                       MACOOP_TRAIT_API
#define trait                                                       MACOOP_IMPL_TRAIT_API_NEW
/// @brief  Used in user source
// #define trait_new                                                   MACOOP_TRAIT_NEW_API
#define trait_new                                                   MACOOP_TRAIT_NEW_API_NEW
#define struct_new                                                  MACOOP_STRUCT_NEW_API
#define call                                                        MACOOP_CALL_API
//==================================================================================================
// Utils Macros
//==================================================================================================
#ifndef ref
#define ref(a)                                                      (&(a))
#endif
#ifndef deref
#define deref(a)                                                    (*(a))
#endif
//==================================================================================================
// Private macros
//==================================================================================================
/// @brief  Append comma
#define MACOOP_APPEND_COMMA(...)                                    __VA_ARGS__,
//--------------------------------------------------------------------------------------------------
/// @brief  Concatenate
#define _MACOOP_CAT(a, b)                                           a##b
#define MACOOP_CAT(a, b)                                            _MACOOP_CAT(a, b)
//--------------------------------------------------------------------------------------------------
/// @brief  Expansion for one more scan
#define MACOOP_EXPAND(...)                                          __VA_ARGS__
//--------------------------------------------------------------------------------------------------
/// @brief  Defer expansion for one more scan
#define MACOOP_EMPTY()
#define MACOOP_DEFER(x) x                                           MACOOP_EMPTY()
//--------------------------------------------------------------------------------------------------
/// @brief  Detect if the parameter is a certain value
#define _MACOOP_CHECK_N(x, n, ...)                                  n
#define MACOOP_CHECK(...)                                           _MACOOP_CHECK_N(__VA_ARGS__, 0, )
//--------------------------------------------------------------------------------------------------
/// @brief  If branching
#define _MACOOP_IF_1(x, ...)                                        x
#define _MACOOP_IF_0(_x, ...)                                       __VA_ARGS__
#define MACOOP_IF(cond, x, y)                                       MACOOP_CAT(_MACOOP_IF_, cond)(x, y)
//--------------------------------------------------------------------------------------------------
/// @brief  Check arguments num is single
#define _MACOOP_VARGS_IS_SINGLE(                                    _1, _2, _3, _4, _5, _6,        \
                                                                    _7, _8, _9, _10, N, ...) N
#define MACOOP_VARGS_IS_SINGLE(...)                                 _MACOOP_VARGS_IS_SINGLE(       \
                                                                    __VA_ARGS__,                   \
                                                                    0, 0, 0, 0, 0, 0,              \
                                                                    0, 0, 0, 1, 0)
//--------------------------------------------------------------------------------------------------
/// @brief  Count args number, 64 maximum
#define _MACOOP_ARGS_COUNT(                                         _00, _01, _02, _03, _04,       \
                                                                    _05, _06, _07, _08, _09,       \
                                                                    _10, _11, _12, _13, _14,       \
                                                                    _15, _16, _17, _18, _19,       \
                                                                    _20, _21, _22, _23, _24,       \
                                                                    _25, _26, _27, _28, _29,       \
                                                                    _30, _31, _32, _33, _34,       \
                                                                    _35, _36, _37, _38, _39,       \
                                                                    _40, _41, _42, _43, _44,       \
                                                                    _45, _46, _47, _48, _49,       \
                                                                    _50, _51, _52, _53, _54,       \
                                                                    _55, _56, _57, _58, _59,       \
                                                                    _60, _61, _62, _63, _64,       \
                                                                    N, ...) N
//--------------------------------------------------------------------------------------------------
#define MACOOP_ARGS_COUNT(...)                                      _MACOOP_ARGS_COUNT(            \
                                                                     0, ##__VA_ARGS__,  64,        \
                                                                    63, 62, 61, 60, 59, 58,        \
                                                                    57, 56, 55, 54, 53, 52,        \
                                                                    51, 50, 49, 48, 47, 46,        \
                                                                    45, 44, 43, 42, 41, 40,        \
                                                                    39, 38, 37, 36, 35, 34,        \
                                                                    33, 32, 31, 30, 29, 28,        \
                                                                    27, 26, 25, 24, 23, 22,        \
                                                                    21, 20, 19, 18, 17, 16,        \
                                                                    15, 14, 13, 12, 11, 10,        \
                                                                     9,  8,  7,  6,  5,  4,        \
                                                                     3,  2,  1,  0)
//--------------------------------------------------------------------------------------------------
/// @brief  Check if is empty
#define _MACOOP_IS_EMPTY_implfn(...)                                _MACOOP_IS_EMPTY_N
#define _MACOOP_IS_EMPTY_child(...)                                 _MACOOP_IS_EMPTY_N
#define _MACOOP_IS_EMPTY_PROBE(x)                                   x, 1,
#define _MACOOP_IS_EMPTY_NT                                         0
#define _MACOOP_IS_EMPTY_T                                          _MACOOP_IS_EMPTY_PROBE()
#define MACOOP_IS_EMPTY_implfn(x, ...)                              MACOOP_CHECK(MACOOP_CAT(_MACOOP_IS_EMPTY_##x, T))
#define MACOOP_IS_EMPTY_child(x, ...)                               MACOOP_CHECK(MACOOP_CAT(_MACOOP_IS_EMPTY_##x, T))
#define _MACOOP_IS_EMPTY_0                                          1
#define _MACOOP_IS_EMPTY_1                                          0
#define _MACOOP_IS_EMPTY_2                                          0
#define _MACOOP_IS_EMPTY_3                                          0
#define _MACOOP_IS_EMPTY_4                                          0
#define _MACOOP_IS_EMPTY_5                                          0
#define _MACOOP_IS_EMPTY_6                                          0
#define _MACOOP_IS_EMPTY_7                                          0
#define _MACOOP_IS_EMPTY_8                                          0
#define _MACOOP_IS_EMPTY_9                                          0
#define _MACOOP_IS_EMPTY_10                                         0
#define _MACOOP_IS_EMPTY_11                                         0
#define _MACOOP_IS_EMPTY_12                                         0
#define _MACOOP_IS_EMPTY_13                                         0
#define _MACOOP_IS_EMPTY_14                                         0
#define _MACOOP_IS_EMPTY_15                                         0
#define _MACOOP_IS_EMPTY_16                                         0
#define MACOOP_IS_EMPTY(...)                                        MACOOP_CAT(_MACOOP_IS_EMPTY_, MACOOP_ARGS_COUNT(__VA_ARGS__))
//--------------------------------------------------------------------------------------------------
/// @brief  Evaluation, for recursion expansion
#define _MACOOP_EVAL5(...)                                          __VA_ARGS__
#define _MACOOP_EVAL4(...)                                          _MACOOP_EVAL5(_MACOOP_EVAL5(_MACOOP_EVAL5(__VA_ARGS__)))
#define _MACOOP_EVAL3(...)                                          _MACOOP_EVAL4(_MACOOP_EVAL4(_MACOOP_EVAL4(__VA_ARGS__)))
#define _MACOOP_EVAL2(...)                                          _MACOOP_EVAL3(_MACOOP_EVAL3(_MACOOP_EVAL3(__VA_ARGS__)))
#define _MACOOP_EVAL1(...)                                          _MACOOP_EVAL2(_MACOOP_EVAL2(_MACOOP_EVAL2(__VA_ARGS__)))
#define MACOOP_EVAL(...)                                            _MACOOP_EVAL1(_MACOOP_EVAL1(_MACOOP_EVAL1(__VA_ARGS__)))
//--------------------------------------------------------------------------------------------------
/// @brief  Unzip the arguments of <group_tag>(...)
///         For example, the result of `MACOOP_UPZIP_GROUP(implfn(void, say))` is
///             ```
///             void, say
///             ```
#define _MACOOP_UPZIP_implfn(...)                                   __VA_ARGS__
#define MACOOP_UPZIP_GROUP(...)                                     MACOOP_CAT(_MACOOP_UPZIP_, __VA_ARGS__)
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
//--------------------------------------------------------------------------------------------------
/// @brief  Apply macro operation for each child macro items
#define _MACOOP_FOR_EACH_CHILD_M0_child(x, ...)                     MACOOP_CAT(_MACOOP_FOR_EACH_CHILD_, MACOOP_IS_EMPTY_child(__VA_ARGS__))
#define _MACOOP_FOR_EACH_CHILD_M1(x, ...)                           (x, __VA_ARGS__)
#define _MACOOP_FOR_EACH_CHILD_0(m, x, ...)                         m(x) MACOOP_DEFER(_MACOOP_FOR_EACH_CHILD_I)()(m, __VA_ARGS__)
#define _MACOOP_FOR_EACH_CHILD_1(m, x, ...)                         m(x)
#define _MACOOP_FOR_EACH_CHILD_I()                                  MACOOP_FOR_EACH_CHILD_ITER
#define MACOOP_FOR_EACH_CHILD_ITER(m, ...)                          _MACOOP_FOR_EACH_CHILD_M0_child(__VA_ARGS__) _MACOOP_FOR_EACH_CHILD_M1(m, __VA_ARGS__)
//--------------------------------------------------------------------------------------------------
/// @brief  Apply macro operation for each implfn macro items
#define _MACOOP_FOR_EACH_M0_implfn(x, ...)                          MACOOP_CAT(_MACOOP_FOR_EACH_, MACOOP_IS_EMPTY_implfn(__VA_ARGS__))
#define _MACOOP_FOR_EACH_M1(x, ...)                                 (x, __VA_ARGS__)
#define _MACOOP_FOR_EACH_0(m, x, ...)                               m(x) MACOOP_DEFER(_MACOOP_FOR_EACH_I)()(m, __VA_ARGS__)
#define _MACOOP_FOR_EACH_1(m, x, ...)                               m(x)
#define _MACOOP_FOR_EACH_I()                                        MACOOP_FOR_EACH_IMPLFN_ITER
#define MACOOP_FOR_EACH_IMPLFN_ITER(m, ...)                         _MACOOP_FOR_EACH_M0_implfn(__VA_ARGS__) _MACOOP_FOR_EACH_M1(m, __VA_ARGS__)
//--------------------------------------------------------------------------------------------------
/// @brief  Apply macro for each implfn items with 1 argument
#define _MACOOP_FOR_EACH_IMPLFN_OP1_M0_implfn(a1, ...)              MACOOP_CAT(_MACOOP_FOR_EACH_IMPLFN_OP1_, MACOOP_IS_EMPTY_implfn(__VA_ARGS__))
#define _MACOOP_FOR_EACH_IMPLFN_OP1_M1(m, a1, ...)                  (m, a1, __VA_ARGS__)
#define _MACOOP_FOR_EACH_IMPLFN_OP1_0(m, a1, x, ...)                m(a1, x) MACOOP_DEFER(_MACOOP_FOR_EACH_IMPLFN_OP1_I)()(m, a1, __VA_ARGS__)
#define _MACOOP_FOR_EACH_IMPLFN_OP1_1(m, a1, x, ...)
#define _MACOOP_FOR_EACH_IMPLFN_OP1_I()                             MACOOP_FOR_EACH_IMPLFN_OP1_ITER
#define MACOOP_FOR_EACH_IMPLFN_OP1_ITER(m, a1, ...)                 _MACOOP_FOR_EACH_IMPLFN_OP1_M0_implfn(a1, __VA_ARGS__) _MACOOP_FOR_EACH_IMPLFN_OP1_M1(m, a1, __VA_ARGS__)
//--------------------------------------------------------------------------------------------------
/// @brief  Struct / Trait impl function extern generator
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_GEN_ST_IMPLFN_EXTERN(Dog)` is
///             ```
///             extern void Dog_say(Dog *self);
///             extern u16 Dog_getnum(Dog *self);
///             extern void Dog_setnum(Dog *selfu16 num);
///             ```
#define _MACOOP_ST_FNPTR_PARAM_1(...)
#define _MACOOP_ST_FNPTR_PARAM_0(...)                               , __VA_ARGS__
#define _MACOOP_ST_FNPTR_PARAM_OVL(st, ...)                         MACOOP_CAT(_MACOOP_ST_FNPTR_PARAM_, MACOOP_IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)
#define _MACOOP_ST_FNPTR_EXT(st, ret, fname, ...)                   extern ret st##_##fname(st *self _MACOOP_ST_FNPTR_PARAM_OVL(st, __VA_ARGS__));
#define _MACOOP_ST_FNPTR_EXT_HELPER(st, ...)                        _MACOOP_ST_FNPTR_EXT(st, __VA_ARGS__)
#define _MACOOP_GEN_ST_FNPTR_EXT(st, ...)                           _MACOOP_ST_FNPTR_EXT_HELPER(st, MACOOP_UPZIP_GROUP(__VA_ARGS__))
#define MACOOP_GEN_ST_IMPLFN_EXTERN(st)                             MACOOP_EVAL(MACOOP_FOR_EACH_IMPLFN_OP1_ITER(_MACOOP_GEN_ST_FNPTR_EXT, st, MACOOP_CAT(st, _implfn)))
#define MACOOP_GEN_TR_IMPLFN_EXTERN(trait, st)                      MACOOP_EVAL(MACOOP_FOR_EACH_IMPLFN_OP1_ITER(_MACOOP_GEN_ST_FNPTR_EXT, st, MACOOP_CAT(trait, _implfn)))
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_GEN_ST_IMPLFN_EXTERN(Dog)
//--------------------------------------------------------------------------------------------------
/// @brief  Struct / trait impl function pointer generator
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_GEN_ST_IMPLFN_PTR_CTOR(Dog)` is
///             ```
///             .say = Dog_say,
///             .getnum = Dog_getnum,
///             .setnum = Dog_setnum,
///             ```
#define _MACOOP_ST_FNPTR_CTOR(st, ret, fname, ...)                  .fname = st##_##fname,
#define _MACOOP_ST_FNPTR_CTOR_HELPER(st, ...)                       _MACOOP_ST_FNPTR_CTOR(st, __VA_ARGS__)
#define _MACOOP_GEN_ST_FNPTR_CTOR(st, ...)                          _MACOOP_ST_FNPTR_CTOR_HELPER(st, MACOOP_UPZIP_GROUP(__VA_ARGS__))
#define MACOOP_GEN_ST_IMPLFN_PTR_CTOR(st)                           MACOOP_EVAL(MACOOP_FOR_EACH_IMPLFN_OP1_ITER(_MACOOP_GEN_ST_FNPTR_CTOR, st, MACOOP_CAT(st, _implfn)))
#define MACOOP_GEN_TR_IMPLFN_PTR_CTOR(trait, st)                    MACOOP_EVAL(MACOOP_FOR_EACH_IMPLFN_OP1_ITER(_MACOOP_GEN_ST_FNPTR_CTOR, st, MACOOP_CAT(trait, _implfn)))
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_GEN_ST_IMPLFN_PTR_CTOR(Dog)
//--------------------------------------------------------------------------------------------------
/// @brief  Struct impl function pointer generator
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_GEN_ST_IMPLFN_PTR(Dog)` is
///             ```
///             void (*say)(Dog *self);
///             u16 (*getnum)(Dog *self);
///             void (*setnum)(Dog *self, u16 num);
///             ```
#define _MACOOP_GEN_ST_FNPTR_PARAM_1(...)
#define _MACOOP_GEN_ST_FNPTR_PARAM_0(...)                           , __VA_ARGS__
#define _MACOOP_GEN_ST_FNPTR_PARAM_OVL(st, ...)                     MACOOP_CAT(_MACOOP_ST_FNPTR_PARAM_, MACOOP_IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)
#define _MACOOP_GEN_ST_IMPLFN_PTR(st, rt, fname, ...)               rt (*fname)(st *self _MACOOP_GEN_ST_FNPTR_PARAM_OVL(st, __VA_ARGS__));
#define _MACOOP_GEN_ST_IMPLFN_PTR_OP_HELPER(st, ...)                _MACOOP_GEN_ST_IMPLFN_PTR(st, __VA_ARGS__)
#define _MACOOP_GEN_ST_IMPLFN_PTR_OP(st, ...)                       _MACOOP_GEN_ST_IMPLFN_PTR_OP_HELPER(st, MACOOP_UPZIP_GROUP(__VA_ARGS__))
#define MACOOP_GEN_ST_IMPLFN_PTR(st)                                MACOOP_EVAL(MACOOP_FOR_EACH_IMPLFN_OP1_ITER(_MACOOP_GEN_ST_IMPLFN_PTR_OP, st, MACOOP_CAT(st, _implfn)))
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_GEN_ST_IMPLFN_PTR(Dog)
//--------------------------------------------------------------------------------------------------
/// @brief Dummy struct, encapsulating the extern function declaration inside MACOOP_IMPL_API
#define MACOOP_DUMMY_STRUCT_NAME(prefix)                            MACOOP_CAT(prefix, MACOOP_CAT(Dummy, __LINE__))
#define MACOOP_DUMMY_STRUCT(prefix)                                 typedef struct MACOOP_DUMMY_STRUCT_NAME(prefix) MACOOP_DUMMY_STRUCT_NAME(prefix)
//--------------------------------------------------------------------------------------------------
/// @brief  Virtual table structure
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_VIRTUAL_TABLE_STRUCT(Dog)` is
///             ```
///             typedef struct Dog_VirtualTable Dog_VirtualTable;
///             struct Dog_VirtualTable {
///                 void *_dummy;
///                 void (*say)(Dog *self, );
///                 u16 (*getnum)(Dog *self, );
///                 void (*setnum)(Dog *self, u16 num);
///             };
///             extern const Dog_VirtualTable Dog_virtual_table;
///             ```
#define MACOOP_VIRTUAL_TABLE_STRUCT(st)                                                            \
    typedef struct st##_VirtualTable st##_VirtualTable;                                            \
    struct st##_VirtualTable {                                                                     \
        void *_dummy;                                                                              \
        MACOOP_GEN_ST_IMPLFN_PTR(st)                                                               \
    };                                                                                             \
    extern const st##_VirtualTable st##_virtual_table;
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_VIRTUAL_TABLE_STRUCT(Dog)
//--------------------------------------------------------------------------------------------------
/// @brief  Child struct generator
///         For example,
///             ```
///             #define Animal_child \
///                 child(Dog, dog1) \
///                 child(Cat, cat1)
///             ```
///         The result of `MACOOP_ST_CHILD_MEMBER_DEFINITION(Dog)` is
///             ```
///             Dog dog1;
///             Cat cat1;
///             ```
///         When the macro is empty,
///             ```
///             #define Animal_child
///             ```
///         The result of `MACOOP_ST_CHILD_MEMBER_DEFINITION(Dog)` is empty
#define _MACOOP_ST_CHILD_OP_child(child_st, name, ...)              child_st name;
#define _MACOOP_ST_CHILD_OP(tag)                                    MACOOP_EXPAND(MACOOP_CAT(_MACOOP_ST_CHILD_OP_, tag))
#define _MACOOP_CHILDST_HELPER_NO_CHILD(...)
#define _MACOOP_CHILDST_HELPER_HAS_CHILD(st)                        MACOOP_EVAL(MACOOP_FOR_EACH_CHILD_ITER(_MACOOP_ST_CHILD_OP, MACOOP_CAT(st, _child)))
#define MACOOP_ST_CHILD_MEMBER_DEFINITION(st)                       MACOOP_CAT(_MACOOP_CHILDST_HELPER_, MACOOP_IF(MACOOP_IS_EMPTY(st##_child), NO_CHILD, HAS_CHILD))(st)
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Animal_child
// #define Animal_child \
//     child(Dog, dog1) \
//     child(Cat, cat1)
// MACOOP_ST_CHILD_MEMBER_DEFINITION(Animal)
//--------------------------------------------------------------------------------------------------
/// @brief  Child struct virtual table binding statement generator
///         For example,
///             ```
///             #define Animal_child \
///                 child(Dog, dog1) \
///                 child(Cat, cat1)
///             ```
///         The result of `MACOOP_ST_CHILD_VTABLE_BINDING(Dog)` is
///             ```
///             .dog1 = ((Dog){.vptr = &(Dog_virtual_table)}),
///             .cat1 = ((Cat){.vptr = &(Cat_virtual_table)}),
///             ```
///         When the macro is empty,
///             ```
///             #define Animal_child
///             ```
///         The result of `MACOOP_ST_CHILD_VTABLE_BINDING(Dog)` is empty
#define _MACOOP_ST_CHILD_BINDING_OP_child(child_st, name, ...)      .name = ((child_st){.vptr = &(child_st##_virtual_table)}),
#define _MACOOP_ST_CHILD_BINDING_OP(tag)                            MACOOP_EXPAND(                 \
                                                                    MACOOP_CAT(                    \
                                                                    _MACOOP_ST_CHILD_BINDING_OP_,  \
                                                                    tag))
#define _MACOOP_CHILDST_BINDING_HELPER_NO_CHILD(...)
#define _MACOOP_CHILDST_BINDING_HELPER_HAS_CHILD(st)                MACOOP_EVAL(MACOOP_FOR_EACH_CHILD_ITER(_MACOOP_ST_CHILD_BINDING_OP, MACOOP_CAT(st, _child)))
#define MACOOP_ST_CHILD_VTABLE_BINDING(st)                          MACOOP_CAT(_MACOOP_CHILDST_BINDING_HELPER_, MACOOP_IF(MACOOP_IS_EMPTY(st##_child), NO_CHILD, HAS_CHILD))(st)
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Animal_child
// #define Animal_child \
//     child(Dog, dog1) \
//     child(Cat, cat1)
// MACOOP_ST_CHILD_VTABLE_BINDING(Animal)
//==================================================================================================
// Public macros, used in class header
//==================================================================================================
/// @brief  Trait definition in header
#define MACOOP_TRAIT_API(trait)                                                                    \
    typedef struct trait trait;                                                                    \
    struct trait {                                                                                 \
        void *vptr;                                                                                \
        MACOOP_GEN_ST_IMPLFN_PTR(trait)                                                            \
    }
//--------------------------------------------------------------------------------------------------
/// @brief  Struct definition in header
///         For example,
///             ```
///             #define Animal_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             #define Animal_child \
///                 child(Dog, dog1) \
///                 child(Cat, cat1)
///             ```
///         the result of `MACOOP_STRUCT_API(Animal)` is
///             ```
///             typedef struct Animal_VirtualTable Animal_VirtualTable;
///             struct Animal_VirtualTable {
///                 void *_dummy;
///                 void (*say)(Animal *self, );
///                 u16 (*getnum)(Animal *self, );
///                 void (*setnum)(Animal *self, u16 num);
///             };
///             extern const Animal_VirtualTable Animal_virtual_table;
///             extern void Animal_say(Animal *self, );
///             extern u16 Animal_getnum(Animal *self, );
///             extern void Animal_setnum(Animal *self, u16 num);
///             typedef struct Animal Animal;
///             struct Animal {
///                 Animal_VirtualTable *vptr;
///                 Dog dog1;
///                 Cat cat1;
///             ```
#define MACOOP_STRUCT_API(st)                                                                      \
    typedef struct st st;                                                                          \
    MACOOP_VIRTUAL_TABLE_STRUCT(st)                                                                \
    MACOOP_GEN_ST_IMPLFN_EXTERN(st)                                                                \
    struct st {                                                                                    \
        const st##_VirtualTable *vptr;                                                             \
        MACOOP_ST_CHILD_MEMBER_DEFINITION(st)
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Animal_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// #define Animal_child
// #define Animal_child \
//     child(Dog, dog1) \
//     child(Cat, cat1)
// MACOOP_STRUCT_API(Animal)
//==================================================================================================
// Public macros, used in class source (.c)
//==================================================================================================
/// @brief  Function prototype
///         For example,
///             ```
///             MACOOP_FN_API(Dog, u16, getnum)
///             ```
///         is expanded as
///             ```
///             u16 Dog_getnum(Dog *self) {
///             ```
///         For example,
///             ```
///             MACOOP_FN_API(Cat, void, setnum, u16 num)
///             ```
///         is expanded as
///             ```
///             void Cat_setnum(Cat *self, u16 num) {
///             ```
#define _MACOOP_FN_PROTOTYPE_PARAM_1(...)
#define _MACOOP_FN_PROTOTYPE_PARAM_0(...)                           , __VA_ARGS__
#define _MACOOP_FN_PROTOTYPE_PARAM_OVL(st, ...)                     MACOOP_CAT(_MACOOP_FN_PROTOTYPE_PARAM_, MACOOP_IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)
#define MACOOP_FN_API(st, rt, fname, ...)                           rt st##_##fname(st *self _MACOOP_FN_PROTOTYPE_PARAM_OVL(st, __VA_ARGS__)) {
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// MACOOP_FN_API(Dog, u16, getnum)
// MACOOP_FN_API(Cat, void, setnum, u16 num)
//--------------------------------------------------------------------------------------------------
/// @brief  Bracket for ending
#define MACOOP_END_API                                              };
//--------------------------------------------------------------------------------------------------
/// @brief  Trait function interface, used in struct function interface
#define MACOOP_IMPL_TRAIT_API(trait)                                trait##_implfn,
#define MACOOP_IMPL_TRAIT_API_NEW(trait)                            trait##_trait,
//--------------------------------------------------------------------------------------------------
/// @brief  Impl, placed in the beginning of a class source
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_IMPL_API(Dog)` is
///             ```
///             const Dog_VirtualTable Dog_virtual_table = (Dog_VirtualTable){
///                 ._dummy = 0,
///                 .say = Dog_say,
///                 .getnum = Dog_getnum,
///                 .setnum = Dog_setnum,
///             };
///             ```
#define MACOOP_IMPL_API(st)                                                                        \
    const st##_VirtualTable st##_virtual_table = {                                                 \
        ._dummy = 0,                                                                               \
        MACOOP_GEN_ST_IMPLFN_PTR_CTOR(st)                                                          \
    };
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_IMPL_API(Dog)
//==================================================================================================
// Public macros, used in user source (.c)
//==================================================================================================
/// @brief  New struct instance, with initialization of virtual table
///         For example,
///             ```
///             #define Animal_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             #define Animal_child \
///                 child(Dog, dog1) \
///                 child(Cat, cat1)
///             ```
///         The `MACOOP_STRUCT_NEW_API(Animal, animal)` is expanded as
///             ```
///             Animal animal = ((Animal){
///                 .vptr = &(Animal_virtual_table),
///                 .dog1 = ((Dog){.vptr = Dog_virtual_table}),
///                 .cat1 = ((Cat){.vptr = Cat_virtual_table}),
///             })
///             ```
///         When the `Animal_child` is empty, `MACOOP_STRUCT_NEW_API(Animal, animal)` expanded as
///             ```
///             Animal animal = ((Animal){
///                 .vptr = &(Animal_virtual_table),
///             })
///             ```
#define MACOOP_STRUCT_NEW_API(st, inst, ...)                                                       \
    st inst = ((st){                                                                               \
        MACOOP_IF(MACOOP_IS_EMPTY(__VA_ARGS__), MACOOP_EMPTY(), MACOOP_APPEND_COMMA(__VA_ARGS__))  \
        .vptr = &(st##_virtual_table),                                                             \
        MACOOP_ST_CHILD_VTABLE_BINDING(st)                                                         \
    })
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Animal_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// #define Animal_child
// #define Animal_child \
//     child(Dog, dog1) \
//     child(Cat, cat1)
// MACOOP_STRUCT_NEW_API(Animal, animal)
//--------------------------------------------------------------------------------------------------
/// @brief  New trait instance, with struct function extern declaration
#define MACOOP_TRAIT_NEW_API(trait, st, inst, ...)                                                 \
    trait inst = ((trait){                                                                         \
        MACOOP_IF(MACOOP_IS_EMPTY(__VA_ARGS__), MACOOP_EMPTY(), MACOOP_APPEND_COMMA(__VA_ARGS__))  \
        .vptr = &(st##_virtual_table),                                                             \
        MACOOP_ST_CHILD_VTABLE_BINDING(st)                                                         \
    })
//--------------------------------------------------------------------------------------------------
/// @brief  New trait instance, with struct function extern declaration
#define MACOOP_TRAIT_NEW_API_NEW(trait, st, inst, ...)              MACOOP_STRUCT_NEW_API(st, inst, __VA_ARGS__)
//--------------------------------------------------------------------------------------------------
/// @brief  Call object function
///         For example,
///             ```
///             #define Dog_implfn \
///                 implfn(void, say) \
///                 implfn(u16, getnum) \
///                 implfn(void, setnum, u16 num)
///             ```
///         The result of `MACOOP_CALL_API(Dog)` is
///             ```
///             ((dog).vptr->say(&(dog)))
///             ```
#define _MACOOP_CALL_1(obj, func)                                   func(obj)
#define _MACOOP_CALL_0(obj, func, ...)                              func(obj, __VA_ARGS__)
#define _MACOOP_CALL_OVL(...)                                       MACOOP_CAT(_MACOOP_CALL_, MACOOP_VARGS_IS_SINGLE(__VA_ARGS__))
#define MACOOP_CALL_API(obj, ...)                                   ((obj).vptr->_MACOOP_CALL_OVL(__VA_ARGS__)(&(obj), __VA_ARGS__))
/// TESTED BY UNCOMMENT BELOW AND CHECK THE EXPANDS
// #define Dog_implfn \
//     implfn(void, say) \
//     implfn(u16, getnum) \
//     implfn(void, setnum, u16 num)
// MACOOP_CALL_API(dog, say)
//==================================================================================================
// EOF
//==================================================================================================
// clang-format on
#endif // #ifndef __MACOOP_H__

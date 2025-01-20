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
 * @date        2025-01-21
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
// DEFINE
//==================================================================================================
//--------------------------------------------------------------------------------------------------
// Options
//--------------------------------------------------------------------------------------------------
/// @brief  Styles, you can also define your favorite one
#define MACOOP_OPTS_STYLE_UPPERCASE             (0)
#define MACOOP_OPTS_STYLE_LOWERCASE             (1)
//--------------------------------------------------------------------------------------------------
// Main Macros
//--------------------------------------------------------------------------------------------------
#if (MACOOP_OPTS_STYLE_UPPERCASE == 1)
/// @brief  Used in class source and header
#define SELF                                    MACOOP_SELF_API
/// @brief  User in class header
#define TRAIT                                   MACOOP_TRAIT_API
#define IMPL                                    MACOOP_IMPL_API
#define STRUCT                                  MACOOP_STRUCT_API
/// @brief  Used in class source
#define FN                                      MACOOP_FN_API
#define END                                     MACOOP_END_API
#define IMPL_TRAIT                              MACOOP_IMPL_TRAIT_API
/// @brief  Used in user source
#define TRAIT_NEW                               MACOOP_TRAIT_NEW_API
#define STRUCT_NEW                              MACOOP_STRUCT_NEW_API
#define CALL                                    MACOOP_CALL_API
#elif (MACOOP_OPTS_STYLE_LOWERCASE == 1)
/// @brief  Used in class source and header
#define mself                                   MACOOP_SELF_API
/// @brief  User in class header
#define trait                                   MACOOP_TRAIT_API
#define impl                                    MACOOP_IMPL_API
#define mstruct                                 MACOOP_STRUCT_API
/// @brief  Used in class source
#define fn                                      MACOOP_FN_API
#define end                                     MACOOP_END_API
#define impl_trait                              MACOOP_IMPL_TRAIT_API
/// @brief  Used in user source
#define trait_new                               MACOOP_TRAIT_NEW_API
#define struct_new                              MACOOP_STRUCT_NEW_API
#define call                                    MACOOP_CALL_API
#endif
//--------------------------------------------------------------------------------------------------
// Private macros
//--------------------------------------------------------------------------------------------------
/// @brief  Concatenate
#define _MACOOP_CAT(a, b)                       a##b
#define MACOOP_CAT(a, b)                        _MACOOP_CAT(a, b)
/// @brief  Expansion for one more scan
#define MACOOP_EXPAND(...)                      __VA_ARGS__
/// @brief  Defer expansion for one more scan
#define _MACOOP_EMPTY()
#define MACOOP_DEFER(x) x                       _MACOOP_EMPTY()
/// @brief  Detect if the parameter is a certain value
#define _MACOOP_CHECK_N(x, n, ...)              n
#define MACOOP_CHECK(...)                       _MACOOP_CHECK_N(__VA_ARGS__, 0, )
/// @brief  Check if is empty
#define _MACOOP_IS_EMPTY_IMPLFN(...)            _MACOOP_IS_EMPTY_N
#define _MACOOP_IS_EMPTY_PROBE(x)               x, 1,
#define _MACOOP_IS_EMPTY_NT                     0
#define _MACOOP_IS_EMPTY_T                      _MACOOP_IS_EMPTY_PROBE()
#define MACOOP_IS_EMPTY(x, ...)                 MACOOP_CHECK(MACOOP_CAT(_MACOOP_IS_EMPTY_##x, T))
/// @brief  Check arguments num
#define _MACOOP_VARGS_IS_SINGLE(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define MACOOP_VARGS_IS_SINGLE(...)             _MACOOP_VARGS_IS_SINGLE(                           \
                                                __VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0)
/// @brief  Evaluation, for recursion expansion
#define _MACOOP_EVAL5(...)                      __VA_ARGS__
#define _MACOOP_EVAL4(...)                      _MACOOP_EVAL5(_MACOOP_EVAL5(_MACOOP_EVAL5(__VA_ARGS__)))
#define _MACOOP_EVAL3(...)                      _MACOOP_EVAL4(_MACOOP_EVAL4(_MACOOP_EVAL4(__VA_ARGS__)))
#define _MACOOP_EVAL2(...)                      _MACOOP_EVAL3(_MACOOP_EVAL3(_MACOOP_EVAL3(__VA_ARGS__)))
#define _MACOOP_EVAL1(...)                      _MACOOP_EVAL2(_MACOOP_EVAL2(_MACOOP_EVAL2(__VA_ARGS__)))
#define MACOOP_EVAL(...)                        _MACOOP_EVAL1(_MACOOP_EVAL1(_MACOOP_EVAL1(__VA_ARGS__)))
/// @brief  Apply macro for each items
#define _MACOOP_FOR_EACH_M0(x, ...)             MACOOP_CAT(_MACOOP_FOR_EACH_, MACOOP_IS_EMPTY(__VA_ARGS__))
#define _MACOOP_FOR_EACH_M1(x, ...)             (x, __VA_ARGS__)
#define _MACOOP_FOR_EACH_0(m, x, ...)           m(x) MACOOP_DEFER(_MACOOP_FOR_EACH_I)()(m, __VA_ARGS__)
#define _MACOOP_FOR_EACH_1(m, x, ...)           m(x)
#define _MACOOP_FOR_EACH_I()                    MACOOP_FOR_EACH
#define MACOOP_FOR_EACH(m, ...)                 _MACOOP_FOR_EACH_M0(__VA_ARGS__) _MACOOP_FOR_EACH_M1(m, __VA_ARGS__)
/// @brief  Apply macro for each items with one argument
#define _MACOOP_FOR_EACH_OP1_M0(a1, ...)        MACOOP_CAT(_MACOOP_FOR_EACH_OP1_, MACOOP_IS_EMPTY(__VA_ARGS__))
#define _MACOOP_FOR_EACH_OP1_M1(m, a1, ...)     (m, a1, __VA_ARGS__)
#define _MACOOP_FOR_EACH_OP1_0(m, a1, x, ...)   m(a1, x) MACOOP_DEFER(_MACOOP_FOR_EACH_OP1_I)()(m, a1, __VA_ARGS__)
#define _MACOOP_FOR_EACH_OP1_1(m, a1, x, ...)
#define _MACOOP_FOR_EACH_OP1_I()                MACOOP_FOR_EACH_OP1
#define MACOOP_FOR_EACH_OP1(m, a1, ...)         _MACOOP_FOR_EACH_OP1_M0(a1, __VA_ARGS__) _MACOOP_FOR_EACH_OP1_M1(m, a1, __VA_ARGS__)
/// @brief  Unzip the arguments of <group_tag>(...)
///         For example,
///         assume a group is `IMPLFN(void, say, void *vself)` with group tag `IMPLFN`
///         the result of `MACOOP_UPZIP_GROUP(IMPLFN(void, say, void *vself))`
///         would be `void, say, void *vself`
#define _MACOOP_UPZIP_IMPLFN(...)               __VA_ARGS__
#define MACOOP_UPZIP_GROUP(...)                 MACOOP_CAT(_MACOOP_UPZIP_, __VA_ARGS__)
/// @brief  Struct / trait impl function extern generator
///         For example,
///         assume Dog_IMPLFN is `IMPLFN(void, say, SELF), IMPLFN(u16, getnum, SELF),`
///         The result of `MACOOP_GEN_ST_IMPLFN_EXTERN(Dog)`
///         would be `extern void Dog_say(SELF); extern u16 Dog_getnum(SELF);`
#define _MACOOP_ST_FNPTR_EXT(st, ret, f, ...)   extern ret st##_##f(__VA_ARGS__);
#define _MACOOP_ST_FNPTR_EXT_HELPER(st, ...)    _MACOOP_ST_FNPTR_EXT(st, __VA_ARGS__)
#define _MACOOP_GEN_ST_FNPTR_EXT(st, ...)                                                          \
    _MACOOP_ST_FNPTR_EXT_HELPER(st, MACOOP_UPZIP_GROUP(__VA_ARGS__))
#define MACOOP_GEN_ST_IMPLFN_EXTERN(st)                                                            \
    MACOOP_EVAL(MACOOP_FOR_EACH_OP1(_MACOOP_GEN_ST_FNPTR_EXT, st, MACOOP_CAT(st, _IMPLFN)))
#define MACOOP_GEN_TR_IMPLFN_EXTERN(trait, st)                                                     \
    MACOOP_EVAL(MACOOP_FOR_EACH_OP1(_MACOOP_GEN_ST_FNPTR_EXT, st, MACOOP_CAT(trait, _IMPLFN)))
/// @brief  Struct / trait impl function pointer generator
///         For example,
///         assume Dog_IMPLFN is `IMPLFN(void, say, SELF), IMPLFN(u16, getnum, SELF),`
///         The result of `MACOOP_GEN_ST_IMPLFN_PTR_CTOR(Dog)`
///         would be `.say = Dog_say, .getnum = Dog_getnum`
#define _MACOOP_ST_FNPTR_CTOR(st, ret, f, ...)  .f = st##_##f,
#define _MACOOP_ST_FNPTR_CTOR_HELPER(st, ...)   _MACOOP_ST_FNPTR_CTOR(st, __VA_ARGS__)
#define _MACOOP_GEN_ST_FNPTR_CTOR(st, ...)                                                         \
    _MACOOP_ST_FNPTR_CTOR_HELPER(st, MACOOP_UPZIP_GROUP(__VA_ARGS__))
#define MACOOP_GEN_ST_IMPLFN_PTR_CTOR(st)                                                          \
    MACOOP_EVAL(MACOOP_FOR_EACH_OP1(_MACOOP_GEN_ST_FNPTR_CTOR, st, MACOOP_CAT(st, _IMPLFN)))
#define MACOOP_GEN_TR_IMPLFN_PTR_CTOR(trait, st)                                                   \
    MACOOP_EVAL(MACOOP_FOR_EACH_OP1(_MACOOP_GEN_ST_FNPTR_CTOR, st, MACOOP_CAT(trait, _IMPLFN)))
/// @brief  Struct impl function pointer generator
///         For example,
///         assume Dog_IMPLFN is `IMPLFN(void, say, SELF), IMPLFN(u16, getnum, SELF),`
///         The result of `MACOOP_GEN_ST_IMPLFN_PTR(Dog)`
///         would be `void (*say)(SELF); u16 (*getnum)(SELF);`
#define _MACOOP_ST_FNPTR_OP_IMPLFN(rt, f, ...)  rt (*f)(__VA_ARGS__);
#define _MACOOP_ST_FNPTR_OP(tag)                MACOOP_EXPAND(MACOOP_CAT(_MACOOP_ST_FNPTR_OP_, tag))
#define MACOOP_GEN_ST_IMPLFN_PTR(st)                                                               \
    MACOOP_EVAL(MACOOP_FOR_EACH(_MACOOP_ST_FNPTR_OP, MACOOP_CAT(st, _IMPLFN)))
/// @brief Dummy struct, encapsulating the extern function declaration inside MACOOP_IMPL_API
#define MACOOP_DUMMY_STRUCT_NAME(prefix)        MACOOP_CAT(prefix, MACOOP_CAT(Dummy, __LINE__))
#define MACOOP_DUMMY_STRUCT(prefix)                                                                \
    typedef struct MACOOP_DUMMY_STRUCT_NAME(prefix) MACOOP_DUMMY_STRUCT_NAME(prefix)
//--------------------------------------------------------------------------------------------------
// Public macros, used in both class header and source
//--------------------------------------------------------------------------------------------------
/// @brief  Virtual self argument, convert to struct type in impl function
#define MACOOP_SELF_API                         void *vself
//--------------------------------------------------------------------------------------------------
// Public macros, used in class header
//--------------------------------------------------------------------------------------------------
/// @brief  Trait definition in header
#define MACOOP_TRAIT_API(trait)                                                                    \
    typedef struct trait trait;                                                                    \
    struct trait {                                                                                 \
        void *self;                                                                                \
        MACOOP_GEN_ST_IMPLFN_PTR(trait)                                                            \
    }
/// @brief  Struct datatype in header
#define MACOOP_STRUCT_API(st)                                                                      \
    typedef struct st st;                                                                          \
    struct st {
/// @brief  Impl, used inside struct
#define MACOOP_IMPL_API(st)                                                                        \
    st *self;                                                                                      \
    MACOOP_GEN_ST_IMPLFN_PTR(st) };                                                                \
    MACOOP_GEN_ST_IMPLFN_EXTERN(st)                                                                \
    MACOOP_DUMMY_STRUCT(st);                                                                       \
    struct MACOOP_DUMMY_STRUCT_NAME(st) { int dummy
//--------------------------------------------------------------------------------------------------
// Public macros, used in class source
//--------------------------------------------------------------------------------------------------
/// @brief  Function prototype
#define _MACOOP_SELF_INST(st)                   st *self = (st *)(vself)
#define MACOOP_FN_API(st, rt, f, ...)           rt st##_##f(__VA_ARGS__) { _MACOOP_SELF_INST(st);
#define MACOOP_END_API                          };
/// @brief  Trait function interface, used in struct function interface
#define MACOOP_IMPL_TRAIT_API(trait)            trait##_IMPLFN
//--------------------------------------------------------------------------------------------------
// Public macros, used in user source
//--------------------------------------------------------------------------------------------------
/// @brief  New trait instance, with struct function extern declaration
#define MACOOP_TRAIT_NEW_API(inst, trait, st, ...)                                                 \
    MACOOP_GEN_TR_IMPLFN_EXTERN(trait, st)                                                         \
    trait inst = ((trait){.self = (void *)&(st){__VA_ARGS__}, MACOOP_GEN_TR_IMPLFN_PTR_CTOR(trait, st)})
/// @brief  New struct instance, with struct function extern declaration
#define MACOOP_STRUCT_NEW_API(inst, st, ...)                                                       \
    st inst = ((st){__VA_ARGS__, .self = &(inst), MACOOP_GEN_ST_IMPLFN_PTR_CTOR(st)})
/// @brief  Call object function
#define _MACOOP_CALL_1(obj, func)               func(obj)
#define _MACOOP_CALL_0(obj, func, ...)          func(obj, __VA_ARGS__)
#define _MACOOP_CALL_OVL(...)                   MACOOP_CAT(_MACOOP_CALL_, MACOOP_VARGS_IS_SINGLE(__VA_ARGS__))
#define MACOOP_CALL_API(obj, ...)               ((obj)._MACOOP_CALL_OVL(__VA_ARGS__)((obj).self, __VA_ARGS__))
//==================================================================================================
// EOF
//==================================================================================================
// clang-format on
#endif // #ifndef __MACOOP_H__

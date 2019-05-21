/****
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* Standard macros and definitions.
* This header has minimal dependency on windows headers and is safe for use in the public API
*
* For the latest on this and related APIs, please see http://casablanca.codeplex.com.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pragma once
// Settings common to all but Windows

#define __declspec(x) __attribute__ ((x))
#define dllimport
#define novtable /* no novtable equivalent */
#define __assume(x) do { if (!(x)) __builtin_unreachable(); } while (false)
#define CASABLANCA_UNREFERENCED_PARAMETER(x) (void)x
#define CPPREST_NOEXCEPT noexcept

#include <assert.h>
#define _ASSERTE(x) assert(x)

#define __cdecl __attribute__ ((cdecl))

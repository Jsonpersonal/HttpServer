/****
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* PPL interfaces
*
* For the latest on this and related APIs, please see http://casablanca.codeplex.com.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pargma once
#ifndef _PPLXINTERFACE_H
#define _PPLXINTERFACE_H

#if (defined(_MSC_VER) && (_MSC_VER >= 1800)) && !CPPREST_FORCE_PPLX
#error This file must not be included for Visual Studio 12 or later
#endif

#if defined(_CRTBLD)
#elif defined(_WIN32)
#if (_MSC_VER >= 1700)
#define _USE_REAL_ATOMICS
#endif
#else // GCC compiler
#define _USE_REAL_ATOMICS
#endif

#include <memory>
#ifdef _USE_REAL_ATOMICS
#include <atomic>
#endif

#if (defined(ANDROID) || defined(__ANDROID__))
// This prevents users from requiring -Wno-attributes when using gcc-4.8 with the android NDK.
#define _pplx_cdecl
#else
#define _pplx_cdecl __cdecl
#endif

namespace pplx
{
  typedef void (_pplx_cdecl * TaskProc_t)(void *);
}// namespace pplx


#endif // _PPLXINTERFACE_H


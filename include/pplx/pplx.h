/****
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* Parallel Patterns Library 并行模式库
*
* For the latest on this and related APIs, please see http://casablanca.codeplex.com.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pragma once
#ifndef _PPLX_H
#define _PPLX_H

#ifndef _WIN32
#if defined(_WIN32) || defined(__cplusplus_winrt)
#define _WIN32
#endif
#endif // _WIN32

// Use PPLx
#ifdef _WIN32
#include "pplx/pplxwin.h"
#elif defined(__APPLE__)
#undef _PPLXIMP
#define _PPLXIMP
#include "pplx/pplxlinux.h"
#else
#include "pplx/pplxlinux.h"
#endif // _WIN32

#endif //_PPLX_H


/****
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* Linux specific pplx implementations
*
* For the latest on this and related APIs, please see http://casablanca.codeplex.com.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pragma once
#ifndef _WIN32
#include "pthread.h"
#include <signal.h>

#if defined(__APPLE__)//IOS
#include <dispatch/dispatch.h>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#else
#include <mutex>   
#include <condition_variable>//条件变量
#endif
#include "pplx/pplxinterface.h"



#endif //!_WIN32

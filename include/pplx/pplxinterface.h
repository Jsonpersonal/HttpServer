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
#define __declspec(x) __attribute__ ((x))

#if (defined(ANDROID) || defined(__ANDROID__))
// This prevents users from requiring -Wno-attributes when using gcc-4.8 with the android NDK.
#define _pplx_cdecl
#else
#define _pplx_cdecl __cdecl
#endif

namespace pplx
{
  typedef void (_pplx_cdecl * TaskProc_t)(void *);
  struct __declspec(novtable) scheduler_interface
  {
      virtual void schedule( TaskProc_t, _In_ void* ) = 0;
  };
  struct scheduler_ptr
  {
     /// <summary>
    /// Creates a scheduler pointer from shared_ptr to scheduler
    /// </summary>
    explicit scheduler_ptr(std::shared_ptr<scheduler_interface> scheduler) : m_sharedScheduler(std::move(scheduler))
    {
        m_scheduler = m_sharedScheduler.get();
    }

    /// <summary>
    /// Creates a scheduler pointer from raw pointer to scheduler
    /// </summary>
    explicit scheduler_ptr(_In_opt_ scheduler_interface * pScheduler) : m_scheduler(pScheduler)
    {
    }

    /// <summary>
    /// Behave like a pointer
    /// </summary>
    scheduler_interface *operator->() const
    {
        return get();
    }

    /// <summary>
    ///  Returns the raw pointer to the scheduler
    /// </summary>
    scheduler_interface * get() const
    {
        return m_scheduler;
    }

    /// <summary>
    /// Test whether the scheduler pointer is non-null
    /// </summary>
    operator bool() const { return get() != nullptr; }
    private:
    std::shared_ptr<scheduler_interface> m_sharedScheduler;
    scheduler_interface * m_scheduler;
  };
  
}// namespace pplx


#endif // _PPLXINTERFACE_H


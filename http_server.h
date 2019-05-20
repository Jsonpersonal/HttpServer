/***
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* HTTP Library: interface to implement HTTP server to service http_listeners.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pragma once
#if _WIN32_WINNT < _WIN32_WINNT_VISTA
#error "Error: http server APIs are not supported in XP"
#endif //_WIN32_WINNT < _WIN32_WINNT_VISTA

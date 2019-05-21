/****
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* HTTP Library: exposes the entry points to the http server transport apis.
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/
#pragma once
#include "memory.h"
#include "cpprest/http_listener.h"
namespace http
{
  class http_server;
  calss http_server_api
  {
    public:
     /// Returns whether or not any listeners are registered.
    static bool has_listener();
     /// Registers a HTTP server API.
    static void register_server_api(std::unique_ptr<http_server>http_server_api);
    /// Clears the http server API.
    static void unregister_server_api();
    /// Registers a listener for HTTP requests and starts receiving.
    static void register_listener(http_listener_impl *pListener);
    /// Unregisters the given listener and stops listening for HTTP requests.
    static void unregister_listener(http_listener_impl *pListener);
    /// Gets static HTTP server API. Could be null if no registered listeners.
    static http_server* server_api();
   private:
    /// Used to lock access to the server api registration
    // static pplx::extensibility::critical_section_t s_lock;
     /// Registers a server API set -- this assumes the lock has already been taken
    static void unsafe_register_server_api(std::unique_ptr<http_server> server_api);
    // Static instance of the HTTP server API.
    static std::unique_ptr<http_server> s_server_api;
     /// Number of registered listeners;
    static pplx::details::atomic_long s_registrations;
    // Static only class. No creation.
    http_server_api();
  };
}

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
namespace web{ namespace http{
/// <summary>
/// Interface http listeners interact with for receiving and responding to http requests.
/// </summary>
class http_server
{
 public:
  /// Release any held resources.
  virtual ~http_server(){};
 /// Start listening for incoming requests.
  virtual void start();
  /// Registers an http listener.
  virtual void register_listener(http_listener_impl *pListener) = 0;
  /// Unregisters an http listener.
  virtual void unregister_listener(http_listener_impl *pListener) = 0;
   /// Stop processing and listening for incoming requests.
  virtual pplx::task<void> stop() = 0;
   /// Asynchronously sends the specified http response.
   /// <param name="response">The http_response to send.</param>
   /// <returns>A operation which is completed once the response has been sent.</returns>
   virtual void respond(http::http_response response) = 0;
};
}
}

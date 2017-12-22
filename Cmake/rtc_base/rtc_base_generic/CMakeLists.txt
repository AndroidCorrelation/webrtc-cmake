# SSL being used here

set(SRCS
  "asyncinvoker.cc"
  "asyncpacketsocket.cc"
  "asyncresolverinterface.cc"
  "asyncsocket.cc"
  "asynctcpsocket.cc"
  "asyncudpsocket.cc"
  "crc32.cc"
  "cryptstring.cc"
  "filerotatingstream.cc"
  "fileutils.cc"
  "helpers.cc"
  "httpbase.cc"
  "httpcommon.cc"
  "ipaddress.cc"
  "messagedigest.cc"
  "messagehandler.cc"
  "messagequeue.cc"
  "nethelper.cc"
  "nethelpers.cc"
  "network.cc"
  "networkmonitor.cc"
  "nullsocketserver.cc"
  "openssladapter.cc"
  "openssldigest.cc"
  "opensslidentity.cc"
  "opensslstreamadapter.cc"
  "physicalsocketserver.cc"
  "proxyinfo.cc"
  "ratelimiter.cc"
  "rtccertificate.cc"
  "rtccertificategenerator.cc"
  "signalthread.cc"
  "sigslot.cc"
  "socketadapters.cc"
  "socketaddress.cc"
  "socketaddresspair.cc"
  "socketstream.cc"
  "ssladapter.cc"
  "sslfingerprint.cc"
  "sslidentity.cc"
  "sslstreamadapter.cc"
  "stream.cc"
  "thread.cc"

  "logsinks.cc"
  "optionsfile.cc"
  "transformadapter.cc"
)
if (${APPLE})
  list(APPEND SRCS
    "macifaddrs_converter.cc"
    "thread_darwin.mm"
  )
endif()
if (${UNIX})
list(APPEND SRCS
  "ifaddrs_converter.cc"
  "unixfilesystem.cc"
)
endif()
if (${WINDOWS})
  list(APPEND SRCS
    "win32socketinit.cc"
    "win32socketserver.cc"

    "win32.cc"
    "win32filesystem.cc"
    "win32securityerrors.cc"
    "win32window.cc"
  )
endif()

prepend_root(SRCS "rtc_base")

find_package(OpenSSL REQUIRED)


add_library (rtc_base_generic SHARED
  ${SRCS}
)

target_include_directories (rtc_base_generic PUBLIC
  "${PROJECT_SOURCE_DIR}"
  "${OPENSSL_INCLUDE_DIR}"
)

target_link_libraries(rtc_base_generic
  rtc_base_approved
  ${OPENSSL_LIBRARIES}
)

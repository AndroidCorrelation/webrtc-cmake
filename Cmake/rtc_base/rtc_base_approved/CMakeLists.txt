set(SRCS
  "base64.cc"
  "bitbuffer.cc"
  "bitrateallocationstrategy.cc"
  "bufferqueue.cc"
  "bytebuffer.cc"
  "checks.cc"
  "copyonwritebuffer.cc"
  "criticalsection.cc"
  "event_tracer.cc"
  "file.cc"
  "flags.cc"
  "location.cc"
  "numerics/histogram_percentile_counter.cc"
  "pathutils.cc"
  "platform_file.cc"
  "platform_thread.cc"
  "race_checker.cc"
  "random.cc"
  "rate_limiter.cc"
  "rate_statistics.cc"
  "ratetracker.cc"
  "string_to_number.cc"
  "stringencode.cc"
  "stringutils.cc"
  "thread_checker_impl.cc"
  "timestampaligner.cc"
  "timeutils.cc"

  "event.cc"
  "logging.cc"
)
# if POSIX (OSX, LINUX, etc. Check if true for linux...)
if (${UNIX})
  list(APPEND SRCS
    "file_posix.cc"
  )
endif()
if (${APPLE})
  find_library(Foundation Foundation)
  list(APPEND SRCS
    "logging_mac.mm"
  )
endif()
if (${WINDOWS})
  list(APPEND SRCS
    "file_win.cc"
  )
endif()

prepend_root(SRCS "rtc_base")


add_library (rtc_base_approved SHARED
  ${SRCS}
)

target_include_directories (rtc_base_approved PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(rtc_base_approved
  # Darwin
  ${Foundation}
)

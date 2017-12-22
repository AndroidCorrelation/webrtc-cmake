set(SRCS "")
# if POSIX (OSX, LINUX, etc. Check if true for linux...)

if (${APPLE})
  list(APPEND SRCS
    "noop.mm"
  )
endif()
if (${WINDOWS})
  list(APPEND SRCS
    "noop.cc"
  )
endif()

prepend_root(SRCS "rtc_base")


add_library (rtc_base SHARED
  ${SRCS}
)

target_include_directories (rtc_base PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(rtc_base
  # Darwin
  rtc_base_generic
)

set(SRCS "")

if (${APPLE})
  list(APPEND SRCS
    "task_queue_gcd.cc"
    "task_queue_posix.cc"
  )
endif()

if (${WINDOWS})
  list(APPEND SRCS
    "task_queue_win.cc"
  )
endif()
prepend_root(SRCS "rtc_base")

add_library (rtc_task_queue SHARED
  ${SRCS}
)

target_include_directories (rtc_task_queue PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(rtc_task_queue
  rtc_base_approved
)

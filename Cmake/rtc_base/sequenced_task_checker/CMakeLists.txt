set(SRCS
  "sequenced_task_checker_impl.cc"
)
prepend_root(SRCS "rtc_base")


add_library (sequenced_task_checker SHARED
  ${SRCS}
)

target_include_directories (sequenced_task_checker PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(sequenced_task_checker
  rtc_task_queue
)

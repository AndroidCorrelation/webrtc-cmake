set(SRCS
  "weak_ptr.cc"
)
prepend_root(SRCS "rtc_base")


add_library (weak_ptr SHARED
  ${SRCS}
)

target_include_directories (weak_ptr PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(weak_ptr

)

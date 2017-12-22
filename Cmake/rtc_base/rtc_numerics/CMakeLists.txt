set(SRCS
  "numerics/exp_filter.cc"
)
prepend_root(SRCS "rtc_base")


add_library (rtc_numerics SHARED
  ${SRCS}
)

target_include_directories (rtc_numerics PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(rtc_numerics
  rtc_base_approved
)

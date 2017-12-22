# //rtc_system_wrappers

set(SRC_ROOT "${PROJECT_SOURCE_DIR}/system_wrappers")
file(GLOB_RECURSE RTC_BASE_SRCS  "${SRC_ROOT}/*.cc" "${SRC_ROOT}/*.c")


file(GLOB_RECURSE RTC_BASE_EXCLUDE "${SRC_ROOT}/*unittest*" "${SRC_ROOT}/*test/*" "${SRC_ROOT}/*test*" "${SRC_ROOT}/*win*"
  #arm platform
  "${SRC_ROOT}/*arm*" "${SRC_ROOT}/*mips*" "${SRC_ROOT}/*neon*" "${SRC_ROOT}/*android*" "${SRC_ROOT}/*linux*"
)

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_system_wrappers SHARED ${RTC_BASE_SRCS} )


target_include_directories (rtc_system_wrappers PUBLIC
  ${PROJECT_SOURCE_DIR}
  "signal_processing/include"
)

target_link_libraries(rtc_system_wrappers
  rtc_base_lib
)

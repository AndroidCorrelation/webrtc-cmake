# //rtc_system_wrappers

file(GLOB_RECURSE RTC_BASE_SRCS  "*.cc" "*.c")


file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*" "*test/*" "*test*" "*win*"
  #arm platform
  "*arm*" "*mips*" "*neon*" "*android*" "*linux*"
)

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_system_wrappers SHARED ${RTC_BASE_SRCS} )


target_include_directories (rtc_system_wrappers PUBLIC
  ${PROJECT_SOURCE_DIR}
)

target_link_libraries(rtc_system_wrappers
  rtc_base_lib
)

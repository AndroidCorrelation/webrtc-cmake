# :rtc_mod-rtc_rtcp

file(GLOB_RECURSE RTC_BASE_SRCS  "*.cc")
file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*"  "*test*"  "kenny.cc"
  #arm platform
  "*arm*" "*mips*" "*neon*" "*android*" "*linux*" "*win*"
)

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_mod-rtc_rtcp SHARED ${RTC_BASE_SRCS} )

target_include_directories (rtc_mod-rtc_rtcp PUBLIC
  ${PROJECT_SOURCE_DIR}
)

target_link_libraries(rtc_mod-rtc_rtcp
  rtc_base_lib
  rtc_system_wrappers
  rtc_api_lib
)

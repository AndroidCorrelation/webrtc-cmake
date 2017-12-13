# :common_audio

file(GLOB_RECURSE RTC_BASE_SRCS  "*.cc" "*.c")
file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*" "*test/*" "*test*" "*win*"
  #arm platform
  "*arm*" "*mips*" "*neon*"

  "*aec_dump/*" "*openmax*"
  )
list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_common_audio SHARED ${RTC_BASE_SRCS} )

target_include_directories (rtc_common_audio PUBLIC
  ${PROJECT_SOURCE_DIR}
  "signal_processing/include"
)

target_link_libraries(rtc_common_audio
  rtc_base_lib
  rtc_system_wrappers
)

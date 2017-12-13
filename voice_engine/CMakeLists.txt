# :rtc_voice_engine

file(GLOB_RECURSE RTC_BASE_SRCS  "*.cc")
file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*"  "*test*" "kenny.cc"
  "*android*" "*linux*" "*win*"
  # arm
  "*arm*" "*mips*" "*neon*"
)

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_voice_engine SHARED ${RTC_BASE_SRCS} )

target_include_directories (rtc_voice_engine PUBLIC
  ${PROJECT_SOURCE_DIR}
)

target_link_libraries(rtc_voice_engine
  rtc_base_lib
  rtc_common_audio
  rtc_mod-rtc_rtcp
)

# :rtc_mod_audio_processing_lib
#rename to rtc_mod-audio_processing

add_definitions(-DWEBRTC_APM_DEBUG_DUMP=0 -DWEBRTC_INTELLIGIBILITY_ENHANCER=0 -DWEBRTC_NS_FLOAT)

file(GLOB_RECURSE RTC_BASE_SRCS "*.cc" "*.c")
file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*" "*test/*" "*test*" "*win*" "*libevent*"
  #arm platform
  "*arm*" "*mips*" "*neon*"

  "*aec_dump/*"
  )
list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_mod_audio_processing_lib SHARED ${RTC_BASE_SRCS} ${RTC_BASE_DARWIN_SRCS})

target_include_directories (rtc_mod_audio_processing_lib PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/../.."
)

target_link_libraries(rtc_mod_audio_processing_lib
  rtc_base_lib
  rtc_common_audio
  rtc_mod-audio_coding
)

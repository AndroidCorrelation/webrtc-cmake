# :rtc_mod-audio_coding

add_definitions(-DWEBRTC_CODEC_OPUS)

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPUS opus)

file(GLOB_RECURSE RTC_BASE_SRCS  "*.cc")

file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*"  "*test*" "*win*" "kenny.cc"
  #arm platform
  "*arm*" "*mips*" "*neon*" "*android*" "*linux*"
  "*rent_a_codec*"
)

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_mod-audio_coding SHARED ${RTC_BASE_SRCS} )


target_include_directories (rtc_mod-audio_coding PUBLIC
  ${PROJECT_SOURCE_DIR}
  ${OPUS_INCLUDE_DIRS}
  "codecs/isac/main/include"
)

target_link_libraries(rtc_mod-audio_coding
  rtc_base_lib
  rtc_voice_engine
  ${OPUS_LIBRARIES}
)

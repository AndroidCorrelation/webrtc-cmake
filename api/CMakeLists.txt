# :api

add_definitions(-DWEBRTC_USE_BUILTIN_ISAC_FLOAT)

file(GLOB RTC_BASE_SRCS "*.cc")
file(GLOB RTC_BASE_EXCLUDE "*unittest*" "*test*" "*win*" "*libevent*")
list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})

add_library (rtc_api_lib SHARED ${RTC_BASE_SRCS})

target_include_directories (rtc_api_lib PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/.."
  "${OPENSSL_INCLUDE_DIR}"

)

target_link_libraries(rtc_api_lib
  rtc_base_lib
  #rtc_mod_audio_processing_lib
)

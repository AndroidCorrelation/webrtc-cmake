cmake_minimum_required (VERSION 3.9.0)

project (libwebrtc C CXX)

add_definitions(-DWEBRTC_MAC -DWEBRTC_POSIX  -DOPENSSL_IS_BORINGSSL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)


###
# Prepends current libraries root to each src file
FUNCTION( prepend_root SOURCE_FILES SUBDIR)
  set(_tmp "")
  FOREACH( SOURCE_FILE ${${SOURCE_FILES}} )
    list( APPEND _tmp "${PROJECT_SOURCE_DIR}/${SUBDIR}/${SOURCE_FILE}" )
  ENDFOREACH()
  SET( ${SOURCE_FILES} ${_tmp} PARENT_SCOPE )
ENDFUNCTION()


find_package(PkgConfig REQUIRED)

add_subdirectory("Cmake/rtc_base")
add_subdirectory("Cmake/api")

#add_subdirectory("rtc_base")


#add_subdirectory("system_wrappers")
#add_subdirectory("common_audio")
#add_subdirectory("voice_engine")
#add_subdirectory("modules/rtp_rtcp")
#add_subdirectory("api") #dep: rtc_base, audio_processing
#add_subdirectory("modules/audio_coding")

#add_subdirectory("modules/audio_processing") #dep: rtc_mod-audio_coding
#add_subdirectory("p2p")

#[[

if (${APPLE})
  list(APPEND SRCS
    "logging_mac.mm"

  )

  find_library(objc objc)
  find_library(CoreServices CoreServices)
  find_library(CoreFoundation CoreFoundation)
  find_library(Foundation Foundation)
endif()
]]
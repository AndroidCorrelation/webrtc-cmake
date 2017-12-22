# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

find_package(PkgConfig REQUIRED)
find_package(OpenSSL REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)


set(RTC_BASE_SRCS

)

if (${APPLE})
  set(RTC_BASE_DARWIN_SRCS

  )
  find_library(objc objc)
  find_library(CoreServices CoreServices)
  find_library(CoreFoundation CoreFoundation)
  find_library(Foundation Foundation)
endif()

#file(GLOB RTC_BASE_EXCLUDE "*unittest*" "*test*" "*win*" "*libevent*")

#list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})


add_library (rtc_base_lib SHARED
  ${RTC_BASE_SRCS}
  ${RTC_BASE_DARWIN_SRCS}
)


target_include_directories (rtc_base_lib PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/.."
  "${OPENSSL_INCLUDE_DIR}"
)


target_link_libraries(rtc_base_lib
  rtc_base_approved
  ${JSONCPP_LIBRARIES}
  ${OPENSSL_LIBRARIES}

  # Darwin
  ${CoreFoundation}
  ${CoreServices}
  ${Foundation}
  ${objc}
)

#set_target_properties(rtc_base_lib PROPERTIES
#  FRAMEWORK TRUE
#  FRAMEWORK_VERSION C
#  MACOSX_FRAMEWORK_IDENTIFIER com.google.wrtc
  #MACOSX_FRAMEWORK_INFO_PLIST Info.plist
  #PUBLIC_HEADER dynamicFramework.h
  #XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
#)
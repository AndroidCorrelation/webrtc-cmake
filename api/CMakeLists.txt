# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DWEBRTC_MAC -DWEBRTC_POSIX -DOPENSSL_IS_BORINGSSL -DWEBRTC_USE_BUILTIN_ISAC_FLOAT)

#find_package(PkgConfig REQUIRED)
#find_package(OpenSSL REQUIRED)
#pkg_check_modules(JSONCPP jsoncpp)


file(GLOB_RECURSE RTC_BASE_SRCS "*.cc")

#if (${APPLE})
#  file(GLOB RTC_BASE_DARWIN_SRCS "*.mm")
#  find_library(objc objc)
#  find_library(CoreServices CoreServices)
#  find_library(CoreFoundation CoreFoundation)
#  find_library(Foundation Foundation)
#endif()

file(GLOB RTC_BASE_EXCLUDE "*unittest*" "*test*" "*win*" "*libevent*")

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})


add_library (rtc_api_lib STATIC ${RTC_BASE_SRCS} ${RTC_BASE_DARWIN_SRCS})
set_target_properties(rtc_api_lib PROPERTIES
  FRAMEWORK TRUE
  FRAMEWORK_VERSION C
  MACOSX_FRAMEWORK_IDENTIFIER com.google.wrtc
  #MACOSX_FRAMEWORK_INFO_PLIST Info.plist
  #PUBLIC_HEADER dynamicFramework.h
  #XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
)

target_include_directories (rtc_base_lib PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/.."
  "${OPENSSL_INCLUDE_DIR}"

)


target_link_libraries(rtc_api_lib
  rtc_base_lib
  ${JSONCPP_LIBRARIES}
  ${OPENSSL_LIBRARIES}

  # Darwin
  ${CoreFoundation}
  ${CoreServices}
  ${Foundation}
  ${objc}
)

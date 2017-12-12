# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DWEBRTC_MAC -DWEBRTC_POSIX -DOPENSSL_IS_BORINGSSL)

find_library(CoreServices CoreServices)
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

file(GLOB RTC_BASE_SRCS "*.cc")
file(GLOB RTC_BASE_EXCLUDE "*unittest*" "*test*" "*win*" "*libevent*")

list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})


add_library (rtc_base_lib SHARED ${RTC_BASE_SRCS})
set_target_properties(rtc_base_lib PROPERTIES
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


target_link_libraries(rtc_base_lib
  ${CoreServices}
  ${JSONCPP_LIBRARIES}
  ${OPENSSL_LIBRARIES}
)

#find_package(JsonCpp)
#message("${JSONCPP_LIBRARIES}")
# /Users/lukeadams/Desktop/wrtc-cmake/webrtc-209f2d5/BUILD.gn search for  WEBRTC_MAC

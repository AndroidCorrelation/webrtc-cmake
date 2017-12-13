# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DWEBRTC_MAC -DWEBRTC_POSIX -DOPENSSL_IS_BORINGSSL -DWEBRTC_USE_BUILTIN_ISAC_FLOAT)


file(GLOB_RECURSE RTC_BASE_SRCS "*.cc")
file(GLOB_RECURSE RTC_BASE_EXCLUDE "*unittest*" "*test*" "*win*" "*libevent*")
list(REMOVE_ITEM RTC_BASE_SRCS ${RTC_BASE_EXCLUDE})


add_library (rtc_p2p_lib SHARED ${RTC_BASE_SRCS} ${RTC_BASE_DARWIN_SRCS})

target_include_directories (rtc_p2p_lib PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

target_link_libraries(rtc_p2p_lib
  rtc_base_lib
)

cmake_minimum_required(VERSION 3.8)
project(CROWMerge)

set(CMAKE_MACOSX_RPATH NEW)
set(CMAKE_BUILD_TYPE Debug)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

if(NOT DEFINED $ENV{LLVM_DIR})
  set(LLVM_DIR "deps")
endif()

if (NOT LLVM_BUILD_TYPE)
  set(LLVM_BUILD_TYPE Release)
endif()
set(LLVM_CONFIG_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/${LLVM_DIR}/llvm-Release-build/bin/llvm-config)
if(NOT EXISTS ${LLVM_CONFIG_EXECUTABLE})
  message(FATAL_ERROR "llvm-config could not be found!")
endif()

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --includedir
  OUTPUT_VARIABLE LLVM_INCLUDEDIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --cppflags
  OUTPUT_VARIABLE LLVM_CXXFLAGS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(LLVM_CXXFLAGS "${LLVM_CXXFLAGS} -fno-exceptions -fno-rtti")

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --libs all
  OUTPUT_VARIABLE LLVM_LIBS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)


execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --libdir
  OUTPUT_VARIABLE LLVM_LIBRARY_DIRS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)


execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --system-libs all
  OUTPUT_VARIABLE LLVM_SYSTEM_LIBS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(LLVM_LIBS "${LLVM_LIBS} ${LLVM_SYSTEM_LIBS}")
string(STRIP ${LLVM_LIBS} LLVM_LIBS)

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --ldflags
  OUTPUT_VARIABLE LLVM_LDFLAGS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(PASS_LDFLAGS "${LLVM_LDFLAGS}")

message(${LLVM_LDFLAGS})
# string(REPLACE -llibxml2.tbd "" NEW_LLVM_LIBS ${LLVM_LIBS} )
message(${LLVM_LIBS})
#string(STRIP ${NEW_LLVM_LIBS} NEW_LLVM_LIBS )

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --bindir
  OUTPUT_VARIABLE LLVM_BINDIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --src-root
  OUTPUT_VARIABLE LLVM_SRC
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND ${LLVM_CONFIG_EXECUTABLE} --obj-root
  OUTPUT_VARIABLE LLVM_BUILD
  OUTPUT_STRIP_TRAILING_WHITESPACE
)


set(LLVM_CXXFLAGS "${LLVM_CXXFLAGS} -fexceptions -std=c++17")

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++17")
  set(LLVM_CXXFLAGS "${LLVM_CXXFLAGS} -fvisibility-inlines-hidden")
  set(PASS_LDFLAGS "-Wl,-undefined,dynamic_lookup") # Apple
endif()


include_directories(include "${CMAKE_BINARY_DIR}/include")
include_directories(include "${LLVM_INCLUDEDIR}")

# variable_watch(LLVM_LIBRARY_DIRS)
link_directories(${LLVM_LIBRARY_DIRS})

set(CLANG_CXXFLAGS "")
set(CLANG_INCLUDEDIR "${LLVM_SRC}/../clang/include" "${LLVM_BUILD}/tools/clang/include")


# variable_watch(LLVM_LDFLAGS)

add_definitions(${LLVM_DEFINITIONS})

set(COMMON_FILES
        include/common/Common.h
        lib/common/Common.cpp
      )

set(LINKER_FILES
      include/linker/Linker.h
      lib/linker/Linker.cpp
)

set(GO_FILES
     include/go/go.h
     lib/go/go.cpp
  )

set(C_FILES
     include/c/c.h
     lib/c/c.cpp
  )
set(LINKER_SOURCES
  ${COMMON_FILES}
  ${LINKER_FILES}
  ${GO_FILES}
  ${C_FILES}
)

add_executable(linker
  ${LINKER_SOURCES}
  tools/linker.cpp)


set(LLVM_LDFLAGS "${LLVM_LDFLAGS}")

VARIABLE_WATCH(LLVM_LIB_DIR)

target_link_libraries(linker  ${LLVM_LIBS} ${LLVM_LDFLAGS})


foreach(target linker)
  set_target_properties(${target} PROPERTIES COMPILE_FLAGS "${LLVM_CXXFLAGS}")
  target_include_directories(${target} PRIVATE "${LLVM_INCLUDEDIR}")
endforeach()

# dynamic
#target_link_libraries(souperCodegen ${PASS_LDFLAGS})

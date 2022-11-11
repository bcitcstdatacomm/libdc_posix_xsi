cmake_minimum_required(VERSION 3.22)

project(dc_posix_xsi
        VERSION 0.2.1
        DESCRIPTION ""
        LANGUAGES C)

set(CMAKE_C_STANDARD 17)

set(SANITIZE TRUE)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(SOURCE_LIST ${SOURCE_DIR}/ ${SOURCE_DIR}/dirent.c
        ${SOURCE_DIR}/fmtmsg.c
        ${SOURCE_DIR}/ftw.c
        ${SOURCE_DIR}/grp.c
        ${SOURCE_DIR}/libgen.c
        ${SOURCE_DIR}/math.c
        ${SOURCE_DIR}/ndbm.c
        ${SOURCE_DIR}/pwd.c
        ${SOURCE_DIR}/search.c
        ${SOURCE_DIR}/signal.c
        ${SOURCE_DIR}/stdlib.c
        ${SOURCE_DIR}/string.c
        ${SOURCE_DIR}/strings.c
        ${SOURCE_DIR}/syslog.c
        ${SOURCE_DIR}/time.c
        ${SOURCE_DIR}/unistd.c
        ${SOURCE_DIR}/utmpx.c
        ${SOURCE_DIR}/wchar.c
        ${SOURCE_DIR}/sys/ipc.c
        ${SOURCE_DIR}/sys/mman.c
        ${SOURCE_DIR}/sys/msg.c
        ${SOURCE_DIR}/sys/resource.c
        ${SOURCE_DIR}/sys/sem.c
        ${SOURCE_DIR}/sys/shm.c
        ${SOURCE_DIR}/sys/stat.c
        ${SOURCE_DIR}/sys/time.c
        ${SOURCE_DIR}/sys/uio.c
        )
set(HEADER_LIST ${INCLUDE_DIR}/dc_posix_xsi/dc_dirent.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_fmtmsg.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_ftw.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_grp.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_libgen.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_math.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_ndbm.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_pwd.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_search.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_signal.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_stdlib.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_string.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_strings.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_syslog.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_time.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_unistd.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_utmpx.h
        ${INCLUDE_DIR}/dc_posix_xsi/dc_wchar.h
    )
set(HEADER_LIST_SYS ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_ipc.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_mman.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_msg.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_resource.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_sem.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_shm.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_stat.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_time.h
        ${INCLUDE_DIR}/dc_posix_xsi/sys/dc_uio.h
    )

add_compile_definitions(_POSIX_C_SOURCE=200809L)
add_compile_definitions(_XOPEN_SOURCE=700)

# Linux
add_compile_definitions(_DEFAULT_SOURCE)

include_directories(${INCLUDE_DIR})
include(CheckCCompilerFlag)

function(AddCompileOptions)
    foreach(FLAG IN LISTS ARGN)
        string(REPLACE "-" "" FLAG_NO_HYPHEN ${FLAG})
        set(CMAKE_C_FLAGS "-Werror -Wunknown-warning-option")
        check_c_compiler_flag(${FLAG} COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
        if (COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
            add_compile_options(${FLAG})
        endif ()
    endforeach()
endfunction()

list(APPEND COMPILER_FLAGS
        "-Wall"
        "-Wextra"
        "-Wpedantic"
        "-Wshadow"
        "-Wstrict-overflow=4"
        "-Wswitch-default"
        "-Wswitch-enum"
        "-Wunused"
        "-Wunused-macros"
        "-Wdate-time"
        "-Winvalid-pch"
        "-Wmissing-declarations"
        "-Wmissing-include-dirs"
        "-Wmissing-prototypes"
        "-Wstrict-prototypes"
        "-Wundef"
        "-Wnull-dereference"
        "-Wstack-protector"
        "-Wdouble-promotion"
        "-Wvla"
        "-Walloca"
        "-Woverlength-strings"
        "-Wdisabled-optimization"
        "-Winline"
        "-Wcast-qual"
        "-Wfloat-equal"
        "-Wformat=2"
        "-Wfree-nonheap-object"
        "-Wshift-overflow"
        "-Wwrite-strings"
        "-Wunsuffixed-float-constants"
        "-Warith-conversion"
        "-Wunsafe-loop-optimizations"
        "-Wvector-operation-performance"
        "-Walloc-zero"
        "-Wtrampolines"
        "-Wtsan"
        "-Wformat-overflow=2"
        "-Wformat-signedness"
        "-Wjump-misses-init"
        "-Wformat-truncation=2")

if (${SANITIZE})
    list(APPEND COMPILER_FLAGS
            "-fsanitize=address"
            "-fsanitize=undefined"
            "-fsanitize-address-use-after-scope"
            "-fstack-protector-all"
            "-fdelete-null-pointer-checks"
            "-fno-omit-frame-pointer"
            "-fsanitize=leak")

    add_link_options("-fsanitize=address")
    add_link_options("-fsanitize=bounds")
endif ()

AddCompileOptions(${COMPILER_FLAGS})

find_package(Doxygen
        REQUIRED
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)

set(DOXYGEN_ALWAYS_DETAILED_SEC YES)
set(DOXYGEN_REPEAT_BRIEF YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_WARNINGS YES)
set(DOXYGEN_QUIET YES)

doxygen_add_docs(doxygen
        ${HEADER_LIST} ${HEADER_LIST_SYS}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generating Doxygen documentation for libdc_posix_optional")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CLANG_TIDY_CHECKS "*")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-id-dependent-backward-branch")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-struct-pack-align")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-unroll-loops")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-accept")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-creat")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-dup")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-open")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-pipe")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-socket")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-bugprone-easily-swappable-parameters")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-cert-dcl03-c")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-deadcode.DeadStores")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-security.insecureAPI.strcpy")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-cast-align")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-format-nonliteral")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-incompatible-pointer-types-discards-qualifiers")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unknown-warning-option")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-but-set-variable")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-function")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-parameter")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-variable")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-vla")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-cppcoreguidelines-init-variables")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-google-readability-todo")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-hicpp-static-assert")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-llvmlibc-restrict-system-libc-headers")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-misc-static-assert")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-misc-unused-parameters")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-readability-identifier-length")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    if (NOT DEFINED ENV{CMDLINE_TOOLS_VER})
        message( FATAL_ERROR "The CMDLINE_TOOLS_VER environment variable must be set" )
    endif ()

    if(NOT EXISTS /Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER})
        message( FATAL_ERROR "/Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER} does not exist" )
    endif ()

    set(CMAKE_C_CLANG_TIDY clang-tidy -extra-arg=-I/Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER}/include -checks=${CLANG_TIDY_CHECKS};--quiet)
else ()
    set(CMAKE_C_CLANG_TIDY clang-tidy -checks=${CLANG_TIDY_CHECKS};--quiet)
endif ()

add_library(dc_posix_xsi SHARED ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_LIST_SYS})
target_include_directories(dc_posix_xsi PRIVATE include/dc_posix_xsi)
target_include_directories(dc_posix_xsi PRIVATE /usr/local/include)
target_link_directories(dc_posix_xsi PRIVATE /usr/local/lib)

set_target_properties(dc_posix_xsi PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIBDC_ENV dc_env REQUIRED)
find_library(LIBGDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)

if(LIBGDBM)
    target_link_libraries(dc_posix_xsi PUBLIC ${LIBGDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(dc_posix_xsi PUBLIC ${LIB_GDBM_COMPAT})
endif()

target_link_libraries(dc_posix_xsi PUBLIC ${LIBDC_ERROR})
target_link_libraries(dc_posix_xsi PUBLIC ${LIBDC_ENV})

install(TARGETS dc_posix_xsi LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix_xsi)
install(FILES ${HEADER_LIST_SYS} DESTINATION include/dc_posix_xsi/sys)

add_dependencies(dc_posix_xsi doxygen)

find_library(LIBCGREEN cgreen REQUIRED)
add_subdirectory(tests)

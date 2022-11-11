set(TEST_HEADER_LIST
        tests.h
        )

set(TEST_SOURCE_LIST
        main.c
        )

include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(libdc_posix_xsi_test ${TEST_SOURCE_LIST} ${TEST_HEADER_LIST} ${SOURCE_LIST} ${HEADER_LIST})

target_compile_features(libdc_posix_xsi_test PRIVATE c_std_17)

target_include_directories(libdc_posix_xsi_test PRIVATE ../include/dc_posix_xsi)
target_include_directories(libdc_posix_xsi_test PRIVATE /usr/include)
target_include_directories(libdc_posix_xsi_test PRIVATE /usr/local/include)

find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIBDC_ENV dc_env REQUIRED)
find_library(LIBM m)
find_library(LIBGDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)

target_link_libraries(libdc_posix_xsi_test PUBLIC ${LIBDC_ERROR})
target_link_libraries(libdc_posix_xsi_test PUBLIC ${LIBDC_ENV})

if(LIBM)
    target_link_libraries(libdc_posix_xsi_test PUBLIC ${LIBM})
endif()

if(LIBGDBM)
    target_link_libraries(libdc_posix_xsi_test PUBLIC ${LIBGDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(libdc_posix_xsi_test PUBLIC ${LIB_GDBM_COMPAT})
endif()

add_test(NAME libdc_posix_xsi_test COMMAND libdc_posix_xsi_test)


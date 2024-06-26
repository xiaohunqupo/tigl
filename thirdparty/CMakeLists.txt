project(thirdparty-libs)

# --------------  BOOST ----------------- #
option(TIGL_USE_INTERNAL_BOOST "Use boost library that comes with tigl" ON)
if (TIGL_USE_INTERNAL_BOOST)

# boost
set (BOOST_DIR ${PROJECT_BINARY_DIR}/boost_1_85_0)
set (BOOST_ARCHIVE ${PROJECT_SOURCE_DIR}/boost_1_85_0.tar.gz)
set (Boost_VERSION "1.85.0")

if (NOT EXISTS ${BOOST_DIR})
    message(STATUS "Extracting boost ${Boost_VERSION}")
    execute_process (
        COMMAND ${CMAKE_COMMAND} -E  tar xzf ${BOOST_ARCHIVE}
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
endif()

add_library(tigl_boost INTERFACE)
add_library(Boost::boost ALIAS tigl_boost)
target_include_directories(tigl_boost INTERFACE
    $<BUILD_INTERFACE:${BOOST_DIR}>
    $<INSTALL_INTERFACE:include/tigl3/internal>
)

add_library(tigl_boost_disable_autolink INTERFACE)
target_compile_definitions(tigl_boost_disable_autolink INTERFACE BOOST_ALL_NO_LIB)
add_library(Boost::disable_autolinking ALIAS tigl_boost_disable_autolink)

add_library(tigl_boost_atomic STATIC
    ${BOOST_DIR}/libs/atomic/src/lock_pool.cpp
)
add_library(Boost::atomic ALIAS tigl_boost_atomic)
set_property(TARGET tigl_boost_atomic PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(tigl_boost_atomic PUBLIC tigl_boost_disable_autolink tigl_boost)

target_include_directories(tigl_boost_atomic PRIVATE
    ${BOOST_DIR}/libs/atomic/src
)

add_library(tigl_boost_chrono STATIC
    ${BOOST_DIR}/libs/chrono/src/chrono.cpp
    ${BOOST_DIR}/libs/chrono/src/process_cpu_clocks.cpp
    ${BOOST_DIR}/libs/chrono/src/thread_clock.cpp
)

add_library(Boost::chrono ALIAS tigl_boost_chrono)
set_property(TARGET tigl_boost_chrono PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(tigl_boost_chrono PUBLIC tigl_boost_disable_autolink tigl_boost)

add_library(tigl_boost_date_time INTERFACE
)

add_library(Boost::date_time ALIAS tigl_boost_date_time)

add_library(tigl_boost_exception STATIC
    ${BOOST_DIR}/libs/exception/src/clone_current_exception_non_intrusive.cpp
)

add_library(Boost::exception ALIAS tigl_boost_exception)
set_property(TARGET tigl_boost_exception PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(tigl_boost_exception PUBLIC tigl_boost_disable_autolink tigl_boost)

add_library(tigl_boost_filesystem STATIC
    ${BOOST_DIR}/libs/filesystem/src/codecvt_error_category.cpp
    ${BOOST_DIR}/libs/filesystem/src/directory.cpp
    ${BOOST_DIR}/libs/filesystem/src/exception.cpp
    ${BOOST_DIR}/libs/filesystem/src/operations.cpp
    ${BOOST_DIR}/libs/filesystem/src/path.cpp
    ${BOOST_DIR}/libs/filesystem/src/path_traits.cpp
    ${BOOST_DIR}/libs/filesystem/src/portability.cpp
    ${BOOST_DIR}/libs/filesystem/src/unique_path.cpp
    ${BOOST_DIR}/libs/filesystem/src/utf8_codecvt_facet.cpp
    ${BOOST_DIR}/libs/filesystem/src/windows_file_codecvt.cpp
)

target_link_libraries(tigl_boost_filesystem PUBLIC tigl_boost_disable_autolink tigl_boost)
target_compile_definitions(tigl_boost_filesystem PUBLIC BOOST_FILESYSTEM_NO_CXX20_ATOMIC_REF=1)
set_property(TARGET tigl_boost_filesystem PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(Boost::filesystem ALIAS tigl_boost_filesystem)

add_library(tigl_boost_system INTERFACE)
add_library(Boost::system ALIAS tigl_boost_system)

set (BOOST_THREAD_SRC 
    ${BOOST_DIR}/libs/thread/src/future.cpp
)

if(WIN32)
    set (BOOST_THREAD_SRC ${BOOST_THREAD_SRC}
        ${BOOST_DIR}/libs/thread/src/win32/thread.cpp
        ${BOOST_DIR}/libs/thread/src/win32/thread_primitives.cpp
        ${BOOST_DIR}/libs/thread/src/win32/tss_dll.cpp
        ${BOOST_DIR}/libs/thread/src/win32/tss_pe.cpp
    )
else()
    set (BOOST_THREAD_SRC ${BOOST_THREAD_SRC}
        ${BOOST_DIR}/libs/thread/src/pthread/once.cpp
        ${BOOST_DIR}/libs/thread/src/pthread/thread.cpp
    )
endif()

add_library(tigl_boost_thread STATIC ${BOOST_THREAD_SRC})
target_link_libraries(tigl_boost_thread PUBLIC tigl_boost_disable_autolink tigl_boost)
target_compile_definitions(tigl_boost_thread PRIVATE BOOST_THREAD_BUILD_LIB)
add_library(Boost::thread ALIAS tigl_boost_thread)
set_property(TARGET tigl_boost_thread PROPERTY POSITION_INDEPENDENT_CODE ON)


if(WIN32)
    target_compile_definitions(tigl_boost_thread PRIVATE -DBOOST_THREAD_WIN32)
else()
    target_compile_definitions(tigl_boost_thread PRIVATE -DBOOST_THREAD_POSIX)
endif()

set(Boost_LIBRARIES Boost::boost Boost::filesystem Boost::thread Boost::system Boost::atomic Boost::chrono Boost::date_time)

if (TIGL_BINDINGS_INSTALL_CPP)
    install (TARGETS
        tigl_boost
        tigl_boost_disable_autolink
        tigl_boost_date_time
        tigl_boost_filesystem
        tigl_boost_chrono
        tigl_boost_atomic
        tigl_boost_system
        tigl_boost_thread
    
        EXPORT tigl3_cpp-targets
             RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
             LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/tigl3
             ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/tigl3
        COMPONENT cpp_bindings
    )
    
    install(DIRECTORY ${BOOST_DIR}/boost
        DESTINATION include/tigl3/internal
        COMPONENT cpp_bindings
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
endif (TIGL_BINDINGS_INSTALL_CPP)

endif(TIGL_USE_INTERNAL_BOOST)

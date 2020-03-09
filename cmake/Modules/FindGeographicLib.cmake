set(GeographicLib_FOUND 1 CACHE INTERNAL "GeographicLib_FOUND")
set(GeographicLib_INCLUDE_DIRS ${GEARS_INCLUDE_DIR}/GeographicLib CACHE INTERNAL "GeographicLib_INCLUDE_DIRS")
include_directories(${GeographicLib_INCLUDE_DIRS})
link_directories(${GEARS_LIBRARY_DIR})

# find_library (GeographicLib_LIBRARIES Geographic
#   PATHS "${CMAKE_INSTALL_PREFIX}/../GeographicLib/lib")

# if (GeographicLib_LIBRARIES)
#   get_filename_component (GeographicLib_LIBRARY_DIRS
#     "${GeographicLib_LIBRARIES}" PATH)
#   get_filename_component (_ROOT_DIR "${GeographicLib_LIBRARY_DIRS}" PATH)
#   set (GeographicLib_INCLUDE_DIRS "${_ROOT_DIR}/../include")
#   set (GeographicLib_BINARY_DIRS "${_ROOT_DIR}/../bin")
#   unset (_ROOT_DIR)
#   if (NOT EXISTS "${GeographicLib_INCLUDE_DIRS}/GeographicLib/Config.h")
#     unset (GeographicLib_INCLUDE_DIRS)
#     unset (GeographicLib_LIBRARIES)
#     unset (GeographicLib_LIBRARY_DIRS)
#     unset (GeographicLib_BINARY_DIRS)
#   endif ()
# endif ()

# include (FindPackageHandleStandardArgs)
# find_package_handle_standard_args (GeographicLib DEFAULT_MSG
#   GeographicLib_LIBRARY_DIRS GeographicLib_LIBRARIES GeographicLib_INCLUDE_DIRS)
# mark_as_advanced (GeographicLib_LIBRARY_DIRS GeographicLib_LIBRARIES
#   GeographicLib_INCLUDE_DIRS)

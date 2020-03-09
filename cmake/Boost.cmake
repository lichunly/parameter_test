set(Boost_INCLUDE_DIRS "/usr/local/apollo/boost/include")
set(Boost_LIBRARY_DIRS "/usr/local/apollo/boost/lib")
set(Boost_LIBRARIES "/usr/local/apollo/boost/lib/libboost_system.so;/usr/local/apollo/boost/lib/libboost_filesystem.so")
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


# find_package(Boost REQUIRED COMPONENTS chrono regex thread filesystem program_options system)
# include_directories(${Boost_INCLUDE_DIRS})
# link_directories(${Boost_LIBRARY_DIRS})
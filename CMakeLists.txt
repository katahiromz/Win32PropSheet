# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(Win32PropSheet CXX RC)

##############################################################################

# Win32PropSheet.exe
add_executable(Win32PropSheet WIN32 Win32PropSheet.cpp Win32PropSheet_res.rc)
target_link_libraries(Win32PropSheet comctl32)

##############################################################################

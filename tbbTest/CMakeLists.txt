cmake_minimum_required(VERSION 3.30)
project(tbbTest)

set(CMAKE_CXX_STANDARD 17)
# Pfad zur vars.bat anpassen
#set(INTEL_VARS_BAT "C:/Program Files (x86)/Intel/oneAPI/tbb/latest/env/vars.bat")

# Füge einen Custom Command hinzu, der vor dem Build ausgeführt wird
#add_custom_target(setup_intel_vars ALL
#        COMMAND cmd /c "${INTEL_VARS_BAT}"
#        COMMENT "Setting Intel environment variables..."
#)



add_executable(tbbTest main.cpp)
#add_dependencies(tbbTest setup_intel_vars)
#find_package(TBB CONFIG REQUIRED)
#target_link_libraries(tbbTest PRIVATE TBB::tbb)
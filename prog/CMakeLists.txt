cmake_minimum_required (VERSION 2.8.12)
# title and version of the project
project (pomerol CXX)

set(default_progs "anderson" "hubbard2d")

find_package(Boost COMPONENTS system program_options REQUIRED)
set(BOOST_EXTRA_LIBS ${Boost_LIBRARIES})
set(BOOST_EXTRA_INCLUDES ${Boost_INCLUDE_DIRS})
if (${PROJECT_CAPNAME}_CXX11)
    find_package(Git)
    execute_process(COMMAND "${GIT_EXECUTABLE}" "clone" "--branch" "master" "https://github.com/aeantipov/gftools.git" "gftools" WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

message(STATUS "Building executables")
if(NOT progs_list)
    set(progs_list "anderson")
endif()

foreach(model ${progs_list})
  list (FIND default_progs ${model} _index)
  if (${_index} GREATER -1)
    string(TOUPPER ${model} def)
    set(def "POMEROL_${def}")
    add_prog(${model} ${def})
  else()
    message(WARNING "Unknown program \"${model}\" has been skiped.")
  endif()
endforeach()

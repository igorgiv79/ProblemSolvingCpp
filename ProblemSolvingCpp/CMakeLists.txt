cmake_minimum_required (VERSION 3.1)
project (ProblemSolvingCpp)
include_directories ("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HEADER_FILES Node.h pch.h)
set(SRC_FILES 
	main.cpp 
	find_sum_of_2_eq_N.cpp 
	reverse_linked_list.cpp 
	virtual_call_from_dtor.cpp
)
add_executable (ProblemSolvingCpp ${SRC_FILES} ${HEADER_FILES} )
target_link_libraries(ProblemSolvingCpp gtest)
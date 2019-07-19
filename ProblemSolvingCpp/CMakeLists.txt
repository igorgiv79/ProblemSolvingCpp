cmake_minimum_required (VERSION 3.1)
project (ProblemSolvingCpp)

IF(UNIX)
include_directories ("/usr/local/include")
link_directories("/usr/local/lib")	
ENDIF()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES Node.h BSTNode.h pch.h Tools.h)
set(SRC_FILES 
	main.cpp 
	find_sum_of_2_eq_N.cpp 
	reverse_linked_list.cpp 
	virtual_call_from_dtor.cpp
	count_leaf_nodes_in_tree.cpp
	is_derived_from.cpp
	is_same_class.cpp
	quick_sort.cpp
	reverse_string_in_place.cpp
	round_to_multiple.cpp
	swap_2_numbers_wo_temp_var.cpp
	get_visited_urls_by_freq.cpp
	calc_bond_profit.cpp
	reverse_words_in_sentense.cpp
)

add_executable (ProblemSolvingCpp ${SRC_FILES} ${HEADER_FILES} )

IF(WIN32)
IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_link_libraries(ProblemSolvingCpp gtestd)
ELSE()
	target_link_libraries(ProblemSolvingCpp gtest)
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
ELSE()
	target_link_libraries(ProblemSolvingCpp gtest)	
ENDIF(WIN32)

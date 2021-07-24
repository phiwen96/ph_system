# processor
	set (_x86_64 "false")
	set (_arm64 "false")
	if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")
		set (_x86_64 "true")
	elseif (${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm64")
		set (_arm64 "true")
	else ()
		message (FATAL_ERROR "unknown processor")
	endif ()

	set (_Darwin "false")
	set (_Linux "false")
	set (_Windows "false")

	if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
		# message("Darwin")
		set (_Darwin "true")
		# add_compile_definitions (Darwin)
	elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
		set (_Linux "true")
		# add_compile_definitions (Linux)
	elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		message (FATAL_ERROR "not yet defined for Windows")

		set (_Windows 1)
		# add_compile_definitions (Windows)
	else ()
		message (FATAL_ERROR "unknown system ${CMAKE_SYSTEM_NAME}")
	endif ()






set (include_dir "${CMAKE_CURRENT_LIST_DIR}/../include/ph_system")
set (src_dir "${CMAKE_CURRENT_LIST_DIR}")

ph_create_modules (

	MODULES 
		"system"


	INCLUDE
		"${include_dir}"

	SRC 
		"${src_dir}"
)

file(GLOB_RECURSE HEADER_LIST "${include_dir}/*.hpp")
file(GLOB SOURCE_LIST "${src_dir}/*.cpp")

set (self ${PROJECT_NAME})

# configure_file (../include/ph_system/system.hpp.in system.hpp)
configure_file (system.hpp.in ${CMAKE_CURRENT_LIST_DIR}/../include/ph_system/system.hpp @ONLY)


add_library (${self} STATIC 
	# ${SOURCE_LIST}  
    ${SOURCE_LIST}
    ${HEADER_LIST} 
)

target_compile_definitions (${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:DEBUG> $<$<CONFIG:RELEASE>:RELEASE>")






ph_precompile (TARGET ${self} PUBLIC PCH ${std_pch} ${boost_pch})

add_library (ph::system ALIAS ${self})
target_link_libraries (${self} PRIVATE ${Boost_LIBRARIES})
target_include_directories (${self} PUBLIC ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
# target_include_directories (${self} PUBLIC ph::coroutines)
target_compile_features (${self} PUBLIC cxx_std_20)


target_include_directories(${self} PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${self}>
    $<INSTALL_INTERFACE:include/${self}>
)

target_include_directories(${self} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()
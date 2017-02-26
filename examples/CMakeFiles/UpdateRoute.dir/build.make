# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/src/github/clean_c_sdk/route4me-c-sdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/src/github/clean_c_sdk/route4me-c-sdk

# Include any dependencies generated for this target.
include test/CMakeFiles/UpdateRoute.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/UpdateRoute.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/UpdateRoute.dir/flags.make

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o: test/CMakeFiles/UpdateRoute.dir/flags.make
test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o: test/UpdateRoute.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/UpdateRoute.c

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UpdateRoute.dir/UpdateRoute.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/UpdateRoute.c > CMakeFiles/UpdateRoute.dir/UpdateRoute.c.i

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UpdateRoute.dir/UpdateRoute.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/UpdateRoute.c -o CMakeFiles/UpdateRoute.dir/UpdateRoute.c.s

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.requires:
.PHONY : test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.requires

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.provides: test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.requires
	$(MAKE) -f test/CMakeFiles/UpdateRoute.dir/build.make test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.provides.build
.PHONY : test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.provides

test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.provides.build: test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o

# Object files for target UpdateRoute
UpdateRoute_OBJECTS = \
"CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o"

# External object files for target UpdateRoute
UpdateRoute_EXTERNAL_OBJECTS =

test/UpdateRoute: test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o
test/UpdateRoute: test/CMakeFiles/UpdateRoute.dir/build.make
test/UpdateRoute: lib/libroute4me.a
test/UpdateRoute: /usr/lib/i386-linux-gnu/libcurl.so
test/UpdateRoute: lib/json-c/libjson-c.a
test/UpdateRoute: test/CMakeFiles/UpdateRoute.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable UpdateRoute"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UpdateRoute.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/UpdateRoute.dir/build: test/UpdateRoute
.PHONY : test/CMakeFiles/UpdateRoute.dir/build

test/CMakeFiles/UpdateRoute.dir/requires: test/CMakeFiles/UpdateRoute.dir/UpdateRoute.c.o.requires
.PHONY : test/CMakeFiles/UpdateRoute.dir/requires

test/CMakeFiles/UpdateRoute.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/UpdateRoute.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/UpdateRoute.dir/clean

test/CMakeFiles/UpdateRoute.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/UpdateRoute.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/UpdateRoute.dir/depend


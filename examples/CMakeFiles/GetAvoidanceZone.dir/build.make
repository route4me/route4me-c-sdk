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
include test/CMakeFiles/GetAvoidanceZone.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/GetAvoidanceZone.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/GetAvoidanceZone.dir/flags.make

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o: test/CMakeFiles/GetAvoidanceZone.dir/flags.make
test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o: test/GetAvoidanceZone.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetAvoidanceZone.c

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetAvoidanceZone.c > CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.i

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetAvoidanceZone.c -o CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.s

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.requires:
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.requires

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.provides: test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.requires
	$(MAKE) -f test/CMakeFiles/GetAvoidanceZone.dir/build.make test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.provides.build
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.provides

test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.provides.build: test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o

# Object files for target GetAvoidanceZone
GetAvoidanceZone_OBJECTS = \
"CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o"

# External object files for target GetAvoidanceZone
GetAvoidanceZone_EXTERNAL_OBJECTS =

test/GetAvoidanceZone: test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o
test/GetAvoidanceZone: test/CMakeFiles/GetAvoidanceZone.dir/build.make
test/GetAvoidanceZone: lib/libroute4me.a
test/GetAvoidanceZone: /usr/lib/i386-linux-gnu/libcurl.so
test/GetAvoidanceZone: lib/json-c/libjson-c.a
test/GetAvoidanceZone: test/CMakeFiles/GetAvoidanceZone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable GetAvoidanceZone"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetAvoidanceZone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/GetAvoidanceZone.dir/build: test/GetAvoidanceZone
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/build

test/CMakeFiles/GetAvoidanceZone.dir/requires: test/CMakeFiles/GetAvoidanceZone.dir/GetAvoidanceZone.c.o.requires
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/requires

test/CMakeFiles/GetAvoidanceZone.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/GetAvoidanceZone.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/clean

test/CMakeFiles/GetAvoidanceZone.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/GetAvoidanceZone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/GetAvoidanceZone.dir/depend

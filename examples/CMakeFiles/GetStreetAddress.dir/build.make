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
include test/CMakeFiles/GetStreetAddress.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/GetStreetAddress.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/GetStreetAddress.dir/flags.make

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o: test/CMakeFiles/GetStreetAddress.dir/flags.make
test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o: test/GetStreetAddress.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetStreetAddress.c

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetStreetAddress.c > CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.i

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/GetStreetAddress.c -o CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.s

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.requires:
.PHONY : test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.requires

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.provides: test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.requires
	$(MAKE) -f test/CMakeFiles/GetStreetAddress.dir/build.make test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.provides.build
.PHONY : test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.provides

test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.provides.build: test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o

# Object files for target GetStreetAddress
GetStreetAddress_OBJECTS = \
"CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o"

# External object files for target GetStreetAddress
GetStreetAddress_EXTERNAL_OBJECTS =

test/GetStreetAddress: test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o
test/GetStreetAddress: test/CMakeFiles/GetStreetAddress.dir/build.make
test/GetStreetAddress: lib/libroute4me.a
test/GetStreetAddress: /usr/lib/i386-linux-gnu/libcurl.so
test/GetStreetAddress: lib/json-c/libjson-c.a
test/GetStreetAddress: test/CMakeFiles/GetStreetAddress.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable GetStreetAddress"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GetStreetAddress.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/GetStreetAddress.dir/build: test/GetStreetAddress
.PHONY : test/CMakeFiles/GetStreetAddress.dir/build

test/CMakeFiles/GetStreetAddress.dir/requires: test/CMakeFiles/GetStreetAddress.dir/GetStreetAddress.c.o.requires
.PHONY : test/CMakeFiles/GetStreetAddress.dir/requires

test/CMakeFiles/GetStreetAddress.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/GetStreetAddress.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/GetStreetAddress.dir/clean

test/CMakeFiles/GetStreetAddress.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/GetStreetAddress.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/GetStreetAddress.dir/depend

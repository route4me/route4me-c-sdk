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
include test/CMakeFiles/SetGps.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/SetGps.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/SetGps.dir/flags.make

test/CMakeFiles/SetGps.dir/SetGps.c.o: test/CMakeFiles/SetGps.dir/flags.make
test/CMakeFiles/SetGps.dir/SetGps.c.o: test/SetGps.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/SetGps.dir/SetGps.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SetGps.dir/SetGps.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SetGps.c

test/CMakeFiles/SetGps.dir/SetGps.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SetGps.dir/SetGps.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SetGps.c > CMakeFiles/SetGps.dir/SetGps.c.i

test/CMakeFiles/SetGps.dir/SetGps.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SetGps.dir/SetGps.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SetGps.c -o CMakeFiles/SetGps.dir/SetGps.c.s

test/CMakeFiles/SetGps.dir/SetGps.c.o.requires:
.PHONY : test/CMakeFiles/SetGps.dir/SetGps.c.o.requires

test/CMakeFiles/SetGps.dir/SetGps.c.o.provides: test/CMakeFiles/SetGps.dir/SetGps.c.o.requires
	$(MAKE) -f test/CMakeFiles/SetGps.dir/build.make test/CMakeFiles/SetGps.dir/SetGps.c.o.provides.build
.PHONY : test/CMakeFiles/SetGps.dir/SetGps.c.o.provides

test/CMakeFiles/SetGps.dir/SetGps.c.o.provides.build: test/CMakeFiles/SetGps.dir/SetGps.c.o

# Object files for target SetGps
SetGps_OBJECTS = \
"CMakeFiles/SetGps.dir/SetGps.c.o"

# External object files for target SetGps
SetGps_EXTERNAL_OBJECTS =

test/SetGps: test/CMakeFiles/SetGps.dir/SetGps.c.o
test/SetGps: test/CMakeFiles/SetGps.dir/build.make
test/SetGps: lib/libroute4me.a
test/SetGps: /usr/lib/i386-linux-gnu/libcurl.so
test/SetGps: lib/json-c/libjson-c.a
test/SetGps: test/CMakeFiles/SetGps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable SetGps"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SetGps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/SetGps.dir/build: test/SetGps
.PHONY : test/CMakeFiles/SetGps.dir/build

test/CMakeFiles/SetGps.dir/requires: test/CMakeFiles/SetGps.dir/SetGps.c.o.requires
.PHONY : test/CMakeFiles/SetGps.dir/requires

test/CMakeFiles/SetGps.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/SetGps.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/SetGps.dir/clean

test/CMakeFiles/SetGps.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/SetGps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/SetGps.dir/depend

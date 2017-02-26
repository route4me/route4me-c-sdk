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
include test/CMakeFiles/LogActivity.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/LogActivity.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/LogActivity.dir/flags.make

test/CMakeFiles/LogActivity.dir/LogActivity.c.o: test/CMakeFiles/LogActivity.dir/flags.make
test/CMakeFiles/LogActivity.dir/LogActivity.c.o: test/LogActivity.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/LogActivity.dir/LogActivity.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/LogActivity.dir/LogActivity.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/LogActivity.c

test/CMakeFiles/LogActivity.dir/LogActivity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LogActivity.dir/LogActivity.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/LogActivity.c > CMakeFiles/LogActivity.dir/LogActivity.c.i

test/CMakeFiles/LogActivity.dir/LogActivity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LogActivity.dir/LogActivity.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/LogActivity.c -o CMakeFiles/LogActivity.dir/LogActivity.c.s

test/CMakeFiles/LogActivity.dir/LogActivity.c.o.requires:
.PHONY : test/CMakeFiles/LogActivity.dir/LogActivity.c.o.requires

test/CMakeFiles/LogActivity.dir/LogActivity.c.o.provides: test/CMakeFiles/LogActivity.dir/LogActivity.c.o.requires
	$(MAKE) -f test/CMakeFiles/LogActivity.dir/build.make test/CMakeFiles/LogActivity.dir/LogActivity.c.o.provides.build
.PHONY : test/CMakeFiles/LogActivity.dir/LogActivity.c.o.provides

test/CMakeFiles/LogActivity.dir/LogActivity.c.o.provides.build: test/CMakeFiles/LogActivity.dir/LogActivity.c.o

# Object files for target LogActivity
LogActivity_OBJECTS = \
"CMakeFiles/LogActivity.dir/LogActivity.c.o"

# External object files for target LogActivity
LogActivity_EXTERNAL_OBJECTS =

test/LogActivity: test/CMakeFiles/LogActivity.dir/LogActivity.c.o
test/LogActivity: test/CMakeFiles/LogActivity.dir/build.make
test/LogActivity: lib/libroute4me.a
test/LogActivity: /usr/lib/i386-linux-gnu/libcurl.so
test/LogActivity: lib/json-c/libjson-c.a
test/LogActivity: test/CMakeFiles/LogActivity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable LogActivity"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LogActivity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/LogActivity.dir/build: test/LogActivity
.PHONY : test/CMakeFiles/LogActivity.dir/build

test/CMakeFiles/LogActivity.dir/requires: test/CMakeFiles/LogActivity.dir/LogActivity.c.o.requires
.PHONY : test/CMakeFiles/LogActivity.dir/requires

test/CMakeFiles/LogActivity.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/LogActivity.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/LogActivity.dir/clean

test/CMakeFiles/LogActivity.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/LogActivity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/LogActivity.dir/depend

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
include test/CMakeFiles/AddOptimization.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/AddOptimization.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/AddOptimization.dir/flags.make

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o: test/CMakeFiles/AddOptimization.dir/flags.make
test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o: test/AddOptimization.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/AddOptimization.dir/AddOptimization.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddOptimization.c

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AddOptimization.dir/AddOptimization.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddOptimization.c > CMakeFiles/AddOptimization.dir/AddOptimization.c.i

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AddOptimization.dir/AddOptimization.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddOptimization.c -o CMakeFiles/AddOptimization.dir/AddOptimization.c.s

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.requires:
.PHONY : test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.requires

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.provides: test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.requires
	$(MAKE) -f test/CMakeFiles/AddOptimization.dir/build.make test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.provides.build
.PHONY : test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.provides

test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.provides.build: test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o

# Object files for target AddOptimization
AddOptimization_OBJECTS = \
"CMakeFiles/AddOptimization.dir/AddOptimization.c.o"

# External object files for target AddOptimization
AddOptimization_EXTERNAL_OBJECTS =

test/AddOptimization: test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o
test/AddOptimization: test/CMakeFiles/AddOptimization.dir/build.make
test/AddOptimization: lib/libroute4me.a
test/AddOptimization: /usr/lib/i386-linux-gnu/libcurl.so
test/AddOptimization: lib/json-c/libjson-c.a
test/AddOptimization: test/CMakeFiles/AddOptimization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable AddOptimization"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AddOptimization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/AddOptimization.dir/build: test/AddOptimization
.PHONY : test/CMakeFiles/AddOptimization.dir/build

test/CMakeFiles/AddOptimization.dir/requires: test/CMakeFiles/AddOptimization.dir/AddOptimization.c.o.requires
.PHONY : test/CMakeFiles/AddOptimization.dir/requires

test/CMakeFiles/AddOptimization.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/AddOptimization.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/AddOptimization.dir/clean

test/CMakeFiles/AddOptimization.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/AddOptimization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/AddOptimization.dir/depend

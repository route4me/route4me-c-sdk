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
include test/CMakeFiles/AddAddressToOptimization.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/AddAddressToOptimization.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/AddAddressToOptimization.dir/flags.make

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o: test/CMakeFiles/AddAddressToOptimization.dir/flags.make
test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o: test/AddAddressToOptimization.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddAddressToOptimization.c

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddAddressToOptimization.c > CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.i

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddAddressToOptimization.c -o CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.s

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.requires:
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.requires

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.provides: test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.requires
	$(MAKE) -f test/CMakeFiles/AddAddressToOptimization.dir/build.make test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.provides.build
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.provides

test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.provides.build: test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o

# Object files for target AddAddressToOptimization
AddAddressToOptimization_OBJECTS = \
"CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o"

# External object files for target AddAddressToOptimization
AddAddressToOptimization_EXTERNAL_OBJECTS =

test/AddAddressToOptimization: test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o
test/AddAddressToOptimization: test/CMakeFiles/AddAddressToOptimization.dir/build.make
test/AddAddressToOptimization: lib/libroute4me.a
test/AddAddressToOptimization: /usr/lib/i386-linux-gnu/libcurl.so
test/AddAddressToOptimization: lib/json-c/libjson-c.a
test/AddAddressToOptimization: test/CMakeFiles/AddAddressToOptimization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable AddAddressToOptimization"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AddAddressToOptimization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/AddAddressToOptimization.dir/build: test/AddAddressToOptimization
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/build

test/CMakeFiles/AddAddressToOptimization.dir/requires: test/CMakeFiles/AddAddressToOptimization.dir/AddAddressToOptimization.c.o.requires
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/requires

test/CMakeFiles/AddAddressToOptimization.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/AddAddressToOptimization.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/clean

test/CMakeFiles/AddAddressToOptimization.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/AddAddressToOptimization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/AddAddressToOptimization.dir/depend


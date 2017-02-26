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
include test/CMakeFiles/SingleDriverRoundTrip.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/SingleDriverRoundTrip.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/SingleDriverRoundTrip.dir/flags.make

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o: test/CMakeFiles/SingleDriverRoundTrip.dir/flags.make
test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o: test/SingleDriverRoundTrip.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SingleDriverRoundTrip.c

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SingleDriverRoundTrip.c > CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.i

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/SingleDriverRoundTrip.c -o CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.s

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.requires:
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.requires

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.provides: test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.requires
	$(MAKE) -f test/CMakeFiles/SingleDriverRoundTrip.dir/build.make test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.provides.build
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.provides

test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.provides.build: test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o

# Object files for target SingleDriverRoundTrip
SingleDriverRoundTrip_OBJECTS = \
"CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o"

# External object files for target SingleDriverRoundTrip
SingleDriverRoundTrip_EXTERNAL_OBJECTS =

test/SingleDriverRoundTrip: test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o
test/SingleDriverRoundTrip: test/CMakeFiles/SingleDriverRoundTrip.dir/build.make
test/SingleDriverRoundTrip: lib/libroute4me.a
test/SingleDriverRoundTrip: /usr/lib/i386-linux-gnu/libcurl.so
test/SingleDriverRoundTrip: lib/json-c/libjson-c.a
test/SingleDriverRoundTrip: test/CMakeFiles/SingleDriverRoundTrip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable SingleDriverRoundTrip"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SingleDriverRoundTrip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/SingleDriverRoundTrip.dir/build: test/SingleDriverRoundTrip
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/build

test/CMakeFiles/SingleDriverRoundTrip.dir/requires: test/CMakeFiles/SingleDriverRoundTrip.dir/SingleDriverRoundTrip.c.o.requires
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/requires

test/CMakeFiles/SingleDriverRoundTrip.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/SingleDriverRoundTrip.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/clean

test/CMakeFiles/SingleDriverRoundTrip.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/SingleDriverRoundTrip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/SingleDriverRoundTrip.dir/depend


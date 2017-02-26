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
include test/CMakeFiles/AddRouteNotes.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/AddRouteNotes.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/AddRouteNotes.dir/flags.make

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o: test/CMakeFiles/AddRouteNotes.dir/flags.make
test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o: test/AddRouteNotes.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddRouteNotes.c

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddRouteNotes.c > CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.i

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/AddRouteNotes.c -o CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.s

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.requires:
.PHONY : test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.requires

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.provides: test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.requires
	$(MAKE) -f test/CMakeFiles/AddRouteNotes.dir/build.make test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.provides.build
.PHONY : test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.provides

test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.provides.build: test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o

# Object files for target AddRouteNotes
AddRouteNotes_OBJECTS = \
"CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o"

# External object files for target AddRouteNotes
AddRouteNotes_EXTERNAL_OBJECTS =

test/AddRouteNotes: test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o
test/AddRouteNotes: test/CMakeFiles/AddRouteNotes.dir/build.make
test/AddRouteNotes: lib/libroute4me.a
test/AddRouteNotes: /usr/lib/i386-linux-gnu/libcurl.so
test/AddRouteNotes: lib/json-c/libjson-c.a
test/AddRouteNotes: test/CMakeFiles/AddRouteNotes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable AddRouteNotes"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AddRouteNotes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/AddRouteNotes.dir/build: test/AddRouteNotes
.PHONY : test/CMakeFiles/AddRouteNotes.dir/build

test/CMakeFiles/AddRouteNotes.dir/requires: test/CMakeFiles/AddRouteNotes.dir/AddRouteNotes.c.o.requires
.PHONY : test/CMakeFiles/AddRouteNotes.dir/requires

test/CMakeFiles/AddRouteNotes.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/AddRouteNotes.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/AddRouteNotes.dir/clean

test/CMakeFiles/AddRouteNotes.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/AddRouteNotes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/AddRouteNotes.dir/depend

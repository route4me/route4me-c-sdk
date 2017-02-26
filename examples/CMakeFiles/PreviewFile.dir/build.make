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
include test/CMakeFiles/PreviewFile.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/PreviewFile.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/PreviewFile.dir/flags.make

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o: test/CMakeFiles/PreviewFile.dir/flags.make
test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o: test/PreviewFile.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alex/src/github/clean_c_sdk/route4me-c-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/PreviewFile.dir/PreviewFile.c.o   -c /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/PreviewFile.c

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PreviewFile.dir/PreviewFile.c.i"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/PreviewFile.c > CMakeFiles/PreviewFile.dir/PreviewFile.c.i

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PreviewFile.dir/PreviewFile.c.s"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/PreviewFile.c -o CMakeFiles/PreviewFile.dir/PreviewFile.c.s

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.requires:
.PHONY : test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.requires

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.provides: test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.requires
	$(MAKE) -f test/CMakeFiles/PreviewFile.dir/build.make test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.provides.build
.PHONY : test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.provides

test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.provides.build: test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o

# Object files for target PreviewFile
PreviewFile_OBJECTS = \
"CMakeFiles/PreviewFile.dir/PreviewFile.c.o"

# External object files for target PreviewFile
PreviewFile_EXTERNAL_OBJECTS =

test/PreviewFile: test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o
test/PreviewFile: test/CMakeFiles/PreviewFile.dir/build.make
test/PreviewFile: lib/libroute4me.a
test/PreviewFile: /usr/lib/i386-linux-gnu/libcurl.so
test/PreviewFile: lib/json-c/libjson-c.a
test/PreviewFile: test/CMakeFiles/PreviewFile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable PreviewFile"
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PreviewFile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/PreviewFile.dir/build: test/PreviewFile
.PHONY : test/CMakeFiles/PreviewFile.dir/build

test/CMakeFiles/PreviewFile.dir/requires: test/CMakeFiles/PreviewFile.dir/PreviewFile.c.o.requires
.PHONY : test/CMakeFiles/PreviewFile.dir/requires

test/CMakeFiles/PreviewFile.dir/clean:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test && $(CMAKE_COMMAND) -P CMakeFiles/PreviewFile.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/PreviewFile.dir/clean

test/CMakeFiles/PreviewFile.dir/depend:
	cd /home/alex/src/github/clean_c_sdk/route4me-c-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test /home/alex/src/github/clean_c_sdk/route4me-c-sdk/test/CMakeFiles/PreviewFile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/PreviewFile.dir/depend


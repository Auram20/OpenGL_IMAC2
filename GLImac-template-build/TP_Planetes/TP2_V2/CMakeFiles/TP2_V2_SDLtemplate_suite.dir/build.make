# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/6im2/manik/Bureau/OpenGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes

# Include any dependencies generated for this target.
include TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/depend.make

# Include the progress variables for this target.
include TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/progress.make

# Include the compile flags for this target's objects.
include TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/flags.make

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/flags.make
TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o: /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP2_V2/SDLtemplate_suite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o -c /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP2_V2/SDLtemplate_suite.cpp

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.i"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP2_V2/SDLtemplate_suite.cpp > CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.i

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.s"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP2_V2/SDLtemplate_suite.cpp -o CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.s

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.requires:

.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.requires

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.provides: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.requires
	$(MAKE) -f TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/build.make TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.provides.build
.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.provides

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.provides.build: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o


# Object files for target TP2_V2_SDLtemplate_suite
TP2_V2_SDLtemplate_suite_OBJECTS = \
"CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o"

# External object files for target TP2_V2_SDLtemplate_suite
TP2_V2_SDLtemplate_suite_EXTERNAL_OBJECTS =

TP2_V2/TP2_V2_SDLtemplate_suite: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o
TP2_V2/TP2_V2_SDLtemplate_suite: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/build.make
TP2_V2/TP2_V2_SDLtemplate_suite: glimac/libglimac.a
TP2_V2/TP2_V2_SDLtemplate_suite: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP2_V2/TP2_V2_SDLtemplate_suite: /usr/lib/x86_64-linux-gnu/libSDL.so
TP2_V2/TP2_V2_SDLtemplate_suite: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP2_V2/TP2_V2_SDLtemplate_suite: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP2_V2/TP2_V2_SDLtemplate_suite: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP2_V2_SDLtemplate_suite"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2_V2_SDLtemplate_suite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/build: TP2_V2/TP2_V2_SDLtemplate_suite

.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/build

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/requires: TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/SDLtemplate_suite.cpp.o.requires

.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/requires

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/clean:
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 && $(CMAKE_COMMAND) -P CMakeFiles/TP2_V2_SDLtemplate_suite.dir/cmake_clean.cmake
.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/clean

TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/depend:
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im2/manik/Bureau/OpenGL/GLImac-Template /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP2_V2 /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2 /home/6im2/manik/Bureau/OpenGL/GLImac-template-build/TP_Planetes/TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP2_V2/CMakeFiles/TP2_V2_SDLtemplate_suite.dir/depend


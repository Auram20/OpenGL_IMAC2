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
CMAKE_BINARY_DIR = /home/6im2/manik/Bureau/OpenGL/GLImac-Template

# Include any dependencies generated for this target.
include TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/depend.make

# Include the progress variables for this target.
include TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/progress.make

# Include the compile flags for this target's objects.
include TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/flags.make

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/flags.make
TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o: TP_Planetes/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/6im2/manik/Bureau/OpenGL/GLImac-Template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o -c /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes/Sphere.cpp

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.i"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes/Sphere.cpp > CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.i

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.s"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes/Sphere.cpp -o CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.s

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.requires:

.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.requires

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.provides: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.requires
	$(MAKE) -f TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/build.make TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.provides.build
.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.provides

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.provides.build: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o


# Object files for target TP_Planetes_Sphere
TP_Planetes_Sphere_OBJECTS = \
"CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o"

# External object files for target TP_Planetes_Sphere
TP_Planetes_Sphere_EXTERNAL_OBJECTS =

TP_Planetes/TP_Planetes_Sphere: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o
TP_Planetes/TP_Planetes_Sphere: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/build.make
TP_Planetes/TP_Planetes_Sphere: glimac/libglimac.a
TP_Planetes/TP_Planetes_Sphere: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP_Planetes/TP_Planetes_Sphere: /usr/lib/x86_64-linux-gnu/libSDL.so
TP_Planetes/TP_Planetes_Sphere: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP_Planetes/TP_Planetes_Sphere: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP_Planetes/TP_Planetes_Sphere: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/6im2/manik/Bureau/OpenGL/GLImac-Template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP_Planetes_Sphere"
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_Planetes_Sphere.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/build: TP_Planetes/TP_Planetes_Sphere

.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/build

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/requires: TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/Sphere.cpp.o.requires

.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/requires

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/clean:
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes && $(CMAKE_COMMAND) -P CMakeFiles/TP_Planetes_Sphere.dir/cmake_clean.cmake
.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/clean

TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/depend:
	cd /home/6im2/manik/Bureau/OpenGL/GLImac-Template && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im2/manik/Bureau/OpenGL/GLImac-Template /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes /home/6im2/manik/Bureau/OpenGL/GLImac-Template /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes /home/6im2/manik/Bureau/OpenGL/GLImac-Template/TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP_Planetes/CMakeFiles/TP_Planetes_Sphere.dir/depend


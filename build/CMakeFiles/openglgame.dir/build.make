# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = "C:/Program Files (x86)/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/John/Documents/cpp/projecttestvim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/John/Documents/cpp/projecttestvim/build

# Include any dependencies generated for this target.
include CMakeFiles/openglgame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openglgame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openglgame.dir/flags.make

CMakeFiles/openglgame.dir/src/main.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/main.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/openglgame.dir/src/main.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/main.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/main.cpp

CMakeFiles/openglgame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/main.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/main.cpp > CMakeFiles/openglgame.dir/src/main.cpp.i

CMakeFiles/openglgame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/main.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/main.cpp -o CMakeFiles/openglgame.dir/src/main.cpp.s

CMakeFiles/openglgame.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/main.cpp.obj.requires

CMakeFiles/openglgame.dir/src/main.cpp.obj.provides: CMakeFiles/openglgame.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/main.cpp.obj.provides

CMakeFiles/openglgame.dir/src/main.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/main.cpp.obj


CMakeFiles/openglgame.dir/src/entity.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/entity.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/entity.cpp.obj: ../src/entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/openglgame.dir/src/entity.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/entity.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/entity.cpp

CMakeFiles/openglgame.dir/src/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/entity.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/entity.cpp > CMakeFiles/openglgame.dir/src/entity.cpp.i

CMakeFiles/openglgame.dir/src/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/entity.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/entity.cpp -o CMakeFiles/openglgame.dir/src/entity.cpp.s

CMakeFiles/openglgame.dir/src/entity.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/entity.cpp.obj.requires

CMakeFiles/openglgame.dir/src/entity.cpp.obj.provides: CMakeFiles/openglgame.dir/src/entity.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/entity.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/entity.cpp.obj.provides

CMakeFiles/openglgame.dir/src/entity.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/entity.cpp.obj


CMakeFiles/openglgame.dir/src/input.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/input.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/input.cpp.obj: ../src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/openglgame.dir/src/input.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/input.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/input.cpp

CMakeFiles/openglgame.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/input.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/input.cpp > CMakeFiles/openglgame.dir/src/input.cpp.i

CMakeFiles/openglgame.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/input.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/input.cpp -o CMakeFiles/openglgame.dir/src/input.cpp.s

CMakeFiles/openglgame.dir/src/input.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/input.cpp.obj.requires

CMakeFiles/openglgame.dir/src/input.cpp.obj.provides: CMakeFiles/openglgame.dir/src/input.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/input.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/input.cpp.obj.provides

CMakeFiles/openglgame.dir/src/input.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/input.cpp.obj


CMakeFiles/openglgame.dir/src/world.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/world.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/world.cpp.obj: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/openglgame.dir/src/world.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/world.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/world.cpp

CMakeFiles/openglgame.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/world.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/world.cpp > CMakeFiles/openglgame.dir/src/world.cpp.i

CMakeFiles/openglgame.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/world.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/world.cpp -o CMakeFiles/openglgame.dir/src/world.cpp.s

CMakeFiles/openglgame.dir/src/world.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/world.cpp.obj.requires

CMakeFiles/openglgame.dir/src/world.cpp.obj.provides: CMakeFiles/openglgame.dir/src/world.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/world.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/world.cpp.obj.provides

CMakeFiles/openglgame.dir/src/world.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/world.cpp.obj


CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj: ../src/graphics/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/graphics/renderer.cpp

CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/graphics/renderer.cpp > CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.i

CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/graphics/renderer.cpp -o CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.s

CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.requires

CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.provides: CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.provides

CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj


CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj: ../src/graphics/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shader.cpp

CMakeFiles/openglgame.dir/src/graphics/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/graphics/shader.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shader.cpp > CMakeFiles/openglgame.dir/src/graphics/shader.cpp.i

CMakeFiles/openglgame.dir/src/graphics/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/graphics/shader.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shader.cpp -o CMakeFiles/openglgame.dir/src/graphics/shader.cpp.s

CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.requires

CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.provides: CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.provides

CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj


CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj: CMakeFiles/openglgame.dir/flags.make
CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj: CMakeFiles/openglgame.dir/includes_CXX.rsp
CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj: ../src/graphics/shaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj -c C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shaderProgram.cpp

CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.i"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shaderProgram.cpp > CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.i

CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.s"
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:/Users/John/Documents/cpp/projecttestvim/src/graphics/shaderProgram.cpp -o CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.s

CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.requires:

.PHONY : CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.requires

CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.provides: CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.requires
	$(MAKE) -f CMakeFiles/openglgame.dir/build.make CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.provides.build
.PHONY : CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.provides

CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.provides.build: CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj


# Object files for target openglgame
openglgame_OBJECTS = \
"CMakeFiles/openglgame.dir/src/main.cpp.obj" \
"CMakeFiles/openglgame.dir/src/entity.cpp.obj" \
"CMakeFiles/openglgame.dir/src/input.cpp.obj" \
"CMakeFiles/openglgame.dir/src/world.cpp.obj" \
"CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj" \
"CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj" \
"CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj"

# External object files for target openglgame
openglgame_EXTERNAL_OBJECTS =

openglgame.exe: CMakeFiles/openglgame.dir/src/main.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/entity.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/input.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/world.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj
openglgame.exe: CMakeFiles/openglgame.dir/build.make
openglgame.exe: CMakeFiles/openglgame.dir/linklibs.rsp
openglgame.exe: CMakeFiles/openglgame.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable openglgame.exe"
	"C:/Program Files (x86)/CMake/bin/cmake.exe" -E remove -f CMakeFiles/openglgame.dir/objects.a
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/ar.exe cr CMakeFiles/openglgame.dir/objects.a @CMakeFiles/openglgame.dir/objects1.rsp
	C:/mingw-w64/i686-4.9.2-posix-dwarf-rt_v3-rev1/mingw32/bin/c++.exe     -Wl,--whole-archive CMakeFiles/openglgame.dir/objects.a -Wl,--no-whole-archive  -o openglgame.exe -Wl,--out-implib,libopenglgame.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/openglgame.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/openglgame.dir/build: openglgame.exe

.PHONY : CMakeFiles/openglgame.dir/build

CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/main.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/entity.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/input.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/world.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/graphics/renderer.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/graphics/shader.cpp.obj.requires
CMakeFiles/openglgame.dir/requires: CMakeFiles/openglgame.dir/src/graphics/shaderProgram.cpp.obj.requires

.PHONY : CMakeFiles/openglgame.dir/requires

CMakeFiles/openglgame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openglgame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openglgame.dir/clean

CMakeFiles/openglgame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/John/Documents/cpp/projecttestvim C:/Users/John/Documents/cpp/projecttestvim C:/Users/John/Documents/cpp/projecttestvim/build C:/Users/John/Documents/cpp/projecttestvim/build C:/Users/John/Documents/cpp/projecttestvim/build/CMakeFiles/openglgame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openglgame.dir/depend


# OpenGL Template

This repo is meant as a starting point for building any OpenGL project with glfw/glad. The glfw and glm repos are added as submodules in the repo and subdirectories in the CMake file.
This way they always stay up to date and are compiled statically into the program.  
The glad files are not added as submodules since they are generated by the [Glad Webgenerator](https://glad.dav1d.de).  
The libraries that come with this repo are the same ones used by Victor Gordan's [OpenGL Tutorial Series](https://www.youtube.com/playlist?list=PLPaoO-vpZnumdcb4tZc4x5Q-v7CkrQ6M-) so its perfectly suited for following along, without having configuration problems.

# Downloading and Building

To build and use this Project, first clone the repo and its submodules and the run cmake.

```bash
git clone --recurse-submodules https://github.com/BelimFaux/opengl_template.git
cd opengl_template
cmake -B build .
cmake --build build -- all
./build/opengl_template
```

If youre IDE doesn't automatically recognize the include directory, a `compile_commands.json` file can be generated from the CMake file.

```bash
cmake -DCMAKE_BUILD_TYPE=debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B build .
```

# Configuring

## Files

All files in the src/ directory get added as source files. Corresponding headers can be stored in the include/ directory.
A `.clang-format` file is provided. You can of course format youre code however you want, but it is important, that you disable `SortIncludes` or similar settings, since glfw always has to be imported after glad.

## Resources

Resources like shaders, images, models etc. that will be imported in the Program can be placed in additional directories, like the shaders/ directory in the example project.
To ensure all paths in the program to these resources are always valid I would recommend setting the path as a compile definition in the CMake file. This way all paths stay absolute and change automatically when you move the project directory.

## CMake

To change the project name or version, adjust the corresponding Variables in the CMakeLists.txt file.

```cmake
project(<your_name> VERSION <your_version>)
```

When adding new external libraries, you have to make sure you link them to youre project.

```cmake
add_subdirectory(${EXTERNAL_DIR}/<yourlib>)
target_link_libraries(${PROJECT_NAME} PRIVATE <yourlib>)
```

External headers can just be placed in the external directory without modification of the CMake file.

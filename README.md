# CRename

Interactive bulk rename utility for terminal geeks.

## Build Requirements
What you will need:
### On Linux/Ubuntu
```
cmake (tested with 3.16.0-rc3)
make (tested with 4.1)
g++ (tested with 7.4.0)
```
### On Windows
```
Visual Studio (tested with Visual Studio 2013 CE and 2019 CE)
```
### Library
```
Boost filesystem 1.71.0
```
**Note**
- For how to build Boost on Linux/Ubuntu, please read and follow this [instruction](https://www.boost.org/doc/libs/1_71_0/more/getting_started/windows.html). Then proceed and change Boost_INCLUDE_DIRS and Boost_LIBRARIES according to your local build in crename's CMakeList.txt.
- On Windows, please consider downloading from [SourceForge](https://sourceforge.net/projects/boost/files/boost-binaries/1.71.0/). With Visual Studio 2013 CE, please download install for msvc  12.0. With Visual Studio 2019 CE, please download install for msvc 14.2.

## Building Project
### On Linux/Ubuntu
1. Clone this repository.
2. cd crename
3. mkdir build
4. cd build
5. cmake -DBoost_LIBRARY_DIR_DEBUG:PATH="/home/thanhdung/Documents/CPP/libs/boost_1_71_0/out/lib" -DBoost_INCLUDE_DIR:PATH="/home/thanhdung/Documents/CPP/libs/boost_1_71_0/out/include" -DBoost_LIBRARY_DIR_RELEASE:PATH="/home/thanhdung/Documents/CPP/libs/boost_1_71_0/out/lib" -B . -S ../src
6. make -j4

**Note:** for the Boost path, set them accoringly to your local Boost build.

### On Windows
1. Clone this repository.
2. Set value for "Additional Include Directories" and "Additional Library Directories" in project's properties to point to Boost installation directory.
3. Hit Build (with either Debug or Release target).

## How to use
Like any interactive applications, crename starts with an command prompting screen.

### File Manipulating
- Directory importing: specify a directory after entered the following command:
```
file import
```
- Adding importing: specify a file after entered the following command:
```
file add
```
- Getting list of added files:
```
file show all
```
- Removing file(s) from list:
```
file remove all/[index]
```

**Note**: use "all" parameter to remove all added files or specify an index (starts from 0) to remove a specific file.


### Rule manipulating
Rules are set of changes that are created by users at runtime to specify how their files' names will be changed.
There are 5 type of rules and each type has its way of constructing behavior:

1. Removing
2. Inserting
3. Indexing
4. Finding and replacing
5. Case converting.

- Adding rule:
```
rule add {rule_type}
```
- Removing rule(s):
```
rule remove all/[index]
```
**Note**: use "all" parameter to remove all added rules or specify an index (starts from 0) to remove a specific rule.

- Rule previewing: showing how rules will run.
```
rule show all/[index]
```

**Note**: use "all" parameter to preview all added rules or specify an index (starts from 0) to preview a specific rule.

### Previewing
- Showing how files' names will be changed:
```
preview
```

### Applying
- Applying changeset to added files:
```
apply
```

**Important:** please note that this action is **irreversible**.

### Moving
Files added and rules created can be moved up or down within the list

### With index

```
file/rule move [from_index] to [to_index]
```

### With keyword

```
file/rule move [from_index] end/first
```

Using "end" wil move item to the end of list while "first" to the start of the list.

## Contact

- If there are any problems or you have any questions, please do not hesitate and contact me via email: 14dh110224@st.huflit.edu.vn

## Distributing
You can freely distribute the source code and/or customize it as well as built binaries to anyone anyway you like. But please mention this repository in your credit

## Contributing
How you can contribute to this project:
- Submit an [issue](https://github.com/thanhdung96/CRename/issues).
- Create a branch from development branch and submit a pull request to development when you're done with it.

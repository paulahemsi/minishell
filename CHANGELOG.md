# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),

## - 2021-07-22

### Changed
- tokens linked list became tokens **double** linked list

## - 2021-07-18
### Added
- Added `get_absolute_path()` function, that retrieves the correct path for a specified binary based on the PATH environment variable, or returns NULL if it can't find it.
- Added the `variadic_strjoin()` function, which permits concatenation of an variable number of strings.
- Added Macros with escaped colors for readline library.
- Added `unset()` builtin function.

### Changed
- Refactor `create_prompt()` function using `variadic_strjoin()`.
- Added	`pwd()` function, that print working directory.

## - 2021-07-17
### Added
- Added `export` function
- Added `hashmap_to_env_whith_quotes` function to insert quotes in each env variable value when is needed
- Created temporary "hook" to allow use of the `export` command

## - 2021-07-16
### Added
- Added handler to signal interrupt and signal quit in input cases.

### Changed
- Altered `print_environment()` to receive a file descriptor as a parameter.

## - 2021-07-15
### Added
- Added changelog and its first entry.
- Defined a global `struct` to contain all the information on a given `minishell` session.
- Initialized environment from `__environ` global variable.
- Initialized the `g_minishell` session struct on `main`.
- Created temporary "hook" to allow use of the `env` command, and made it run a function to print the environment.
- Implemented variable expansions

### Changed
- Removed `readline.h` escape characters from our color definitions and added them only to the prompt.

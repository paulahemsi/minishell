# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),

## - 2021-08-4
### Changed
- Strings between quotes with spaces untouched.

## - 2021-08-3
### Added
- Added easter egg.

## - 2021-07-31
### Added
- Added prompt welcome message.

## - 2021-07-28
### Added
- Added file here document redirection feature.

## - 2021-07-26
### Added
- Added file redirection feature.
- Added error status tracking.
### Changed
- Variables values now accept's equal sign
- Set variable followed by command is accepted

## - 2021-07-25
### Added
- Added `echo` builtin function.

### Changed
- Refactored error message function to use `variadic_strjoin()` instead of several print function calls.
- Correct all signals behaviors.

## - 2021-07-23
### Added
- Added pipe checker.

## - 2021-07-22
### Added
- Added pipe feature.

### Changed
- tokens linked list became tokens **double** linked list
- new tokend types: `T_PIPE` `T_REDIRECT` `T_HERE_DOC` `T_FILE`

## - 2021-07-21
### Added
- Added `cd` builtin function.

## - 2021-07-18
### Added
- Added `get_absolute_path()` function, that retrieves the correct path for a specified binary based on the PATH environment variable, or returns NULL if it can't find it.
- Added the `variadic_strjoin()` function, which permits concatenation of an variable number of strings.
- Added Macros with escaped colors for readline library.
- Added `unset()` builtin function.
- Added	`pwd()` function, that print working directory.

### Changed
- Refactor `create_prompt()` function using `variadic_strjoin()`.

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

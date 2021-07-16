# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),

## - 2021-07-16
### Added
- Added handler to signal interrupt and signal quit in input cases.

## - 2021-07-15
### Added
- Added changelog and its first entry.
- Defined a global `struct` to contain all the information on a given `minishell` session.
- Initialized environment from `__environ` global variable.
- Initialized the `g_minishell` session struct on `main`.
- Created temporary "hook" to allow use of the `env` command, and made it run a function to print the environment.

### Changed
- Removed `readline.h` escape characters from our color definitions and added them only to the prompt.


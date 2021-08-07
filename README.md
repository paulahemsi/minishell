
# minishell
As beautiful as a shell

* [Introduction](#introduction)
* [Usage](#usage)
* [Builtins implemented](#builtins_implemented)
* [Step by step](#step_by_step)
* [Mindmap](#mindmap)
* [Study resources](#study_resources)
* [libft functions](#libft_functions)

## introduction

The objective of this project is to create a simple shell and learn a lot about processes and file descriptors

The existence of shells is linked to the very existence of IT. At the time, all coders agreed that communicating with a computer using aligned 1/0 switches was seriously irritating. It was only logical that they came up with the idea to communicate with a computer using interactive lines of commands in a language somewhat close to english.
With Minishell project, we’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.

![image](https://user-images.githubusercontent.com/63563271/127766732-743a1cf4-6d1e-4663-b8d6-1705f69c63dd.png)


## usage

Clone the repo `git clone --recurse-submodules https://github.com/paulahemsi/minishell.git`

Install Readline library `make install`

Compile Minishell `make`

Run `./minishell`

Enjoy! 

![minihell_2x](https://user-images.githubusercontent.com/63563271/128601846-b290ea5f-e45a-4a6d-8446-3684576d5782.gif)

## builtins_implemented

command | description  |
---|------|
**echo** | echo the STRING(s) to standart output. **-n** flag: do not output the trailing newline |
**cd** | change the shell working directory	(with a relative or absolute path)|
**pwd** | print name of current/working directory	|
**export** | set export attribute for shell variables | 
**unset** | unset values of shell variables |
**env** | print the environment	| 
**exit** | cause the shell to exit with the exit status specified	| 

## step_by_step

* Prompt implementation
* HashTable functions implementation
* Tokenizer implementation
* Variables expansion implementation
* Builtins implementation
* Parse and execute sistem design
* Signals implementation
* Parsing implementation
* Execute implementation
* Norme
* Bugs hunting

## mindmap

![mindmap](https://user-images.githubusercontent.com/63563271/128610128-fa85c8ae-eff7-4b8a-9b29-90cdfc4aeaa5.png)


## study_resources

### unix
* [Unix Processes in C -video](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
* [Termination Signals](https://www.gnu.org/software/libc/manual/html_node/Termination-Signals.html)
* [Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_10)
* [Bash Guide for Beginners](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)
* [Programming Terminal Devices -video](https://www.youtube.com/watch?v=t5sC6G73oo4)
* [Introduction to System Programming -video](https://www.youtube.com/watch?v=qThI-U34KYs&list=PL7B2bn3G_wfC-mRpG7cxJMnGWdPAQTViW)
* [Capturing exit status code of child process](https://stackoverflow.com/questions/27306764/capturing-exit-status-code-of-child-process)
* [Notion with details about Readline lib, Termcaps and Signals](https://www.notion.so/Minishell-e856e9af377f44b588e5fe120d4b6e2a)
* [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

### hashtable
* [Hash Table in C/C++ – A Complete Implementation](https://www.journaldev.com/35238/hash-table-in-c-plus-plus)

### tokenizer
* [Lexical Analysis](https://en.wikipedia.org/wiki/Lexical_analysis)

### more
* [Notion with tons of materials](https://www.notion.so/Minishell-Materials-7bbd45a806e04395ab578ca3f805806c)

## libft_functions
<details>
  <summary>Click to expand </summary>

### Part_1

**ctype.h** 

| Function | Description |
| --- | --- |
| [**ft\_isalpha**](https://github.com/paulahemsi/libft/blob/main/ft_isalpha.c) |checks for an alphabetic character.|
| [**ft\_isdigit**](https://github.com/paulahemsi/libft/blob/main/ft_isdigit.c) | checks for a digit (0 through 9).|
| [**ft\_isalnum**](https://github.com/paulahemsi/libft/blob/main/ft_isalnum.c) | checks for an alphanumeric character; it  is  equivalent  to (isalpha(c) || isdigit(c)).|
| [**ft\_isascii**](https://github.com/paulahemsi/libft/blob/main/ft_isascii.c) | checks  whether  c  is a 7-bit unsigned char value that fits into the ASCII character set. |
| [**ft\_isprint**](https://github.com/paulahemsi/libft/blob/main/ft_isprint.c) | checks for any printable character including space.|
| [**ft\_isupper**](https://github.com/paulahemsi/libft/blob/main/ft_isupper.c) | checks if character is uppercase.|
| [**ft\_toupper**](https://github.com/paulahemsi/libft/blob/main/ft_toupper.c) | convert lowercase letters to uppercase|
| [**ft\_tolower**](https://github.com/paulahemsi/libft/blob/main/ft_tolower.c) | convert uppercase letters to lowercase. |

**string.h**

| Function | Description |
| --- | --- |
| [**ft\_memset**](https://github.com/paulahemsi/libft/blob/main/ft_memset.c) | fills the first n bytes of the memory area pointed to by s with the constant byte c|
| [**ft\_bzero**](https://github.com/paulahemsi/libft/blob/main/ft_bzero.c) | erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.|
| [**ft\_memcpy**](https://github.com/paulahemsi/libft/blob/main/ft_memcpy.c) | copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use  memmove(3)  if the memory areas do overlap.
| [**ft\_memccpy**](https://github.com/paulahemsi/libft/blob/main/ft_memccpy.c) | copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found. If the memory areas overlap, the results are undefined.|
| [**ft\_memmove**](https://github.com/paulahemsi/libft/blob/main/ft_memmove.c) | copies n bytes from memory area src to memory area dest. The two strings may overlap; the copy is always done in a non-destructive manner.|
| [**ft\_memchr**](https://github.com/paulahemsi/libft/blob/main/ft_memchr.c) |scans the initial n bytes of the memory area pointed to by s for the first instance of c.|
| [**ft\_memcmp**](https://github.com/paulahemsi/libft/blob/main/ft_memcmp.c) | function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|
| [**ft\_strlen**](https://github.com/paulahemsi/libft/blob/main/ft_strlen.c) | The ft\_strlen() function computes and returns the length of the string s.|
| [**ft\_strlcpy**](https://github.com/paulahemsi/libft/blob/main/ft_strlcpy.c) | copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.|
| [**ft\_strlcat**](https://github.com/paulahemsi/libft/blob/main/ft_strlcat.c) |  appends the NUL-terminated string src to the end of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.|
| [**ft\_strchr**](https://github.com/paulahemsi/libft/blob/main/ft_strchr.c) | returns a pointer to the first occurrence of the character c in the string s.|
| [**ft\_strrchr**](https://github.com/paulahemsi/libft/blob/main/ft_strrchr.c) | returns a pointer to the last occurrence  of the character c in the string s.|
| [**ft\_strnstr**](https://github.com/paulahemsi/libft/blob/main/ft_strnstr.c) | locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.|
| [**ft\_strncmp**](https://github.com/paulahemsi/libft/blob/main/ft_strncmp.c) | lexicographically compares the null-terminated strings s1 and s2. Returns an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2. Compares not more than n characters. The comparison is done using unsigned characters, so that '\200' is greater than '\0'.|
| [**ft\_strdup**](https://github.com/paulahemsi/libft/blob/main/ft_strdup.c) | returns a pointer to a new string which is a duplicate  of  the string s.|

**stdlib.h**  

| Function | Description |
| --- | --- |
| [**ft\_atoi**](https://github.com/paulahemsi/libft/blob/main/ft_atoi.c) | converts the initial portion of the string pointed to by str to int representation and returns the int. |
| [**ft\_calloc**](https://github.com/paulahemsi/libft/blob/main/ft_calloc.c) |  allocates memory for an array of  nmemb  elements  of  size  bytes  each and returns a pointer to the allocated memory. The memory is set to zero.|

### Part_2

**string's functions**

| Function | Description |
| --- | --- |
| [**ft\_substr**](https://github.com/paulahemsi/libft/blob/main/ft_substr.c) | Allocates and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.|
| [**ft\_strjoin**](https://github.com/paulahemsi/libft/blob/main/ft_strjoin.c) | Allocates and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|
| [**ft\_strtrim**](https://github.com/paulahemsi/libft/blob/main/ft_strtrim.c) | Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|
| [**ft\_split**](https://github.com/paulahemsi/libft/blob/main/ft_split.c) | Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.|
| [**ft\_strmapi**](https://github.com/paulahemsi/libft/blob/main/ft_strmapi.c) | Applies the function ’f’ to each character of the string ’s’ to create a new string resulting from successive applications of ’f’.|

**string to int**

| Function | Description |
| --- | --- |
| [**ft\_itoa**](https://github.com/paulahemsi/libft/blob/main/ft_itoa.c) | Allocates and returns a string representing the integer received as an argument. Negative numbers must be handled.|

**file-descriptor's functions**

| Function | Description |
| --- | --- |
| [**ft\_putchar\_fd**](https://github.com/paulahemsi/libft/blob/main/ft_putchar_fd.c) | Outputs the character ’c’ to the given file descriptor.|
| [**ft\_putstr\_fd**](https://github.com/paulahemsi/libft/blob/main/ft_putstr_fd.c) | Outputs the string ’s’ to the given file descriptor.|
| [**ft\_putendl\_fd**](https://github.com/paulahemsi/libft/blob/main/ft_putendl_fd.c) | Outputs the string ’s’ to the given file descriptor, followed by a newline.|
| [**ft\_putnbr\_fd**](https://github.com/paulahemsi/libft/blob/main/ft_putnbr_fd.c) | Outputs the integer ’n’ to the given file descriptor.|

### Bonus

**Linked Lists**

| Function | Description |
| --- | --- |
| [**ft\_lstnew**](https://github.com/paulahemsi/libft/blob/main/ft_lstnew.c) | Allocates and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.|
| [**ft\_lstadd_front**](https://github.com/paulahemsi/libft/blob/main/ft_lstadd_front.c) | Adds the element ’new’ at the beginning of the list.|
| [**ft\_lstsize**](https://github.com/paulahemsi/libft/blob/main/ft_lstsize.c) | Counts the number of elements in a list.|
| [**ft\_lstlast**](https://github.com/paulahemsi/libft/blob/main/ft_lstlast.c) | Returns the last element of the list.|
| [**ft\_lstadd_back**](https://github.com/paulahemsi/libft/blob/main/ft_lstadd_back.c) | Adds the element ’new’ at the end of the list.|
| [**ft\_lstdelone**](https://github.com/paulahemsi/libft/blob/main/ft_lstdelone.c) | Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.|
| [**ft\_lstclear**](https://github.com/paulahemsi/libft/blob/main/ft_lstclear.c) | Deletes and frees the given element and every successor of that element, using the function ’del’ and free. Finally, the pointer to the list is set to NULL.|
| [**ft\_lstiter**](https://github.com/paulahemsi/libft/blob/main/ft_lstiter.c) | Iterates the list ’lst’ and applies the function ’f’ to the content of each element.|
| [**ft\_lstmap**](https://github.com/paulahemsi/libft/blob/main/ft_lstmap.c) | Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.|

**Double Linked Lists**

| Function | Description |
| --- | --- |
| [**ft\_dlstnew**](https://github.com/paulahemsi/libft/blob/main/ft_dlstnew.c) | Allocates and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.|
| [**ft\_dlstadd_front**](https://github.com/paulahemsi/libft/blob/main/ft_dlstadd_front.c) | Adds the element ’new’ at the beginning of the double linked list.|
| [**ft\_dlstsize**](https://github.com/paulahemsi/libft/blob/main/ft_dlstsize.c) | Counts the number of elements in a double linked list.|
| [**ft\_dlstlast**](https://github.com/paulahemsi/libft/blob/main/ft_dlstlast.c) | Returns the last element of the double linked list.|
| [**ft\_dlstadd_back**](https://github.com/paulahemsi/libft/blob/main/ft_dlstadd_back.c) | Adds the element ’new’ at the end of the double linked list.|
| [**ft\_dlstdelone**](https://github.com/paulahemsi/libft/blob/main/ft_dlstdelone.c) | Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.|
| [**ft\_dlstclear**](https://github.com/paulahemsi/libft/blob/main/ft_dlstclear.c) | Deletes and frees the given element and every successor of that element, using the function ’del’ and free. Finally, the pointer to the double linked list is set to NULL.|
| [**ft\_dlstiter**](https://github.com/paulahemsi/libft/blob/main/ft_dlstiter.c) | Iterates the double linked list ’lst’ and applies the function ’f’ to the content of each element.|
| [**ft\_dlstmap**](https://github.com/paulahemsi/libft/blob/main/ft_dlstmap.c) | Iterates the double linked list ’lst’ and applies the function ’f’ to the content of each element. Creates a new double linked list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.|

### Extras

| Function | Description |
| --- | --- |
| [**ft\_putchar**](https://github.com/paulahemsi/libft/blob/main/ft_putchar.c) | outputs the character c to the standard output.|
| [**ft\_putstr**](https://github.com/paulahemsi/libft/blob/main/ft_putstr.c) | outputs a string to the standard output.|
| [**ft\_putendl**](https://github.com/paulahemsi/libft/blob/main/ft_putendl.c) | outputs a string to the standard output, followed by a newline.|
| [**ft\_putnbr**](https://github.com/paulahemsi/libft/blob/main/ft_putnbr.c) | outputs the integer n to the standard output|
| [**ft\_strequ**](https://github.com/paulahemsi/libft/blob/main/ft_strequ.c) | lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.|
| [**ft\_strnequ**](https://github.com/paulahemsi/libft/blob/main/ft_strnequ.c) | lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.|
| [**ft\_strclr**](https://github.com/paulahemsi/libft/blob/main/ft_strclr.c) | sets every character of the string s to '\0'.|
| [**ft\_isspace**](https://github.com/paulahemsi/libft/blob/main/ft_isspace.c) | tests for the white-space characters. For any locale, this includes the following standard characters:  `\v`   `\n`   `\t`   `\r`   `\f`. Returns zero if the character tests false and returns non-zero if the character tests true.|
| [**ft\_isblank**](https://github.com/paulahemsi/libft/blob/main/ft_isblank.c) | checks for a blank character; that is, a space or a tab.|
| [**ft\_isxdigit**](https://github.com/paulahemsi/libft/blob/main/ft_isxdigit.c) |  checks for hexadecimal digits. |
| [**ft\_isnegative**](https://github.com/paulahemsi/libft/blob/main/ft_isnegative.c) |  checks if a number is negative. |
| [**ft\_countdigit**](https://github.com/paulahemsi/libft/blob/main/ft_countdigit.c) | Count the digits from an unsigned int.|
| [**ft\_numlen**](https://github.com/paulahemsi/libft/blob/main/ft_numlen.c) | Count the digits from an int.|
| [**get\_next\_line**](https://github.com/paulahemsi/libft/blob/main/get_next_line.c) | Read a line from stdin or fd|
| [**get\_next\_line\_multifd**](https://github.com/paulahemsi/libft/blob/main/get_next_line_multfd.c) | Read a line from multiples fd's|
| [**ft\_add**](https://github.com/paulahemsi/libft/blob/main/ft_add.c) | variadic function which returns the sum of the numbers passed as arguments. The first argument must be the amount of numbers to be summed.|
| [**ft\_itoa_hex**](https://github.com/paulahemsi/libft/blob/main/ft_itoa_hex.c) | Convert the decimal unsigned integer received as argument to hexadecimal. Allocates and returns a string with the hex number.|
| [**ft\_putnbr\_unsigned**](https://github.com/paulahemsi/libft/blob/main/ft_putnbr_unsigned.c) | outputs the unsigned integer n to the standard output.|
| [**ft\_free\_and\_null**](https://github.com/paulahemsi/libft/blob/main/ft_free_and_null.c) | frees and null the given pointer.|

</details>

:shell:

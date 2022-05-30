# Libft
## It is a library with implementation of the most popular basic functions
### Memory
- ft_calloc - allocates the requested memory and returns a pointer to it
- ft_bzero - erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros bytes containing '\0') to that area
- ft_memccpy - copies characters from the object pointed to by src to the object pointed to by dest
- ft_memchr - searches within the first num bytes of the block of memory pointed by ptr for the first occurrence of value, and returns a pointer to it.
- ft_memcmp - compares the first n bytes of memory area str1 and memory area str2
- ft_memcpy - copies n characters from memory area src to memory area dest
- ft_memmove - copies n characters from str2 to str1
- ft_memset - copies the character c to the first n characters of the string pointed to, by the argument str
### Linked list
- ft_lstadd_back - add new element at the end of linked list using recursive method
- ft_lstadd_front - add new element at the start of linked list
- ft_lstclear - freeing memory from the linked list using recursive method
- ft_lstdelone - freeing memory from single element of the linked list and deleting it from linked list
- ft_lstiter - applying provided function to each element of the linked list
- ft_lstlast - returning the pointer to the last element of the linked list
- ft_lstmap - iterate whole linked list, applying to each element provided function, reseiving updated element and create new updated linked list
- ft_lstnew - malloc the memory for linked list element
- ft_lstsize - returning the count of linked list elements in recursive method
### Strings
- ft_split - split str by provided char
- ft_strchr - check does str contain the provided char, return the pointer or null pointer
- ft_strdup - copy str for new place int the memory
- ft_strjoin - concat two strings
- ft_strlcat - concat two strings adding null terminator at the end
- ft_strlcpy - copy string with adding null terminator at the end
- ft_strlen - copy str for new place in the memory
- ft_strmapi - create string by reciving each element from provided function, adding at the end null terminator
- ft_strncmp - compare characters of two strings 
- ft_strnstr - locates the first occurrence of the null-terminated string little in the null-terminated string big
- ft_strrchr - searches for the last occurrence of the character c
- ft_strtrim - removes all whitespace characters from the beginning and the end of a string
- ft_substr - copy string by provided lenght adding null terminator at the end
### ASCII
- ft_atoi - converts the string argument str to an integer (type int)
- ft_isalnum - checks whether the argument passed is an alphanumeric character (alphabet or number) or not
- ft_isalpha - checks whether a character is an alphabet (a to z and A-Z) or not
- ft_isascii - returns non-zero digit if passed value is ascii character otherwise zero
- ft_isdigit - if the passed character is a decimal digit character.
- ft_isprint - checks whether a character is a printable character or not
- ft_itoa - converts an integer value to a null-terminated string
- ft_tolower - takes an uppercase alphabet and convert it to a lowercase character
- ft_toupper - takes an lowercase alphabet and convert it to a uppercase character
### Write to file
- ft_putchar_fd - write single char into opened file description
- ft_putendl_fd - write string with \n symbol at the end into opened description
- ft_putnbr_fd - write int number into opened file description in a recursive method
- ft_putstr_fd - write string into opened file description
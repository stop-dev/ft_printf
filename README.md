# ft_printf
ft_printf is a training project that was implemented at 42 (Moscow campus).<br />

There is a library that contains ft_printf(), a function that mimics the original C printf().<br />
- Implemented types: c, s, p, d, i, u, x, X, %<br />
- Implemented options: -, 0, ., *

## Usage
Create library: ``make``<br />
Remove \*.o files: ``make clean``<br />
Remove \*.o and \*.a files: ``make fclean``

### Compilation
Create ``main.c`` file and compile:
```bash
gcc main.c libftprintf.a
```
### Execution
```bash
./a.out
```
### Main example:
```c
#include "ft_printf.h"

int main()
{
      ft_printf("Hello, World!");
      return (0);
}
```
Output:
```
Hello, World!
```
## Additional information
**_42_** is a computer programming school that is entirely free and available to students who are 18-years or older. Its teaching methods are based on peer learning: no teachers, no lectures, fully hands on. The education model focuses on project-based learning and teamwork, rather than theoretical education. There are a lot of campuses all over the world in the 42 NETWORK.

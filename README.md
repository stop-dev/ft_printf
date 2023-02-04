# ft_printf
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

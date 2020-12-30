# txtfmt.h

A simple header file with various Linux-compatible C text formatting
macros. The provided macros are:

* `fg(color, string)`: Renders the text with the given foreground color.
* `bg(color, string)`: Renders the text with the given background color.
* `fg_b(color, string)`: Same as `fg()`, but uses bright versions of
  default colors.
* `bg_b(color, string)`: Same as `bg()`, but uses bright versions of
  default colors.
* `bold(string)`: Renders the string in bold.
* `underline(string)`: Renders the string underlined.
* `reverse_video(string)`: Renders the string, with the foreground and
  background colors swapped.

See the provided test file (`test.c`) for precise examples of usage.

## Color selection

txtfmt.h provides eight standard colors to work with, each of which is
denoted using a lowercase word: `black`, `red`, `green`, `brown`, `blue`,
`magenta`, `cyan`, and `white`. Because of the way the macros are set up,
these special symbols can _only_ be used in the `color` argument to `fg`,
`bg`, `fg_b`, and `bg_b`; they will not conflict with other variable or
function names.

## Non-constant strings

Since the formatting functions are implemented as macros, they throw
compiler errors when operating on non-constant strings. So, for
example, the following code won't work:

```c
const char *foo = "abcd";
puts(fg(green, foo));
```

Instead, you should use `printf` or `sprintf` to substitute the text into
a format string appropriately. The previous example thus becomes:

```c
const char *foo = "abcd";
printf(fg(green, "%s"), foo);
```

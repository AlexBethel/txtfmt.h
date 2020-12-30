/* Test and demonstration code for txtfmt.h. */
/* Copyright (c) 2020 by Alexander Bethel. */

/* This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <stdio.h>
#include "txtfmt.h"

int main(int argc, char **argv)
{
  /* Individual colors in foreground and background, dark and light
   * versions. */
#define test_color(color) \
  printf(#color "\t\t" \
         fg(color, "*** ") \
         bg(color, "***") \
         fg(color, " dark ") \
         fg_b(color, "light") \
         "\n");
  test_color(black);
  test_color(red);
  test_color(green);
  test_color(brown);
  test_color(blue);
  test_color(magenta);
  test_color(cyan);

  /* Combining foreground and background colors. */
  printf(fg(green, bg(red, "Merry Christmas")) ", ");

  /* Underlining text. */
  printf(underline("and") " ");

  /* Bold text. */
  printf(bold("a") " ");

  /* Reverse video text. */
  printf(reverse_video("happy") " ");

  /* Combining reverse video with foreground and background. (This
   * makes bright background colors possible on Linux.) */
  printf(reverse_video(fg_b(blue, "new year")));
  printf("!\n");

  return 0;
}

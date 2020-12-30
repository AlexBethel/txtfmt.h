# Makefile for the txtfmt.h test program.
# Copyright (c) 2020 by Alexander Bethel.

#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.

#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#  General Public License for more details.

#  You should have received a copy of the GNU General Public License
#  along with this program. If not, see <https://www.gnu.org/licenses/>.

CC=gcc
CFLAGS=-g -Wall
OBJFLAGS=$(CFLAGS) -c
LIBS=

OBJFILES=test.o
HEADERS=txtfmt.h

# Testing program (default action).
prog: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBS) -o $@

# Object files.
%.o: %.c $(HEADERS)
	$(CC) $(OBJFLAGS) $< -o $@

# Run the testing program.
test: prog
	./$<

# Cleanup.
clean:
	$(RM) prog $(OBJFILES)

.PHONY: clean test

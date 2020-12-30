/* txtfmt.h */
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

#ifndef TXTFMT_H
#define TXTFMT_H

/* ---- Basic primitive strings ---- */

/* Control sequence introducer. */
#define FMT_CSI "\e["

/* Set display attributes. See console_codes(4), section "ECMA-48 Set
 * Graphics Rendition" for documentation. */
#define FMT_ATTR(param) FMT_CSI param "m"

/* ---- Color names ---- */
#define FMTCOL_black "0"
#define FMTCOL_red "1"
#define FMTCOL_green "2"
#define FMTCOL_brown "3"
#define FMTCOL_blue "4"
#define FMTCOL_magenta "5"
#define FMTCOL_cyan "6"
#define FMTCOL_white "7"

/* ---- Commands ---- */

/* Set foreground and background colors using format attributes. */
#define fg(col, txt) \
  FMT_ATTR("3" FMTCOL_##col) txt FMT_ATTR("39")
#define bg(col, txt) \
  FMT_ATTR("4" FMTCOL_##col) txt FMT_ATTR("49")

/* Bright versions of above. */
#define fg_b(col, txt) \
  FMT_ATTR("9" FMTCOL_##col) txt FMT_ATTR("39")
#define bg_b(col, txt) \
  FMT_ATTR("10" FMTCOL_##col) txt FMT_ATTR("49")

/* Bold text. */
#define bold(txt) \
  FMT_ATTR("1") txt FMT_ATTR("22")

/* Underline text. */
#define underline(txt) \
  FMT_ATTR("4") txt FMT_ATTR("24")

/* Reverse video text (i.e., foreground and background swapped). */
#define reverse_video(txt) \
  FMT_ATTR("7") txt FMT_ATTR("27")

#endif /* TXTFMT_H */

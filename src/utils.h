/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Main functions of the program.
 *
 * Copyright (C) 2007 David Härdeman <david@hardeman.nu>
 * Copyright (C) 2018 Przemyslaw Pawelczyk <przemoc@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; only version 2 of the License is applicable.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILS_H
#define UTILS_H

/* For uint64_t */
#include <stdint.h>
/* For ssize_t */
#include <unistd.h>
/* For FILE */
#include <stdio.h>
/* For struct passwd */
#include <pwd.h>
/* For struct group */
#include <grp.h>

/* Character separating the single entries */
#define SEPARATOR ((char)';')

/* Adjusts the verbosity level for msg() */
void adjust_verbosity(int adj);

/* Verbosity levels using stdout */
#define MSG_NORMAL    0
#define MSG_DEBUG     1
#define MSG_QUIET    -1
/* Verbosity levels using stderr */
#define MSG_WARNING  -2
#define MSG_ERROR    -3
#define MSG_CRITICAL -4

/* Prints messages to console according to the current verbosity */
int msg(int level, const char *fmt, ...);

/* Malloc which either succeeds or exits */
void *xmalloc(size_t size);

/* Ditto for strdup */
char *xstrdup(const char *s);

/* Human-readable printout of binary data */
void binary_print(const char *s, ssize_t len);

/* Writes data to a file or exits on failure */
void xfwrite(const void *ptr, size_t size, FILE *stream);

/* Writes an int to a file, using len bytes, in bigendian order, with separator */
void write_int(uint64_t value, FILE *to);

/* Writes a binary string to a file */
void write_binary_string(const char *string, size_t len, FILE *to);

/* Writes a normal C string to a file including a separator */
void write_string(const char *string, FILE *to);

/* Reads an int from a file, using len bytes, in bigendian order, with separator */
uint64_t read_int(char **from, const char *max);

/* Reads a binary string from a file */
char *read_binary_string(char **from, size_t len, const char *max);

/* Reads a normal C string from a file and takes care of the separator*/
char *read_string(char **from, const char *max);

/* Caching version of getgrnam */
struct group *xgetgrnam(const char *name);

/* Caching version of getgrgid */
struct group *xgetgrgid(gid_t gid);

/* Caching version of getpwnam */
struct passwd *xgetpwnam(const char *name);

/* Caching version of getpwuid */
struct passwd *xgetpwuid(uid_t uid);

#endif /* UTILS_H */

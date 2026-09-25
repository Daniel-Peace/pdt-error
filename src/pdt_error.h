/**
 * =========================================================
 * Copyright (c) 2026 Daniel Peace
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 * =========================================================
 */

#ifndef PDT_ERROR_DEFINITION
#define PDT_ERROR_DEFINITION

#include <pdt_string.h>
#include <pdt_boolean.h>

/**
 * An enum representing the currently supported error types.
 */
typedef enum
{
  PDT_OK    = 0,
  PDT_ERROR = 1,
} PDT_Error_Type;

/**
 * A struct representing a possible error. Contains not only
 * the error code of the error, but also a description of
 * the error.
 */
typedef struct
{
    PDT_Error_Type  type;
    PDT_String      description;
} PDT_Error;

/**
 * Checks if the given "PDT_Error" is an error or not. If
 * the given "PDT_Error" is an error or is `NULL` "PDT_True"
 * is returned, otherwise "PDT_False" is returned.
 */
PDT_Boolean isError(PDT_Error* error);

#endif

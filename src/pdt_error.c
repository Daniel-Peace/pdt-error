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

#include "pdt_error.h"
#include <pdt_string.h>

PDT_Boolean PDT_Error_isError(PDT_Error error)
{
    return error.type ? PDT_TRUE : PDT_FALSE;
}

PDT_Error PDT_Error_create(PDT_Error_Type type)
{
    PDT_Error error;

    error.type = type;

    switch (type)
    {
        case PDT_OK:
            PDT_String_createFromNullTerminated(PDT_ERROR_OK_DEFAULT_MESSAGE, &(error.description));
            break;

        case PDT_ERROR:
            PDT_String_createFromNullTerminated(PDT_ERROR_ERROR_DEFAULT_MESSAGE, &(error.description));
            break;
    }

    return error;
}

PDT_Error PDT_Error_createWithCustomMsg(PDT_Error_Type type, PDT_String description)
{
    PDT_Error error;

    error.type = type;

    error.description = description;

    return error;
}

PDT_Error PDT_Error_createWithCustomMsgUnsafe(PDT_Error_Type type, const char* description)
{
    PDT_Error error;

    error.type = type;

    if (description == 0)
    {
        const char* defaultDescription;

        switch (type)
        {
            case PDT_OK:
                defaultDescription = PDT_ERROR_OK_DEFAULT_MESSAGE;
                break;

            case PDT_ERROR:
                defaultDescription = PDT_ERROR_ERROR_DEFAULT_MESSAGE;
                break;
        }

        PDT_String_createFromNullTerminated(defaultDescription, &(error.description));
    } else
    {
        PDT_String_createFromNullTerminated(description, &(error.description));
    }

    return error;
}

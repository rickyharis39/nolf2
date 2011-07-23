/*
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

# ifndef __STL_OUTERMOST_HEADER_ID
#  define __STL_OUTERMOST_HEADER_ID 0x269
#  include <stl/_prolog.h>
# endif

#   include __STL_NATIVE_C_HEADER(string.h)

# if defined (__BORLANDC__) && defined (__STL_IMPORT_VENDOR_CSTD)
#  include <using/cstring>
# endif /* BORLAND */

# if (__STL_OUTERMOST_HEADER_ID == 0x269)
#  include <stl/_epilog.h>
#  undef __STL_OUTERMOST_HEADER_ID
# endif

// Local Variables:
// mode:C++
// End:


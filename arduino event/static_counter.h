/*
 * satic_counter.h
 *
 * Created: 2016-09-12 00:20:17
 *  Author: Jonatan
 */ 

#include "Arduino.h"

#ifndef SATIC_COUNTER_H_
#define SATIC_COUNTER_H_


template< size_t n > // This type returns a number through function lookup.
struct cn // The function returns cn<n>.
    { char data[ n + 1 ]; }; // The caller uses (sizeof fn() - 1).

template< typename id, size_t n, size_t acc >
cn< acc > seen( id, cn< n >, cn< acc > ); // Default fallback case.

/* Evaluate the counter by finding the last defined overload.
   Each function, when defined, alters the lookup sequence for lower-order
   functions. */
#define counter_read( id ) \
( sizeof seen( id(), cn< 1 >(), cn< \
( sizeof seen( id(), cn< 2 >(), cn< \
( sizeof seen( id(), cn< 4 >(), cn< \
( sizeof seen( id(), cn< 8 >(), cn< \
( sizeof seen( id(), cn< 16 >(), cn< \
( sizeof seen( id(), cn< 32 >(), cn< 0 \
/* Add more as desired; trimmed for Stack Overflow code block. */ \
                      >() ).data - 1 ) \
                      >() ).data - 1 ) \
                      >() ).data - 1 ) \
                      >() ).data - 1 ) \
                      >() ).data - 1 ) \
                      >() ).data - 1 )

/* Define a single new function with place-value equal to the bit flipped to 1
   by the increment operation.
   This is the lowest-magnitude function yet undefined in the current context
   of defined higher-magnitude functions. */
#define counter_inc( id ) \
cn< counter_read( id ) + 1 > \
seen( id, cn< ( counter_read( id ) + 1 ) & ~ counter_read( id ) >, \
          cn< ( counter_read( id ) + 1 ) & counter_read( id ) > )


#endif /* SATIC_COUNTER_H_ */
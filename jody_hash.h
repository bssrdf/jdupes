/* Jody Bruchon's fast hashing function (headers)
 * See jody_hash.c for license information */

#ifndef JODY_HASH_H
#define JODY_HASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Required for uint64_t */
#include <stdint.h>

/* Width of a jody_hash. Changing this will also require
 * changing the width of tail masks to match. */
#ifndef JODY_HASH_WIDTH
#define JODY_HASH_WIDTH 64
#endif

#if JODY_HASH_WIDTH == 64
typedef uint64_t jodyhash_t;
#endif
#if JODY_HASH_WIDTH == 32
typedef uint32_t jodyhash_t;
#endif
#if JODY_HASH_WIDTH == 16
typedef uint16_t jodyhash_t;
#endif

#ifndef JODY_HASH_NOCOMPAT
typedef jodyhash_t hash_t;
#endif

/* Version increments when algorithm changes incompatibly */
#define JODY_HASH_VERSION 5

extern jodyhash_t jody_block_hash(const jodyhash_t * restrict data,
		const jodyhash_t start_hash, const size_t count);

#ifdef __cplusplus
}
#endif

#endif	/* JODY_HASH_H */

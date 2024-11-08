// The MIT License (MIT)
// 
// Copyright (c) 2022 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#include <stddef.h>

#define ALIGN4(s)  (((((s) - 1) >> 2) << 2) + 4)

enum ALGORITHM
{
  NEXT_FIT = 0,
  BEST_FIT,
  WORST_FIT,
  FIRST_FIT
}; 

/**
 * @brief Initialize the allocation arena and set the algorithm type
 *
 * This function takes the provided size and calls malloc to allocate a 
 * memory arena. The size must be aligned to a word boundary.
 * 
 * If the allocation succeeds it returns 0. If the allocation fails or the 
 * size is less than 0 the function returns -1
 *
 * \param size The size of the pool to allocate in bytes
 * \param algorithm The heap algorithm to implement
 * \return 0 on success. -1 on failure
 **/
int memalloc_init( size_t size, enum ALGORITHM algorithm );


/**
 * @brief Destroy the arena 
 *
 * This function releases the arena
 *
 * \return None 
 **/
void memalloc_destroy( );


/**
 * @brief Allocate memory from the arena 
 *
 * This function allocated memory from the arena.  The parameter size 
 * specifies the number of bytes to allocates.  This _must_ be 4 byte aligned using the 
 * ALIGN4 macro. 
 * 
 * The function searches the arena for a free block using the heap allocation algorithm 
 * specified when the arena was allocated.
 *
 * If there is no available block of memory the function returns NULL
 *
 * \return A pointer to the available memory or NULL if no free block is found 
 **/
void * memalloc_alloc( size_t size );


/*
 * \brief free the pointer
 *
 * frees the memory block pointed to by pointer. if the block is adjacent
 * to another block then coalesce (combine) them
 *
 * \param ptr the heap memory to free
 *
 * \return none
 */
void memalloc_free(void *ptr);

/*
 * \brief Allocator size
 *
 * Return the number of nodes in the allocators linked list 
 *
 * \return The size of the allocator linked list 
 */
int memalloc_size( );


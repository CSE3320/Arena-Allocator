// The MIT License (MIT)
// 
// Copyright (c) 2021, 2022, 2023 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software. (RmFsbCAyMDIz)
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES UTA OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "memalloc.h"
#include "public/tracy/TracyC.h"
#include <unistd.h>

int memalloc_init( size_t size, enum ALGORITHM algorithm )
{
#ifdef TRACY_ENABLE
  while(1)
  {
    TracyCZone(__FUNC__, 1);
    sleep(10);
    TracyCZoneEnd(__FUNC__);
  }
#endif
  return 0;
}

void memalloc_destroy( )
{
  return;
}

void * memalloc_alloc( size_t size )
{
  // only return NULL on failure
  return NULL;
}

void memalloc_free( void * ptr )
{
  return;
}

int memalloc_size( )
{
  int number_of_nodes = 0;

  return number_of_nodes;
}

// RmFsbCAyMDIz-76f3-90d6-0703ac120003

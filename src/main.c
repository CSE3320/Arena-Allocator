#include "memalloc.h"
#include "tinytest.h"
#include <stdio.h>
#include <string.h>
/*
*
* TEST CASE 1: Test init and a single allocation
*
*/
int test_case_1()
{
  memalloc_init( 65535, BEST_FIT );
  char * ptr = ( char * ) memalloc_alloc ( 65535 );

  int size = memalloc_size();

  // If you failed here your allocation on line 13 failed
  TINYTEST_ASSERT( ptr ); 

  // If you failed here your linked list did not have a single node
  // check your memalloc_alloc or memalloc_size
  TINYTEST_EQUAL( size, 1); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 2: Test Coalescing Free Blocks 
*
* This test case tests combining free block when the
* second free block is freed second 
*
*/
int test_case_2()
{
  memalloc_init( 128000, BEST_FIT );

  char * ptr1    = (char*)memalloc_alloc( 65535 );
  char * ptr2    = (char*)memalloc_alloc( 65 );

  // If you failed here your allocation on line 39 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here your allocation on line 40 failed
  TINYTEST_ASSERT( ptr2 ); 

  memalloc_free( ptr1 );
  memalloc_free( ptr2 );

  int size = memalloc_size();

  // If you failed here your linked list did not have a single node
  // check your memalloc_alloc or memalloc_size and make sure you
  // are combining adjacent free nodes and counting your link list
  // correctly

  TINYTEST_EQUAL( size, 1 ); 

  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 3: Test Coalescing Free Blocks 
*
* This test case tests combining free block when the
* second free block is freed first 
*
*/
int test_case_3()
{
  memalloc_init( 65600, BEST_FIT );

  char * ptr1    = (char*)memalloc_alloc( 65536 );
  char * ptr2    = (char*)memalloc_alloc( 64 );

  // If you failed here your allocation on line 76 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here your allocation on line 77 failed
  TINYTEST_ASSERT( ptr2 ); 

  memalloc_free( ptr2 );
  memalloc_free( ptr1 );

  int size = memalloc_size();

  // If you failed here your linked list did not have a single node
  // check your memalloc_alloc or memalloc_size and make sure you
  // are combining adjacent free nodes and counting your link list
  // correctly

  TINYTEST_EQUAL( size, 1 ); 

  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 4: Test First Fit and splitting free blocks
*
*/
int test_case_4()
{
  memalloc_init( 65535, FIRST_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  int size = memalloc_size();

  // If you failed here your allocation on line 110 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here your allocation on line 111 failed
  TINYTEST_ASSERT( ptr2 ); 

  // If you failed here your linked list did not have three nodes
  // check your memalloc_alloc or memalloc_size and make sure you
  // are allocating and splitting nodes and counting your link list
  // correctly

  TINYTEST_EQUAL( size, 3); 
  memalloc_destroy( );
  return 1;
}


/*
*
* TEST CASE 5: Test Next 
*
*/
int test_case_5()
{
  memalloc_init( 4144, NEXT_FIT );

  char * ptr1 = ( char * ) memalloc_alloc ( 1024 );
  char * buf1 = ( char * ) memalloc_alloc ( 4 );
  char * ptr6 = ( char * ) memalloc_alloc ( 16 );
  char * buf2 = ( char * ) memalloc_alloc ( 4 );
  char * ptr2 = ( char * ) memalloc_alloc ( 2048 );
  char * buf3 = ( char * ) memalloc_alloc ( 4 );
  char * ptr7 = ( char * ) memalloc_alloc ( 16 );
  char * buf4 = ( char * ) memalloc_alloc ( 4 );
  char * ptr3 = ( char * ) memalloc_alloc ( 1024 );

  // If you failed here your allocation on line 141 failed
  TINYTEST_ASSERT( ptr1 ); 
  
  // If you failed here your allocation on line 145 failed
  TINYTEST_ASSERT( ptr2 ); 
  
  // If you failed here your allocation on line 149 failed
  TINYTEST_ASSERT( ptr3 ); 
  
  // If you failed here your allocation on line 143 failed
  TINYTEST_ASSERT( ptr6 ); 
  
  // If you failed here your allocation on line 147 failed
  TINYTEST_ASSERT( ptr7 ); 

  memalloc_free( ptr1 ); 
  memalloc_free( ptr2 ); 
  memalloc_free( ptr3 ); 

  char * ptr5 = ( char * ) memalloc_alloc ( 2000 );

  // If you failed here your allocation on line 170 failed
  TINYTEST_ASSERT( ptr5 ); 

  ptr5 = ptr5;
  ptr7 = ptr7;
  ptr6 = ptr6;
  buf1 = buf1;
  buf2 = buf2;
  buf3 = buf3;
  buf4 = buf4;

  char * ptr4 = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here your allocation on line 183 failed
  TINYTEST_ASSERT( ptr4 ); 

  // If you failed here your allocation on line 149 failed
  TINYTEST_ASSERT( ptr3 ); 

  // If you failed here your Next Fit algorithm is not choosing
  // the correct hole 
  TINYTEST_EQUAL( ptr3, ptr4 ); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 6: Test Worst Fit 
*
*/
int test_case_6()
{
  memalloc_init( 71608, WORST_FIT );
  char * ptr1    = ( char * ) memalloc_alloc ( 65535 );
  char * buffer1 = ( char * ) memalloc_alloc( 4 );
  char * ptr4    = ( char * ) memalloc_alloc ( 64 );
  char * buffer2 = ( char * ) memalloc_alloc( 4 );
  char * ptr2    = ( char * ) memalloc_alloc ( 6000 );

  // If you failed here your allocation on line 206 failed
  TINYTEST_ASSERT( ptr1 ); 
  
  // If you failed here your allocation on line 210 failed
  TINYTEST_ASSERT( ptr2 ); 
  
  // If you failed here your allocation on line 208 failed
  TINYTEST_ASSERT( ptr4 ); 

  memalloc_free( ptr1 ); 
  memalloc_free( ptr2 ); 

  buffer1 = buffer1;
  buffer2 = buffer2;
  ptr4 = ptr4;

  char * ptr3 = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here then your worst fit picked the wrong node on line 228
  TINYTEST_EQUAL( ptr1, ptr3 ); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 7: Test Best Fit 
*
*/
int test_case_7()
{
  memalloc_init( 75000, BEST_FIT );
  char * ptr1    = ( char * ) memalloc_alloc ( 65535 );
  char * buffer1 = ( char * ) memalloc_alloc( 1 );
  char * ptr4    = ( char * ) memalloc_alloc ( 65 );
  char * buffer2 = ( char * ) memalloc_alloc( 1 );
  char * ptr2    = ( char * ) memalloc_alloc ( 1500 );

  // If you failed here your allocation on line 244 failed
  TINYTEST_ASSERT( ptr1 ); 
  
  // If you failed here your allocation on line 248 failed
  TINYTEST_ASSERT( ptr2 ); 
  
  // If you failed here your allocation on line 246 failed
  TINYTEST_ASSERT( ptr4 ); 

  memalloc_free( ptr1 ); 
  memalloc_free( ptr2 ); 

  buffer1 = buffer1;
  buffer2 = buffer2;
  ptr4 = ptr4;

  char * ptr3 = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here your allocation on line 266 failed
  TINYTEST_ASSERT( ptr3 ); 

  // If you failed here your allocation on 266 picked the wrong node for Best Fit
  TINYTEST_EQUAL( ptr2, ptr3 ); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 8: Test allocating more than we should 
*
*/
int test_case_8()
{
  memalloc_init( 255, BEST_FIT );
  char * ptr = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here your Best Fit allocation line 285 didn't return NULL like 
  // it should have
  TINYTEST_EQUAL( ptr, NULL ); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 9: Test allocating more than we should 
*
*/
int test_case_9()
{
  memalloc_init( 255, FIRST_FIT );
  char * ptr = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here your First Fit allocation on line 302 didn't return NULL like 
  // it should have
  TINYTEST_EQUAL( ptr, NULL ); 

  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 10: Test allocating more than we should 
*
*/
int test_case_10()
{
  memalloc_init( 255, WORST_FIT );
  char * ptr = ( char * ) memalloc_alloc ( 1000 );

  // If you failed here your Worst Fit allocation on line 320 didn't return NULL like 
  // it should have
  TINYTEST_EQUAL( ptr, NULL ); 

  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 11: Test Next Fit and splitting free blocks
*
*/
int test_case_11()
{
  memalloc_init( 4144, NEXT_FIT );

  char * ptr1 = ( char * ) memalloc_alloc ( 1024 );
  char * buf1 = ( char * ) memalloc_alloc ( 4 );
  char * ptr6 = ( char * ) memalloc_alloc ( 16 );
  char * buf2 = ( char * ) memalloc_alloc ( 4 );
  char * ptr2 = ( char * ) memalloc_alloc ( 2048 );
  char * buf3 = ( char * ) memalloc_alloc ( 4 );
  char * ptr7 = ( char * ) memalloc_alloc ( 16 );
  char * buf4 = ( char * ) memalloc_alloc ( 4 );
  char * ptr3 = ( char * ) memalloc_alloc ( 1024 );

  // if you failed here your allocation on line 339 failed
  TINYTEST_ASSERT( ptr1 ); 

  // if you failed here your allocation on line 343 failed
  TINYTEST_ASSERT( ptr2 ); 

  // if you failed here your allocation on line 347 failed
  TINYTEST_ASSERT( ptr3 ); 

  // if you failed here your allocation on line 341 failed
  TINYTEST_ASSERT( ptr6 ); 

  // if you failed here your allocation on line 345 failed
  TINYTEST_ASSERT( ptr7 ); 

  memalloc_free( ptr1 ); 
  memalloc_free( ptr2 ); 
  memalloc_free( ptr3 ); 

  char * ptr5 = ( char * ) memalloc_alloc ( 2000 );

  // if you failed here your allocation on line 368 failed
  TINYTEST_ASSERT( ptr5 ); 

  ptr5 = ptr5;
  ptr7 = ptr7;
  ptr6 = ptr6;
  buf1 = buf1;
  buf2 = buf2;
  buf3 = buf3;
  buf4 = buf4;

  char * ptr4 = ( char * ) memalloc_alloc ( 1000 );

  // if you failed here your allocation on line 383 failed
  TINYTEST_ASSERT( ptr4 ); 

  // if you failed here your allocation on line 347 failed
  TINYTEST_ASSERT( ptr3 ); 

  // If you fail here then your Next Fit algorithm picked the wrong node
  TINYTEST_EQUAL( ptr3, ptr4 ); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 12: Test destroy
*
*/
int test_case_12()
{
  memalloc_init( 65535, BEST_FIT );
  memalloc_destroy( );

  int size = memalloc_size();

  // If you failed here then your destroy did not free
  // your linked list
  TINYTEST_EQUAL( size, 0); 
  return 1;
}

/*
*
* TEST CASE 13: Test Next Fit and splitting free blocks
*
*/
int test_case_13()
{
  memalloc_init( 65535, NEXT_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  // If you failed here then your allocation on line 422 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here then your allocation on line 423 failed
  TINYTEST_ASSERT( ptr2 ); 

  int size = memalloc_size();

  // If you failed here then your next fit is not splitting free blocks
  // correctly
  TINYTEST_EQUAL( size, 3); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 14: Test Best Fit and splitting free blocks
*
*/
int test_case_14()
{
  memalloc_init( 65535, BEST_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  int size = memalloc_size();

  // If you failed here then your allocation on line 448 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here then your allocation on line 449 failed
  TINYTEST_ASSERT( ptr2 ); 

  
  // If you failed here then your best fit is not splitting free blocks
  // correctly
  TINYTEST_EQUAL( size, 3); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 15: Test Worst Fit and splitting free blocks
*
*/
int test_case_15()
{
  memalloc_init( 65535, WORST_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  // If you fail here then your allocation on line 475 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you fail here then your allocation on line 476 failed
  TINYTEST_ASSERT( ptr2 ); 

  int size = memalloc_size();

  // If you failed here then your worst fit is not splitting free blocks
  // correctly
  TINYTEST_EQUAL( size, 3); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 16: Test Worst Fit and using the memory we were given 
*
*/
int test_case_16()
{
  memalloc_init( 65535, WORST_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  // If you fail here then your allocation on line 475 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you fail here then your allocation on line 476 failed
  TINYTEST_ASSERT( ptr2 ); 

  memcpy( ptr2, "THIS IS THE TEST STRING", 23);

  int compare = memcmp( ptr2, "THIS IS THE TEST STRING", 23 );

  TINYTEST_EQUAL( compare, 0); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 17: Test Next Fit and using the memory we were given 
*
*/
int test_case_17()
{
  memalloc_init( 65535, NEXT_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  // If you fail here then your allocation on line 475 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you fail here then your allocation on line 476 failed
  TINYTEST_ASSERT( ptr2 ); 

  memcpy( ptr2, "THIS IS THE TEST STRING", 23);

  int compare = memcmp( ptr2, "THIS IS THE TEST STRING", 23 );

  TINYTEST_EQUAL( compare, 0); 
  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 18: Free then allocate and make sure we re-use the same block 
*
*/
int test_case_18()
{
  memalloc_init( 1536, FIRST_FIT );
  char * ptr1 = ( char * ) memalloc_alloc ( 1024 );
  char * ptr2 = ( char * ) memalloc_alloc ( 256 );

  // If you failed here your allocation on line 558 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you failed here your allocation on line 559 failed
  TINYTEST_ASSERT( ptr2 ); 

  memalloc_free( ptr2 );
  
  char * ptr3 = ( char * ) memalloc_alloc ( 256 );

  // If you failed here your allocation on line 571 failed
  TINYTEST_ASSERT( ptr3 ); 

  // If you fail here then your first fit did not reuse the correct node 
  TINYTEST_EQUAL( ptr2, ptr3 ); 

  memalloc_destroy( );
  return 1;
}

/*
*
* TEST CASE 19: Test if your code safeguards against calling memalloc_alloc 
*               after destroy 
*
*/
int test_case_19()
{
  memalloc_init( 65535, BEST_FIT );
  char * ptr = ( char * ) memalloc_alloc ( 65535 );

  int size = memalloc_size();

  // If you failed here your allocation on line 13 failed
  TINYTEST_ASSERT( ptr ); 

  // If you failed here your linked list did not have a single node
  // check your memalloc_alloc or memalloc_size
  TINYTEST_EQUAL( size, 1); 

  memalloc_destroy( );

  char * ptr2 = ( char * ) memalloc_alloc ( 65535 );

  // You must return NULL on the alloc on line 605 since it occurs
  // after the destroy
  TINYTEST_EQUAL( ptr2, NULL); 

  return 1;
}

/*
*
* TEST CASE 20: Test Next Fit and looping around the end of the linked list 
*
*/
int test_case_20()
{
  memalloc_init( 12000, NEXT_FIT );

  char * ptr1  = ( char * ) memalloc_alloc ( 10000 );
  char * ptr2  = ( char * ) memalloc_alloc ( 65 );

  // If you fail here then your allocation on line 623 failed
  TINYTEST_ASSERT( ptr1 ); 

  // If you fail here then your allocation on line 624 failed
  TINYTEST_ASSERT( ptr2 ); 

  memalloc_free( ptr1 );

  char * ptr3  = ( char * ) memalloc_alloc ( 10000 );

  // Your next fit picked the wrong node if this line fails
  TINYTEST_EQUAL( ptr1, ptr3 ); 
  memalloc_destroy( );
  return 1;
}

int tinytest_setup(const char *pName)
{
    fprintf( stderr, "tinytest_setup(%s)\n", pName);
    return 0;
}



int tinytest_teardown(const char *pName)
{
    fprintf( stderr, "tinytest_teardown(%s)\n", pName);
    return 0;
}


TINYTEST_START_SUITE(MavAllocTestSuite);
  TINYTEST_ADD_TEST(test_case_1,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_2,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_3,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_4,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_5,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_6,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_7,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_8,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_9,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_10,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_11,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_12,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_13,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_14,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_15,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_16,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_17,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_18,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_19,tinytest_setup,tinytest_teardown);
  TINYTEST_ADD_TEST(test_case_20,tinytest_setup,tinytest_teardown);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(MavAllocTestSuite);

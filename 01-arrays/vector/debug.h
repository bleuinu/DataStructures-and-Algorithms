#pragma once 

#if 1
	#define DEBUG
#endif

#ifdef DEBUG
	#define TEST_INIT
#if 1
	#define TEST_INSERT
	#define TEST_IF_EMPTY
	#define TEST_PUSH
	#define TEST_PREPEND

	#define TEST_POP
	#define TEST_DELETE_AT

	#define TEST_FIND
	#define TEST_REMOVE

	#define TEST_RESIZE_DOUBLE
	#define TEST_RESIZE_HALVE
#endif
#endif

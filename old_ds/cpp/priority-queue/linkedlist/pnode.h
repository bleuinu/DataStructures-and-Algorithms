#pragma once

/****************************
 * Date: Feb 2, 2019
 * At  : Copa Vida
 **************************/

/* initial values for data and priority are 0 */
enum {DATA=0, PRIORITY=0};

typedef int Element;

typedef struct PNode
{
	struct PNode *next;
	struct PNode *prev;
	Element data;
	int priority;
} Node;

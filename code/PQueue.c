// Priority Queue ADO implementation ... COMP9024 23T2

#include "PQueue.h"
#include <assert.h>
#include <limits.h>

typedef struct {
   Vertex item[MAX_NODES];  // array of vertices currently in queue
   int    length;           // #values currently stored in item[] array
} PQueueT;

static PQueueT PQueue;      // defines the Priority Queue Object

// set up empty priority queue
void PQueueInit() {
   PQueue.length = 0;
}

// insert vertex v into priority queue
// no effect if v is already in the queue
void joinPQueue(int v) {
   assert(PQueue.length < MAX_NODES);                // ensure queue ADO is not full
   int i = 0;
   while (i < PQueue.length && PQueue.item[i] != v)  // check if v already in queue
      i++;
   if (i == PQueue.length) {                         // v not found => add it at the end
      PQueue.item[PQueue.length] = v;
      PQueue.length++;
   }
}

// remove the highest priority vertex from PQueue
// highest priority = lowest value priority[v]
// returns the removed vertex
Vertex leavePQueue(int priority[]) {
   assert(PQueue.length > 0);

   int i, bestIndex = 0, bestVertex = PQueue.item[0], bestWeight = INT_MAX;
   for (i = 0; i < PQueue.length; i++) {         // find i with min priority[item[i]]
      if (priority[PQueue.item[i]] < bestWeight) {
         bestIndex = i;
         bestWeight = priority[PQueue.item[i]];
	 bestVertex = PQueue.item[i];            // vertex with lowest value so far
      }
   }
   PQueue.length--;
   PQueue.item[bestIndex] = PQueue.item[PQueue.length];  // replace dequeued node
							 // by last element in array
   return bestVertex;
}

// check if priority queue PQueue is empty
bool PQueueIsEmpty() {
   return (PQueue.length == 0);
}
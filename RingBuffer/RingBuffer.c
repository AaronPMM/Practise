#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "RingBuffer.h"

//#define  RING_BUFFER_MAX_SIZE  100


tsRingBuffer *RingBuffer_tsCreateQueue(unsigned int capacity)
{
    tsRingBuffer *queue = (tsRingBuffer *)malloc(sizeof(tsRingBuffer));

    if(queue == NULL)
    {
        printf("malloc fail\n");
        return NULL;
    }
    else
    {
        //初始化
        queue->head = 0;
        queue->tail = -1;
        queue->queueSize = 0;
        queue->capacity = capacity;
        queue->data = (int *)malloc(capacity * sizeof(int));

        return queue;
    }

}

//添加缓冲区
int RingBuffer_iEnqueue(tsRingBuffer *queue, int item)
{
    if(queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }

    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->data[queue->tail] = item;
    queue->queueSize++;
    
    return 1;
}


//取出缓冲区
int RingBuffer_iDequeue(tsRingBuffer *queue)
{
    int iItem;
    if(queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }

    iItem = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->queueSize--;

    return iItem;
}

//检测缓冲区是空还是满
int RingBuffer_bCheckQueueEmptyOrFull(tsRingBuffer *queue)
{
    if(queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }

    if(queue->queueSize == 0)
    {
        printf("queue empty\n");
        return 0;
    }
    else if ( queue->queueSize == queue->capacity)
    {
        printf("queue full\n");
        return 1;
    }
    
}

//检查缓冲区大小
unsigned int RingBuffer_uiGetQueueSize(tsRingBuffer *queue)
{
    if(queue == NULL)
    {
        printf("queue is NULL\n");
        return -1;
    }

    return queue->queueSize;
}

//重置缓冲区
int RingBuffer_iDestoryQueue(tsRingBuffer *queue)
{
    if(queue == NULL)
    {
        printf("queue is NULL\n");
        return 0;
    }

    free(queue->data);
    free(queue);

    return 0;
}

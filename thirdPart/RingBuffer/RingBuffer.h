#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include <stdio.h>

struct RingQueue
{
    unsigned int head;       //环形缓冲区头
    unsigned int tail;       //环形缓冲区尾
    unsigned int queueSize;  //环形缓冲区大小
    unsigned int capacity;   //环形缓冲区容量
    int *data;               //数据
};

typedef struct RingQueue tsRingBuffer;

tsRingBuffer *RingBuffer_tsCreateQueue(unsigned int capacity);
int RingBuffer_iEnqueue(tsRingBuffer *queue, int item);
int RingBuffer_iDequeue(tsRingBuffer *queue);
int RingBuffer_bCheckQueueEmptyOrFull(tsRingBuffer *queue);
unsigned int RingBuffer_uiGetQueueSize(tsRingBuffer *queue);
int RingBuffer_iDestoryQueue(tsRingBuffer *queue);
#endif
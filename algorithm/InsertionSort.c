/******************************************************************************

                  版权所有 (C), 2023-2023，78157

 ******************************************************************************
  文 件 名   : InsertionSort.c
  版 本 号   : 初稿
  作    者   : 78157
  生成日期   : 2023/1/11
  最近修改   :
  功能描述   : 插入算法
  函数列表   :
  修改历史   :
  1.日    期   : 2023/1/11
    作    者   : 78157
    修改内容   : 创建文件

******************************************************************************/

/*----------------------------------------------*
 * 包含头文件                                   *
 *----------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------*
 * 外部变量说明                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 内部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 模块级变量                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 宏定义                                       *
 *----------------------------------------------*/

void print_array(int *array, int length)
{
    int index;
    printf("\r\n");

    for(index = 0; index < length; index++){
        printf("%d ", array[index]);
    }

    printf("\r\n");
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void main(void)
{
    int array[] = {9, 5, 1, 4, 3};
    int array_length;

    array_length = sizeof(array) / sizeof(array[0]);

    insertionSort(array, array_length);
    print_array(array, array_length);
}
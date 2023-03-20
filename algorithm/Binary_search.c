/******************************************************************************

                  版权所有 (C), 2023-2023，78157

 ******************************************************************************
  文 件 名   : Binary_search.c
  版 本 号   : 初稿
  作    者   : 78157
  生成日期   : 2023/1/4
  最近修改   :
  功能描述   : 二分查找法
  函数列表   :
  修改历史   :
  1.日    期   : 2023/1/4
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

int binarySearchWithIterativeMethod(int *data, int find, int min, int max)
{
    int result = -1;
    int mid, min_index, max_index, mid_index;

    min_index = min;
    max_index = max;

    while(min_index < max_index) {
        mid_index = min_index + (max_index - min_index) / 2;
        mid = data[mid_index];

        if (mid == find) {
            return ((max - min) / 2);
        } else if (mid < find) {
            max_index = mid_index - 1;
        } else {
            min_index = mid_index + 1;
        }
    }

    return -1;
}

int binarySearchWithRecursive(int *data, int find, int min, int max)
{
    if(min > max)
        return -1;

    int mid, mid_index, max_index;

    mid_index = min + (max - min) / 2 ;
    mid = data[mid_index];

    if(mid == find)
        return (min + (max - min) / 2);
    else if(mid < find){
        return binarySearchWithRecursive(data, find, min, mid_index - 1);
    }else {
        return binarySearchWithRecursive(data, find, mid_index + 1, max);
    }
}

void main(void)
{
    int arrary[7] = {1, 2, 3, 4, 5, 6, 7};
    int arrary_length;
    int result;
    int x = 4;
    arrary_length = sizeof(arrary)/sizeof(arrary[0]);

    //result = binarySearchWithIterativeMethod(arrary, x, 0, arrary_length - 1);
    result = binarySearchWithRecursive(arrary, x, 0, arrary_length - 1);
    if(result == -1){
        printf("not find %d\r\n", x);
    }else {
        printf("Element is found at index %d\r\n", result);
    }

}

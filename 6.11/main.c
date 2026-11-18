#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// 印出陣列函式
void printArray(const int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

// 課本習題 6.11 改良版氣泡排序法
// a) 內層迴圈比較次數隨每輪 pass 減少 (SIZE - 1 - pass)
// b) 加入 swapped 旗標，若某一輪沒有任何交換則提早結束
void bubbleSortOptimized(int a[], int size)
{
    int pass;
    int j;
    int tmp;
    int swapped;
    int totalComparisons = 0;
    int totalSwaps = 0;

    printf("=== 開始改良版氣泡排序 (Optimized Bubble Sort) ===\n");

    for (pass = 0; pass < size - 1; pass++)
    {
        swapped = 0; // 重置交換旗標
        printf("Pass %d (預計比較 %d 次): ", pass + 1, size - 1 - pass);

        // a) 比較次數每輪減少 pass 次
        for (j = 0; j < size - 1 - pass; j++)
        {
            totalComparisons++;
            if (a[j] > a[j + 1])
            {
                // 進行交換
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = 1;
                totalSwaps++;
            }
        }

        printArray(a, size);

        // b) 檢查是否發生交換，若無交換表示已完全排序好，立即終止
        if (swapped == 0)
        {
            printf("--> [提前結束] 本輪無任何交換，陣列已完全排序！於 Pass %d 終止。\n", pass + 1);
            break;
        }
    }

    printf("排序完成！總比較次數: %d, 總交換次數: %d\n\n", totalComparisons, totalSwaps);
}

int main(void)
{
    // 測試資料 1：一般未排序陣列
    int a[SIZE] = {26, 5, 81, 7, 63, 19, 45, 99, 12, 33};

    printf("【測試 1：一般未排序陣列】\n");
    printf("原始陣列:\n");
    printArray(a, SIZE);
    printf("\n");

    bubbleSortOptimized(a, SIZE);

    printf("排序後陣列:\n");
    printArray(a, SIZE);
    printf("==================================================\n\n");

    // 測試資料 2：近乎排序完成的陣列 (驗證條件 b: 提早結束)
    int b[SIZE] = {1, 2, 4, 3, 5, 6, 7, 8, 9, 10};

    printf("【測試 2：近乎已排序陣列 (驗證提早終止機制)】\n");
    printf("原始陣列:\n");
    printArray(b, SIZE);
    printf("\n");

    bubbleSortOptimized(b, SIZE);

    printf("排序後陣列:\n");
    printArray(b, SIZE);
    printf("==================================================\n");

    system("pause");
    return 0;
}

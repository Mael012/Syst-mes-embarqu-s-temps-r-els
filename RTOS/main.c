#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"

// Task 1: Print "Working"
void vTask1(void *pvParameters) {
    for (;;) {
        printf("Working\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

// Task 2: Convert Fahrenheit to Celsius
void vTask2(void *pvParameters) {
    const float fahrenheit = 100.0;
    float celsius;
    for (;;) {
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("Fahrenheit: %.2f, Celsius: %.2f\n", fahrenheit, celsius);
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
    }
}

// Task 3: Multiply two large integers
void vTask3(void *pvParameters) {
    const long int num1 = 123456789;
    const long int num2 = 987654321;
    long int result;
    for (;;) {
        result = num1 * num2;
        printf("Result of multiplication: %ld\n", result);
        vTaskDelay(pdMS_TO_TICKS(3000)); // Delay for 3 seconds
    }
}

// Task 4: Binary search in a fixed list
void vTask4(void *pvParameters) {
    int list[50];
    for (int i = 0; i < 50; i++) {
        list[i] = i + 1; // Fill the list with values 1 to 50
    }
    int target = 25; // Element to search
    int left = 0, right = 49, mid;
    for (;;) {
        left = 0;
        right = 49;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (list[mid] == target) {
                printf("Element %d found at index %d\n", target, mid);
                break;
            }
            if (list[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        vTaskDelay(pdMS_TO_TICKS(4000)); // Delay for 4 seconds
    }
}

int main(void) {
    // Create tasks
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask3, "Task 3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask4, "Task 4", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
    return 0;
}

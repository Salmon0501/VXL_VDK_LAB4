#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <stdint.h>
#include "main.h"

#define SCH_MAX_TASKS   40
#define NO_TASK_ID      0u
#define TICK_MS         10u

static inline uint32_t SCH_Lock(void) {
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    return primask;
}

static inline void SCH_Unlock(uint32_t primask) {
    __set_PRIMASK(primask);
}

void     SCH_Init(void);
void     SCH_Update(void);
void     SCH_Dispatch_Tasks(void);

uint32_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
uint8_t  SCH_Delete_Task(uint32_t taskID);

#endif


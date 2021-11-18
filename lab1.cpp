#include <stdio.h>
#include "tpl_os.h"
#include "mcp23s17.h"


FUNC(int, OS_APPL_CODE) main(void)
{
    initCoroBoard();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}


TASK(task1)
{
    printf("task1 is running\n");    
    ioExt.digitalWrite(mcp23s17::PORTA, 0, 1);
    printf("task1 is running, LED A0 is turned on\n");

    printf("call to ActivateTask() to task2 will be performed\n");
    ActivateTask(task2);
    printf("call to ActivateTask() to task2 is performed\n");

    printf("call to ActivateTask() to task3 will be performed\n");
    ActivateTask(task3);
    printf("call to ActivateTask() to task3 is performed\n");
    
    TerminateTask();
}

TASK(task2)
{
    printf("task2 is running\n");        
    ioExt.digitalWrite(mcp23s17::PORTA, 2, 1);
    printf("task2 is running, LED A2 is turned on\n");
    TerminateTask();
}

TASK(task3)
{
    printf("task3 is running\n");    
    ioExt.digitalWrite(mcp23s17::PORTA, 3, 1);
    printf("task3 is running, LED A3 is turned on\n");
    TerminateTask();
}


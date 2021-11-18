#include <stdio.h>
#include "tpl_os.h"
#include "mcp23s17.h"
#include "tft.h"

FUNC(int, OS_APPL_CODE) main(void)
{
    initCoroBoard();
    StartOS(OSDEFAULTAPPMODE);
    setupTimer();
    Tft.setTextCursor(0,0); 
    return 0;
}


TASK(task1)
{
    uint32 time1=0;
    time1=getTimerValue();
    Tft.println("task1 is running at");
    Tft.println(time1);
    ioExt.digitalWrite(mcp23s17::PORTA, 0, 1);
    ActivateTask(task2);

    ActivateTask(task3);

    TerminateTask();
}

TASK(task2)
{
    uint32 time2=0;
    time2=getTimerValue();
    Tft.println("task2 is running at");
    Tft.println(time2);
    ioExt.digitalWrite(mcp23s17::PORTA, 2, 1);
    TerminateTask();
}

TASK(task3)
{
    uint32 time3=0;
    time3=getTimerValue();
    Tft.println("task3 is running at");
    Tft.println(time3);
    ioExt.digitalWrite(mcp23s17::PORTA, 3, 1);
    TerminateTask();
}


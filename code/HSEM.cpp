void WorkTask::task() { // Task 1 (CM4)
    // init local variables
    while(true) {
    // take own HSEM2 -> block CM7 to sync
    while(HAL_HSEM_FastTake(2) != HAL_OK);
    // Do Stuff
    // release own HSEM (HSEM2)
    HAL_HSEM_Release(2, 0);
    // wait until HSEM1 is released
    while(HAL_HSEM_IsSemTaken(1));
    } // spin wait
}

void WorkTask::task() { // Task 2 (CM7)
    // init local variables
    while(true) {
    // take own HSEM1 -> block CM4 to sync
    while(HAL_HSEM_FastTake(1) != HAL_OK);
    // Do Stuff
    // release own HSEM (HSEM1)
    HAL_HSEM_Release(1, 0);
    // wait until HSEM2 is released
    while(HAL_HSEM_IsSemTaken(2));
    } // spin wait
}
// Name: Abhishek Pandit
// Date created: Nov 1, 2023

// this program implements the consumer problem
// importing all the necessary libraries
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SHM_NAME "/shm_example"
#define SEM_FULL_NAME "/sem_full_example"
#define SEM_EMPTY_NAME "/sem_empty_example"

struct Table {
    int items[2];
};

int main() {
    // shm_open() creates or opens a POSIX shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    // converts the mapped memory to the Table explicitly
    Table* table = static_cast<Table*>(mmap(0, sizeof(Table), PROT_READ, MAP_SHARED, shm_fd, 0));
    //sem_full, sem_empty tells how many elements are left to insert
    sem_t* sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);
    sem_t* sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, 2);

    for (int i = 0; i < 10; ++i) {
        sem_wait(sem_full);
        std::cout << "\tConsumed " << table->items[i % 2] << std::endl;
        sleep(1 + rand() % 2);
        sem_post(sem_empty);
        // std::cout << "\n" << std::endl;
    };
    std::cout << "\n" << std::endl;
    sem_close(sem_full);  //close the port
    sem_close(sem_empty); //close the port
    munmap(table, sizeof(Table));
    close(shm_fd); //close the shared memory

    return 0;
}

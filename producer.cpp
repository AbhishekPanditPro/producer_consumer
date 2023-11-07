// Name: Abhishek Pandit
// Date created: Nov 1, 2023

/*
program structures:

0th: most important, creating a shared memory as a table
1st: the producer will produce and fill up the table, till then the consumer will wait 
2nd: after the table is filled up. the consumer will consume it, till then the producer will wait
3rd : use semaphores to synchronize producer and consumer
4th: use the mutual exclusion or use the threads 

*/


// this program implements the producer and consumer problem
// importing all the necessary standard libraries
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
    std::cout <<"\n" << std::endl;
    // shm_open() creates or opens a POSIX shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    // ftruncate sets the shared memory to the size of Table which is 2, this acts as a buffer memory
    ftruncate(shm_fd, sizeof(Table));
    // converts the mapped memory to the Table explicitly
    Table* table = static_cast<Table*>(mmap(0, sizeof(Table), PROT_WRITE, MAP_SHARED, shm_fd, 0));
    //sem_full, sem_empty tells how many elements are left to insert
    sem_t* sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);
    sem_t* sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, 2);

    for (int i = 0; i < 10; ++i) {
        sem_wait(sem_empty);
        table->items[i % 2] = i;
        std::cout << "Produced " << i << std::endl;
        sleep(1 + rand() % 2);
        sem_post(sem_full);
    }

    sem_close(sem_full);  //close the port
    sem_close(sem_empty); //close the port
    munmap(table, sizeof(Table));
    close(shm_fd); //close the shared memory

    return 0;
}

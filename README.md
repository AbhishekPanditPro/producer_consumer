# Producer_Consumer
Producer-Consumer program is a process synchronization problem where producer produces items, puts them in the buffer memory, and consumer consumes the memory. The buffer works as a shared memory between producer and consumer.

## Note: C++ compiler is inbuilt in the Unix/Linux
To run in program in Windows, you need to have C++ compiler installed and add the compiler path to the system variables.

## Executing the program
In the Shell or Command Line Interface (CLI):
```console
foo@bar:~$ g++ producer.cpp -o producer
foo@bar:~$ g++ consumer.cpp -o consumer
foo@bar:~$ ./producer & ./consumer &

```
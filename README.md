# Producer_Consumer
Producer-Consumer program is a process synchronization problem where producer produces items, puts them in the buffer memory, and consumer consumes the memory. The buffer works as a shared memory between producer and consumer and the program works concurrently.

## Note: C++ compiler is inbuilt in the Unix/Linux
To run in program in Windows, you need to have C++ compiler installed and add the compiler path to the system variables.
## Importing the file locally
Clone the repository
```console
foo@bar % git clone https://github.com/AbhishekPanditPro/producer_consumer.git
```
## Executing the program
In the Shell or Command Line Interface (CLI):
```console
foo@bar % g++ producer.cpp -pthread -o producer
foo@bar % g++ consumer.cpp -pthread -o consumer
foo@bar % ./producer & ./consumer &

```

## Output
The output will look like similar to this:

```console
[1] 23382
[2] 23383
foo@bar % 

Produced 0
Produced 1
	Consumed 0
	Consumed 1
Produced 2
Produced 3
	Consumed 2
	Consumed 3
Produced 4
	Consumed 4
Produced 5
Produced 6
	Consumed 5
Produced 7
	Consumed 6
	Consumed 7
Produced 8
Produced 9
	Consumed 8
	Consumed 9

[1]  - done       ./producer
foo@bar % 


[2]  + done       ./consumer
```
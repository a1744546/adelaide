#include "slow_functions.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// How nice of me to include a global that tells you how many commands there were :)
int total_commands = 0;
static pthread_mutex_t lock2; 

// ####################################################################################
// ## Please write some code in the following two functions

void * writer(void * in_ptr)
{
	typedef char* (provateType)[1000];
	//must include bad_write;
	//printf("%s", (*((provateType*)in_ptr))[0]);
	if (pthread_mutex_init(&lock2, NULL) != 0) 
	{ 
		printf("FAIL!\n"); 
	} 
	int written_commands = 0;
    while(written_commands < total_commands)
    {
		pthread_mutex_lock(&lock2);
        bad_write((*((provateType*)in_ptr))[written_commands]);
		pthread_mutex_unlock(&lock2);
		written_commands++;
    }
}

void * reader(void * empty)
{
	//must include bad_read
	sleep(5);
    int readen_commands = 0;
	while(readen_commands < total_commands)
    {
		pthread_mutex_lock(&lock2);
        bad_read(empty);
		pthread_mutex_unlock(&lock2);
		readen_commands++;
    }
}


// ################################################################################
// ## DO NOT MODIFY 

int main()
{

	// ## Parse STDIN and read into commands
	char * commands[100];
	char line[256];
    while (fgets(line, 256, stdin))
    {
		commands[total_commands] = (char*)(malloc(strlen(line) * sizeof(char)));
 		strcpy(commands[total_commands], line);
		total_commands = total_commands + 1;
	}

	pthread_t write1;
	pthread_t read1;

	// Creates a thread which executes writer!
	if(pthread_create(&write1, NULL, writer, commands))
	{
		fprintf(stderr, "Error creating write thread\n");
		return 1;
	}

	// Creates a thread which executes reader!
	if(pthread_create(&read1, NULL, reader, NULL))
	{
		fprintf(stderr, "Error creating read thread\n");
		return 1;
	}

	// Ensure Threads Join Well
	if(pthread_join(write1, NULL)) 
	{
		fprintf(stderr, "Error joining write thread\n");
		return 2;
	}

	if(pthread_join(read1, NULL)) 
	{
		fprintf(stderr, "Error joining read thread\n");
		return 2;
	}

	// Did you really call the right functions?
	get_output();

	// I am a responsible memory user!
	int command_i;
	for (command_i = 0; command_i < total_commands; command_i++)
	{
		free(commands[command_i]);
	}
	return 0;

}
// ## DO NOT MODIFY 
// ################################################################################

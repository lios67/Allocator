# Allocator

	The way I design this project is to have if statements to handle the commands from the users. One if statement for "QUIT" to exit the code on command. If statement for "STAT" to print the results in the array. If statement for  "C" to compact the empty spaces in the array. If statement for "RQ" to request for a process to be added to the memory(array). Finally an if statement for "RL" to release the process the user ask for. For the array I choose to use -1 as a representation for having no process in that memory space. For reading the data from the input I choose to read the whole line (I use getline). The problems I faced while working on this project was how to print out the way it should with the free space. To get around this I use multiple if statements to check if the last index of the array is -1 so I know it is free. Another problem is to have the loop skip a space that was too small for the process because it was splitting process 4 in to to places, that does not show BEST-FIT. To get around this I have a loop to check the space first before I make any changes to the memory space. 



Output:
Addresses [0 : 262143] Process P0
Addresses [262144 : 524287] Process P1
Addresses [524288 : 786487] Process P2
Addresses [786488 : 1048575] Free

Addresses [0 : 262143] Process P0
Addresses [262144 : 462143] Process P3
Addresses [462144 : 524287] Free
Addresses [524288 : 786487] Process P2
Addresses [786488 : 1048575] Free

Addresses [0 : 262143] Process P0
Addresses [262144 : 462143] Process P3
Addresses [462144 : 524287] Free
Addresses [524288 : 786487] Process P2
Addresses [786488 : 986487] Process P4
Addresses [986488 : 1048575] Free

Addresses [0 : 262143] Process P0
Addresses [262144 : 462143] Process P3
Addresses [462144 : 724343] Process P2
Addresses [724344 : 924343] Process P4
Addresses [924344 : 1048575] Free

To Run:
g++ -o allocator.exe allocator_OLin.cpp 
./allocator.exe 1048576

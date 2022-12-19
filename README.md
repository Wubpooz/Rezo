# Rezo  

## UDP  

Start 2 terminals, in the first run `./server_udp` and `./client_udp localhost` in the second.  
Then in the second terminal write a message (if it's more than 20 characters it will be truncated).  
You're now supposed to see the message in the first terminal.  

&nbsp;

## TCP  

Start 2 terminals, in the first run `./server_udp` and `./client_udp localhost` in the second.  
Then in the second terminal write a first message (truncated at 20 characters) ; now look at the first one, you can respond.  
You can go back and forth and exchange messages between them.  
To exit, just type `exit`.


## Makefile

[Makefile](https://github.com/Wubpooz/Rezo/blob/master/UDP/Makefile) :  
- `make` : compile all .c
- `make clean` : remove ALL binaries

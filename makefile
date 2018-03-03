objects = main.o server.o client.o morse.o cpu.o autokey.o
iradio:$(objects)
	gcc -o cw $(objects) -lwiringPi -lpthread

clean:
	rm $(objects)

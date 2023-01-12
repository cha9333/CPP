intro_exe: job.o hobby.o main.o
	gcc -o intro_exe job.o hobby.o main.o

job.o:	
	gcc -c -o job.o job.c

hobby.o:	
	gcc -c -o hobby.o hobby.c

main.o:	
	gcc -c -o main.o main.c

clean:
	rm -f *.o
	rm intro_exe




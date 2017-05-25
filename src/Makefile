all: librwlock.a app

librwlock.a: 	
	gcc -Wall -c rwlock.c 
	ar -cvq librwlock.a rwlock.o
	ranlib librwlock.a

app: 	
	gcc -Wall -o app app.c -I. -L. -lrwlock -lpthread

clean: 
	rm -fr *.o *.a *~ a.out app rwlock.o librwlock.a

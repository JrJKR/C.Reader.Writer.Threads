#include <stdio.h>
#include <pthread.h>
#include "rwlock.h"

void rw_init (struct rwlock *L)
{
	L->count = 0;
}

void rw_writer_lock (struct rwlock *L) {
	pthread_mutex_lock( &L->mutex);
}

void rw_writer_unlock (struct rwlock *L) {
	pthread_mutex_unlock( &L->mutex);
}

void rw_reader_lock (struct rwlock *L) {
	pthread_mutex_lock( &L->cmutex);
	if ( L->count == 0) {
		L->count++;
		pthread_mutex_lock( &L->mutex);
		pthread_mutex_unlock( &L->cmutex);
		return;
	}
	L->count++;
	pthread_mutex_unlock( &L->cmutex);
}

void rw_reader_unlock (struct rwlock *L) {
	pthread_mutex_lock( &L->cmutex);
	if ( L->count == 1) {
		L->count--;
		pthread_mutex_unlock( &L->mutex);
		pthread_mutex_unlock( &L->cmutex);
		return;
	}
	L->count--;
	pthread_mutex_unlock( &L->cmutex);
}

void rw_destroy (struct rwlock *L) {

	pthread_mutex_destroy( &L->mutex);
	pthread_mutex_destroy( &L->cmutex);
	// pthread_cond_destroy( &L->rcond); //not used
}
struct rwlock {
	int count;
	pthread_mutex_t mutex; //application SD
	pthread_mutex_t cmutex; //lock SD
	// pthread_cond_t rcond; //not used
};

void rw_init (struct rwlock *L); 
void rw_writer_lock (struct rwlock *L); 
void rw_writer_unlock (struct rwlock *L);  
void rw_reader_lock (struct rwlock *L);
void rw_reader_unlock (struct rwlock *L); 
void rw_destroy (struct rwlock *L);
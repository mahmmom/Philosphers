/*#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TH 100

uint64_t		amount = 0;

pthread_mutex_t	amount_lock;

void	*update_amount(void *data)
{
	pthread_mutex_lock(&amount_lock);
	amount += 1;
	pthread_mutex_unlock(&amount_lock);
	return (NULL);
}

int	main(void)
{
	pthread_t	waiters[TH];

	pthread_mutex_init(&amount_lock, NULL);
	for (int i = 0; i < TH; ++i)
	{
		if (pthread_create(waiters + 1, NULL, update_amount, NULL))
			exit(EXIT_FAILURE);
	}
	for (int i = 0; i < TH; ++i)
	{
		pthread_join(waiters[i], NULL);
	}
	pthread_mutex_destroy(&amount_lock);
	printf("%llu\n", amount);
}
*/
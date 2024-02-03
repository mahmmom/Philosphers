/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_thread_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:44:07 by mohamoha          #+#    #+#             */
/*   Updated: 2024/02/03 18:42:06 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_error_handler(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_handle("The value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		error_handle("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		error_handle("A deadlock would occur if the thread "
			"blocked waiting for mutex.");
	else if (EPERM == status)
		error_handle("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		error_handle("The process cannot allocate enough memory"
			" to create another mutex.");
	else if (EBUSY == status)
		error_handle("Mutex is locked");
}

void	mutex_handler(t_mutx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		mutex_error_handler(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		mutex_error_handler(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		mutex_error_handler(pthread_mutex_destroy(mutex), opcode);
	else
		error_handle("Wrong opcode for mutex_handle:"
			"use <LOCK> <UNLOCK> <INIT> <DESTROY>");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_handle("No resources to create another thread");
	else if (EPERM == status)
		error_handle("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_handle("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_handle("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_handle("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_handle("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

void	thread_handle(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_handle("Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH>");
}

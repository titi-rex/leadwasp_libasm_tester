/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:41:29 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/11 15:19:22 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "colors.h"

extern int	g_max_len_size;

static void	test_clear(t_test *head)
{
	t_test	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

static int	test_format_status_exit(t_test *test)
{
	char	*msg;
	char	*color;

	color = RED;
	if (test->status == 0)
	{
		msg = "[OK]";
		color = GREEN;
	}
	else if (test->status == 255)
		msg = "[KO]";
	else if (test->status == 1)
		msg = "[INTERNAL ERROR]";
	else
		msg = "[malformed test]";
	printf("\t%s> %-*s : %s\n"END, color, g_max_len_size, test->name, msg);
	return (test->status);
}

static int	test_format_status_signal(t_test *test)
{
	char	*msg;
	char	*color;

	color = YELLOW;
	if (test->status == SIGSEGV)
		msg = "[SEGV]";
	else if (test->status == SIGBUS)
		msg = "[BUSE]";
	else if (test->status == SIGFPE)
		msg = "[FPE]";
	else if (test->status == SIGSYS)
		msg = "[SYS]";
	else if (test->status == SIGABRT)
		msg = "[ABRT]";
	else if (test->status == SIGALRM)
	{
		msg = "[TIMEOUT]";
		color = BLUE;
	}
	else
		msg = "[unhandled signal]";
	printf("\t%s> %-*s : %s\n"END, color, g_max_len_size, test->name, msg);
	return (-1);
}

static void	testcpy(t_test *dst, t_test *src)
{
	strcpy(dst->name, src->name);
	dst->id = src->id;
	dst->flags = src->flags;
	dst->status = src->status;
	dst->function = src->function;
	dst->scenario = src->scenario;
	dst->next = src->next;
}

static void	child(t_test **head, t_test *ref_test)
{
	int		ret;
	int		fds[2];
	t_test	test;

	(void)head;
	testcpy(&test, ref_test);
	test_clear(*head);
	if (test.flags & FLAG_TIMEOUT_L)
		alarm(TIMEOUT_L);
	else
		alarm(TIMEOUT);
	if (test.flags & FLAG_STDIN)
	{
		if (pipe(fds) == -1 
			|| dup2(fds[1], STDOUT_FILENO) == -1 
			|| dup2(fds[0], STDIN_FILENO) == -1)
			exit(INTERNAL_ERROR);
	}
	ret = test.function();
	exit(ret);
}

static int	test_execute(t_test **head, t_test *test)
{
	int	pid;
	int	wstatus;

	pid = fork();
	if (pid == 0)
		child(head, test);
	else if (pid == 0)
		return (-2);
	if (wait(&wstatus) == -1)
		printf("FATAL: wait error\n");
	else if (WIFEXITED(wstatus))
	{
		test->status = WEXITSTATUS(wstatus);
		return (test_format_status_exit(test));
	}
	else if (WIFSIGNALED(wstatus))
	{
		test->status = WTERMSIG(wstatus);
		return (test_format_status_signal(test));
	}
	return (-2);
}

int	test_launcher(t_test **head, const char *name)
{
	t_test	*current;
	char	*color;
	int		success;
	int		total;

	success = 0;
	total = 0;
	current = *head;
	printf(GRAY_LIGHT"%s: \n"END, name);
	while (current)
	{
		if (test_execute(head, current) == 0)
			++success;
		++total;
		current = current->next;
	}
	color = (total == success) ? GREEN_LIGHT: BOLD RED ;
	printf("%stests successful: %d/%d\n"END, color, success, total);
	test_clear(*head);
	g_max_len_size = 0;
	return (-(total == success));
}

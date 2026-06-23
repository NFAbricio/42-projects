#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef void	(*t_fd_writer)(int);

static int	g_total = 0;
static int	g_passed = 0;

static void	print_result(const char *name, int ok)
{
	g_total++;
	if (ok)
	{
		g_passed++;
		printf("[OK] %s\n", name);
	}
	else
		printf("[KO] %s\n", name);
}

static int	string_equals(const char *left, const char *right)
{
	if (left == NULL || right == NULL)
		return (left == right);
	return (strcmp(left, right) == 0);
}

static char	*duplicate_buffer(const char *buffer, ssize_t length)
{
	char	*copy;

	copy = malloc((size_t)length + 1);
	if (copy == NULL)
		return (NULL);
	memcpy(copy, buffer, (size_t)length);
	copy[length] = '\0';
	return (copy);
}

static char	*capture_fd_output(t_fd_writer writer)
{
	int		pipe_fd[2];
	int		saved_stdout;
	char	buffer[128];
	ssize_t	bytes_read;
	char	*capture;

	if (pipe(pipe_fd) != 0)
		return (NULL);
	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (NULL);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
		close(saved_stdout);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (NULL);
	}
	close(pipe_fd[1]);
	writer(STDOUT_FILENO);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1);
	close(pipe_fd[0]);
	if (bytes_read < 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	capture = duplicate_buffer(buffer, bytes_read);
	return (capture);
}

static void	write_putchar(int fd)
{
	ft_putchar_fd('A', fd);
}

static void	write_putstr(int fd)
{
	ft_putstr_fd("libft", fd);
}

static void	write_putendl(int fd)
{
	ft_putendl_fd("libft", fd);
}

static void	write_putnbr(int fd)
{
	ft_putnbr_fd(-42, fd);
}

static int	*make_int(int value)
{
	int	*number;

	number = malloc(sizeof(*number));
	if (number != NULL)
		*number = value;
	return (number);
}

static void	del_int(void *content)
{
	free(content);
}

static void	increment_int(void *content)
{
	(*(int *)content)++;
}

static void	*double_int(void *content)
{
	int	*copy;

	copy = make_int((*(int *)content) * 2);
	return (copy);
}

static char	shift_by_index(unsigned int index, char c)
{
	return ((char)(c + (char)index));
}

static void	add_one_by_index(unsigned int index, char *c)
{
	(void)index;
	if (c != NULL)
		*c = (char)(*c + 1);
}

static void	run_string_tests(void)
{
	char	*joined;
	char	*trimmed;
	char	*duplicate;
	char	*substring;
	char	*mapped;
	char	iterated[] = "abc";
	char	lcpy_buffer[5];
	char	lcat_buffer[16] = "foo";
	char	chr_source[] = "libft";
	char	strchr_source[] = "banana";
	char	strrchr_source[] = "banana";

	print_result("ft_strlen basic", ft_strlen("libft") == 5);
	print_result("ft_strlen empty", ft_strlen("") == 0);
	duplicate = ft_strdup("libft");
	print_result("ft_strdup content", string_equals(duplicate, "libft"));
	print_result("ft_strdup distinct pointer", duplicate != NULL && duplicate != (char *)"libft");
	free(duplicate);
	print_result("ft_strchr found", ft_strchr(strchr_source, 'n') == strchr_source + 2);
	print_result("ft_strchr end", ft_strchr(chr_source, '\0') == chr_source + 5);
	print_result("ft_strrchr found", ft_strrchr(strrchr_source, 'a') == strrchr_source + 5);
	print_result("ft_strncmp prefix", ft_strncmp("abc", "abd", 2) == 0);
	print_result("ft_strncmp diff", ft_strncmp("abc", "abd", 3) < 0);
	print_result("ft_strlcpy return", ft_strlcpy(lcpy_buffer, "hello", sizeof(lcpy_buffer)) == 5);
	print_result("ft_strlcpy content", string_equals(lcpy_buffer, "hell"));
	print_result("ft_strlcat return", ft_strlcat(lcat_buffer, "bar", sizeof(lcat_buffer)) == 6);
	print_result("ft_strlcat content", string_equals(lcat_buffer, "foobar"));
	joined = ft_strjoin("lib", "ft");
	print_result("ft_strjoin content", string_equals(joined, "libft"));
	free(joined);
	substring = ft_substr("libft", 1, 3);
	print_result("ft_substr content", string_equals(substring, "ibf"));
	free(substring);
	trimmed = ft_strtrim("   libft   ", " ");
	print_result("ft_strtrim content", string_equals(trimmed, "libft"));
	free(trimmed);
	mapped = ft_strmapi("abc", shift_by_index);
	print_result("ft_strmapi content", string_equals(mapped, "ace"));
	free(mapped);
	ft_striteri(iterated, add_one_by_index);
	print_result("ft_striteri content", string_equals(iterated, "bcd"));
}

static void	run_memory_tests(void)
{
	char	buffer[8];
	char	move_buffer[16] = "abcdef";
	char	memchr_source[] = "libft";
	unsigned char	*allocated;

	ft_memset(buffer, 'x', 4);
	buffer[4] = '\0';
	print_result("ft_memset content", string_equals(buffer, "xxxx"));
	ft_bzero(buffer, 4);
	print_result("ft_bzero zero", buffer[0] == '\0' && buffer[1] == '\0' && buffer[2] == '\0' && buffer[3] == '\0');
	ft_memcpy(buffer, "abc", 4);
	print_result("ft_memcpy content", string_equals(buffer, "abc"));
	ft_memmove(move_buffer + 2, move_buffer, 4);
	print_result("ft_memmove overlap", string_equals(move_buffer, "ababcd"));
	print_result("ft_memchr found", ft_memchr(memchr_source, 'b', 5) == memchr_source + 2);
	print_result("ft_memcmp equal", ft_memcmp("abc", "abc", 3) == 0);
	print_result("ft_memcmp diff", ft_memcmp("abc", "abd", 3) < 0);
	allocated = ft_calloc(4, sizeof(unsigned char));
	print_result("ft_calloc non-null", allocated != NULL);
	print_result("ft_calloc zeroed", allocated != NULL && allocated[0] == 0 && allocated[1] == 0 && allocated[2] == 0 && allocated[3] == 0);
	free(allocated);
}

static void	run_conversion_tests(void)
{
	char	*itoa_value;

	print_result("ft_atoi positive", ft_atoi("42") == 42);
	print_result("ft_atoi negative", ft_atoi("   -42") == -42);
	print_result("ft_isalpha", ft_isalpha('a') == 1 && ft_isalpha('1') == 0);
	print_result("ft_isdigit", ft_isdigit('9') == 1 && ft_isdigit('x') == 0);
	print_result("ft_isalnum", ft_isalnum('9') == 1 && ft_isalnum('#') == 0);
	print_result("ft_isascii", ft_isascii(127) == 1 && ft_isascii(128) == 0);
	print_result("ft_isprint", ft_isprint(' ') == 1 && ft_isprint('\n') == 0);
	print_result("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('!') == '!');
	print_result("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('!') == '!');
	itoa_value = ft_itoa(-123);
	print_result("ft_itoa", string_equals(itoa_value, "-123"));
	free(itoa_value);
}

static void	run_output_tests(void)
{
	char	*captured;

	captured = capture_fd_output(write_putchar);
	print_result("ft_putchar_fd", string_equals(captured, "A"));
	free(captured);
	captured = capture_fd_output(write_putstr);
	print_result("ft_putstr_fd", string_equals(captured, "libft"));
	free(captured);
	captured = capture_fd_output(write_putendl);
	print_result("ft_putendl_fd", string_equals(captured, "libft\n"));
	free(captured);
	captured = capture_fd_output(write_putnbr);
	print_result("ft_putnbr_fd", string_equals(captured, "-42"));
	free(captured);
}

static void	run_list_tests(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*mapped;
	t_list	*last_node;
	int		*value1;
	int		*value2;
	int		*value3;

	value1 = make_int(10);
	value2 = make_int(20);
	value3 = make_int(30);
	node1 = ft_lstnew(value1);
	node2 = ft_lstnew(value2);
	print_result("ft_lstnew content", node1 != NULL && node1->content == value1 && node1->next == NULL);
	list = node1;
	if (list != NULL && node2 != NULL)
	{
		ft_lstadd_front(&list, node2);
		print_result("ft_lstadd_front", list == node2 && list->next == node1);
		ft_lstadd_back(&list, ft_lstnew(value3));
		last_node = ft_lstlast(list);
		print_result("ft_lstadd_back", last_node != NULL && last_node->content == value3);
		print_result("ft_lstsize", ft_lstsize(list) == 3);
		print_result("ft_lstlast", last_node != NULL && last_node->content == value3);
		ft_lstiter(list, increment_int);
		print_result("ft_lstiter", *(int *)list->content == 21 && *(int *)list->next->content == 11);
		mapped = ft_lstmap(list, double_int, del_int);
		print_result("ft_lstmap non-null", mapped != NULL);
		print_result("ft_lstmap content", mapped != NULL && mapped->next != NULL && *(int *)mapped->content == 42 && *(int *)mapped->next->content == 22);
		ft_lstclear(&mapped, del_int);
		ft_lstclear(&list, del_int);
	}
	else
		print_result("ft_lst setup", 0);
}

int	main(void)
{
	printf("Running libft tests...\n");
	run_conversion_tests();
	run_memory_tests();
	run_string_tests();
	run_output_tests();
	run_list_tests();
	printf("Summary: %d/%d passed\n", g_passed, g_total);
	return (g_passed == g_total ? EXIT_SUCCESS : EXIT_FAILURE);
}
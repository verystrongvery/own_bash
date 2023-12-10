#include "bash.h"

void	check_quotes(char *s, int q[], int *i)
{
	int p;

	while (s[*i])
	{
		p = *i == 0 ? OUT : q[*i - 1];
		if ((p == Q_B || p == Q_S) && s[*i] != '\'')
			q[*i] = Q_B;
		else if ((p == DQ_B || p == DQ_S) && (s[*i - 1] == '\\'
			|| s[*i] != '"'))
			q[*i] = DQ_B;
		else if ((p == Q_S || p == Q_B) && s[*i] == '\'')
			q[*i] = Q_E;
		else if ((p == Q_E || p == OUT || p == DQ_E) && s[*i] == '\'')
			q[*i] = Q_S;
		else if ((p == Q_E || p == OUT || p == DQ_E)
			&& (s[*i] != '"' && s[*i] != '\''))
			q[*i] = OUT;
		else if ((p == Q_E || p == OUT || p == DQ_E) && s[*i] == '"')
			q[*i] = DQ_S;
		else if ((p == DQ_S || p == DQ_B) && s[*i] == '"')
			q[*i] = DQ_E;
		(*i)++;
	}
}

char	***unexpected_eof_error(char *s1, char *s2)
{
	putstr_newline("");
	free_init(&s1, NULL);
	free_init(&s2, NULL);
	return (0);
}

char	***parsing_cmds(char *str)
{
	int		quotes[MAX];
	int		q_idx;
	char	*line;

	if (!str[0])
	{
		free_init(&str, NULL);
		return (NULL);
	}
	q_idx = 0;
	check_quotes(str, quotes, &q_idx);
	while (quotes[q_idx - 1] == DQ_B || quotes[q_idx - 1] == Q_B
		|| quotes[q_idx - 1] == DQ_S || quotes[q_idx - 1] == Q_S)
	{
		putstr("> ");
		if (!get_next_line(0, &line))
			return (unexpected_eof_error(line, str));
		str = gnljoin(str, "\n");
		str = gnljoin(str, line);
		free_init(&line, NULL);
		check_quotes(str, quotes, &q_idx);
	}
	return (split_cmds(str, quotes));
}

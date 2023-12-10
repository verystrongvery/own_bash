#include "bash.h"

char	**split_arr(char *str, int num, int idxs[][2])
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (num + 1));
	i = -1;
	while (++i < num)
		ret[i] = _strndup(str + idxs[i][0], idxs[i][1]);
	ret[num] = 0;
	free_init(&str, NULL);
	return (ret);
}

void	put_in_idxs(int idxs[][2], int i, int data1, int data2)
{
	idxs[i][0] = data1;
	idxs[i][1] = data2;
}

int		check_str(char *s, int idxs[][2], int *len, int *quotes)
{
	int	arg_n;
	int	i;

	arg_n = -1;
	i = 0;
	while (s[++i] && (++*len) >= 0)
	{
		if (quotes[i] == Q_B || quotes[i] == DQ_B)
			continue;
		if (s[i - 1] == ' ' && (_strchr("|<>", s[i]) != NOTHING))
			put_in_idxs(idxs, ++arg_n, i, 1);
		else if ((_strchr("|<> ", s[i - 1]) == NOTHING)
			&& (_strchr("|<> ", s[i]) != NOTHING))
		{
			put_in_idxs(idxs, ++arg_n, i - *len, *len);
			if ((_strchr("|<>", s[i]) != NOTHING))
				put_in_idxs(idxs, ++arg_n, i, 1);
		}
		if (s[i] == '>' && s[i + 1] == '>' && i++)
			idxs[arg_n][1]++;
		if ((_strchr("|<> ", s[i - 1]) != NOTHING)
			|| (_strchr("|<> ", s[i]) != NOTHING))
			*len = 0;
	}
	return (arg_n);
}

int		count_arg_num(char *s, int idxs[][2])
{
	int	quotes[MAX];
	int arg_n;
	int len;
	int	i;

	arg_n = -1;
	len = 0;
	if (_strchr("|<>", s[0]) != NOTHING)
	{
		g_except[SYNTAX] = s[0];
		return (0);
	}
	i = 0;
	check_quotes(s, quotes, &i);
	arg_n = check_str(s, idxs, &len, quotes);
	if (s[_strlen(s) - 1] != ' ')
		put_in_idxs(idxs, ++arg_n, _strlen(s) - (len + 1), len + 1);
	return (++arg_n);
}

void	split_one_more(char *str, int cmd_num, int idxs[][2], char ***ret)
{
	char	**temp;
	int		arg_num;
	int		i;

	temp = split_arr(str, cmd_num, idxs);
	i = -1;
	while (++i < cmd_num)
	{
		arg_num = count_arg_num(temp[i], idxs);
		if (!arg_num)
			g_except[NONE] = 1;
		ret[i] = split_arr(temp[i], arg_num, idxs);
	}
	free(temp);
}

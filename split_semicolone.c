#include "sh.h"

char		**quotes_splite(char const *s, char c)
{
	char	**str;
	int		start;
	int		index;
	int		words;

	start = 0;
	index = 0;
	words = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);

	while (s[index])
	{
        while (s[index] == c)
            index++;
		start = index;
		
		while ((s[index] != c) && s[index])
		{
			if (s[index] == '\"')
			{
				index++;
				while (s[index] != '\"' && s[index])
				{	
					// if (s[index] == '\0')
					// {
					// 	ft_putendl("Unmatched \'.");
					// 	exit (1);
					// }
					index++;
				}
			}

			if (s[index] == '\'')
			{
				index++;
				while (s[index] != '\'' && s[index])
				{	
					if (s[index] == '\0')
					{
						ft_putendl("Unmatched \'.");
						exit (1);
					}
					index++;
				}
			}
			index++;
		}
		if (index > start)
			str[words++] = ft_strsub(s, start, (index - start));
	}
	str[words] = NULL;
	return (str);
}


//cmd "tst;;;;;;;tst1"
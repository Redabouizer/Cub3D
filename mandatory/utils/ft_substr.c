#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str)
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}
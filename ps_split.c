#include <stdlib.h>

static int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

static int countword(const char *s)
{
    int i = 0;
    int in_word = 0;
    int count = 0;

    while (s[i])
    {
        if (!is_space(s[i]) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (is_space(s[i]))
            in_word = 0;
        i++;
    }
    return count;
}

char **ft_split(const char *str)
{
    int i = 0, j = 0;
    int words = countword(str);
    char **out = (char **)malloc(sizeof(char *) * (words + 1));
    if (!out)
        return NULL;

    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (!str[i])
            break;

        int start = i;
        while (str[i] && !is_space(str[i]))
            i++;
        int end = i;

        out[j] = (char *)malloc((end - start + 1));
        if (!out[j])
        {
            while (--j >= 0)
                free(out[j]);
            free(out);
            return NULL;
        }

        int k = 0;
        while (start < end)
            out[j][k++] = str[start++];
        out[j][k] = '\0';
        j++;
    }
    out[j] = NULL;
    return out;
}

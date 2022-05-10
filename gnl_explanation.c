#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t    ft_strlen(char *s) // 4 - Que deve fazer a contagem de S e retornar i com o tamanho total de s
{
    size_t    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c) // 3 - strrchr é invocado pra fazer a busca por um \n no valor s
{
    int    i;

    i = 0;
    if (!s) // Se ele receber s vazio retorna 0
        return (0);
    if (c == '\0') // Se ele entrar com byte nulo
        return ((char *)&s[ft_strlen(s)]); // Retornamos o array com o tamanho contado por strlen
    while (s[i] != '\0') // Enquanto não chegarmos ao final do array
    {
        if (s[i] == (char) c) // Fazemos uma verificação para buscar o C (\n) passado dentro de S
            return ((char *)&s[i]); // Quando encontramos retornamos o array de s no valor de i para frente
        i++;
    }
    return (0); // Caso não consiga, retornaremos 0
}

char    *ft_strjoin(char *main_str, char *buff) // 5
{
    size_t    i;
    size_t    j;
    char    *str;

    if (!main_str) // Faz uma verificação para saber se main_str é vazio
    {
        main_str = (char *)malloc(1 * sizeof(char)); // Caso seja, criamos um array na memória usando ele como array
        main_str[0] = '\0'; // incrementamos na posição zero um byte nulo
    }
    if (!main_str || !buff) // Caso ambas funções estejam vazias retornamos nulo
        return (NULL);
    str = malloc(sizeof(char) * ((ft_strlen(main_str) + ft_strlen(buff)) + 1)); // Alocamos na memoria uma array com tamanho de strlen dos parametros main_str e buff + 1
    if (!str) // Caso o alocamento não tenha dado certo retornamos null
        return (NULL);
    i = -1; // Iniciamos o parametro i como -1 para economizar espaço na função
    j = 0; // Iniciamos j como 0
    if (main_str) // Caso não estejamos no final de main_str
        while (main_str[++i] != '\0') // Faremos um loop para concatenar tudo que estiver em main_str para str
            str[i] = main_str[i];
    while (buff[j] != '\0') // Após isso concatenamos tudo que estiver em buff para str (usamos 2 contadores pois os valores são separados)
        str[i++] = buff[j++];
    str[ft_strlen(main_str) + ft_strlen(buff)] = '\0'; // Adicionamos a str no tamanho de main_str + buff um byte nulo
    free(main_str); // Limpamos o valor de main_str
    return (str); // Retornamos str para função principal
}

char    *ft_get_line(char *main_str) // 6
{
    int        i;
    char    *str;

    i = 0; // iniciamos o i com valor de 0
    if (!main_str[i]) // Caso o valor de main_str no byte de i seja vazio
        return (NULL); // Retornamos nulo
    while (main_str[i] && main_str[i] != '\n') // Enquanto não chegar ao final de main_str ou chegar a uma quebra de linha
        i++; // incrementamos o valor de i
    str = (char *)malloc(sizeof(char) * (i + 2)); // Alocamos o valor de i + 2 (para o \n e \0)em um array na memória
    if (!str) // Caso o alocamento tenha dado errado retornamos null
        return (NULL);
    i = 0; // Reiniciamos o parametro de i para 0
    while (main_str[i] && main_str[i] != '\n') // Enquanto não chegar ao final de main_str ou a uma quebra de linha
    {
        str[i] = main_str[i]; // Iremos copiar o valor de main_str para str
        i++;
    }
    if (main_str[i] == '\n') // Caso main_str esteja em uma quebra de linha
    {
        str[i] = main_str[i]; // Iremos incrementar a quebra de linha 1 vez
        i++;
    }
    str[i] = '\0'; // Incrementamos um byte nulo
    return (str); // Retornamos str para a função principal ** obs: não limpamos main_str dessa vez
}

char    *ft_new_left_str(char *main_str) // 7
{
    int        i;
    int        j;
    char    *str;

    i = 0; // Iniciamos o parametro i com valor 0
    while (main_str[i] && main_str[i] != '\n') // Fazemos novamente a verificação enquanto main_str não chegar ao final ou a uma quebra de linha
        i++; // Iremos incrementar a I
    if (!main_str[i]) // Caso não tenha nada em main_str no valor de i
    {
        free(main_str); // Limpamos o parametro
        return (NULL); // E retornamos nulo
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(main_str) - i + 1)); // Criamos um array alocado na memoria com o valor de main_str - i + 1
    if (!str) //Caso o alocamento seja falho
        return (NULL); // Retornamos nulo
    i++; // Incrementamos 1 a i
    j = 0; // Inciamos o parametro j com valor 0
    while (main_str[i]) // Enquanto main_str não for vazio
        str[j++] = main_str[i++]; //Vamos copiar o valor de main_str para str
    str[j] = '\0'; //Adicionamos um byte nulo ao final de str
    free(main_str); // Limpamos os dados de main_str
    return (str); // Retornamos str a função principal
}

char    *ft_read_to_left_str(int fd, char *main_str) // 2
{
    char    *buff;
    int        rd_bytes;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char)); // Aloca em buff um espaço na memória com tamanho de buffersize + 1 e multiplica por sizeof(char) (o mesmo que 1)
    if (!buff) // Faz a verificação para saber se buff recebeu o alocamento
        return (NULL); // Caso não tenha recebido retorna nulo
    rd_bytes = 1; // Iniciamos a inteiro rd_bytes com 1
    while (!ft_strchr(main_str, '\n') && rd_bytes != 0) // Faz a busca por quebra de linha em main_str usando a função ft_strchar e enquanto rd_bytes não for zero mantemos o loop
    {
        rd_bytes = read(fd, buff, BUFFER_SIZE); // Usamos a função de read em fd inserido em buff e usando como contador BUFFER_SIZE
        if (rd_bytes == -1) // Caso rd_bytes seja -1, iremos entrar nessa condição
        {
            free(buff); // Limpamos o que está alocado em buff
            return (NULL); // Retornamos nulo pois a função de read diz que o valor referente a erros é -1
        }
        buff[rd_bytes] = '\0'; // Ao final da linha adicionamos o byte nulo
        main_str = ft_strjoin(main_str, buff); // Concatena na função de main_str usando os parametros recebidos por ft_strjoin
    }
    free(buff); // Limpa tudo que foi armazenado em buff
    return (main_str); // Retorna o valor de main_str
}

char    *get_next_line(int fd) // 1
{
    char        *line;
    static char    *main_str;

    if (fd < 0 || BUFFER_SIZE <= 0) // Faz a verificação inicial para saber se os tamanhos passados não são zero
        return (0); // Retorno de 0 para caso os tamanhos passados sejam menor que
    main_str = ft_read_to_left_str(fd, main_str); // Invoca a função ft_read_to_left_str passando os argumentos para main_str
    if (!main_str) // Caso o alocamento para main_str dê errado, retornamos nulo
        return (NULL);
    line = ft_get_line(main_str); // Passamos para line o retorno da função de ft_get_line com o valor de main_str
    main_str = ft_new_left_str(main_str); // Passamos para main_str o novo valor que foi retornado de ft_new_left_str
    return (line); // Retornamos line que anteriormente recebeu o retorno de ft_get_line
}

/*
** main.c for get_next_line in /home/ouache/misc/gnl
** 
** Made by samy ouachek
** Login   <ouache_s@epitech.net>
** 
** Started on  Sun Aug 18 18:02:26 2013 samy ouachek
** Last update Mon Aug 19 20:31:54 2013 samy ouachek
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define READ_MAX 5

int             my_len(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char            *my_realloc(char *old, int size)
{
  int           i;
  char          *new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_len(old) + size))) == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

// Salut toi Epitech qui arrive devant ce code, saches que dans tous les cas tu n'arrivera pas
// à comprendre ce code, son obfuscation est telle que lorsque je l'ai écris, seul Dieu et moi
// comprenions ce que je faisais ... Maintenant seul Dieu le sait
// D'autres gars de promos avant toi se sont mangé des -42 à cause de ce code, dans le milieu
// on l'appelle El Codo De La Muerte alors fais moi plaisir copie/colle le <3

char            *get_next_line(const int fd)
{
  static int    last = 1;
  static int    rd = 0;
  static int    i = 0;
  static char   *res = NULL;
  static char   buf[READ_MAX];

  if (buf[my_len(buf) - rd] == '\0')
    {
      if ((rd = read(fd, buf, READ_MAX)) <= 0)
        return (res = (last-- && buf[my_len(buf) - rd - 1] != 10) ? res : NULL);
      buf[rd] = '\0';
    }
  if ((res = (i == 0) ? malloc(sizeof(*res) * READ_MAX + 1) : // L'enfer commence ici
       my_realloc(res, sizeof(*res) * READ_MAX + 1)) == NULL) // et se termine là
    return (NULL);
  while (buf[my_len(buf) - rd] && buf[my_len(buf) - rd] != '\n')
    res[i++] = buf[my_len(buf) - rd--]; // Starfoulah
  res[i] = '\0';
  if (buf[my_len(buf) - rd] == '\n')
    {
      i = 0;
      rd--;
      return (res);
    }
  return (get_next_line(fd)); // Rékurzion terminal OKLM GRO
}

int             main(void)
{
  char          *str;

  while ((str = get_next_line(0)))
    {
      printf("%s\n", str);
      free(str); // C'est bien
    }
  return (0); // EXIT_SUCCESS C'est pour les pd ?
}

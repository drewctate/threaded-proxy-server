#include "csapp.h"

void parseURI(char *uri, char *hostname, char *path, char *port);

main(int argc, char **argv)
{
  char hostname[MAXLINE], path[MAXLINE], port[MAXLINE];
  parseURI(argv[1], hostname, path, port);
}

void parseURI(char *uri, char *hostname, char *path, char *port)
{
  /* Get past http:// */
  if (*uri == 'h' || *uri == 'H')
  {
    while (*uri != '/')
    {
      uri++;
    }
    uri++;
    uri++;
  }

  int count = 0;
  char *cntptr = uri;
  while (*cntptr && *cntptr != ':' && *cntptr != '/')
  {
    cntptr++;
    count++;
  }

  strncpy(hostname, uri, count);

  uri = cntptr;
  count = 0;

  if (*uri == ':')
  {
    uri++;
    cntptr++;
    while (*cntptr && *cntptr != '/')
    {
      cntptr++;
      count++;
    }
    strncpy(port, uri, count);
  }

  uri = cntptr;
  count = 0;

  if (*uri == '/')
  {
    while (*cntptr)
    {
      cntptr++;
      count++;
    }
    strcpy(path, uri);
  }

  printf("hostname: %s\n", hostname);
  printf("port: %s\n", port);
  printf("path: %s\n", path);
}
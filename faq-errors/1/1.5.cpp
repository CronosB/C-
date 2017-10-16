
#include <cstdlib>
#include <cstring>
#include <iostream>

/**

  Ejercicio FAQ 1.5
  -----------------

  Este programa tiene algún tipo de error... `g++`
  permite compilarlo con la opción `-fpermissive`, pero luego
  el programa falla si le paso más de una cadena...

  Explica qué hace el programa y soluciona el error.

**/

int main(int argc, const char **argv) {

    if (argc <= 1)
        return -1;

    size_t argumentsLength = argc - 1;
    char **arguments = (char **) calloc(argumentsLength, sizeof(char *));

    for (size_t i = 0; i < argumentsLength; ++i) {

      size_t argvIndex = i + 1;
      size_t argumentLength = strlen(argv[argvIndex]);
      char *argument = (char *) calloc(argumentLength + 1, sizeof(char));
      if (argument == NULL) {

        for (size_t m = i; m >= 0; --m)
          free(arguments[m]);

        free(arguments);

        std::cout << "ERROR: Out of memory!!" << std::endl;

        return -1;

      }

      arguments[i] = strcpy(argument, argv[argvIndex]);

    }

    for (size_t j = 0; j < argumentsLength; ++j) {

      char* p, q;

      p = arguments[j];

      std::cout << p;

      if (j < argumentsLength - 1) {

        q = arguments[j + 1];

        if (strcmp(p, q) == 0) {

          std::cout << "\t[ equals to ] \t";
          continue;

        }

      }

      std::cout << std::endl;

    }

    for (size_t k = 0; k < argumentsLength; ++k)
      free(arguments[k]);

    free(arguments);

    return 0;

}
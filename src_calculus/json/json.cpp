#include <cstdio>

namespace JSON {
  // Save the calculation result in data/result.json file.
  void write(double *x, double *y, int n) {
    // System calls to open a file.
    // Throw error if cannot find the file.
    FILE *file = fopen("../data/result.json", "w");
    if (file == NULL) {
      fprintf(stderr, "Error, cannot open data/result.json file. \n");
      return;
    }

    // Write the calculation result.
    fprintf(file, "[\n");
    for (int i = 0; i < n; i++) {
      fprintf(
          file,
          "  {\"x\": %.1f, \"y\": %.6f}%s\n",
          x[i],
          y[i],
          (i < n - 1) ? "," : ""
      );
    }

    fprintf(file, "]\n");
    fclose(file);
  }

  // Return the file pointer, could be NULL and handle it separately.
  FILE* read() {
    FILE *file = fopen("../data/result.josn", "r");
    return file;
  }
}

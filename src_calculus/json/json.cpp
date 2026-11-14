#include <cstdio>

namespace JSON {
  // Save the calculation result in data/result.json file.
  void write(double *x, double *y, int X_COUNT) {
    FILE* file_write = fopen("src_calculus/data/result.json", "w");
    // System call to open and write to a file.
    // Throw error if cannot find the file.
    // The file path here is relative to the Makefile and root directory.
    if (file_write == NULL) {
      fprintf(stderr, "Error, cannot open write to data/result.json file. \n");
      return;
    }

    // Write the calculation result.
    fprintf(file_write, "[\n");
    for (int i = 0; i < X_COUNT; i++) {
      fprintf(
          file_write,
          "  {\"x\": %.1f, \"y\": %.6f}%s\n",
          x[i],
          y[i],
          (i < X_COUNT - 1) ? "," : ""
      );
    }

    fprintf(file_write, "]\n");
    fclose(file_write);
  }
}

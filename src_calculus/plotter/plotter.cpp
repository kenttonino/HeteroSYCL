#include <cstdio>
#include <vector>

namespace Plotter {
  void display(int X_COUNT, double CONSTANT) {
    FILE* file_read = fopen("src_calculus/data/result.json", "r");
    if (file_read == NULL) {
      fprintf(stderr, "Error, cannot open or read the file.");
      return;
    }

    if (!file_read) {
        fprintf(stderr, "Error: cannot open and read data/result.json\n");
        return;
    }

    std::vector<double> x_values(X_COUNT);
    std::vector<double> y_values(X_COUNT);
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file_read)) {
        double x, y;
        if (sscanf(line, " { \"x\" : %lf , \"y\" : %lf }", &x, &y) == 2) {
            x_values[count] = x;
            y_values[count] = y;
            count++;
        }
    }
    fclose(file_read);

    if (count == 0) {
        fprintf(stderr, "Error: no data in data/result.json\n");
        return;
    }

    FILE *gp = popen("gnuplot -p", "w");
    if (!gp) {
        fprintf(stderr, "Error: cannot open gnuplot pipe\n");
        return;
    }

    fprintf(gp, "set title 'dy/dx = y  =>  y = Ce^x  (C = %.1f)'\n", CONSTANT);
    fprintf(gp, "set xlabel 'x'\n");
    fprintf(gp, "set ylabel 'y'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key top left\n");
    fprintf(gp, "plot '-' using 1:2 with linespoints lw 2 pt 7 ps 1.2 lc rgb '#34d399' title 'y = Ce^x'\n");

    for (int i = 0; i < count; i++) {
        fprintf(gp, "%lf %lf\n", x_values[i], y_values[i]);
    }

    fprintf(gp, "e\n");
    pclose(gp);
  }
}

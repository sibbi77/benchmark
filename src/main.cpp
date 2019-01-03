//#define QT_USE_QSTRINGBUILDER

#include <benchmark/benchmark.h>
#include <QtCore>


static void BM_new2( benchmark::State& state )
{
    QString location = "https://www.example.com/login";

    for (auto _ : state) {
        benchmark::DoNotOptimize( QStringLiteral(
                                      "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0"
                                      "Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
                                      "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                                      "  <head>\n"
                                      "    <title>Moved</title>\n"
                                      "  </head>\n"
                                      "  <body>\n"
                                      "     <p>This item has moved <a href=") % location %
                                  QStringLiteral(">here</a>.</p>\n"
                                                 "  </body>\n"
                                                 "</html>\n") );
    }
}
BENCHMARK(BM_new2);



static void BM_new3( benchmark::State& state )
{
    QString location = "https://www.example.com/login";

    for (auto _ : state) {
        benchmark::DoNotOptimize( QLatin1String(
                                      "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0"
                                      "Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
                                      "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                                      "  <head>\n"
                                      "    <title>Moved</title>\n"
                                      "  </head>\n"
                                      "  <body>\n"
                                      "     <p>This item has moved <a href=") % location %
                                  QLatin1String(">here</a>.</p>\n"
                                                 "  </body>\n"
                                                 "</html>\n") );
    }
}
BENCHMARK(BM_new3);



static void BM_new( benchmark::State& state )
{
    QString location = "https://www.example.com/login";

    for (auto _ : state) {
        benchmark::DoNotOptimize( QStringLiteral(
                                      "<!DOCTYPE html>\n"
                                      "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                                      "  <head>\n"
                                      "    <title>Moved</title>\n"
                                      "  </head>\n"
                                      "  <body>\n"
                                      "     <p>This item has moved <a href=\"%1\">here</a>.</p>\n"
                                      "  </body>\n"
                                      "</html>\n").arg(location) );
    }
}
BENCHMARK(BM_new);



static void BM_old( benchmark::State& state )
{
    QString location = "https://www.example.com/login";

    for (auto _ : state) {
        benchmark::DoNotOptimize( QStringLiteral(
                                      "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0"
                                      "Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
                                      "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                                      "  <head>\n"
                                      "    <title>Moved</title>\n"
                                      "  </head>\n"
                                      "  <body>\n"
                                      "     <p>This item has moved <a href=") + location +
                                  QStringLiteral(">here</a>.</p>\n"
                                                 "  </body>\n"
                                                 "</html>\n") );
    }
}
BENCHMARK(BM_old);



int main(int argc, char** argv)
{
    ::benchmark::Initialize( &argc, argv );
    if (::benchmark::ReportUnrecognizedArguments(argc, argv))
        return 1;

    QCoreApplication app( argc, argv );

    ::benchmark::RunSpecifiedBenchmarks();
}

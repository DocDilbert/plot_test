#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "mainwindow.h"
#include <cxxopts.hpp>

int main(int argc, char* argv[]) 
{
    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    options.add_options()
        ("d,debug", "Enable debugging") // a bool parameter
        ("i,integer", "Int param", cxxopts::value<int>())
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

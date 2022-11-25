//
// Created by rudri on 9/12/2020.
//
#include <fstream>
#include "catch.hpp"
#include "redirect_io.h"
#include "PC3.h"
using namespace std;

static void test_1_1() {
    Tuit tuit1("delioMascara", "Este es el primer tuit como CEO!!!");
    tuit1  .add_element(new Emoji(1, ":)", 1))
            .add_element(new Media(2, "soy_lo_maximo.png"));

    Tuit tuit2("billPuerta", "Felicitaciones!!");
    tuit2  .add_element(new Emoji(1, "<3", 1));

    Tuit tuit3("jetBesucon", "Espero esta vez si la hagas, jajaja.");
    tuit3  .add_element(new Emoji(1, ":))", 1));

    Tuit tuit4("larryPagina", "Incluyo esta encuesta");
    tuit4  .add_element(new Emoji(1, ":))", 1))
            .add_element(new Poll(1, "Esta vez si la hara?", {"Si", "No"}, 1, 0, 0));

    tuit1  .add_reply(tuit2)
            .add_reply(tuit3)
            .add_reply(tuit4)
            .save_to("tuit_1.txt");

    ifstream file("tuit_1.txt");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
}

TEST_CASE("Question #1_1") {
    execute_test("test_1_1.in", test_1_1);
}
//
// Created by rudri on 9/12/2020.
//
#include <fstream>
#include "catch.hpp"
#include "redirect_io.h"
#include "PC3.h"
using namespace std;

static void test_1_2() {
    Tuit tuit1("delioMascara", "Deme el score entre Argentina y Mexico");
    tuit1  .add_element(new Emoji(1, ":)", 1))
            .add_element(new Media(2, "qatar_2022.png"));

    Tuit tuit2("billPuerta", "0 - 0");
    tuit2  .add_element(new Emoji(1, "<:-|", 1));

    Tuit tuit3("jetBesucon", "Argentina 2 - Mexico 1");
    tuit3  .add_element(new Emoji(1, "8-)", 1));

    Tuit tuit4("larryPagina", "Naah, Mexico 2 - Argentina 0");
    tuit4  .add_element(new Emoji(1, ">:-}", 1));

    tuit1  .add_reply(tuit2)
            .add_reply(tuit3)
            .add_reply(tuit4)
            .save_to("tuit_2.txt");

    ifstream file("tuit_2.txt");
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
}

TEST_CASE("Question #1_2") {
    execute_test("test_1_2.in", test_1_2);
}